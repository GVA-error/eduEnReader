#include "wordcash.h"

WordCash::WordCash()
{
    _curCashedPersent = 0;
}

void WordCash::cashAllFiles()
{
    _cashMap.clear();
    _logicList.clear();
    QStringList bindNames;
    Logic::getAllFiles(bindNames, QDir().currentPath(), QStringList("*.bnd"));
    qint32 cashed = 0;
    for (QString bindName : bindNames)
    {
        SoundStore::PTR soundStore = nullptr;//SoundStore::factoryMethod();
        TextStore::PTR textStore = TextStore::factoryMethod();
        Logic::PTR logic = Logic::factoryMethod();
        logic->readFromFile(bindName, textStore, soundStore);
        cashLogic(logic);
        _logicList.push_back(logic);
        cashed++;
        _curCashedPersent = 100.f * (qreal)cashed / bindNames.size();
        emit newFileCashed();
    }

}

Logic::CashMap WordCash::getCashMap()
{
    return _cashMap;
}

void WordCash::cashLogic(Logic::PTR logic)
{
    QSharedPointer <Logic::Cash> cash = QSharedPointer <Logic::Cash>(new Logic::Cash());
    cash->_binds = logic->getBindVector();
    cash->_soundFileUrl = logic->getCurSoundStoreUrl();

    QSet <QString> cashWordSet;
    for (qint32 bindNumber = 0; bindNumber<cash->_binds.size(); bindNumber++)
    {
        TextFragment::PTR text = cash->_binds[bindNumber].text;
        QSet <QString> bindWordSet = text->getWordSet();
        for (QString word : bindWordSet)
        {
            cash->_wordPos[word].insert(bindNumber);
        }
        cashWordSet += bindWordSet;
    }
    for (QString word : cashWordSet)
        _cashMap[word].push_back(cash);
}









