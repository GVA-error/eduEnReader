import QtQuick 2.8
import QtWebEngine 1.4

import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2

import TextStoreModul 1.0
import SoundStoreModul 1.1
import UiControlerModul 1.1

Page {
    title: "settings"
    GroupBox {
        id: gridBox
        Layout.fillWidth: true
        leftPadding: 100

        GridLayout {
            id: gridLayout
            rows: 3
            flow: GridLayout.TopToBottom
            anchors.fill: parent
            Text { text: "Text color mark" }
            Label { text: "Examples size" }
            Label { text: "Difference of examples size +-" }

            ToolButton {
                id: colorButton
                Rectangle {
                    id: colorRect
                    anchors.fill: parent
                    color: homePage.homeDocument.markColor
                }
                onClicked: {
                    colorDialog.open()
                }
                ColorDialog {
                    id: colorDialog
                    color: homePage.homeDocument.markColor
                    onAccepted: {
                        colorRect.color = color
                        homePage.homeDocument.markColor = color
                    }
                }
            }

            TextField {
                id : fromExamplesSize
                validator: IntValidator { bottom:0; top: 1000}
                text: homePage.homeUiControler.examplesSize
                onTextChanged: {
                    homePage.homeUiControler.examplesSize = text*1
                    if (text.length == 0)
                       text = "0";
                }

            }

            TextField {
                id : diffExamplesSize
                validator: IntValidator { bottom:0; top: 1000}
                text: homePage.homeUiControler.diffSize
                onTextChanged:{
                    homePage.homeUiControler.diffSize = text*1
                    if (text.length == 0)
                       text = "0";
                }
            }
        }
    }
}
