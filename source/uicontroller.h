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
 * -n) Подсветка розово серым - увеличение шрифта 1.5
 * -n) Ввод отдельных слов
 *
 *
 *
 *
 * -3) Препод может отключить текст и запретить браузер
 * -2) Использовать последние версии qml
 * -1) Что за бага с колёсиком мыши? Срочный рефакоринг?
 * 0) Вкл/откл подсветки, вкл/откл текста.
 * 1) Ввести понятие бесконечного бинда - нужно для последнего бинда
 * 2) Усреднить громкость - нормализовать каждый файл
 * 3) Записывать все распознанные строки
 * 4) Представление дирректории комментариев в виде оглавления
 * 8) Борьба с шумом с помощью вейлет преобразований через dll WavUtills
 * 7) Использование внешнего апи
 * 10) Архивирование
 * 11) Ускорить алгоритм повторного биндинга через использование окна
 * 15) Умное выделение (Между пробелами)
 * 16) Вставка рапознонаго текста
 * 17) Вставка временных отметок
 * 18) Полный экран
 * 20) ПРоблема с тире - странно воспроизводит
 * 21) Проблема с выделением цветом - крайне не стабильно
 * 22) Проверка кодек и сущевствования файлов
 * 23) Хранение времени в милисекундах
 * 24) Минимальное/максимальное количество слов в фрагменте
 * 27) Псевдонимы?
 * 30) Dont find corelation - выводит при не рабочем скрипте распознования
 * n) Децентралиация вычислений?
 * n+1) Подбор сетки под фрагмент
 * X) Система уравнений букв - показать неверность
 * X) Балансировка колличества букв
 * X) Использовать логические паузы
 * X) Список коллизий
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
    bool getMouseIsPressed() const;
    void setMouseIsPressed(bool& newValue);

    void setDocument(TextStore* TS);
    void setSoundStore(SoundStore* TS);

    QStringList getExampleList() const;
    void setExampleList(const QStringList& newExamples);

    QStringList getCommentList() const;
    void setCommentList(QStringList newComments);

    TextStore* getDocument();
    SoundStore* getSoundStore();

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
    void addComment(const QUrl&, const QString& name);
    void getExample();
    void openSoundFile(const QString& fileName);
    void cursorPosChanged();
    void setCursorPosInTimePos();
    void setTimePosInCursorPos();

    QString formUrlToTranslateSellected();

    // Нужны для воспроизведения примеров
    void getExamplesFor(const QString& seekablePhrase);
    void playExample(QString ID);

    QUrl getCommentUrlWithName(const QString& name) const;

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
