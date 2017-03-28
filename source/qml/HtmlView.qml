import QtQuick 2.8
import QtWebEngine 1.4

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0

import TextStoreModul 1.0
import UiControlerModul 1.1

SimpleDialog{
    id: root
    onBack: hideDialog()
    Rectangle{
        width: translateDialog.baseW * 9 / 10
        height: translateDialog.baseH * 3 / 4
        radius: 4
        anchors.centerIn: parent

        Flickable {
            id: flickable
            anchors.fill: parent
            flickableDirection: Flickable.VerticalFlick
            TextArea.flickable:
            TextArea {
                id : commentArrea
                text: document.text
                textFormat: Qt.RichText
                readOnly: true
            }
            ScrollBar.vertical: ScrollBar {}
        }

        TextStore{
            id : document
            target: commentArrea
        }

    }
    function openHtml(url){
        document.setFileUrl(url)
    }
}
