#ifndef UIController_H
#define UIController_H

#include <QObject>
#include "logic.h"
#include "soundstore.h"
#include "textstore.h"
#include "soundfragment.h"
#include "textfragment.h"
#include "ASR/bindmaker.h"

/* TODO LIST
 * -1) Что за бага с колёсиком мыши? Срочный рефакоринг?
 * 1) Ввести понятие бесконечного бинда - нужно для последнего бинда
 * 3) Записывать все распознанные строки
 * 4) Представление дирректории комментариев в виде оглавления
 * 5) Home для логики - переходы в примерах
 * 8) Борьба с шумом с помощью вейлет преобразований через dll WavUtills
 * 7) Использование внешнего апи
 * 10) Архивирование
 * 11) Ускорить алгоритм повторного биндинга через использование окна
 * 13) Конвертор форматов
 * 15) Умное выделение (Между пробелами)
 * 16) Вставка рапознонаго текста
 * 17) Вставка временных отметок
 * 18) Полный экран
 * 19) Подавление шума - Очень сильно влияет шум
 * 20) ПРоблема с тире - странно воспроизводит
 * 21) Проблема с выделением цветом - крайне не стабильно
 * 22) Проверка кодек и сущевствования файлов
 * 23) Хранение времени в милисекундах
 * 27) Псевдонимы?
 * 30) Dont find corelation - выводит при не рабочем скрипте распознования
 * n) Децентралиация вычислений?
 * n+1) Подбор сетки под фрагмент
*/
class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TextStore* document READ getDocument WRITE setDocument) // NOTIFY не нужен так как при использовании с ГУИ инициализация идёт в начале,
    Q_PROPERTY(SoundStore* soundStore READ getSoundStore WRITE setSoundStore) // иначе нотификация не нужна.
    Q_PROPERTY(QStringList exampleListModel READ getExampleList WRITE setExampleList NOTIFY exampleListChanged)
    Q_PROPERTY(QStringList commentListModel READ getCommentList WRITE setCommentList NOTIFY commentListChanged)
    Q_PROPERTY(bool mouseIsPressed READ getMouseIsPressed WRITE setMouseIsPressed)
public:
    explicit UIController(QObject *parent = 0);

    bool mouseIsPressed;
    bool getMouseIsPressed() const {return mouseIsPressed;}
    void setMouseIsPressed(bool& newValue) { mouseIsPressed = newValue;}

    void setDocument(TextStore* TS) {
        _textStore =  TextStore::PTR(TS);
        QObject::connect(_textStore.data(), SIGNAL(cursorPositionChanged()), this, SLOT(cursorPosChanged()));
        // По скольку последовательность вызовов setDocument и setSoundStore пишу так
        if (_textStore.isNull() == false && _soundStore.isNull() == false)
            initBindMaker(_textStore, _soundStore, _logic);
    }

    void setSoundStore(SoundStore* TS) {
        _soundStore =  SoundStore::PTR(TS);
        QObject::connect(_soundStore.data(), SIGNAL(posChanged()), this, SLOT(setCursorPosInTimePos()));
        // По скольку последовательность вызовов setDocument и setSoundStore пишу так
        if (_textStore.isNull() == false && _soundStore.isNull() == false)
            initBindMaker(_textStore, _soundStore, _logic);
    }

    QStringList getExampleList() const { return _exampleList; }
    void setExampleList(const QStringList& newExamples){
        _exampleList = newExamples;
        emit exampleListChanged();
    }

    QStringList getCommentList() const{ return _commentList; }
    void setCommentList(const QStringList& newComments){
        _commentList = newComments;
        emit commentListChanged();
    }

    TextStore* getDocument() { return _textStore.data(); }
    SoundStore* getSoundStore() { return _soundStore.data(); }

signals:
    void soundSellectionChanged();
    void textSellectionChanged();
    void exampleListChanged();
    void commentListChanged();
public slots:

    void saveHome();
    void home();
    void openBindFile(const QUrl &bindFileName);
    void saveBindFile(const QUrl &bindFileName);
    void createBindFile(const QUrl &soundFileName);
    void makeBind(); // автопривязка TODO переименовать
    void addComment(const QUrl&);
    void getExample();
    void openSoundFile(QString fileName);
    void cursorPosChanged();
    void setCursorPosInTimePos();
    void setTimePosInCursorPos();

    QString formUrlToTranslateSellected();

    // Нужны для воспроизведения примеров
    void getExamplesFor(const QString& seekablePhrase);
    void playExample(QString ID);

    QUrl getCommentUrlWithName(QString name);

protected slots:
    void recognizeIsFinished();

private:
    Logic::PTR _logic;
    SoundStore::PTR _soundStore; //bool _f_setSound;
    TextStore::PTR _textStore;  //bool _f_setText;
    BindMaker::PTR _bindMaker;
    QStringList _exampleList; // Модель для гуи
    QStringList _commentList; // Модель для гуи
    QMap <QString, Logic::Example> _example;

    bool _f_reconizing;
    bool _f_home; // Нужен для возврата домой

    const QString _baseTranslateURL = "http://www.multitran.com/m.exe?l1=1&l2=2&s="; // +word0+word1 ..

    TextFragment::PTR getSellectedText();
    void setSellectionText(TextFragment::PTR);
    void setSellectionText(qint64 begin, qint64 end);
    void initBindMaker(TextStore::PTR, SoundStore::PTR, Logic::PTR);
};

#endif // UIController_H
