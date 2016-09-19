import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1
import UiControlerModul 1.0

Item {

    UiControler{
        id: uiControler
        oldXSoundPos: 0
        mouseIsPressed: false
    }

    Action {
        id: playAction
        text: "Play"
        shortcut: "ctrl+p"
        iconSource: "images/editcut.png"
        iconName: "edit-cut"
        onTriggered: textArea.cut()
    }

    Action {
        id: bindAction
        text: "Copy"
        shortcut: "Ctrl+C"
        iconSource: "images/editcopy.png"
        iconName: "edit-copy"
        onTriggered: textArea.copy()
    }

    Action {
        id: openAction
        text: "Paste"
        shortcut: "ctrl+v"
        iconSource: "qrc:images/editpaste.png"
        iconName: "edit-paste"
        onTriggered: textArea.paste()
    }

    ToolBar
    {
        id : soundToolBar
        width: 150

        RowLayout {
            spacing: 0

            ToolButton { action: playAction }
            ToolButton { action: bindAction }
            ToolButton { action: openAction }

            Item { Layout.fillWidth: true }
        }

    }


    Rectangle {
        anchors.left: soundToolBar.right
        anchors.right: parent.right
        id: soundGraph
        height: soundToolBar.height
        color: "blue"

        radius: 10

        Rectangle{
            id : selectRect
            x: 0
            y: 0
            width: 3
            height: soundGraph.height
            color: "red"
            opacity : 0.5
        }

        MouseArea {
            anchors.fill: parent
            onReleased: {
                uiControler.mouseIsPressed = false;
            }
            onMouseXChanged:{
                if (!uiControler.mouseIsPressed)
                    return;
                var x = mouseX;
                var w = x - uiControler.oldXSoundPos;
                if (w < 0)
                {
                    w = Math.abs(w);
                    selectRect.x = uiControler.oldXSoundPos - w;
                    if (selectRect.x < 0)
                        selectRect.x = 0;
                }
                if (w < 5)
                    w = 3;
                selectRect.width = w;
            }

            onPressed:{
                var x = mouseX;
                selectRect.x = x;
                uiControler.oldXSoundPos = x;
                uiControler.mouseIsPressed = true;
            }
        }

    }



}
