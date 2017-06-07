import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import TextStoreModul 1.0
import UiControllerModul 1.1

ToolBar {
    leftPadding: 10
    topPadding: 10
    bottomPadding : 10
    Material.elevation: 6
    id : root
    function setExampleText(text){
        exampleTextEdit.text = text
    }
    Flow {
        id: flow
        width: parent.width
        spacing: 30
        Row {
            id: fileRow
            QML_ToolBarButton {
                fix_width : 100
                text: "Lectures"
                checked: pageView.currentIndex === 0
                onClicked: mainRoot.goOpenFile()
            }
            ToolSeparator {
                leftPadding: 15
                rightPadding: 15
                height: parent.height
                //contentItem.visible: fileRow.y === editRow.y
            }
        }
        Row {
            id: homeRow
            visible: homeUiController.someOpen
            QML_ToolBarButton {
                fix_width : 100
                text: "Home"
                checked: pageView.currentIndex === 1
                onClicked: { // TODO вернуть затычку
                    //if (waitDialog.visible === false)
                        mainRoot.goHome()
                }
            }
        }
        Row {
            id: settingsRow
            QML_ToolBarButton {
                fix_width : 100
                text: "settings"
                checked: pageView.currentIndex === 2
                onClicked: mainRoot.goSettings()
            }
        }
    }
}

