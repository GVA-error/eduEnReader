import QtQuick 2.8
import QtWebEngine 1.4

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import TextStoreModul 1.0
import SoundStoreModul 1.1
import UiControlerModul 1.1


TextArea {
    id: root
    Accessible.name: "document"
    textFormat: Qt.RichText
    wrapMode: TextArea.Wrap
    focus: true
    selectByMouse: true
    persistentSelection: true
    baseUrl: "qrc:/"
    leftPadding: 6
    rightPadding: 6
    topPadding: 0
    bottomPadding: 0
    background: null
    readOnly: true

    text: document.text

    property bool dontSync : false

    function syncSoundAndSliderPosition()
    {
        if (dontSync || uiControler.canNotSync())
            return;
        var mid = uiControler.getMidMarkable();
        var centr = positionToRectangle(mid).y;
        //flickableItem.contentY = centr - root.height/2
        uiControler.markCurText()
    }


    MouseArea {
        acceptedButtons: Qt.RightButton
        anchors.fill: parent
        onClicked: contextMenue.open()
    }

    onLinkActivated: Qt.openUrlExternally(link)
    Menu {
        id : contextMenue


        //title: "Edit"
        MenuItem {
            text: "Translate"
            onTriggered: {
                var translateUrl = uiControler.formUrlToTranslateSellected();
                translateDialog.setUrl(translateUrl)
                translateDialog.showDialog()
            }
        }
        MenuItem {
            text: "Example"
            onTriggered: {
                uiControler.getExample()
                showExamples();
            }

        }
    }
}









//TextArea{
//    id: root
//   // frameVisible: false
//    //height: 500
//    text: document.text
//    textFormat: Qt.RichText
//    Component.onCompleted: forceActiveFocus()
//    //wrapMode: TextArea.Wrap
//   // flickableItem.interactive: false


//    onSelectedTextChanged: {
//        uiControler.startSellectTimer()
//    }

//    MouseArea{
//        anchors.fill: root
//        acceptedButtons: Qt.RightButton
//        cursorShape: Qt.IBeamCursor
//        propagateComposedEvents: true
//        onClicked: {
//            if (mouse.button == Qt.RightButton)
//                contextMenue.popup();
//        }
//        onReleased: {
//            if (!propagateComposedEvents) {
//                propagateComposedEvents = true
//             }
//        }
//        onPressed: {
//            if (mouse.source !== Qt.MouseEventNotSynthesized)
//                 mouse.accepted = true
//        }
//    }

//    Action{
//        id: exampleAction
//        text: "Example"
//        shortcut: "ctrl+e"
//        iconSource: "images/editcut.png" // TODO придумать иконку
//        iconName: "edit-cut"
//        onTriggered: { var translateUrl = uiControler.getExample() }
//    }
//    Action{
//        id: translateAction
//        text: "Translate"
//        shortcut: "ctrl+t"
//        iconSource: "images/editcut.png" // TODO придумать иконку
//        iconName: "edit-cut"
//        onTriggered: {
//            var translateUrl = uiControler.formUrlToTranslateSellected();
//            translateDialog.setUrl(translateUrl)
//            translateDialog.showDialog()
//        }
//    }
//}

