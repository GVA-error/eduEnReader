import QtQuick 2.8
import QtWebEngine 1.4

import QtQuick.Controls 2.1
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
            rows: 1
            flow: GridLayout.TopToBottom
            anchors.fill: parent
            Label { text: "Mark text color" }
            //Label { text: "Line 2" }

            ToolButton {
                id: colorButton
                Rectangle {
                    id: colorRect
                    anchors.fill: parent
                    //anchors.margins: 8
                    color: homePage.homeDocument.markColor
                  //  border.width: 1
                   // border.color: homePage.homeDocument.markColor
                }
                onClicked: {
                    colorDialog.open()
                }
                ColorDialog {
                    id: colorDialog
                    color: homePage.homeDocument.markColor
                    onAccepted: {
                        colorRect.color = color
                    }
                }
            }
        }
    }

}
