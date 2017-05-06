import QtQuick 2.0

QML_SimpleDialog {
    id: root
    anchors.fill: parent
    signal ok()
   // property string text: textEditor.text

    QML_TextEditor{
        id : textEditor
        anchors.centerIn: parent
        width: baseW
        height: baseH
        //text: root.text
        onOk: root.ok()
    }

    function setText(newText){
        textEditor.setDocumentText(newText)
    }
    function getText(){
        return textEditor.getDocumentText()
    }
    function openFile(fileName){
        textEditor.openFile(fileName)
    }
    function save(){
        textEditor.save()
    }
}
