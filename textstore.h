#ifndef TEXTSTORE_H
#define TEXTSTORE_H

#include <QObject>
#include <QTextDocument>
#include <QString>
#include <QVector>

class TextStore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 blockSize)
    Q_PROPERTY(QVector <QString> textBlocks)
public:
    explicit TextStore(QObject *parent = 0);

    // Размер блока, каждый блок отвечает за свою часть текста, модификаторы за текст не считаем
    const qint32 blockSize = 10;
    // для удобства обработки храним текст в блоках
    QVector <QString> textBlocks;


signals:
    void textWasChanged();
public slots:

    Q_INVOKABLE QVariant getBlock(qint64 blockNumber);

};

#endif // TEXTSTORE_H
