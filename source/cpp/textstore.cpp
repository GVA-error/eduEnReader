#include <QColor>
#include "textstore.h"

#include <QtGui/QTextDocument>
#include <QtGui/QTextCursor>
#include <QtGui/QFontDatabase>
#include <QtCore/QFileInfo>

TextStore::TextStore()
    : _target(0)
    , _doc(&_default_m_doc)
    , _cursorPosition(0)
    , _selectionStart(0)
    , _selectionEnd(0)
    , _saved_url(QUrl())
    , _saved_curPosition(0)
    , _mousePresed(false)
    , _someOpened(false)
{
    _markColor = getDefaultMarkColor(); // TODO Заменить на сигналы
}

void TextStore::addTextForComment(const QString& text, const QColor& textColor)
{
    QString addingText = "\n" + text + " - ";
    //_text.push_back(addingText);
    qint64 textLength = getString().length();
    auto cursor = textCursor();
    cursor.setPosition(textLength);
    cursor.insertText(addingText);

    qint64 addingTextLength = addingText.length();
    setSelectionStart(textLength);
    setSelectionEnd(textLength + addingTextLength - 3);
    setTextColor(textColor);
    saveAs(_fileUrl, ".html");
}

bool TextStore::posIsCorrect(qint64 curPos) const
{
    if (curPos < 0 || curPos > _text.length())
        return false;
    return true;
}

qint64 TextStore::getWordEnd(qint64 curPos, bool reversDirrection) const
{
    qint64 wordEnd;
    QRegExp sep("\\W"); // TODO сначало искать начало слова
    if (reversDirrection)
        wordEnd = _text.lastIndexOf(sep, curPos);
    else
        wordEnd = _text.indexOf(sep, curPos);

    if (wordEnd < 0)
        if (reversDirrection)
            wordEnd = 0;
        else
            wordEnd = _text.length() - 1;
    return wordEnd;
}

//qint64 TextStore::indexOfPrefixOrPostFix(const QString& str, qint64 leftOffset) const
//{
//    qint32 index = -1;
//    for (auto fix : _prefixAndPostFix)
//    {
//        qint32 curIndex;
//        if (leftOffset >= 0)
//            curIndex = str.indexOf(fix, leftOffset);
//        else
//            curIndex = str.lastIndexOf(fix, -leftOffset);

//        if (curIndex != -1 && curIndex < index)
//            index = curIndex;
//    }
//    return index;
//}

//QStringList TextStore::getAllWordVarints(const QString& word) const
//{
//    QStringList vars;
//    for (auto prefix : _prefixAndPostFix)
//        for (auto postfix : _prefixAndPostFix)
//            vars.push_back(prefix + word + postfix);
//    return vars;
//}

//bool TextStore::isPrefixOrPostfix(const QString& s) const
//{
//    if (_prefixAndPostFix.indexOf(s))
//        return true;
//    return false;
//}

QList <qint64> TextStore::getWordPositions(const QString& word) const
{
    QString text = getString();
    QString curTextPart = text;

    //QStringList textList = text.split(_prefixAndPostFix);
    QList <qint64> rezList;

    qint64 beginPos = 0;
    while (curTextPart.length() != 0)
    {
        qint64 pos = curTextPart.indexOf(word);
        qint64 realPos = beginPos + pos;
        if (pos == -1)
            break;
        qint64 l = word.length();
        qint64 cutSize = pos + l;
        beginPos += cutSize;
        curTextPart = curTextPart.mid(cutSize);
        QRegExp sep("\\W");
        if (!sep.exactMatch(text.at(realPos-1)))
            if (realPos > 1)
                continue;
        if (!sep.exactMatch(text.at(realPos+l)))
            if (realPos < text.length())
                continue;
        rezList.push_back(realPos);
    }
    return rezList;
}

QString TextStore::getString(qint64 begin, qint64 end) const
{
    QString str = getString();
    //Q_ASSERT(end >= begin); // TODO Вернуть после введения понятия бесконечного бинда
    if (end < begin)
        end = begin = 0; // TODO а это стереть

    //if (begin == 5174)
   //     return str.mid(begin, end - begin);

    return str.mid(begin, end - begin);
}

QString TextStore::getString() const
{
    QString planeText = _doc->toPlainText(); // заменить на член
    return planeText;
}

QString TextStore::getSellectedStreing() const
{
    qint64 begin = _selectionStart;
    qint64 end = _selectionEnd;
    QString sellectedString = getString(begin, end);
    return sellectedString;
}

//qint64 TextStore::getCursorPos() const
//{

//    return _cursorPosition;
//}

void TextStore::saveHome()
{
    _saved_curPosition = cursorPosition();
    _saved_url = _fileUrl;
}

void TextStore::home()
{
    _doc->clear();
    setFileUrl(_saved_url);
    setCursorPosition(_saved_curPosition);
}

void TextStore::setTarget(QQuickItem *target)
{
    _doc = 0;
    _target = target;
    if (!_target)
        return;

    QVariant doc = _target->property("textDocument");
    if (doc.canConvert<QQuickTextDocument*>()) {
        QQuickTextDocument *qqdoc = doc.value<QQuickTextDocument*>();
        if (qqdoc)
            _doc = qqdoc->textDocument();
    }
    assert(_doc != 0);
    emit targetChanged();
}

void TextStore::setFileUrl(const QUrl &url)
{
    QString fileName = QQmlFile::urlToLocalFileOrQrc(url);
    //assert(fileName.isEmpty() == false);
    _documentTitle = QFileInfo(fileName).baseName();
    _fileUrl = url;
    if (QFile::exists(fileName)) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly))
        {
            QByteArray data = file.readAll();
            QTextCodec *codec = QTextCodec::codecForName("utf-8");
            setText(codec->toUnicode(data));
            if (_doc)
            {
                _doc->setHtml(data);
                _doc->setModified(false);
                setCursorPosition(1);
            }
            emit textChanged();
            emit documentTitleChanged();
           // _someOpened = true;
           // emit someOpenedChanged();
            reset();
        }
    }
    else if (_doc)
        _doc->clear();

    emit fileUrlChanged();
}

QString TextStore::documentTitle() const
{
    return _documentTitle;
}

void TextStore::setDocumentTitle(QString arg)
{
    if (_documentTitle != arg) {
        _documentTitle = arg;
        emit documentTitleChanged();
    }
}

void TextStore::setText(const QString &arg)
{
    if (_text != arg) {
        _text = arg;
        emit textChanged();
    }
}

void TextStore::saveAs(const QUrl &arg, const QString &fileType)
{
    bool isHtml = fileType.contains(QLatin1String("htm"));
    QLatin1String ext(isHtml ? ".html" : ".txt");
    QString localPath = arg.toLocalFile();
    if (!localPath.endsWith(ext))
        localPath += ext;
    QFile f(localPath);
    if (!f.open(QFile::WriteOnly)) {
        emit error(tr("Cannot save: ") + f.errorString());
        return;
    }
    //QString out = (isHtml ? _doc->toHtml() : _doc->toPlainText()).toUtf8();
  //  _doc->setProperty("lang", QVariant("ru-RU"));
    f.write(_doc->toHtml().toUtf8());
    f.close();
    setFileUrl(QUrl::fromLocalFile(localPath));
}

void TextStore::save()
{
    saveAs(_fileUrl, ".html");
}

QUrl TextStore::fileUrl() const
{
    return _fileUrl;
}

QString TextStore::text() const
{
    return _text;
}

void TextStore::setSelectionByWord(qint32 pos)
{
    if (pos < 0)
        pos = 0;
    QTextCursor cursor = textCursor();
    cursor.setPosition(pos);
    cursor.select(QTextCursor::WordUnderCursor);

    setSelectionEnd(cursor.selectionEnd());
    setSelectionStart(cursor.selectionStart());
}

void TextStore::setCursorPosition(int position)
{
    if (position == _cursorPosition)
        return;

    if (position < 0)
        _cursorPosition = 0;
    else
        _cursorPosition = position;

    reset();
}

void TextStore::reset()
{
    emit fontFamilyChanged();
    emit alignmentChanged();
    emit boldChanged();
    emit italicChanged();
    emit underlineChanged();
    emit fontSizeChanged();
    emit textColorChanged();
    emit cursorPositionChanged();
    emit someSellectedChanged();
}

QTextCursor TextStore::textCursor() const
{
    QTextCursor cursor = QTextCursor(_doc);
    if (_selectionStart != _selectionEnd &&
            _selectionStart>=0 && _selectionEnd>=0)
    {
        cursor.setPosition(_selectionStart);
        cursor.setPosition(_selectionEnd, QTextCursor::KeepAnchor);
    }
    else if (_cursorPosition >= 0)
        cursor.setPosition(_cursorPosition);
    else
        cursor.setPosition(0);

    return cursor;
}

void TextStore::mergeFormatOnAll(const QTextCharFormat &format)
{
    QTextCursor cursor = textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(format);
}

void TextStore::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
}

void TextStore::setSelectionStart(int position)
{
    if (position>0)
        _selectionStart = position;
    else
        _selectionStart = 0;
    emit selectionStartChanged();
    emit someSellectedChanged();
}

void TextStore::setSelectionEnd(int position)
{
    if (position > 0)
        _selectionEnd = position;
    else
        _selectionEnd = 0;
    emit selectionEndChanged();
    emit someSellectedChanged();
}

void TextStore::setAlignment(Qt::Alignment a)
{
    if (_selectionStart < 0 || _selectionEnd < 0)
        return;
    QTextBlockFormat fmt;
    fmt.setAlignment((Qt::Alignment) a);
    QTextCursor cursor = QTextCursor(_doc);
    cursor.setPosition(_selectionStart, QTextCursor::MoveAnchor);
    cursor.setPosition(_selectionEnd, QTextCursor::KeepAnchor);
    cursor.mergeBlockFormat(fmt);
    emit alignmentChanged();
}

Qt::Alignment TextStore::alignment() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return Qt::AlignLeft;
    return textCursor().blockFormat().alignment();
}

bool TextStore::bold() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return false;
    return textCursor().charFormat().fontWeight() == QFont::Bold;
}

bool TextStore::italic() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return false;
    return textCursor().charFormat().fontItalic();
}

bool TextStore::underline() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return false;
    return textCursor().charFormat().fontUnderline();
}

void TextStore::setBold(bool arg)
{
    QTextCharFormat fmt;
    fmt.setFontWeight(arg ? QFont::Bold : QFont::Normal);
    mergeFormatOnWordOrSelection(fmt);
    emit boldChanged();
}

void TextStore::setItalic(bool arg)
{
    QTextCharFormat fmt;
    fmt.setFontItalic(arg);
    mergeFormatOnWordOrSelection(fmt);
    emit italicChanged();
}

void TextStore::setUnderline(bool arg)
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(arg);
    mergeFormatOnWordOrSelection(fmt);
    emit underlineChanged();
}

int TextStore::fontSize() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return 0;
    QTextCharFormat format = cursor.charFormat();
    return format.font().pointSize();
}

void TextStore::setFontSize(int arg)
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return;
    QTextCharFormat format;
    format.setFontPointSize(arg);
    mergeFormatOnWordOrSelection(format);
    emit fontSizeChanged();
}

QColor TextStore::textColor() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return QColor(Qt::black);
    QTextCharFormat format = cursor.charFormat();
    return format.foreground().color();
}

void TextStore::setTextColor(const QColor &c)
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return;
    QTextCharFormat format;
    format.setForeground(QBrush(c));
    mergeFormatOnWordOrSelection(format);
    emit textColorChanged();
}

void TextStore::setWorldMark(const QString& word)
{
    setAllUnMarkText();
    auto wordPositions = getWordPositions(word);
    for (auto pos : wordPositions)
    {
        qint64 posEnd = pos + word.length();
        setSelectionEnd(posEnd);
        setSelectionStart(pos);
        setMarkText(); // Возвращать старый селлект нет смысла, так как метод исполбьзуется только во время примеров
    }
}

void TextStore::setAllMarkText()
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return;

    QTextCharFormat format;
    format.setBackground(QBrush(_markColor));

    mergeFormatOnAll(format);
}

void TextStore::setMarkText()
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return;

    QTextCharFormat format;
    format.setBackground(QBrush(_markColor));
    mergeFormatOnWordOrSelection(format);
}

void TextStore::setAllUnMarkText()
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return;

    QTextCharFormat format;
    format.setBackground(QBrush(Qt::GlobalColor::white));

    mergeFormatOnAll(format);
}

void TextStore::setUnMarkText()
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return;

    QTextCharFormat format;
    format.setBackground(QBrush(Qt::GlobalColor::white));
    mergeFormatOnWordOrSelection(format);
}

QString TextStore::fontFamily() const
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return QString();
    QTextCharFormat format = cursor.charFormat();
    return format.font().family();
}

void TextStore::setFontFamily(const QString &arg)
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return;
    QTextCharFormat format;
    format.setFontFamily(arg);
    mergeFormatOnWordOrSelection(format);
    emit fontFamilyChanged();
}

QStringList TextStore::defaultFontSizes() const
{
    // uhm... this is quite ugly
    QStringList sizes;
    QFontDatabase db;
    foreach (int size, db.standardSizes())
        sizes.append(QString::number(size));
    return sizes;
}
