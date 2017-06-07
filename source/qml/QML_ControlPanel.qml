import QtQuick 2.8

import QtMultimedia 5.8
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import SoundStoreModul 1.1
import UiControllerModul 1.1
import TextStoreModul 1.0

// Ползунок, старт, пауза ..
Rectangle{
    id : root
    property bool readOnly: false
    property int buttonSize: 30
    property var soundStore
    property var textArea
    property var uiController
    height: buttonSize

    RowLayout{
        id: leftControlPanel
        anchors.left: parent.left
        anchors.top: parent.top
        spacing: 5
        anchors.topMargin: 7
        QML_ImageButton {
            id : playButton
            width: buttonSize
            height: buttonSize
            anchors.left: parent.left
            backgroundImage: soundStore.state === soundStore.playingState() ? "images/stop.png" : "images/play.png"
            onTrigered: {
                if (soundStore.state === soundStore.playingState())
                    soundStore.stop()
                else {
                    textArea.undoBindEditing()
                    soundStore.start()
                }
            }
        }
    }
    // Ползуок
    QML_VideoSlider{
        id : videoSlider
        source : soundStore
        height: buttonSize
        anchors.left: leftControlPanel.right
        anchors.right: rightControlPanel.left
       // anchors.rightMargin: rightControlPanel.spacing
    }
    RowLayout{
        id: rightControlPanel
        anchors.right: parent.right
        anchors.top: parent.top
        spacing: 5
        anchors.topMargin: 7
        width: (buttonSize + spacing) * (readOnly ? 2 : 4)
        QML_ImageButton {
            id : centraliseButton
            width: buttonSize
            height: buttonSize
            backgroundImage: uiController.dontSynch ? "images/not-synch.png" : "images/synch.png"
            onTrigered: {
                uiController.dontSynch = !uiController.dontSynch
            }
        }
        QML_ImageButton {
            id : autoCommentButton
            visible: readOnly === false
            width: readOnly ? 0 : buttonSize
            height: buttonSize
            backgroundImage: "images/textleft.png"
            onTrigered: {
                createNewCommentSplit.open()
            }
        }
        QML_ImageButton {
            id : synchButton
            visible: readOnly === false
            width: readOnly ? 0 : buttonSize
            height: buttonSize
            backgroundImage: "images/bind.png"
            onTrigered: {
                curTsBindingStart.open()
            }
        }
        QML_ImageButton {
            id : saveButton
            visible: readOnly === false
            width: readOnly ? 0 : buttonSize
            height: buttonSize
            backgroundImage: "images/filesave.png"
            onTrigered: {
                uiController.save()
                messageDialog.title = "successful"
                messageDialog.text = "saved"
                messageDialog.open()
            }
        }
        QML_ImageButton {
            id : homeButton
            width: readOnly ? buttonSize : 0
            height: buttonSize
            backgroundImage: soundStore.isExample === true ? "images/go-home.png" : "images/cant-go-home.png"
            onTrigered: {
                if (soundStore.isExample)
                    goHome()
                showComments()
            }
        }
    }
}
