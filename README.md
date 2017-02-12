# eduEnReader

Автор: Голубцов Василий Анатольевич.

Программа для создания интерактивных материалов по изучению иностранных языков под Windows 7.

Разрабатывается функционал для создания интерактивных транскрипций аналогичных используемым на ted.com + функционал дающий дополнительную справочную информацию необходимую для человека изучающего иностранный язык в виде различного мультимедиа — видео, текст, звук.

Требования к окружению Windows:
  - последнее версия обновлений windows 7 или установленный набор компиляторов msvc2015
  - видео и аудио кодеки // На тестовой машине установлен K-Lite Codec Pack Basic.
  - google chrome / chromium последней версии // программа использует движок хрома.

Файлы интерактивных материалов:
  <name> - название материала.
  <name>.bnd — основной файл с зависимостями.
  <name>.wav/<name>.mp4/<name>.mp3 — файлы хранящие видео или звуковые данные материала.
  <name>.html — файлы хранящие текст.

Структура каталогов:

  ./Build — Последняя построенная версия проекта на Linux.

  ./dlls — различные dll которые могут понадобиться для запуска ПО. Скобки указывают на различные версии dll — для конкретной системы может понадобится одна из них. Для использования убрать версию из названия.

  ./examples — готовые интерактивные материалы.

  ./source — файлы исходных кодов.

  ./v* - каталоги готовых версий проекта.

  ./v*/Binars — Бинарники к текущей версии.
  ./v*/reader — версия для чтения.
  ./v*/writer — версия для создания.
  ./v*/Demo — версия имеющая функционал как для чтения так и для создания. Используется для демонстрации всего функционала, данная версия полностью аналогична той что дебажится на машине разработчика. Версии reader и writer — есть урезанные demo. Урезается доступ к функционалу через uml.

Patch notes:

./v1.0 — Доступен функционал для автоматического создания интерактивных транскрипций и их воспроизведения. 
Для создания используется библиотека kaldi, поэтому данный функционал не доступен в текущей версии для Windows.
Пример готового материала находится в папке examples. Для воспроизведения необходимо наличие файлов интерактивного материала в папке с исполняемым файлом.
Баги: В windows при выходе выскакивает крит. Данная версия требует тестирования.
