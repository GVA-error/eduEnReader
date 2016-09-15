import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import TextStoreModul 1.0
import SoundStoreModul 1.0
import UiControlerModul 1.0

Window {
    id: mainWindow
    visible: true
    width: 1200
    height: 900

    UiControler{
        id: uiControler
        oldXPos: 0
        mouseIsPressed: false
    }

    TextStore{
       id: textStore
       onTextWasChanged: {
      }
    }

    SoundStore{
        id: soundStore
    }

    ScrollView {
        id: scrlSound
        width: mainWindow.width * 9 / 10
        height: mainWindow.height * 3.2 / 10
        Rectangle {
            id: soundGraph
            width: mainWindow.width * 10 / 10
            height: mainWindow.height * 3 / 10
            color: "blue"

            Rectangle{
                id : selectRect
                x: 0
                y: 0
                width: 10
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
                    var w = x - uiControler.oldXPos;
                    if (w < 0)
                    {
                        w = Math.abs(w);
                        selectRect.x = uiControler.oldXPos - w;
                        if (selectRect.x < 0)
                            selectRect.x = 0;
                    }
                    if (w < 5)
                        w = 5;
                    selectRect.width = w;
                }

                onPressed:{
                    var x = mouseX;
                    selectRect.x = x;
                    uiControler.oldXPos = x;
                    uiControler.mouseIsPressed = true;
                }
            }

        }
    }

    Button {
        id: btnPlay
        width: mainWindow.width * 1 / 10
        height: mainWindow.height * 1 / 10
        x: mainWindow.width * 9 / 10
        y: mainWindow.height * 0 / 10

        text: "Play"
    }

    Button {
        id: btnRec
        width: mainWindow.width * 1 / 10
        height: mainWindow.height * 1 / 10
        x: mainWindow.width * 9 / 10
        y: mainWindow.height * 1 / 10

        text: "Rec"
    }

    Button {
        id: btnOpen
        width: mainWindow.width * 1 / 10
        height: mainWindow.height * 1 / 10
        x: mainWindow.width * 9 / 10
        y: mainWindow.height * 2 / 10

        text: "..."

        onClicked: {
            textView.text = textStore.getBlock(0);
            textView.text += textStore.getBlock(1);
        }
    }

     ScrollView {
         id: scrlText
         width: mainWindow.width * 10 / 10
         height: mainWindow.height * 6 / 10
         x: mainWindow.width * 0 / 10
         y: mainWindow.height * 4 / 10
        TextEdit
        {
            id: textView
            width: mainWindow.width * 10 / 10
            height: mainWindow.height * 9 / 10
            x: mainWindow.width * 0 / 10
            y: mainWindow.height * 0 / 10
            font.family: "Lucida Calligraphy"
            anchors.fill: parent
            font.pointSize: 20
        }
     }



}

