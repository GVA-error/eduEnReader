#ifndef TEXTSTORE_H
#define TEXTSTORE_H

#include <QQuickTextDocument>
#include <QMouseEvent>
#include <QtGui/QTextCharFormat>
#include <QtCore/QTextCodec>
#include <assert.h>
#include "store.h"

#include <qqmlfile.h>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class TextStore : public QObject, public Store <TextStore>
{
    Q_OBJECT

    Q_ENUMS(HAlignment)

    Q_PROPERTY(QQuickItem *target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(int cursorPosition READ cursorPosition WRITE setCursorPosition NOTIFY cursorPositionChanged)
    Q_PROPERTY(int selectionStart READ selectionStart WRITE setSelectionStart NOTIFY selectionStartChanged)
    Q_PROPERTY(int selectionEnd READ selectionEnd WRITE setSelectionEnd NOTIFY selectionEndChanged)

    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(QString fontFamily READ fontFamily WRITE setFontFamily NOTIFY fontFamilyChanged)
    Q_PROPERTY(Qt::Alignment alignment READ alignment WRITE setAlignment NOTIFY alignmentChanged)

    Q_PROPERTY(bool bold READ bold WRITE setBold NOTIFY boldChanged)
    Q_PROPERTY(bool italic READ italic WRITE setItalic NOTIFY italicChanged)
    Q_PROPERTY(bool underline READ underline WRITE setUnderline NOTIFY underlineChanged)

    Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize NOTIFY fontSizeChanged)

    Q_PROPERTY(QStringList defaultFontSizes READ defaultFontSizes NOTIFY defaultFontSizesChanged)

    Q_PROPERTY(QUrl fileUrl READ fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString documentTitle READ documentTitle WRITE setDocumentTitle NOTIFY documentTitleChanged)

    Q_PROPERTY(QColor markColor READ getMarkColor WRITE setMarkCalor NOTIFY markColorChanged)

public:
    TextStore();
    virtual ~TextStore(){}

    QString getString(qint64 begin, qint64 end) const;
    QString getString() const;
    QString getSellectedStreing() const;
    qint64 getCursorPos() const;

    QQuickItem *target() { return _target; }

    void setTarget(QQuickItem *target);

    void setCursorPosition(int position);
    void setSelectionStart(int position);
    void setSelectionEnd(int position);

    int cursorPosition() const { return _cursorPosition; }
    int selectionStart() const { return _selectionStart; }
    int selectionEnd() const { return _selectionEnd; }

    QString fontFamily() const;

    QColor textColor() const;

    Qt::Alignment alignment() const;
    void setAlignment(Qt::Alignment a);

    bool bold() const;
    bool italic() const;
    bool underline() const;
    int fontSize() const;

    QStringList defaultFontSizes() const;
    QUrl fileUrl() const;
    QString text() const;

    QString documentTitle() const;

public Q_SLOTS:
    void setBold(bool arg);
    void setItalic(bool arg);
    void setUnderline(bool arg);
    void setFontSize(int arg);
    void setTextColor(const QColor &arg);
    void setMarkText();
    void setAllMarkText();
    void setUnMarkText();
    void setAllUnMarkText();
    void setFontFamily(const QString &arg);

    void setFileUrl(const QUrl &arg) override;
    void setText(const QString &arg);
    void saveAs(const QUrl &arg, const QString &fileType);

    void setDocumentTitle(QString arg);

    void saveHome();
    void home();

    void setMarkCalor(const QColor& c){ _markColor = c; }
    QColor getMarkColor() const { return _markColor; }
signals:
    void targetChanged();
    void cursorPositionChanged();
    void selectionStartChanged();
    void selectionEndChanged();

    void fontFamilyChanged();
    void textColorChanged();
    void alignmentChanged();

    void boldChanged();
    void italicChanged();
    void underlineChanged();

    void fontSizeChanged();
    void defaultFontSizesChanged();

    void fileUrlChanged();

    void textChanged();
    void documentTitleChanged();
    void error(QString message);

    void markColorChanged();
private:
    void reset();
    QTextCursor textCursor() const;
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void mergeFormatOnAll(const QTextCharFormat &format);

    QQuickItem *_target;
    QTextDocument *_doc;
    // Нужен для возможости полного функционирования объектов textStore без привязки к гуи гуи
    // К примеру при поиске примеров с нужным словом
    QTextDocument _default_m_doc;
    QColor _markColor;

    bool _mousePresed;

    qint32 _cursorPosition;
    qint32 _selectionStart;
    qint32 _selectionEnd;

    QUrl _saved_url;
    qint64 _saved_curPosition;

    QFont _font;
    qint32 _fontSize;
    QUrl _fileUrl;
    QString _text;
    QString _documentTitle;
};


#endif // TEXTSTORE_H
