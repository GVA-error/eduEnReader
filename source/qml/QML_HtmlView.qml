import QtQuick 2.8
import QtWebEngine 1.4

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0

import TextStoreModul 1.0
import UiControllerModul 1.2

QML_SimpleDialog{
    id: root
    Rectangle{
        width: baseW * 9 / 10
        height: baseH * 3 / 4
        radius: 4
        anchors.centerIn: parent

        Flickable {
            id: flickable
            anchors.fill: parent
            flickableDirection: Flickable.VerticalFlick
            TextArea.flickable: TextArea {
                id: commentArrea
                Accessible.name: "document"
                //visible: homePage.curRightList == 1
                textFormat: Qt.RichText
                wrapMode: TextArea.Wrap
                focus: true
                selectByMouse: true
                persistentSelection: true
                //baseUrl: "qrc:/"
                leftPadding: 10
                rightPadding: 10
                topPadding: 10
                bottomPadding: 10
                background: null
                readOnly: true
                mouseSelectionMode : TextInput.SelectWords
                text: documentHtml.text
            }
            ScrollBar.vertical: ScrollBar {}
        }

        TextStore{
            id : documentHtml
            target: commentArrea
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
                onClicked: hideDialog()
            }
        }

    }
    function openHtml(url){
        document.setFileUrl(url)
    }
    function setHtml(newHtml){
        document.text = newHtml
    }
    function getHtml(){
        return document.text
    }
}
