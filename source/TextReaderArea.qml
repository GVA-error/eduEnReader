import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

TextArea{
    id: root
    Accessible.name: "document"
    frameVisible: false
    baseUrl: "qrc:/"
    //height: 500
    text: document.text
    textFormat: Qt.RichText
    Component.onCompleted: forceActiveFocus()
    readOnly: true
    wrapMode: TextArea.Wrap
    flickableItem.interactive: false

    function syncSoundAndSliderPosition()
    {
        var centr = (positionToRectangle(selectionStart).y + positionToRectangle(selectionEnd).y) / 2;
        flickableItem.contentY = centr - root.height/2
    }

    Menu {
        id : contextMenue
        //title: "Edit"
        MenuItem {
            text: "Translate"
            action: translateAction
        }
        MenuItem {
            text: "Example"
            action: exampleAction
        }
    }
    MouseArea{
        acceptedButtons: Qt.RightButton
        anchors.fill: textArea
        cursorShape: Qt.IBeamCursor
        onClicked: {
            if (mouse.button == Qt.RightButton)
                contextMenue.popup();
        }
        onReleased: {
            if (!propagateComposedEvents) {
                propagateComposedEvents = true
             }
        }
    }

    Action{
        id: exampleAction
        text: "Example"
        shortcut: "ctrl+e"
        iconSource: "images/editcut.png" // TODO придумать иконку
        iconName: "edit-cut"
        onTriggered: { var translateUrl = uiControler.getExample() }
    }
    Action{
        id: translateAction
        text: "Translate"
        shortcut: "ctrl+t"
        iconSource: "images/editcut.png" // TODO придумать иконку
        iconName: "edit-cut"
        onTriggered: {
            var translateUrl = uiControler.formUrlToTranslateSellected();
            translateDialog.setUrl(translateUrl)
            translateDialog.showDialog()
        }
    }
}

