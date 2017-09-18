import QtQuick 2.8
import QtQuick.Controls 2.1

import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtWebEngine 1.4

import UiControllerModul 1.2
import TextStoreModul 1.0

Page {
    property string phrase
    property bool readOnly: false
    padding: 30

    Rectangle {
        id: input
        height: 70
        width: parent.width
        anchors.top: parent.top
        Component.onCompleted: {
            //homeUiController.getMatirealsFor("");
        }
        QML_ImageButton{
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 5
            backgroundImage: "images/go-home.png"
            width: 50
            height: 50
            onTrigered: goHome()
        }

        Rectangle{
            //anchors.centerIn: parent
            x : parent.width / 4
            y : 10
            width: parent.width * 1 / 2
            Rectangle{
                id : curSourceRect
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                width: curSource.width
                border.color: "skyblue"
                border.width: 1
                QML_ComboBox{
                    id : curSource
                    width: 300
                    model: homeUiController.exercisesListModel
                    onCurrentTextChanged: {
                        exerciseText.fileUrl = homeUiController.getExercisesUrlWithName(currentText)
                        //webView.show()
                        console.log("!!!"+exerciseText.fileUrl + "!!!!!!!!!!!")
                        webViewRect.visible = true
                    }
                }
            }
        }
    }

    Rectangle{
        id: webViewRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: input.bottom
        anchors.bottom: parent.bottom
        visible: false

        QML_TextReaderArea {
            id: exerciseTextArea
            anchors.fill: parent
            sourceDocument: TextStore{
                id : exerciseText
                target: exerciseTextArea.textArea
                fileUrl : "http://"
            }
            uiController: homeUiController
            contextMenue: READ_TextAreaContextMenue {
                id : readContextMenue
                textStore: exerciseText
            }
        }



    }

}
