import QtQuick 2.0
import QtQuick.Controls 1.4
import TextStoreModul 1.0

SimpleDialog{
    id: root
    onBack: hideDialog()
    Rectangle{
        width: translateDialog.baseW * 9 / 10
        height: translateDialog.baseH * 3 / 4
        radius: 100
        anchors.centerIn: parent
        TextArea {
            id : commentArrea
            anchors.fill: parent
            text: document.text
            textFormat: Qt.RichText
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
