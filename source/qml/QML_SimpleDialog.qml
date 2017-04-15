import QtQuick 2.0
import QtQuick.Controls 1.4
import QtWebEngine 1.4

Item {
    id: root
    signal back
    property alias contentText: dialogText.text
    property real baseW : 3/4 * width;
    property real baseH : 3/4 * height;
    anchors.fill: parent
    visible: false
    QML_DialogBackground {
        id: dialogBackground
        onBackClicked: {
            hideDialog()
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

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: textBack
            text: qsTr("Back")
            color: "black"
            visible: true

            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 16

            font.pixelSize: 24

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            MouseArea {
                anchors.centerIn: parent
                width: parent.paintedWidth
                height: parent.paintedHeight
                onClicked: back()
            }
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
