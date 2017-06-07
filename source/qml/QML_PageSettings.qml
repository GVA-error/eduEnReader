import QtQuick 2.8
import QtWebEngine 1.4

import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3

import TextStoreModul 1.0
import UiControllerModul 1.1
import QML_SettingsModul 1.0

Page {
    id: root
    title: "settings"
    property bool showLectureText : textLectureShowing.checked
    property bool showExampleText : textExamplesShowing.checked
    property bool showTranslateDialog: translateDialogShowing.checked
    property bool showUserLikeComments: userLikeComments.checked
    property int autoCommentNumber: autocommentNumber.text*1
    property bool readOnly: false
    padding: 30

    QML_ImageButton{
        id: homeButton
        anchors.right: parent.right
        anchors.top: parent.top
        backgroundImage: "images/go-home.png"
        width: 50
        height: 50
        z: 1
        onTrigered: goHome()
    }
    Flickable {
        anchors.fill: parent
        ScrollBar.vertical: ScrollBar{
            anchors.top: parent.top
            anchors.topMargin: homeButton.height + root.padding
            width: 20
            bottomPadding: root.padding + writeGridBox.anchors.topMargin + root.padding
        }
        flickableDirection: Flickable.VerticalFlick
        contentWidth: parent.width
        contentHeight: readGridBox.height + writeGridBox.height
        QML_Settings{
            id : settingsStore
        }
        GroupBox {
            id: readGridBox
            Component.onCompleted: contentItem.interactive = false
            Layout.fillWidth: true
            width: 2 / 3 * parent.width
            leftPadding: 50
            rightPadding: 50
            anchors.top: parent.top
            title: "Read options:"

            GridLayout {
                rows: 6
                flow: GridLayout.TopToBottom
                width: parent.width
                rowSpacing: 10
                columnSpacing: 30

                Label { text: "Text color mark" }
                Label { text: "Examples size" }
                Label { text: "Difference of examples size +-" }
                Label { text: "Show lectures text" }
                Label { text: "Show examples text" }
                Label { text: "Show translate dialog" }

                ToolButton {
                    id: colorButton
                    Rectangle {
                        id: colorRect
                        anchors.fill: parent
                        radius: 4
                        color: settingsStore.textMarkColor
                    }
                    onClicked: {
                        colorDialog.open()
                    }
                    ColorDialog {
                        id: colorDialog
                        color: settingsStore.textMarkColor
                        onAccepted: {
                            colorRect.color = color
                            settingsStore.textMarkColor = color
                            homeTextStore.markColor = color
                        }
                    }
                }
                TextField {
                    id : fromExamplesSize
                    validator: IntValidator { bottom:0; top: 1000}
                    text: settingsStore.exampleSize
                    Layout.fillWidth: true
                    onTextChanged: {
                        if (text.length == 0)
                           text = "0";
                        settingsStore.exampleSize = text*1
                        homeUiController.examplesSize = text*1
                    }
                }
                TextField {
                    id : diffExamplesSize
                    validator: IntValidator { bottom:0; top: 1000}
                    text: settingsStore.exampleDiff
                    Layout.fillWidth: true
                    onTextChanged:{
                        if (text.length == 0)
                           text = "0";
                        settingsStore.exampleDiff = text*1
                        homeUiController.diffSize = text*1
                    }
                }
                CheckBox{
                    id : textLectureShowing
                    checked: settingsStore.showLectureText
                    onCheckedChanged: {
                        settingsStore.showLectureText = checked
                    }
                }
                CheckBox{
                    id : textExamplesShowing
                    checked: settingsStore.showExampleText
                    onCheckedChanged: {
                        settingsStore.showExampleText = checked
                    }
                }
                CheckBox{
                    id : translateDialogShowing
                    checked: settingsStore.showTranslateDialog
                    onCheckedChanged: {
                        settingsStore.showTranslateDialog = checked
                    }
                }
            }
        }
        GroupBox {
            id: writeGridBox
            visible: readOnly === false
            Component.onCompleted: contentItem.interactive = false
            Layout.fillWidth: true
            width: 2 / 3 * parent.width
            anchors.top: readGridBox.bottom
            anchors.topMargin: 5 + font.pixelSize
            leftPadding: 50
            rightPadding: 50
            title: "Write options:"

            GridLayout {
                rows: 2
                flow: GridLayout.TopToBottom
                width: parent.width
                rowSpacing: 10
                columnSpacing: 30

                Label { text: "User like comments" }
                Label { text: "Auto comment size" }

                CheckBox{
                    id : userLikeComments
                    checked: settingsStore.showUserLikeComments
                    onCheckedChanged: {
                        settingsStore.showUserLikeComments = checked
                    }
                }
                TextField {
                    id : autocommentNumber
                    validator: IntValidator { bottom:1; top: 100}
                    text: settingsStore.autoCommentNumber
                    Layout.fillWidth: true
                    onTextChanged:{
                        if (text.length == 0)
                           text = "1";
                        settingsStore.autoCommentNumber = text*1
                    }
                }
            }
        }
    }
}

