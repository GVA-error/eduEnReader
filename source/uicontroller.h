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
 * 3) Записывать все распознанные строки
 * 8) Борьба с шумом с помощью вейлет преобразований через dll WavUtills
 * 10) Архивирование
 * 11) Ускорить алгоритм повторного биндинга через использование окна
 * 12) Логическе заполнение по времени
 * 13) Конвертор форматов
 * 15) Умное выделение (Между пробелами)
 * 16) Вставка рапознонаго текста
 * 17) Вставка временных отметок
 * 18) Полный экран
 * 19) Подавление шума - Очень сильно влияет шум
 * 20) ПРоблема с тире - странно воспроизводит
 * 21) Проблема с переводом
 * 22) Proverki kodek i sushestvovaniya faylov
*/
class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TextStore* document READ getDocument WRITE setDocument)
    Q_PROPERTY(SoundStore* soundStore READ getSoundStore WRITE setSoundStore)
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
        // По скольку последовательность вызовов setDocument и setSoundStore пишу так
        if (_textStore.isNull() == false && _soundStore.isNull() == false)
            initBindMaker(_textStore, _soundStore, _logic);
    }

    TextStore* getDocument() {return _textStore.data(); }
    SoundStore* getSoundStore() {return _soundStore.data(); }

signals:
    void soundSellectionChanged();
    void textSellectionChanged();
public slots:

    void openBindFile(const QUrl &bindFileName);
    void saveBindFile(const QUrl &bindFileName);
    void createBindFile(const QUrl &soundFileName);
    void makeBind(); // автопривязка TODO переименовать
    void openSoundFile(QString fileName);
    void cursorPosChanged();
    void setCursorPosInTimePos();
    void setTimePosInCursorPos();

    QString formUrlToTranslateSellected();

protected slots:
    void recognizeIsFinished();

private:
    Logic::PTR _logic;
    SoundStore::PTR _soundStore; //bool _f_setSound;
    TextStore::PTR _textStore;  //bool _f_setText;
    BindMaker::PTR _bindMaker;

    bool _f_reconizing;

    const QString _baseTranslateURL = "http://www.multitran.com/m.exe?l1=1&l2=2&s="; // +word0+word1 ..

    void setSellectionText(TextFragment::PTR);
    void setSellectionText(qint64 begin, qint64 end);
    void initBindMaker(TextStore::PTR, SoundStore::PTR, Logic::PTR);
};

#endif // UIController_H
