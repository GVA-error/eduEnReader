#ifndef UIController_H
#define UIController_H

#include <QObject>
#include <QTime>
#include "logic.h"
#include "soundstore.h"
#include "textstore.h"
#include "soundfragment.h"
#include "textfragment.h"
#include "Binding/bindmaker.h"
#include "cpp/Processes/bindopenprocess.h"
#include "cpp/Processes/tsbindingprocess.h"

// Заметка: Когда буду делать лекции сделать шрифт побольше

/* TODO LIST
 *
 * Ближайший план:
 * 0) Cохранение
 * 1) Настройка типа выделения
 * 2) Разбиение биндов с учётом позиций слов
 * 3) Проверить путь комментариев после сохранения
 * 7) Отмена процесса
 * 8) Импорт из титров
 * 9) Отпаралелить открытие текста
 * 10) На опене кнопка всеобщего бинда с учётом моментов тишины и текста
 * 11) На са доме + с учётом текста пользователя
 * 12) Выделение между тишиной, синтаксическими формами и словами
 * Баг репорт:
 * Из-за проблем с кодировкой строка размер строки ограничен - проверить на винде
 *
 * Рефакторинг:
 * 1) Продумать имена
 * 2) Find_if заменить на qFind
 *
 * Заметки:
 * -n) Оставить среди соседних локальных минимумов меньший
 * -n) Использование следующего текстового фрагмента при поиске предыдущего если не найдена кореляция
 * -n) Синхронизация с удалёнкой
 * -n) Убрать дубли примеров
 * -n) Выпадающие меню хидер
 * -n) Вмонтирование с ютюба
 * -n) Тестим строя график максимального количества символов в фрагменте
 * -n) Тестить позиционирование бессмысленно, так как если есть хотя бы пара всё ок
 * -n) А деление сов зависит исключитебно от системы распознования
 * -n) 3 причины возникновения ошибки: неправильное деление слов, неверное распознование, неверный поиск локальных минимумов
 * -n) вероятность сдвижки влево
 *
 * -11) Нормальный вывод в консоль
 * -9) Поиск сомнительных моментов - надо?
 * -8) Применение оптимизационных алгоритмов к крупным частям
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
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString curState READ curState /*WRITE setCurState */NOTIFY curStateChanged)
    Q_PROPERTY(QString soundSource READ soundSource WRITE setSoundSource NOTIFY soundSourceChanged)
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
    void titleChanged();
    void curStateChanged();
    void soundSourceChanged();
public slots:

    // Проперти
    QString title() const;
    void setTitle(const QString&);
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
    QString curState() const;
    void setCurState(const QString& newState);

    void saveHome(bool push = false);
    void home();

    void setSoundSource(const QString& source);
    QString soundSource() const;

    void setPreviewForCurLecture(const QUrl& url);
    QUrl getImageUrl(const QString& bindFile) const;
    QString getTitle(const QString& bindFile) const;
    void synchBndFileList();
    void synchCommentList();
    void openBindFile(const QUrl &bindFileName);
    void saveBindFile(const QUrl &bindFileName);
    void createBindFile(const QUrl &soundFileName);
    void makeBind(); // автопривязка TODO переименовать

    // Биндинг видео файлов в папке лекций
    void allTsBinding(); // Биндинг основываясь на моментах тишины всех файлов без бинда
    void allStBinding(); // Биндинг основываясь на знаках пунктуации всех файлов
    void curUserStBinding(); // Биндинг основываясь на текстовых отрезках заданых пользователем

    QUrl addComment();
    void addComment(const QUrl& path);
    void openSoundFile(const QString& fileName);
    void cursorPosChanged();
    void setCursorPosInTimePos();
    void setTimePosInCursorPos();
    void markCurText(); // Нужна для синхронизации во время централизации текста
    void markLastText();
    void unmarkLastText();
    //void unmarkAllText() {  }
    void startSellectTimer();
    void markComment(const QString& name);
    void unmarkComment(const QString& name);

    void setExamplesSize(qint32 newSize){
        _examplesSize = newSize; }
    qint32 getExamplesSize(){ return _examplesSize; }
    void setDiffSize(qint32 newDiff){
        _diffSize = newDiff;
    }
    qint32 getDiffSize(){ return _diffSize; }
    qint32 getCommentListSize() { return _commentList.size(); }
    QString getFirstComment() { return _commentList.front(); }

    QString formUrlToTranslateSellected();

    // Нужны для воспроизведения примеров
    void playExample(QString ID);
    void getExample();
    void getExamplesFor(const QString& seekablePhrase);

    // Для поиска материалов по выделенному слову или введёному пользователем
    void getMatireals();
    void getMatirealsFor(QString seekablePhrase);

    void goOutHome() { _f_home = false; }

    void setForOpening(const QUrl& newOpening) {
        QString fileName = newOpening.toLocalFile();
        _logicReader->setFileName(fileName); }
    void openWaited() {
        if (_opening)
            return;
        _opening = true;
        setCurCommentUrl(QUrl(""));
        _logicReader->runInThisThread();
        openingFinished();
    }
    QString openState() { return _logicReader->getCurState(); }

    QUrl getCommentUrlWithName(const QString& name) const;
    QUrl getBindFileUrlWithName(const QString& name) const;
    QUrl getMatirealUrlWithName(const QString& name) const;

    void deleteBindWithName(const QString& name);
    void deleteBind(const QString& fileName);
    void deleteCommentWithName(const QString& name);

    // Нужны для qml виджета PageOpen
    // Является ли путь к bind файлу на самом деле папкой.
    bool isDir(const QString& name) const;
    void setCurDir(const QString &name);
    QDir getDir(const QString& name) const;

    qint32 getMidMarkable() const;
    qint32 getBeginMarkable() const;
    qint32 getEndMarkable() const;

    bool canNotSync() const { return _sellectTimer.elapsed() < _sellectingTime; }
    bool haveCommentInThisPosition() { return _commentList.empty() == false; }

    void stopAllThreads();

    // Правка текста бинда
    void addWordInCurBindEnd() { _logic->addWordInCurBindEnd(); }
    void addWordInCurBindBegin() { _logic->addWordInCurBindBegin(); }
    void deleteWordFromCurBindEnd() { _logic->deleteWordFromCurBindEnd(); }
    void deleteWordFromCurBindBegin() { _logic->deleteWordFromCurBindBegin(); }
    void setCurBindEnd(qint64 pos) { _logic->setCurBindEnd(pos); }
    void setCurBindBegin(qint64 pos) { _logic->setCurBindBegin(pos); }

    void addTextInComment(const QString &commentName, const QString&, const QColor& textColor = QColor("black"));
protected slots:
    void recognizeIsFinished();
    void openingFinished();
    void handleNextOrFinish();

private:
    QTime _sellectTimer; // Следит чтобы во время выделения текста и немного погодя не производилось синхронизаций со звуком, из-за глюка с пропагейшеном
    QString _curState;
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
    //BindMaker::PTR _bindMaker;
    BindOpenProcess::PTR _logicReader;
    TsBindingProcess::PTR _bindMaker;

    // Организация очереди биндинга
    QStringList _bindSiqence; // Очередь для биндинга
    QMap <QString, bool> _f_bindSequnceProcess; // Обработан ли тот или иной файл в очереди
    QString _curBinding; // Текущий обрабатываемый файл

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

    void initBindingSequence();

    void synchTitle(const QString &bindFile);
    TextFragment::PTR getSellectedText();
    void setSellectionText(TextFragment::PTR);
    void setSellectionText(qint64 begin, qint64 end);
    void initBindMaker(TextStore::PTR, SoundStore::PTR, Logic::PTR);
    void initLogicReader(TextStore::PTR, SoundStore::PTR, Logic::PTR);

    QString getCurStateBindSequnce();
};

#endif // UIController_H
