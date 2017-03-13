#include "datapreparation.h"

DataPreparation::DataPreparation(QObject *parent) : QObject(parent)
{
}

QString DataPreparation::prepeareWav(const QString& videoFile)
{
    QString wavFile = _scripter.extractAudio(videoFile);
    //generateNoise_wav(wavFile, _noise_wav);
    generateNoise_wav(wavFile, _noise_wav, _noiseWindowBegin, _noiseWindowEnd);
    _scripter.noiseReduse(wavFile, _noise_wav);
    return wavFile;
}

void DataPreparation::generateNoise_wav(const QString& fileName, const QString& noiseWav, qint64 begin, qint64 end)
{
    QString tmp_filtred = "f_" + fileName;
    if (QFile::exists(tmp_filtred))
        QFile::remove(tmp_filtred);
    QFile::copy(fileName, tmp_filtred);
    _scripter.noiseReduse(tmp_filtred, tmp_filtred);

    _wav.openInFile(tmp_filtred);
    _wav.setReadPos(begin);
    qint64 curPos = begin;
    qint64 globalMinPos = curPos;
    qreal globalMinEnergy;
    qint64 step = _noiseFileSize / 4;
    double* buff = new double[_noiseFileSize];
    _wav.read(buff, step * 3);
    bool f_processing = true;
    while (f_processing && curPos + step*5 < end)
    {
        double* readBuffer = new double[step];
        f_processing = _wav.read(readBuffer, step);
        double* tmp = buff;
        buff = join(buff, 3*step, readBuffer, step);
        delete tmp;
        delete readBuffer;
        qreal localEnergy = getEnergy(buff, 0, step * 4);
        if (curPos == begin || localEnergy < globalMinEnergy)
        {
            globalMinPos = curPos;
            globalMinEnergy = localEnergy;
        }
        tmp = buff;
        buff = splitBegin(buff, 4*step, step);
        delete tmp;
        curPos += step;
    }
    delete buff;

    _wav.openInFile(fileName);
    WavWorker::Settings settings;
    writePreparation(settings);
    if (QFile::exists(noiseWav))
        QFile::remove(noiseWav);
    _wav.openOutFile(noiseWav, settings);
    _wav.copyPart(globalMinPos, _noiseFileSize);
}

double* DataPreparation::join(double* prefix, qint64 prefixSize, double* data, qint64 dataSize) const
{
    double* rez = new double[prefixSize + dataSize];
    for (int i = 0; i < prefixSize; i++)
        rez[i] = prefix[i];
    for (int i = 0; i < dataSize; i++)
        rez[prefixSize + i] = data[i];
    return rez;
}

double* DataPreparation::splitBegin(double* source, qint64 sourceSize, qint64 splitSize) const
{
    double* rez = new double[sourceSize - splitSize];
    for (int i = 0; i < sourceSize - splitSize; i++)
        rez[i] = source[splitSize + i];
    return rez;
}

qreal DataPreparation::getEnergy(double* data, qint64 begin, qint64 end)
{
    qreal energy = 0;
    for (qint64 i = begin; i < end; i++)
    {
        // это не мощность, на windSize делить не обязательно
        // так как окно всегда одинакого, деление не чего не даёт
        qreal localEnergy = data[i]; // Можно использовать окно хеминга для вычисления, но нас тут не итересует точность
        energy += localEnergy * localEnergy;
    }
    return energy;
}

qint64 DataPreparation::getEnergyMin(double* data, qint64 dataSize, qint64 windowSize)
{
    qint64 edgeOffset = windowSize/2;
    qint64 minPos = 0;
    qreal curMinLevel = -1;
    for (qint64 i = edgeOffset; i<dataSize-edgeOffset; i+=windowSize/4) // TODO можно попробовать обратный обход
    {
        qint64 beginWind = i-edgeOffset;
        qint64 endWind = i+edgeOffset;
        qreal curEnergyLevel = getEnergy(data, beginWind, endWind);
        if (curEnergyLevel < curMinLevel || curMinLevel < 0)
        {
            curMinLevel = curEnergyLevel;
            minPos = i;
        }
    }
    return minPos;
}

qreal DataPreparation::getStadyComponent(double* data, qint64 dataSize)
{
    qreal summ = 0;
    for (qint64 i = 0 ; i<dataSize; i++)
        summ+= data[i];
    qreal avg = summ/dataSize;
    return avg;
}

void DataPreparation::useMultyWindow(double* data, qint64 dataSize)
{
    for (qint64 i = 0; i<dataSize; i++)
        data[i] *= 0.54f - 0.46f*cos(M_2_PI*i/(dataSize-1));
}

void DataPreparation::deleteStadyComponent(double* data, qint64 dataSize)
{
    qreal stadyComponent = getStadyComponent(data, dataSize);
    for (qint64 i = 0; i<dataSize; i++)
        data[i] -= stadyComponent;
}

void DataPreparation::writePreparation(WavWorker::Settings& settings, const QDir& outDirrectory)
{
    if (outDirrectory.exists() == false)
        QDir().mkdir(outDirrectory.path());
    // Щитаем шаг
    settings.samplesPerSecond = _16k;
    settings.bitRate = 16;
}

void DataPreparation::splitFile(const QString& fileName, qreal minSplitSize, qreal maxSplitSize, const QDir& outDirrectory)
{
    assert(minSplitSize > 0 && maxSplitSize > 0 && maxSplitSize > minSplitSize);
    WavWorker::Settings settings;
    writePreparation(settings);
    qint64 discret = settings.samplesPerSecond;
    qint64 maxStep = maxSplitSize * discret;
    qint64 minStep = minSplitSize * discret;
    double* buff = new double[2*maxStep];
    if (QFile(fileName).exists() == false)
    {
        qDebug() << "Incorrect file name or file not exists: " << fileName << "\n";
        return;
    }
    qint64 partNumber = 0;
    qint64 curBuffSize = 0;
    bool f_processing = true;
    qint64 curPos = 0;
    _wav.openInFile(fileName);
    while (f_processing)
    {
        QString ID = QString().number(partNumber);
        QString outputName = formNPurtName(fileName, ID);
        if (curBuffSize < maxStep)
        {
            qint64 readBufferSize = maxStep;
            double* readBuffer = new double[readBufferSize];
            f_processing = _wav.read(readBuffer, readBufferSize);
            double* tmp = buff;
            buff = join(buff, curBuffSize, readBuffer, readBufferSize);
            delete tmp;
            delete readBuffer;
            curBuffSize += maxStep;
        }
        assert(curBuffSize >= minStep);
        qint64 minPos = minStep + getEnergyMin(buff + minStep, curBuffSize - minStep);
        _wav.openOutFile(outputName, settings);
        _wav.write(buff, minPos);
        _rezFileNameList.push_back(outputName);
        _rezFileBeginOffset[outputName] = (floor(10 * (qreal)curPos / discret))/10;
        _rezFileEndOffset[outputName] = (floor(10 * (qreal)(curPos + minPos) / discret))/10;
        curPos += minPos;
        double* tmp = buff;
        buff = splitBegin(buff, curBuffSize, minPos);
        curBuffSize -= minPos;
        delete tmp;
        partNumber++;
    }
    delete buff;
    for (auto part : _rezFileNameList)
        _scripter.normalise(part);
}

void DataPreparation::splitFile(const QString &fileName, qreal splitSize, const QDir &outDirrectory)
{
    QStringList rezFileList;
    // Настраиваем файловую систему
    //if (fileIsCorrect(fileName) == false)
    //    return rezFileList;
    WavWorker::Settings settings;
    // Щитаем шаг
    writePreparation(settings);
    qint32 step = splitSize * settings.samplesPerSecond;

    if (splitSize<1.0f)
        qCritical() << "Soo shorty file split is don't good idea";

    double *buff = new double[step];
    _wav.openInFile(fileName);
    qint64 partNumber = 0;
    qint64 curPos = 0;
    while (_wav.read(buff, step))
    {
        // Note: так как буфер не пересчитываеться поседний файл записываеться с тишиной
        QString ID = QString().number(partNumber);
        QString outputName = formNPurtName(fileName, ID);
        _wav.openOutFile(outputName, settings);
        _wav.write(buff, step);
        rezFileList.push_back(outputName);
        partNumber++;
        _rezFileBeginOffset[outputName] = curPos;
        _rezFileEndOffset[outputName] = curPos + step;
        curPos += step;
    }
    delete buff;
}

// Нужна для разбиения файла на части
QString DataPreparation::formNPurtName(const QString& sourceName, const QString& ID)
{
    QFileInfo file(sourceName);
    QString shortName = file.baseName();
    QString dir = SPLIT_DIR.absolutePath();
    QString rezName = dir + "/" + ID + "_" + shortName + ".wav";
    return rezName;
}

/*
void DataPreparation::savePartFile(const SoundFileRead *file, const QString& partName, qint64 begin, qint64 end)
{
    qint64 size = end-begin;
    double* partData = new double[size];
    getNormalized(partData, file, begin, end);
    // ТУТ сохранение файла
    delete partData;
}

// Нужна для сохронения и подготовки
void DataPreparation::getNormalized(double*& out, const SoundFileRead* file, qint64 begin, qint64 end)
{
    if (!out)
    {
        qCritical() << "Not prepered normalized data";
        return;
    }
    double maxValue = getMaxAmplitude(file, begin, end);
    for (auto i = begin; i < end; i++)
    {
        double curValue = 0; // ТУТ file->operator ()(i);
        double normalizedValue = curValue / maxValue;
        assert(curValue <= maxValue);
        qint64 curOutIndex = i - begin;
        out[curOutIndex] = normalizedValue;
    }
}
// Нужна для нормализации
qint32 DataPreparation::getMaxAmplitude(const SoundFileRead* file, qint64 begin, qint64 end)
{
    qint32 maxValue = 0;
    for (auto i = begin; i<end; i++)
    {
        qint32 curValue = 0;// ТУТ abs(file->operator ()(i));
        if (curValue > maxValue)
            maxValue = curValue;
    }
    return maxValue;
}
*/
/*
bool DataPreparation::fileIsCorrect(const QString& fileName)
{
    // ТУТ riffwave_reader rrif(fileName.toLatin1());
    qint32 realDiscret =  0; // ТУТ rrif.samplespersec();
    if (realDiscret != _16k) // так как всёравно запишем битрейтом 16 - битность не интересует
    {
        qCritical() << "It version mantain 16kHz only";
        return false;
    }
    return true;
}
*/
void DataPreparation::clearDefaultSplitDir()
{
    clearDir(SPLIT_DIR);
    _rezFileNameList.clear();
    _rezFileBeginOffset.clear();
    _rezFileEndOffset.clear();

}

bool DataPreparation::clearDir(const QDir &dir)
{
    const QFileInfoList fileList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    bool result = true;
    QFile file;

    auto cur = fileList.constBegin();
    auto end = fileList.constEnd();
    for (; result && cur != end; cur++)
    {
        const QString fileName = cur->absoluteFilePath();

        qDebug () << QString("Remove ") << fileName;

        result = file.remove ();

        if (!result)
            qDebug () << file.errorString ();
    }

    return result;
}
