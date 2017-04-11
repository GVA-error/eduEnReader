import QtQuick 2.0

SimpleDialog {
    id: root
    anchors.fill: parent

    property var fileModel;
    property var openFunction;
    property var getUrlFunction

    onBack: hideDialog()
    ListDialog{
        width: root.baseW * 7 / 10
        height: root.baseH * 3 / 4
        anchors.centerIn: root
        out_model: fileModel
        title: "Lectures list"
        onSelected : {
            var fileUrl = getUrlFunction(str);
            hideDialog()
            openFunction(fileUrl)
        }
    }
}
