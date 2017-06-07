import QtQuick 2.0
import UiControllerModul 1.1

QML_ListDialog{
    id : comments
    property var uiController
    out_model: uiController.commentListModel
    title: "Comments"
    showDeleteButton: true
    onDeleteClicked: {
        deleteDialog.title = "Delete?";
        deleteDialog.text = "Do you wanna delete " + str + "? You can\'t undo it";
        deleteDialog.deleteName = str
        deleteDialog.show()
    }
    onEnteredOnString: uiController.markComment(str)
    onExitedFromString: {
        uiController.unmarkComment(str)
        flickableTextArea.textArea.syncSoundAndSliderPosition()
    }

    QML_YesNoDialog{
        id : deleteDialog
        property string deleteName
        onYes: {
            uiController.deleteCommentWithName(deleteName)
        }
    }
}
