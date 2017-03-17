import QtQuick 2.5
import QtWebEngine 1.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.1
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import TextStoreModul 1.0
import SoundStoreModul 1.1
import UiControlerModul 1.1

// TODO РЕФАКТОРИНГ
/*
При вызове контексного меню MenuContentItem.qml:178: ReferenceError: Acccessible is not defined
*/

ApplicationWindow {
    id : root
    visible: true
    width: 1024
    height: 768
    title: document.documentTitle + " - Text Editor Example"

    toolBar: TopToolBar{ id : mainToolBar }

    // Список комментариев
    ListDialog{
        id : comments;
        out_model: uiControler.commentListModel
        title: "Comments"

        anchors.top : parent.top
        anchors.bottom: controlPanel.top
        anchors.right : mainVideoView.left
        anchors.left : controlPanel.left

        onSelected : {
            var fileUrl = uiControler.getCommentUrlWithName(str);
            commentDialog.openHtml(fileUrl)
            commentDialog.showDialog()
        }
    }

    // Видео
    MainVideoView{
        id : mainVideoView
        anchors.top : parent.top;
        anchors.bottom: controlPanel.top;
        //anchors.right : soundToolBar.right
        x : (parent.width - width) / 2
        //y : 0
        width: 640
        height: 480
        color: "black"
    }

    // Список примеров
    ListDialog{
        id : examples;
        out_model: uiControler.exampleListModel;
        title: "Examples"

        anchors.top : parent.top
        anchors.bottom: controlPanel.top
        anchors.left: mainVideoView.right
        anchors.right: controlPanel.right

        onSelected : uiControler.playExample(str);
    }

    // Ползунок, старт, пауза
    ControlPanel{
        id : controlPanel
        anchors.top: mainVideoView.bottom
        //anchors.bottom: parent.bottom
        width: parent.width
        //anchors.fill: parent
    }

    TextReaderArea{
        id : textArea
        width: parent.width
        anchors.top: controlPanel.bottom
        anchors.bottom: parent.bottom
    }

// Модели
    UiControler{
        id: uiControler
        mouseIsPressed: false
        document : document
        soundStore : soundStore
    }
    TextStore {
        id: document
        target: textArea
        cursorPosition: textArea.cursorPosition
        selectionStart: textArea.selectionStart
        selectionEnd: textArea.selectionEnd
        textColor: "Black"

        onError: {
            errorDialog.text = message
            errorDialog.visible = true
        }
    }
    WebViewDialog{
        id: translateDialog
        contentText: qsTr("Translate")
        defaultURL : "http://www.multitran.com/m.exe?l1=1&l2=2&s=word"
    }
    HtmlView{ id: commentDialog }
    MessageDialog { id : errorDialog }
    SoundStore {
        id : soundStore
        onPosChanged: textArea.syncSoundAndSliderPosition()
    }


}

