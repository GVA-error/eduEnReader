import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

Dialog {
    visible: true
    title: "Please enter"
    property string question: labelQuestion.text
    property string text: inputField.text

    standardButtons: StandardButton.Ok | StandardButton.Cancel
    contentItem: Rectangle {
        color: "lightskyblue"
        implicitWidth: 400
        implicitHeight: 100
        Label {
            id: labelQuestion
            text: "Hello blue sky!"
        }
        TextInput{
            id : inputField
            text : "someName"
            anchors.left: labelQuestion.right
        }
    }
}
