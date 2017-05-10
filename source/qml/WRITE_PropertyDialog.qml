import QtQuick 2.0

QML_SimpleDialog {
    id: root
    anchors.fill: parent
    property var uiController

    WRITE_Propertyes{
        width: root.baseW
        height: root.baseH
        onOk: hideDialog()
        anchors.centerIn: parent
        uiController: root.uiController
    }
}
