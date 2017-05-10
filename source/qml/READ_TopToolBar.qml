import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import TextStoreModul 1.0
import UiControlerModul 1.1

ToolBar {
    leftPadding: 10
    topPadding: 10
    bottomPadding : 10
    Material.elevation: 6
    id : root
    property var pageView
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
                onClicked: mainRoot.goOpenFile() // openDialog.open()
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
            QML_ToolBarButton {
                fix_width : 100
                text: "Video"
                checked: pageView.currentIndex === 1
                onClicked: {
                    mainRoot.goHome()
                }
            }
        }
        Row {
            id: translationHelp
            QML_ToolBarButton {
                fix_width : 100
                text: "Matireals"
                checked: pageView.currentIndex === 2
                onClicked: mainRoot.goTranslitionHelp()
            }
        }
        Row {
            id: settingsRow
            QML_ToolBarButton {
                fix_width : 100
                text: "settings"
                checked: pageView.currentIndex === 3
                onClicked: mainRoot.goSettings()
            }
        }
        Row {
            id: exampleRow
            //spacing: 30
            QML_ToolBarButton {
                fix_width : 100
                text: "examples"
                checked: homePage.isExampleShowing()
                onClicked: {
                    if (homePage.isExampleShowing())
                        mainRoot.goHome()
                    else{
                        mainRoot.goExamples()
                        exampleTextEdit.forceActiveFocus()
                    }
                }
            }
            Label{
                text: " "
                //y : 10
                visible: homePage.isExampleShowing()
            }
            TextField {
                placeholderText: qsTr("Enter word or phrase")
                padding: 7
                visible: homePage.isExampleShowing()
                id : exampleTextEdit
                text: ""
                Material.accent: Material.LightBlue
                onTextChanged: {
                    homePage.setExamples(text)
                    pageView.setCurrentIndex(1)
                }
            }
        }
    }
}

