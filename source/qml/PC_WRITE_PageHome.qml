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
    id: root

    title: "main"
    property var homeDocument : document
    property var homeSoundStore : soundStore
    property var homeUiControler : uiControler
    property var textArea : flickableTextArea.textArea

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
        Component.onCompleted: contentItem.interactive = false
        z : 3
        Page{// Список комментариев
            visible: exampleCommentsPageLits.currentIndex == 0
            QML_CommentList{
                id: commentList
                anchors.fill: parent
                showDeleteButton: true
                uiController: uiControler
                onSelected: {
                    soundStore.stop()
                    //var commentText = commentDialog.getHtml()
                    var fileUrl = uiController.getCommentUrlWithName(str)
                    commentEditor.openFile(fileUrl)
                    commentEditor.showDialog()
                }
            }
        }
    }

    // Видео
    Rectangle{
        id : mainVideoView
        z : 3
        anchors.bottom: controlPanel.top
        x : 10
        y : 10
        width: parent.width * 2 / 3
        height: 480
        color: "black"
        SoundStore { // TODO стоит выделить класс плеера и стора отдельно
           id : soundStore;
           anchors.fill: parent
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
                else {
                    soundStore.start()
                    textArea.undoBindEditing()
                }
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

    MouseArea{ // TODO Ареа - Костыль, чтобы flickableTextArea не ловил лишних событий
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

    // Текст
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
        allowSellectOnlyWord: false
    }

    UiControler{
        id: uiControler
        mouseIsPressed: flickableTextArea.mouseLeftPresed
        document : TextStore {
            id: document
            target: flickableTextArea.textArea
            cursorPosition: target.cursorPosition
            selectionStart: target.selectionStart
            selectionEnd: target.selectionEnd
            textColor: "Black"
            onError: {
                errorDialog.text = message
                errorDialog.visible = true
            }
            onSelectionEndChanged:
                if (selectionStart === 0) // TODO костыль для ctr+A выделения
                    uiControler.synchCommentList()
        }
        soundStore : soundStore
        property bool dontSynch : false
        onDontSynchChanged:{
            if (!dontSynch)
                flickableTextArea.textArea.syncSoundAndSliderPosition(true)
        }
        Component.onCompleted: {
            synchBndFileList()
        }
    }

//    QML_HtmlView{
//        id: commentDialog
//        z: 4
//    }
    MessageDialog {
        id: errorDialog
    }

    Menu {
        id : contextMenue
        MenuItem {
            text: "Edit text"
            //enabled: document.someOpened()
            onTriggered: {
                mainEditor.showDialog()
            }
        }
        MenuItem {
            text: "Add comment"
            enabled: document.someSellected
            onTriggered: {
                var commentFile = uiControler.addComment()
                commentEditor.openFile(commentFile)
                commentEditor.showDialog()
            }
        }
        MenuSeparator{}
        MenuItem {
            text: "Correct bind end"
            //enabled: document.someOpened()
            onTriggered: {
                textArea.startBindEdtingEnd()
                soundStore.stop()
            }
        }
        MenuItem {
            text: "Correct bind begin"
            //enabled: document.someOpened()
            onTriggered: {
                textArea.startBindEdtingBegin()
                soundStore.stop()
            }
        }
        MenuItem {
            text: "Add in comment"
            enabled: document.someSellected && uiController.haveCommentInThisPosition()
            onTriggered: {
                commentedColorDialog.open()
            }
        }

        MenuSeparator{}
        MenuItem {
            text: "Propertyes"
            onTriggered: {
                propertyDialog.showDialog()
            }
        }
    }
    ColorDialog {
        id: commentedColorDialog
        color: "skyblue"
        onAccepted: {
            commentDialog.textColor = color
            commentDialog.showDialog()
        }
    }
    QML_CommentSellectDialog{
        id: commentDialog
        z: 10
        property color textColor: "skyblue"
        uiController: uiControler
        onVisibleChanged: {
            if (visible === true)
            {
                var commentListSize = uiControler.getCommentListSize()
                if (commentListSize === 1)
                {
                    var firsCommentName = uiControler.getFirstComment()
                    select(firsCommentName)
                }
            }
        }
        onSelected: {
            var sellectedString = document.getSellectedStreing()
            document.setTextColor(textColor)
            uiControler.addTextInComment(str, sellectedString, textColor)
            hideDialog()
        }
    }
}
