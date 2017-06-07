import QtQuick 2.0
import QtQuick.Controls 2.1
import TextStoreModul 1.0

// Список примеров или комментариев
SwipeView {
    id: exampleCommentsPageLits
    property bool readOnly
    property var uiController

    currentIndex: readOnly || (settingPage.showUserLikeComments && !readOnly) ? 0 : 2
    Page{// Список комментариев для чтения
        id : readCommentPage
        visible: exampleCommentsPageLits.currentIndex == 0
        padding: 10
        QML_TextReaderArea {
            id : commentArrea
            anchors.fill: parent

            sourceDocument: TextStore{
                id : commentDoc
                target: commentArrea.textArea
                fileUrl : uiController.curCommentUrl
            }
            uiController: root.uiController
            contextMenue: READ_TextAreaContextMenue {
                id : readContextMenue
                textStore: commentDoc
            }

            //text: commentDoc.text
            //textFormat: Qt.RichText
            //readOnly: true
            //onTextChanged: cursorPosition = 0
        }
    }
    Page{// Список примеров
        id: readExamplePage
        topPadding: 15
        visible: exampleCommentsPageLits.currentIndex == 1
        QML_ListDialog{
            z : 3;
            id : examples;
            out_model: uiController.exampleListModel;
            title: uiController.curExampleWord
            anchors.fill: parent
            onSelected : uiController.playExample(str)
        }
    }
    Page{// Список комментариев для редактирования
        visible: exampleCommentsPageLits.currentIndex == 2
        QML_CommentList{
            id: commentList
            anchors.fill: parent
            showDeleteButton: true
            uiController: exampleCommentsPageLits.uiController
            onSelected: {
                soundStore.stop()
                //var commentText = commentDialog.getHtml()
                var fileUrl = uiController.getCommentUrlWithName(str)
                commentEditor.openFile(fileUrl)
                commentEditor.showDialog()
            }
        }
    }
}
