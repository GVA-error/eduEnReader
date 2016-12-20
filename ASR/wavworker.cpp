#include "wavworker.h"

WavWorker::WavWorker()
{
    _in = NULL;
    _out = NULL;
}

WavWorker::~WavWorker()
{

}

void WavWorker::defaultInitFSInfo(SF_INFO&sfinfo)
{
    memset (&sfinfo, 0, sizeof (sfinfo));
}

void WavWorker::initFSInfo(SF_INFO& sfinfo, const Settings& settings)
{
    defaultInitFSInfo(sfinfo);
    sfinfo.samplerate	= settings.samplesPerSecond;
    sfinfo.channels		= 1;
    switch (settings.bitRate) {
    case 16:
        sfinfo.format		= (SF_FORMAT_WAV | SF_FORMAT_PCM_16);
        break;
    default:
        qCritical() << "Can no maintance bitRate: " << settings.bitRate;
        exit(1);
        break;
    }
}

void WavWorker::openInFile(const QString& fileName)
{
    SF_INFO	sfinfo;
    if (_in)
        sf_close(_in);
    defaultInitFSInfo(sfinfo);
    _in = sf_open(fileName.toLatin1(), SFM_READ, &sfinfo);
    if (!_in)
    {
        qCritical() << "Can not open input file: " << fileName;
        exit(1);
    };
}

void WavWorker::openOutFile(const QString& fileName, const Settings& settings)
{
    SF_INFO sfinfo;
    if (_out)
        sf_close(_out);
    initFSInfo(sfinfo, settings);
    _out = sf_open (fileName.toLatin1(), SFM_WRITE, &sfinfo);
    if (!_out)
    {
        qCritical() << "Can not open output file: " << fileName;
        exit(1);
    };
}

bool WavWorker::read(double* data, int buffSize)
{
    bool succes = sf_read_double(_in, data, buffSize);
    return succes;
}

bool WavWorker::write(double* data, int dataSize)
{
    bool succes = sf_write_double (_out, data, dataSize);
    return succes;
}
