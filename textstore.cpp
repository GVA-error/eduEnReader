#include <QColor>
#include "textstore.h"

TextStore::TextStore(QObject *parent) : QObject(parent)
{
    QColor col = QColor().red();
    if (!col.isValid())
       return;
    QTextCharFormat fmt;
    fmt.setForeground(col);

    QTextEdit textEdit;
    textEdit.setDocument(document.data());
  /*  QTextCursor cursor = textEdit.textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
    textEdit->mergeCurrentCharFormat(fmt);*/


    emit textWasChanged();
}
