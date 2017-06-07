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
import UiControllerModul 1.1

Page {
    id: root
    //padding: 30

    title: "main"
    property var textStore : textStore
    property var soundStore : soundStore
    property var uiController : uiController
    property var textArea : flickableTextArea.textArea
    property bool readOnly: false

    function isExampleShowing() {
        return exampleCommentsPageLits.currentIndex === 1
    }
    function showComments() {
        if (readOnly || settingPage.showUserLikeComments)
            exampleCommentsPageLits.setCurrentIndex(0)
        else
            exampleCommentsPageLits.setCurrentIndex(2)
    }
    function showExamples() {
        exampleCommentsPageLits.setCurrentIndex(1)
    }
    function setExamples(str) {
        uiController.getExamplesFor(str)
    }

    // Список примеров или комментариев
    QML_HomePageInfoView {
        id: exampleCommentsPageLits
        rightPadding: 10
        anchors.top : parent.top
        anchors.bottom: mainVideoView.bottom
        anchors.right : parent.right
        anchors.left : mainVideoView.right
        Component.onCompleted: contentItem.interactive = false
        readOnly: root.readOnly
        uiController: uiController
        z : 3
    }

    // Видео
    Rectangle{
        id : mainVideoView
        z : 3
        //anchors.bottom: controlPanel.top
        x : 10
        y : 10
        width: parent.width * 2 / 3
        height: parent.height * 2 / 3
        color: "black"
        SoundStore { // TODO стоит выделить класс плеера и стора отдельно?
           id : soundStore;
           anchors.fill: parent
           //source: root.source
           onPosChanged: {
               flickableTextArea.textArea.syncSoundAndSliderPosition(false)
           }
           onOpeningError: {
               clear()
               textArea.text = "Video source is not found";
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
    QML_ControlPanel{
        id : controlPanel
        readOnly: root.readOnly
        soundStore: soundStore
        textArea:  root.textArea
        uiController: uiController

        anchors.top: mainVideoView.bottom
        anchors.right : mainVideoView.right
        anchors.left : mainVideoView.left
        anchors.topMargin: 3

        //buttonSize: 20
        Component.onCompleted: contentItem.interactive = false
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
        anchors.topMargin: 14
        width: parent.width
        Component.onCompleted: contentItem.interactive = false
        sourceDocument: textStore
        uiController: uiController
        contextMenue: readOnly ? readContextMenue : writeContextMenue
        allowSellectOnlyWord: root.readOnly
    }

    UiController{
        id: uiController
        mouseIsPressed: flickableTextArea.mouseLeftPresed
        document : TextStore {
            id: textStore
            target: flickableTextArea.textArea
            cursorPosition: target.cursorPosition
            selectionStart: target.selectionStart
            selectionEnd: target.selectionEnd
            textColor: "Black"
            onTextChanged: textArea.text = text
            onError: {
                errorDialog.text = message
                errorDialog.visible = true
            }
            onSelectionEndChanged:
                if (selectionStart === 0) // TODO костыль для ctr+A выделения
                    uiController.synchCommentList()
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
    WRITE_TextAreaContextMenue {
        id : writeContextMenue
    }
    READ_TextAreaContextMenue {
        id : readContextMenue
        textStore: homeTextStore
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
        uiController: uiController
        onVisibleChanged: {
            if (visible === true)
            {
                var commentListSize = uiController.getCommentListSize()
                if (commentListSize === 1)
                {
                    var firsCommentName = uiController.getFirstComment()
                    select(firsCommentName)
                }
            }
        }
        onSelected: {
            var sellectedString = textStore.getSellectedStreing()
            textStore.setTextColor(textColor)
            uiController.addTextInComment(str, sellectedString, textColor)
            hideDialog()
        }
    }
}
