import QtQuick 2.0
import Qt.labs.platform 1.0

Menu {
    id : contextMenue
    MenuItem {
        text: "Edit text"
        onTriggered: {
            mainEditor.showDialog()
        }
    }
    MenuItem {
        text: "Add comment"
        enabled: textStore.someSellected
        onTriggered: {
            var commentFile = uiControler.addComment()
            commentEditor.openFile(commentFile)
            commentEditor.showDialog()
        }
    }
    MenuSeparator{}
    MenuItem {
        text: "Correct bind end"
        //enabled: document.someOpened()
        onTriggered: {
            textArea.startBindEdtingEnd()
            soundStore.stop()
        }
    }
    MenuItem {
        text: "Correct bind begin"
        //enabled: document.someOpened()
        onTriggered: {
            textArea.startBindEdtingBegin()
            soundStore.stop()
        }
    }
    MenuItem {
        text: "Add in comment"
        enabled: textStore.someSellected && uiController.haveCommentInThisPosition()
        onTriggered: {
            commentedColorDialog.open()
        }
    }
    MenuSeparator{}
    MenuItem {
        text: "Propertyes"
        onTriggered: {
            propertyDialog.showDialog()
        }
    }
}
