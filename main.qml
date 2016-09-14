import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import TextStoreModul 1.0

Window {
    id: mainWindow
    visible: true
    width: 1200
    height: 900

    TextStore{
       id: textStore

       onTextWasChanged: {
           textView.text = "123";
           textView.text = textStore.getBlock(0);
      }
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

           anchors.fill: background


           font.pointSize: 20
        }
     }



}

