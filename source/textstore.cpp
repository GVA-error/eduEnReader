#include <QColor>
#include "textstore.h"

#include <QtGui/QTextDocument>
#include <QtGui/QTextCursor>
#include <QtGui/QFontDatabase>
#include <QtCore/QFileInfo>

TextStore::TextStore()
    : m_target(0)
    , m_doc(0)
    , m_cursorPosition(-1)
    , m_selectionStart(0)
    , m_selectionEnd(0)
{
    m_doc = &_default_m_doc;
    _saved_url = QUrl();
    _saved_curPosition = 0;
}

QString TextStore::getString(qint64 begin, qint64 end) const
{
    QString str = getString();
    //Q_ASSERT(end >= begin); // TODO Вернуть после введения понятия бесконечного бинда
    if (end < begin)
        end = begin = 0; // TODO а это стереть

    if (begin == 5174)
        return str.mid(begin, end - begin);

    return str.mid(begin, end - begin);
}

QString TextStore::getString() const
{
    QString planeText = m_doc->toPlainText(); // заменить на член
    return planeText;
}

QString TextStore::getSellectedStreing() const
{
    qint64 begin = m_selectionStart;
    qint64 end = m_selectionEnd;
    QString sellectedString = getString(begin, end);
    return sellectedString;
}

qint64 TextStore::getCursorPos() const
{
    return m_cursorPosition;
}

void TextStore::saveHome()
{
    _saved_curPosition = getCursorPos();
    _saved_url = m_fileUrl;
}

void TextStore::home()
{
    setFileUrl(_saved_url);
    setCursorPosition(_saved_curPosition);
}

void TextStore::setTarget(QQuickItem *target)
{
    m_doc = 0;
    m_target = target;
    if (!m_target)
        return;

    QVariant doc = m_target->property("textDocument");
    if (doc.canConvert<QQuickTextDocument*>()) {
        QQuickTextDocument *qqdoc = doc.value<QQuickTextDocument*>();
        if (qqdoc)
            m_doc = qqdoc->textDocument();
    }
    emit targetChanged();
}

void TextStore::setFileUrl(const QUrl &url)
{
    QString fileName = QQmlFile::urlToLocalFileOrQrc(url);
    //assert(fileName.isEmpty() == false);
    m_documentTitle = QFileInfo(fileName).baseName();
    m_fileUrl = url;
    if (QFile::exists(fileName)) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly))
        {
            QByteArray data = file.readAll();
            QTextCodec *codec = QTextCodec::codecForHtml(data);
            setText(codec->toUnicode(data));
            if (m_doc)
            {
                m_doc->setHtml(data);
                m_doc->setModified(false);
            }
            emit textChanged();
            emit documentTitleChanged();

            reset();
        }
    }
    emit fileUrlChanged();
}

QString TextStore::documentTitle() const
{
    return m_documentTitle;
}

void TextStore::setDocumentTitle(QString arg)
{
    if (m_documentTitle != arg) {
        m_documentTitle = arg;
        emit documentTitleChanged();
    }
}

void TextStore::setText(const QString &arg)
{
    if (m_text != arg) {
        m_text = arg;
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
    if (!f.open(QFile::WriteOnly | QFile::Truncate | (isHtml ? QFile::NotOpen : QFile::Text))) {
        emit error(tr("Cannot save: ") + f.errorString());
        return;
    }
    f.write((isHtml ? m_doc->toHtml() : m_doc->toPlainText()).toLocal8Bit());
    f.close();
    setFileUrl(QUrl::fromLocalFile(localPath));
}

QUrl TextStore::fileUrl() const
{
    return m_fileUrl;
}

QString TextStore::text() const
{
    return m_text;
}

void TextStore::setCursorPosition(int position)
{
    if (position == m_cursorPosition)
        return;

    m_cursorPosition = position;

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
}

QTextCursor TextStore::textCursor() const
{
    QTextCursor cursor = QTextCursor(m_doc);
    if (m_selectionStart != m_selectionEnd) {
        cursor.setPosition(m_selectionStart);
        cursor.setPosition(m_selectionEnd, QTextCursor::KeepAnchor);
    } else {
        cursor.setPosition(m_cursorPosition);
    }
    return cursor;
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
    m_selectionStart = position;
}

void TextStore::setSelectionEnd(int position)
{
    m_selectionEnd = position;
}

void TextStore::setAlignment(Qt::Alignment a)
{
    QTextBlockFormat fmt;
    fmt.setAlignment((Qt::Alignment) a);
    QTextCursor cursor = QTextCursor(m_doc);
    cursor.setPosition(m_selectionStart, QTextCursor::MoveAnchor);
    cursor.setPosition(m_selectionEnd, QTextCursor::KeepAnchor);
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

void TextStore::setTextBackground(const QColor &c)
{
    QTextCursor cursor = textCursor();
    if (cursor.isNull())
        return;
    QTextCharFormat format;
    format.setBackground(QBrush(c));
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
