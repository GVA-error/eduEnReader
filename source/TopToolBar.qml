import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.1

ToolBar {
    id: root
//    width: parent.width// - videoRect.width
//    //anchors.top: menuBar.
//    //anchors.right: videoRect.left

    RowLayout {
        anchors.fill: parent
        spacing: 0
        ToolButton { action: fileOpenAction }
        QMLToolBarSeparator {}
        Item { Layout.fillWidth: true }
    }


    Action {
        id: fileOpenAction
        iconSource: "images/fileopen.png"
        iconName: "document-open"
        text: "Open"
        onTriggered: {
            fileDialog.selectExisting = true
            fileDialog.open()
        }
    }
    FileDialog {
        id: fileDialog
        nameFilters : ["Bind file (*.bnd)"]
        onAccepted : {
            if (fileDialog.selectExisting)
                uiControler.openBindFile(fileUrl)
            else
                uiControler.saveBindFile(fileUrl)
        }
    }
}
