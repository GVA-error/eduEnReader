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

/* TODO LIST
 *
 *  Новый компаунд: 0.02,0.20 5:-60,-40,-10 -5 -90 0.1
 *
 * Ближайший план:
 * 0) Убрать дубли примеров
 * 1) Кнопка удаления лекций
 * 2) Кнопки удаления и добавления комментариев
 * 3) Создание лекций
 * 4) Правка биндов
 * 5) Прогрес
 * 6) Буферизация - показ
 * 7) Windows XP? Обдумать
 *
 * Баг репорт:
 * Из-за проблем с кодировкой строка размер строки ограничен - проверить на винде
 *
 *
 * Заметки:
 *
 * -n) Синхронизация с удалёнкой
 * -n) Дополнительные словари
 * -n) Выпадающие меню хидер
 * -n) Вмонтирование с ютюба
 * -n) Описание кнопок в конфиге
 * -n) Скрыть текст
 *
 * -11) Нормальный вывод в консоль
 * -9) Поиск сомнительных моментов - надо?
 * -8) Применение оптимизационных алгоритмов к крупным частям
 * -6) Сохранение коментариев относительным путём, а не прямым как сейчас
 * -4) Сьтруктурировать словарь как файловую структуру. - Файловый словарь?
 * -3) Препод может отключить текст и запретить браузер
 * 0) Вкл/откл подсветки, вкл/откл текста.
 * 1) Ввести понятие бесконечного бинда - нужно для последнего бинда
 * 4) Представление дирректории комментариев в виде оглавления
 * 7) Использование внешнего апи
 * 8) Список для транслейта
 * 10) Архивирование
 * 11) Ускорить алгоритм повторного биндинга через использование окна
 * 16) Вставка рапознонаго текста
 * 17) Вставка временных отметок
 * 18) Полный экран
 * 20) ПРоблема с тире - странно воспроизводит
 * 21) Проблема с выделением цветом - крайне не стабильно
 * 22) Проверка кодек и сущевствования файлов
 * 23) Хранение времени в милисекундах
 * 27) Псевдонимы?
 * 30) Dont find corelation - выводит при не рабочем скрипте распознования
 * n) Децентралиация вычислений?
 * n+1) Подбор сетки под фрагмент
 * X) Система уравнений букв - показать неверность
 * X) Балансировка колличества букв
 * X) Вторичная разбивка по мидам уже разбитых при распозновании
 * X) График зависимости средней длинны от константы порога локальных минимумов
*/
class UIController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TextStore* document READ getDocument WRITE setDocument) // NOTIFY не нужен так как при использовании с ГУИ инициализация идёт в начале,
    Q_PROPERTY(SoundStore* soundStore READ getSoundStore WRITE setSoundStore) // иначе нотификация не нужна.
    Q_PROPERTY(QStringList bindFilesListModel READ getbindFilesList WRITE setbindFilesList NOTIFY bindFilesListChanged)
    Q_PROPERTY(QStringList exampleListModel READ getExampleList WRITE setExampleList NOTIFY exampleListChanged)
    Q_PROPERTY(QStringList matirealsListModel READ getMatirealsList WRITE setMatirealsList NOTIFY matirealsListChanged)
    Q_PROPERTY(QStringList commentListModel READ getCommentList WRITE setCommentList NOTIFY commentListChanged)
    Q_PROPERTY(bool mouseIsPressed WRITE setMouseIsPressed)
    Q_PROPERTY(qint32 examplesSize READ getExamplesSize WRITE setExamplesSize NOTIFY examplesSizeChanged)
    Q_PROPERTY(qint32 diffSize READ getDiffSize WRITE setDiffSize NOTIFY diffSizeChanged)
    Q_PROPERTY(QUrl curCommentUrl READ curCommentUrl WRITE setCurCommentUrl NOTIFY curCommentUrlChanged)

public:
    explicit UIController(QObject *parent = 0);

    bool getMouseIsPressed() const;
    void setMouseIsPressed(bool& newValue);

    void setDocument(TextStore* TS);
    void setSoundStore(SoundStore* TS);

    TextStore* getDocument();
    SoundStore* getSoundStore();

signals:
    void soundSellectionChanged();
    void textSellectionChanged();
    void bindFilesListChanged();
    void exampleListChanged();
    void commentListChanged();
    void examplesSizeChanged();
    void matirealsListChanged();
    void diffSizeChanged();
    void curCommentUrlChanged();
public slots:

    QStringList getbindFilesList() const;
    void setbindFilesList(const QStringList& newBindFiles);

    QStringList getExampleList() const;
    void setExampleList(const QStringList& newExamples);

    QStringList getCommentList() const;
    void setCommentList(QStringList newComments);

    QUrl curCommentUrl();
    void setCurCommentUrl(const QUrl&);

    QStringList getMatirealsList() const;
    void setMatirealsList(const QStringList& newMatireals);

    void saveHome(bool push = false);
    void home();

    QUrl getImageUrl(const QString& bindFile) const;
    QString getTitle(const QString& bindFile) const;
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

    void setExamplesSize(qint32 newSize){
        _examplesSize = newSize; }
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

    // Для поиска материалов по выделенному слову или введёному пользователем
    void getMatireals();
    void getMatirealsFor(QString seekablePhrase);

    void goOutHome() { _f_home = false; }

    QUrl getCommentUrlWithName(const QString& name) const;
    QUrl getBindFileUrlWithName(const QString& name) const;
    QUrl getMatirealUrlWithName(const QString& name) const;

    // Нужны для qml виджета PageOpen
    // Является ли путь к bind файлу на самом деле папкой.
    bool isDir(const QString& name) const;
    void setCurDir(const QString &name);
    QDir getDir(const QString& name) const;

    qint32 getMidMarkable() const;
    qint32 getBeginMarkable() const;
    qint32 getEndMarkable() const;

    bool canNotSync() const { return _sellectTimer.elapsed() < _sellectingTime; }

protected slots:
    void recognizeIsFinished();

private:
    QTime _sellectTimer; // Следит чтобы во время выделения текста и немного погодя не производилось синхронизаций со звуком, из-за глюка с пропагейшеном
    const qint32 _sellectingTime = 500; // ..
    const QUrl _defaultLecturePicture = QUrl::fromLocalFile("./default.jpeg");
    const QUrl _defaultDirPicture = QUrl::fromLocalFile("./defaultDir.jpeg");
    const QUrl _defaultUpDirPicture = QUrl::fromLocalFile("./defaultUpDir.jpeg");
    qreal _examplesSize; // Храним в qreal, пока пользователь оперирует только целыми значениями
    qreal _diffSize;
    bool _mouseIsPressed;
    bool _opening;

    Logic::PTR _logic;
    SoundStore::PTR _soundStore; //bool _f_setSound;
    TextStore::PTR _textStore;  //bool _f_setText;
    BindMaker::PTR _bindMaker;
    QStringList _bindFilesList; // Модель для гуи
    QStringList _exampleList; // Модель для гуи
    QStringList _commentList; // Модель для гуи
    QStringList _matirealsList; // Модель для гуи
    QMap <QString, Logic::Example> _example; // Для обработки клика по списку примеров
    QMap <QString, QUrl> _bindFile; // Для обработки клика по скписку бинд файлов
    QMap <QString, QString> _bindTitles; // Для отображения списка бинд файлов
    QMap <QString, QUrl> _matirealUrl; // Для выдачи пользователю справочной информации из материалов

    QUrl _curCommentUrl;

    // Нужно для виджета PageOpen
    QDir _curDir; // Текущая директория
    QMap <QString, QDir> _dirs; // Папки из текущей директории

    bool _f_reconizing;
    bool _f_home; // Нужен для возврата домой

    // TODO Убрать - не используеться
    const QString _baseTranslateURL = "http://www.multitran.com/m.exe?l1=1&l2=2&s="; // +word0+word1 ..

    void synchTitle(const QString &bindFile);
    TextFragment::PTR getSellectedText();
    void setSellectionText(TextFragment::PTR);
    void setSellectionText(qint64 begin, qint64 end);
    void initBindMaker(TextStore::PTR, SoundStore::PTR, Logic::PTR);
};

#endif // UIController_H
