import QtQuick 2.0
import QtQuick.Controls 1.4
import QtWebEngine 1.4

QML_SimpleDialog {
    id: root

    property string stateText

    baseW : 3/7 * width;
    baseH : 3/7 * height;

    onStateTextChanged: {
        contentText = stateText
        if (stateText === "end" || stateText === "")
            hideDialog()
        else if (visible == false && stateText !== "end" && stateText !== "")
            showDialog()
    }

    Rectangle{
        anchors.centerIn: parent
        width: baseW
        height: baseH
        color: "transparent"
        Text {
            id: text
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 14
            anchors.bottomMargin: 14
            font.pointSize: 18
            text: qsTr("Cancel")
        }
        MouseArea{
            z: 200
            anchors.fill: text
            onClicked: {
                cancelDialog.open()
            }
        }
    }
    QML_YesNoDialog{
        id: cancelDialog
        title: "cancel?"
        text: "Do you want cancel it process?"
        onYes: {
            homeUiController.setCurState("Cancaling. Please wait...");
            homeUiController.stopAllThreads()
            hideDialog()
        }
    }
}
