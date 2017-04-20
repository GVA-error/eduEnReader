import QtQuick 2.8
import QtWebEngine 1.4

import QtMultimedia 5.8
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2

import TextStoreModul 1.0
import SoundStoreModul 1.1
import UiControlerModul 1.1

Page {
    title: "main"
    property var homeDocument : document
    property var homeSoundStore : soundStore
    property var homeUiControler : uiControler
    property var textArea : flickableTextArea

    function isExampleShowing() { return exampleCommentsPageLits.currentIndex == 1}
    function showComments() { exampleCommentsPageLits.setCurrentIndex(0) }
    function showExamples() { exampleCommentsPageLits.setCurrentIndex(1) }
    function setExamples(str) { uiControler.getExamplesFor(str) }

    // Список примеров или комментариев
    SwipeView {
        id: exampleCommentsPageLits
        rightPadding: 20
        anchors.top : parent.top
        anchors.bottom: controlPanel.top
        anchors.right : controlPanel.right
        anchors.left : mainVideoView.right
        Component.onCompleted: contentItem.interactive = false
        z : 3
        Page{// Список комментариев
            visible: exampleCommentsPageLits.currentIndex == 0
            padding: 10
            Flickable {
                id: flickable
                anchors.fill: parent
                flickableDirection: Flickable.VerticalFlick
                TextArea.flickable:
                QML_TextReaderArea {
                    id : commentArrea
                    text: commentDoc.text
                    textFormat: Qt.RichText
                    readOnly: true
                }
                ScrollBar.vertical: ScrollBar {}
                TextStore{
                    id : commentDoc
                    target: commentArrea
                    fileUrl : uiControler.curCommentUrl;
                }
            }

/*          // Старый диолог
            QML_ListDialog{
                id : comments;
                anchors.fill: parent
                out_model: uiControler.commentListModel
                title: "Comments"
                onSelected : {
                    var fileUrl = uiControler.getCommentUrlWithName(str);
                    commentDialog.openHtml(fileUrl)
                    commentDialog.showDialog()
                }
            }*/
        }
        Page{// Список примеров
            visible: exampleCommentsPageLits.currentIndex == 1
            QML_ListDialog{
                z : 3;
                id : examples;
                out_model: uiControler.exampleListModel;
                title: "Examples"
                anchors.fill: parent
                onSelected : uiControler.playExample(str);
            }
        }
    }

    // Видео    
    Rectangle{
        id : mainVideoView
        z : 3
        anchors.bottom: controlPanel.top;
        x : 10
        y : 10
        width: parent.width * 2 / 3
        height: 480
        color: "black"
        SoundStore {
           id : soundStore;
           anchors.fill: parent;
           //source: root.source
           onPosChanged: {
               textArea.syncSoundAndSliderPosition(false)
           }
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log(soundStore.state)
                console.log(soundStore.PlayingState)
                if (soundStore.state === soundStore.playingState())
                    soundStore.stop()
                else
                    soundStore.start()
            }
        }
    }

    // Ползунок, старт, пауза
    PC_READ_ControlPanel{
        id : controlPanel
        anchors.top: mainVideoView.bottom
        //anchors.right : parent.right
        width: parent.width
        Component.onCompleted: contentItem.interactive = false
        //anchors.fill: parent
        x : mainVideoView.x
        z : 2
    }

    MouseArea{ // Ареа - Костыль, чтобы flickableTextArea не ловил лишних событий
        acceptedButtons: Qt.LeftButton
        anchors.top: parent.top
        anchors.bottom: flickableTextArea.top
        width: parent.width
        z:1
        id : mouseArea
        Component.onCompleted: contentItem.interactive = false
        propagateComposedEvents: false
        onPressed: {
           // console.log("CLICKED FALSE")
            mouse.accepted = true
        }
    }

    Flickable {
        id: flickableTextArea
        visible: (settingPage.showExampleText === true && soundStore.isExample === true)
                 || (settingPage.showLectureText === true && soundStore.isExample === false)
        anchors.top: controlPanel.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        Component.onCompleted: contentItem.interactive = false
        flickableDirection: Flickable.VerticalFlick
        TextArea.flickable: QML_TextReaderArea{
            id : textArea
            anchors.fill: parent
        }
        ScrollBar.vertical: ScrollBar {
            width: 20
        }
        Behavior on contentY {
                 NumberAnimation {
                     duration: 600
                 }
             }
        function synch(f_pushSynch) { textArea.syncSoundAndSliderPosition(f_pushSynch) }
        function getCurY() { return contentY }
        function setCurY(newY) {
            contentY = newY

        }
        function getCurHeigth() { return height }
    }

    UiControler{
        id: uiControler
        mouseIsPressed: textArea.mouseLeftPresed
        document : document
        soundStore : soundStore
        property bool dontSynch : false
        onDontSynchChanged:{
            if (!dontSynch)
                textArea.syncSoundAndSliderPosition(true)
        }
        Component.onCompleted: {
            synchBndFileList()
        }
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
  /*  SoundStore {
        id : soundStore
        onPosChanged: {
            textArea.syncSoundAndSliderPosition()
        }
    }*/
 /*   QML_WebViewDialog{
        id: translateDialog
        contentText: qsTr("Translate")
        defaultURL : "http://www.multitran.com/m.exe?l1=1&l2=2&s=word"
    }*/
    QML_HtmlView{
        id: commentDialog
        z: 4
    }

}
