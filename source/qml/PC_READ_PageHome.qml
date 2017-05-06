import QtQuick 2.8
import QtQml 2.2
import QtWebEngine 1.4

import QtMultimedia 5.8
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2
import Qt.labs.platform 1.0

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
        rightPadding: 10
        anchors.top : parent.top
        anchors.bottom: controlPanel.top
        anchors.right : controlPanel.right
        anchors.left : mainVideoView.right
        Component.onCompleted: interactive = false
        z : 3
        Page{// Список комментариев
            visible: exampleCommentsPageLits.currentIndex == 0
            padding: 10
            Flickable {
                id: flickable
                anchors.fill: parent
                flickableDirection: Flickable.VerticalFlick
                TextArea.flickable: TextArea {
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
            topPadding: 15
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
               flickableTextArea.textArea.syncSoundAndSliderPosition(false)
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


    QML_TextReaderArea{
        id: flickableTextArea
        visible: (settingPage.showExampleText === true && soundStore.isExample === true)
                 || (settingPage.showLectureText === true && soundStore.isExample === false)
        anchors.top: controlPanel.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        Component.onCompleted: contentItem.interactive = false
        sourceDocument: document
        uiController: uiControler
        contextMenue: contextMenue
    }

    UiControler{
        id: uiControler
        mouseIsPressed: textArea.mouseLeftPresed
        document: TextStore {
            id: document
            target: flickableTextArea.textArea
            cursorPosition: flickableTextArea.textArea.cursorPosition
            selectionStart: flickableTextArea.textArea.selectionStart
            selectionEnd: flickableTextArea.textArea.selectionEnd
            textColor: "Black"
            onError: {
                errorDialog.text = message
                errorDialog.visible = true
            }
        }
        soundStore : soundStore
        property bool dontSynch : false
        onDontSynchChanged:{
            if (!dontSynch)
                textArea.syncSoundAndSliderPosition(true)
        }
        Component.onCompleted:{
            synchBndFileList()
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
    MessageDialog {
        id: errorDialog
    }
    Menu {
        id : contextMenue
        MenuItem {
            text: "Translation/Synonyms"
            onTriggered: {
                //var translateUrl = uiControler.formUrlToTranslateSellected();
                //translateDialog.setUrl(translateUrl)
                //translateDialog.showDialog()
                goTranslitionHelp()
            }
        }
        MenuItem {
            text: "Example"
            onTriggered: {
                //uiControler.getExample()
                mainToolBar.setExampleText(document.getSellectedStreing())
                showExamples();
            }
        }
/*
        MenuSeparator {
            visible: recentFilesModel.count > 0
        }
*/
        Instantiator {
                model: homePage.homeUiControler.matirealsListModel
                MenuItem {
                    text: modelData
                    onTriggered: {
                        translitionHelpPage.setSource(text);
                        goTranslitionHelp()
                    }
                }
                onObjectAdded: contextMenue.insertItem(2+index, object)
                onObjectRemoved: contextMenue.removeItem(object)
        }


//        MenuItem {
//            text: "Set color"
//            onTriggered: {
//                colorDialog.open()
//            }
//        }

//        MenuItem {
//            text: "Add comment"
//            onTriggered: {
//                commentFileDialog.open()
//            }
//        }

/*
        ColorDialog {
            id: colorDialog
            color: homePage.homeDocument.markColor
            onAccepted: {
                document.setTextColor(color)
            }
        }*/
    }

}
