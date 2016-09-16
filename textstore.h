#ifndef TEXTSTORE_H
#define TEXTSTORE_H

#include <QObject>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QTextCodec>
#include <QTextEdit>
#include <QCursor>
#include <QString>
#include <QVector>
#include <QTextBlock>


// Не нужен
class TextStore : public QObject
{
    Q_OBJECT
public:
    typedef QSharedPointer <TextStore> PTR;
    static QSharedPointer <TextStore> factoryMethod()
    {
        PTR rezPtr = QSharedPointer <TextStore> (new TextStore());
        return rezPtr;
    }

    explicit TextStore(QObject *parent = 0);

    QSharedPointer<QTextDocument> document;
signals:
    void textWasChanged();
public slots:
    void setDocument(QTextDocument& newDock){ document = QSharedPointer<QTextDocument>(&newDock); }

private:

    void clearSimularBind(qint64 beginTextPos, qint64 endTextPos, QColor color, qint64 beginSoundPos, qint64 endSoundPos);
};

#endif // TEXTSTORE_H
