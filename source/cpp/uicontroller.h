#ifndef UIController_H
#define UIController_H

#include <QObject>
#include <QTime>
#include "logic.h"
#include "soundstore.h"
#include "textstore.h"
#include "soundfragment.h"
#include "textfragment.h"
#include "ASR/bindmaker.h"

// Заметка: Когда буду делать лекции сделать шрифт побольше
// Расказать о минимальной длинне примеров
// Рассказать о возможности искать примеры по длинне

/* TODO LIST
 *
 * -n) Возможность искать примеры определённой длинны
 * -n) Синхронизация с удалёнкой
 *
 * -10) Функция энергии при оптимизации, мексимум фрагментов - количество распознаных слов
 * -9) Поиск сомнительных моментов - надо?
 * -8) Применение оптимизационных алгоритмов к крупным частям
 * -7) Сдвиг начала следующего локального бинда оносительно преыдущего - продумать
 * -6) Сохранение коментариев относительным путём, а не прямым как сейчас
 * -5) Эволюционный/прожиг алгоритм сброса - применять когда частей мало
 * -4) Сьтруктурировать словарь как файловую структуру. - Файловый словарь?
 * -3) Препод может отключить текст и запретить браузер
 * -2) Использовать последние версии qml
 * -1) Что за бага с колёсиком мыши? Срочный рефакоринг?
 * 0) Вкл/откл подсветки, вкл/откл текста.
 * 1) Ввести понятие бесконечного бинда - нужно для последнего бинда
 * 3) Записывать все распознанные строки
 * 4) Представление дирректории комментариев в виде оглавления
 * 5) Вывод примеров определённой длинны
 * 6) Если пользователь не видит начала или конца производить сдвиг текста
 * 7) Использование внешнего апи
 * 8) Список для транслейта
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
 * X) Вторичная разбивка по мидам уже разбитых при распозновании
 * X) Проблема двух дикторов
*/
class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TextStore* document READ getDocument WRITE setDocument) // NOTIFY не нужен так как при использовании с ГУИ инициализация идёт в начале,
    Q_PROPERTY(SoundStore* soundStore READ getSoundStore WRITE setSoundStore) // иначе нотификация не нужна.
    Q_PROPERTY(QStringList bindFilesListModel READ getbindFilesList WRITE setbindFilesList NOTIFY bindFilesListChanged)
    Q_PROPERTY(QStringList exampleListModel READ getExampleList WRITE setExampleList NOTIFY exampleListChanged)
    Q_PROPERTY(QStringList commentListModel READ getCommentList WRITE setCommentList NOTIFY commentListChanged)
    Q_PROPERTY(bool mouseIsPressed WRITE setMouseIsPressed)
    Q_PROPERTY(qint32 examplesSize READ getExamplesSize WRITE setExamplesSize NOTIFY examplesSizeChanged)
    Q_PROPERTY(qint32 diffSize READ getDiffSize WRITE setDiffSize NOTIFY diffSizeChanged)

public:
    explicit UIController(QObject *parent = 0);

    bool mouseIsPressed;
    bool getMouseIsPressed() const;
    void setMouseIsPressed(bool& newValue);

    void setDocument(TextStore* TS);
    void setSoundStore(SoundStore* TS);

    QStringList getbindFilesList() const;
    void setbindFilesList(const QStringList& newBindFiles);


    QStringList getExampleList() const;
    void setExampleList(const QStringList& newExamples);

    QStringList getCommentList() const;
    void setCommentList(QStringList newComments);


    TextStore* getDocument();
    SoundStore* getSoundStore();

signals:
    void soundSellectionChanged();
    void textSellectionChanged();
    void bindFilesListChanged();
    void exampleListChanged();
    void commentListChanged();
    void examplesSizeChanged();
    void diffSizeChanged();
public slots:

    void saveHome();
    void home();

    void synchBndFileList();
    void openBindFile(const QUrl &bindFileName);
    void saveBindFile(const QUrl &bindFileName);
    void createBindFile(const QUrl &soundFileName);
    void makeBind(); // автопривязка TODO переименовать
    void addComment(const QUrl&, const QString& name);
    void openSoundFile(const QString& fileName);
    void cursorPosChanged();
    void setCursorPosInTimePos();
    void setTimePosInCursorPos();
    void markCurText(); // Нужна для синхронизации во время централизации текста
    void markLastText();
    void unmarkLastText();
    void startSellectTimer();

    void setExamplesSize(qint32 newSize){ _examplesSize = newSize; }
    qint32 getExamplesSize(){ return _examplesSize; }
    void setDiffSize(qint32 newDiff){
        _diffSize = newDiff;
    }
    qint32 getDiffSize(){ return _diffSize; }

    QString formUrlToTranslateSellected();

    // Нужны для воспроизведения примеров
    void playExample(QString ID);
    void getExample();
    void getExamplesFor(const QString& seekablePhrase);

    void goOutHome() { _f_home = false; }

    QUrl getCommentUrlWithName(const QString& name) const;
    QUrl getBindFileUrlWithName(const QString& name) const;

    qint32 getMidMarkable() const;
    qint32 getBeginMarkable() const;
    qint32 getEndMarkable() const;

    bool canNotSync() const { return _sellectTimer.elapsed() < _sellectingTime; }

protected slots:
    void recognizeIsFinished();

private:
    QTime _sellectTimer; // Следит чтобы во время выделения текста и немного погодя не производилось синхронизаций со звуком, из-за глюка с пропагейшеном
    const qint32 _sellectingTime = 500; // ..
    qreal _examplesSize; // Храним в qreal, пока пользователь оперирует только целыми значениями
    qreal _diffSize;

    Logic::PTR _logic;
    SoundStore::PTR _soundStore; //bool _f_setSound;
    TextStore::PTR _textStore;  //bool _f_setText;
    BindMaker::PTR _bindMaker;
    QStringList _bindFilesList; // Модель для гуи
    QStringList _exampleList; // Модель для гуи
    QStringList _commentList; // Модель для гуи
    QMap <QString, Logic::Example> _example; // Для обработки клика по списку примеров
    QMap <QString, QUrl> _bindFile; // Для обработки клика по скписку бинд файлов

    bool _f_reconizing;
    bool _f_home; // Нужен для возврата домой

    const QString _baseTranslateURL = "http://www.multitran.com/m.exe?l1=1&l2=2&s="; // +word0+word1 ..

    TextFragment::PTR getSellectedText();
    void setSellectionText(TextFragment::PTR);
    void setSellectionText(qint64 begin, qint64 end);
    void initBindMaker(TextStore::PTR, SoundStore::PTR, Logic::PTR);
};

#endif // UIController_H
