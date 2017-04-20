import QtQuick 2.0
import QtQuick.Controls 1.4
import QtWebEngine 1.4

Item {
    id: root
    signal back
    property alias contentText: dialogText.text
    property real baseW : 3/7 * width;
    property real baseH : 3/7 * height;

    anchors.fill: parent
    visible: false
    QML_DialogBackground { id: dialogBackground }
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

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }
    function showDialog() {
        dialogBackground.show()
        root.visible = true

    }
    function hideDialog() {
        dialogBackground.hide()
        root.visible = false
    }
}
