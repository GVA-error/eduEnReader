import QtQuick 2.0

QML_SimpleDialog {
    id: root
    anchors.fill: parent

    property var fileModel;
    property var openFunction;
    property var getUrlFunction

    onBack: hideDialog()
    QML_ListDialog{
        width: baseW * 7 / 10
        height: baseH * 3 / 4
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
