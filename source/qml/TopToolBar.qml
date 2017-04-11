
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
    function setExampleText(text){
        exampleTextEdit.text = text
    }

    Flow {
        id: flow
        width: parent.width
        spacing: 30
        Row {
            id: fileRow
            QMLButtonStyle {
                fix_width : 100
                text: "Lectures"
                checked: pageView.currentIndex == 0
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
            QMLButtonStyle {
                fix_width : 100
                text: "home"
                checked: pageView.currentIndex == 1
                onClicked: mainRoot.goHome()
            }
//            ToolSeparator {
//                contentItem.visible: fileRow.y === editRow.y
//            }
        }
        Row {
            id: translationHelp
            QMLButtonStyle {
                fix_width : 100
                text: "Matireals"
                checked: pageView.currentIndex == 2
                onClicked: mainRoot.goTranslitionHelp()
            }
        }
        Row {
            id: settingsRow
            QMLButtonStyle {
                fix_width : 100
                text: "settings"
                checked: pageView.currentIndex == 3
                onClicked: mainRoot.goSettings()
            }
        }
        Row {
            id: exampleRow
            //spacing: 30
            QMLButtonStyle {
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

   /* FileDialog {
        id: openDialog
        fileMode: FileDialog.OpenFile
        selectedNameFilter.index: 1
        nameFilters : ["Bind file (*.bnd)"]
        folder: appPath
        onAccepted : {
                homePage.homeUiControler.openBindFile(file)
        }
    }*/
}

