import QtQuick 2.0
import QtWebEngine 1.4

QML_SimpleDialog {
    id : root
    property url defaultURL
    onBackClicked: hideDialog()
    Rectangle{
        width: translateDialog.baseW * 9 / 10
        height: translateDialog.baseH * 3 / 4
        radius: 100
        anchors.centerIn: parent
        WebEngineView{
            id: webView
            anchors.fill : parent
            url: defaultURL
        }
    }
    function setUrl(url){
        webView.url = url
    }
    function runScript(js){
        //var js = "document.documentElement.outerHTML";
        webview.runJavaScript(js, function(result){console.log(result);})
    }
}
