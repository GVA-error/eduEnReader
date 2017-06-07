import QtQuick 2.0
import QtQuick.Controls 1.4
import QtWebEngine 1.4

Item {
    id: root
    property alias contentText: dialogText.text
    property real baseW : 6/7 * width;
    property real baseH : 6/7 * height;
    anchors.fill: parent
    visible: false

    signal backClicked

    Behavior on visible {
         NumberAnimation {
             duration: 250
         }
     }
    QML_DialogBackground {
        id: dialogBackground
        onBackClicked: {
            root.backClicked()
        }
    }
    Rectangle {
        id: dialog
        width: baseW
        height: baseH
        radius: 4
        color: "whitesmoke"
        anchors.top: parent.top
        anchors.topMargin: {
            Qt.inputMethod.visible ?
                        (parent.height - Qt.inputMethod.keyboardRectangle.height - dialog.height)/2 :
                        (parent.height - dialog.height)/2;
        }
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id: dialogText
            wrapMode: Text.Wrap
            color: "black"
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins: 16
            }

            font.pixelSize: 16

            //verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }
    }
    function showDialog() {
        dialogBackground.show()
        root.visible = true
    }
    function hideDialog() {
        root.visible = false
        dialogBackground.hide()
    }
}
