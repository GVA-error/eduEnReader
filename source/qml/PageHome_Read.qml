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

    function isExampleShowing() { return pageLits.currentIndex == 1}
    function showComments() { pageLits.setCurrentIndex(0) }
    function showExamples() { pageLits.setCurrentIndex(1) }
    function setExamples(str) { uiControler.getExamplesFor(str) }

    // Список примеров или комментариев
    SwipeView {
        id: pageLits
        rightPadding: 20
        anchors.top : parent.top
        anchors.bottom: controlPanel.top
        anchors.right : controlPanel.right
        anchors.left : mainVideoView.right

        Page{// Список комментариев
            visible: pageLits.currentIndex == 0

            ListDialog{
                id : comments;
                anchors.fill: parent
                out_model: uiControler.commentListModel
                title: "Comments"
                onSelected : {
                    var fileUrl = uiControler.getCommentUrlWithName(str);
                    commentDialog.openHtml(fileUrl)
                    commentDialog.showDialog()
                }
            }
        }
        Page{// Список примеров
            visible: pageLits.currentIndex == 1
            ListDialog{
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
        //anchors.top : parent.top;
        anchors.bottom: controlPanel.top;
        x : 10 //(parent.width - width) / 3
        y : 10
        width: parent.width * 2 / 3
        height: 480
        color: "black"
        SoundStore {
           id : soundStore;
           anchors.fill: parent;
           //source: root.source
           onPosChanged: {
               textArea.syncSoundAndSliderPosition()
           }
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log(soundStore.state)
                if (soundStore.state === 3)
                    soundStore.pause()
                else
                    soundStore.start()
            }
        }
    }


    // Ползунок, старт, пауза
    ControlPanel{
        id : controlPanel
        anchors.top: mainVideoView.bottom
        //anchors.right : parent.right
        width: parent.width
        //anchors.fill: parent
        x : mainVideoView.x
    }

    Flickable {
        id: flickableTextArea
        visible: settingPage.showText === true
        anchors.top: controlPanel.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        flickableDirection: Flickable.VerticalFlick
        TextArea.flickable: TextReaderArea{ id : textArea }
        ScrollBar.vertical: ScrollBar {
            width: 20
        }
        Behavior on contentY {
                 NumberAnimation {
                     duration: 600
                 }
             }

        function getCurY() { return contentY }
        function setCurY(newY) {
            contentY = newY

        }
        function getCurHeigth() { return height }
    }

    UiControler{
        id: uiControler
        mouseIsPressed: false
        document : document
        soundStore : soundStore
        property bool dontSynch : false
        onDontSynchChanged:{
            if (!dontSynch)
                textArea.syncSoundAndSliderPosition()
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
    WebViewDialog{
        id: translateDialog
        contentText: qsTr("Translate")
        defaultURL : "http://www.multitran.com/m.exe?l1=1&l2=2&s=word"
    }
    HtmlView{ id: commentDialog }

}
