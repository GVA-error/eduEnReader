#include "textstore.h"

TextStore::TextStore(QObject *parent) : QObject(parent)
{
    textBlocks.resize(2);

    textBlocks[0] = "0123456789";
    textBlocks[1] = "<h1>abc</h1>";

    emit textWasChanged();
}

QVariant TextStore::getBlock(qint64 blockNumber)
{
    return textBlocks.at(blockNumber);
}
