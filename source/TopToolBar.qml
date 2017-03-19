
import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import Qt.labs.platform 1.0


ToolBar {
    leftPadding: 50
    topPadding: 5
    bottomPadding : 5
    id : root
    Flow {
        id: flow
        width: parent.width
        spacing: 30
        Row {
            id: fileRow
            QMLButtonStyle {
                fix_width : 100
                text: "Open"
                onClicked: openDialog.open()
            }
            ToolSeparator {
                //contentItem.visible: fileRow.y === editRow.y
            }
        }
        Row {
            id: homeRow
            QMLButtonStyle {
                fix_width : 100
                text: "Home"
                checked: pageView.currentIndex == 0
                onClicked: mainRoot.goHome()
            }
//            ToolSeparator {
//                contentItem.visible: fileRow.y === editRow.y
//            }
        }
        Row {
            id: settingsRow
            QMLButtonStyle {
                fix_width : 100
                text: "settings"
                checked: pageView.currentIndex == 1
                onClicked: mainRoot.goSettings()
            }
//            ToolSeparator {
//                contentItem.visible: fileRow.y === editRow.y
//            }
        }
        Row {
            id: exampleRow
            QMLButtonStyle {
                fix_width : 100
                text: "examples"
                checked: homePage.curRightList == 1
                onClicked: mainRoot.goExamples()
            }
//            ToolSeparator {
//                contentItem.visible: fileRow.y === editRow.y
//            }
        }
    }


    FileDialog {
        id: openDialog
        fileMode: FileDialog.OpenFile
        selectedNameFilter.index: 1
        nameFilters : ["Bind file (*.bnd)"]
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        onAccepted : {
                homePage.homeUiControler.openBindFile(file)
        }
    }


//    FileDialog {
//        id: fileDialog
//        nameFilters : ["Bind file (*.bnd)"]
//        onAccepted : {
//            if (fileDialog.selectExisting)
//                uiControler.openBindFile(fileUrl)
//            else
//                uiControler.saveBindFile(fileUrl)
//        }
//    }
}






//ToolBar {
//    id: root
////    width: parent.width// - videoRect.width
////    //anchors.top: menuBar.
////    //anchors.right: videoRect.left

//    RowLayout {
//        anchors.fill: parent
//        spacing: 0
//        ToolButton { action: fileOpenAction }
//        QMLToolBarSeparator {}
//        Item { Layout.fillWidth: true }
//    }


//    Action {
//        id: fileOpenAction
//        iconSource: "images/fileopen.png"
//        iconName: "document-open"
//        text: "Open"
//        onTriggered: {
//            fileDialog.selectExisting = true
//            fileDialog.open()
//        }
//    }
//}
