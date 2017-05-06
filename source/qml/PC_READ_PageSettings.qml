import QtQuick 2.8
import QtWebEngine 1.4

import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2

import TextStoreModul 1.0
import UiControlerModul 1.1
import QML_SettingsModul 1.0

Page {
    title: "settings"
    property bool showLectureText : textLectureShowing.checked
    property bool showExampleText : textExamplesShowing.checked
    padding: 10

    QML_Settings{
        id : settingsStore
    }

    GroupBox {
        Component.onCompleted: contentItem.interactive = false
        id: gridBox
        Layout.fillWidth: true
        width: 2 / 3 * parent.width
        leftPadding: 50
        rightPadding: 50

        GridLayout {
            id: gridLayout
            rows: 5
            flow: GridLayout.TopToBottom
            width: parent.width
            rowSpacing: 10
            columnSpacing: 30

            Label { text: "Text color mark" }
            Label { text: "Examples size" }
            Label { text: "Difference of examples size +-" }
            Label { text: "Show lectures text" }
            Label { text: "Show examples text" }

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
                        homePage.homeDocument.markColor = color
                    }
                }
            }
            TextField {
                id : fromExamplesSize
                validator: IntValidator { bottom:0; top: 1000}
                text: settingsStore.exampleSize
                Layout.fillWidth: true
                onTextChanged: {
                    settingsStore.exampleSize = text*1
                    homePage.homeUiControler.examplesSize = text*1
                    if (text.length == 0)
                       text = "0";
                }

            }
            TextField {
                id : diffExamplesSize
                validator: IntValidator { bottom:0; top: 1000}
                text: settingsStore.exampleDiff
                Layout.fillWidth: true
                onTextChanged:{
                    settingsStore.exampleDiff = text*1
                    homePage.homeUiControler.diffSize = text*1
                    if (text.length == 0)
                       text = "0";
                }
            }
            CheckBox{
                id : textLectureShowing
                checked: settingsStore.showLectureText
                onCheckedChanged: {
                    settingsStore.showLectureText = checked
                    homePage.textArea
                }
            }
            CheckBox{
                id : textExamplesShowing
                checked: settingsStore.showExampleText
                onCheckedChanged: {
                    settingsStore.showExampleText = checked
                }
            }
        }
    }
}

