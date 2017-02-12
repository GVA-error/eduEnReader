import QtQuick 2.0
import QtQuick.Controls 1.4
import QtWebEngine 1.4

Item {
    id: root
    signal back
    property alias contentText: dialogText.text
    anchors.fill: parent
    visible: false
    DialogBackground {
        id: dialogBackground
        onBackClicked: {
        //    hideDialog()
        }
    }
    Rectangle {
        id: dialog
        width: parent.width * 3 / 4
        height: parent.height * 3 / 4
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
        Rectangle
        {
            width: parent.width * 9 / 10
            height: parent.height * 3 / 4
            radius: 100
            anchors.centerIn: parent

            WebEngineView
            {
                anchors.fill: parent
                url: "http://www.multitran.com/m.exe?l1=1&l2=2&s=word"
                id: webView
            }
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
    function setUrl(url)
    {
        webView.url = url
       /* var request = new XMLHttpRequest()
        request.open('GET', "http://habrahabr.ru/rss/hubs/", true);
        request.onreadystatechange = function () {
            if (request.readyState === XMLHttpRequest.DONE) {
                if(request.readyState === 4) {
                   // console.log(request.responseText)
                    dataModel.xml = request.responseText
                } else {
                    console.log("HTTP request failed", request.status)
                }
            }
        }
        request.send()*/
    }
    function setHtml(html)
    {
        webView.loadHtml(html)
//        var request = new XMLHttpRequest()

//        request.open('GET', html, true);
//        request.onreadystatechange = function () {
//            if (request.readyState === XMLHttpRequest.DONE) {
//                if(request.readyState === 4) {
//                   // console.log(request.responseText)
//                    webView.loadHtml(request.responseText)

//                } else {
//                    console.log("HTTP request failed", request.status)
//                }
//            }
//        }
//        request.send()

    }
    function setXPath(xPath)
    {

    }
}
