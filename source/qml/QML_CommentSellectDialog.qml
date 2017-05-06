import QtQuick 2.0

QML_SimpleDialog {
    id: root
    baseW: parent.width * 5/8
    baseH: parent.height * 5/8
    signal selected(var str)
    property var uiController
    function select(str){
        root.selected(str)
    }

    QML_CommentList{
        id: commentDialog
        anchors.centerIn: root
        width: baseW
        height: baseH
        showDeleteButton: false
        uiController: root.uiController
        onSelected: {
            root.selected(str)
        }
    }
}
