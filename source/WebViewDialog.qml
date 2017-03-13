import QtQuick 2.0
import QtWebEngine 1.4

SimpleDialog {
    id : root
    property url defaultURL
    property string postLoadScript
    property bool scriptRuned : false
    onBack: hideDialog()
    Rectangle{
        id : webRect
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
        //webView.reload()
        webView.runJavaScript(js, function(result){
            console.log("JS_begin: " + result + " JS_end");
           // if (result!=="undefined")
                webView.loadHtml(result, webView.url)
        })
    }
}
