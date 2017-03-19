import QtQuick 2.8

import QtMultimedia 5.8
import QtQuick.Controls 2.1
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import SoundStoreModul 1.1
import UiControlerModul 1.1
import TextStoreModul 1.0

// Ползунок, старт, пауза ..
Rectangle{
    id : root
    height: 50
    ToolButton {
        id : playButton
        y : 5
        // width: 30
        background: Image {
            source: soundStore.state == SoundStore.PlayingState ? "images/stop.png" : "images/play.png"
        }
        onClicked: {
            if (soundStore.state == SoundStore.PlayingState)
                soundStore.stop()
            else
                soundStore.start()
        }
    }
    // Ползуок
    VideoSlider{
        id : videoSlider;
        source : soundStore;
        anchors.left: playButton.right
        //anchors.right: mainVideoView.right

        //        x : (root.width - mainVideoView.width) / 2;
     //   y : 200;
        height: root.height;
        width: mainVideoView.width - playButton.width;
        anchors.bottom:  root.bottom
    }
}

//    Action {
//        id: bindAction
//        text: "Bind"
//        shortcut: "ctrl+B"
//        iconSource: "images/bind.png"
//        iconName: "Bind "
//        onTriggered: uiControler.makeBind()
//    }
//    Action {
//        id: playAction
//        text: "Play"
//        shortcut: "Ctrl+P"
//        iconSource: soundStore.state == SoundStore.PlayingState ? "images/stop.png" : "images/play.png"
//        iconName: "Play"
//        onTriggered: {
//            if (soundStore.state == SoundStore.PlayingState)
//                soundStore.stop()
//            else
//                soundStore.start()
//        }
//    }
//    Action {
//        id: pauseAction
//        text: "Pause"
//        shortcut: "ctrl+O"
//        iconSource: "qrc:images/stop.png"
//        iconName: "Pause"
//        onTriggered: soundStore.stop()
//    }
//    ToolBar{
//        //anchors.fill: parent
//        anchors.left: parent.left
//        anchors.right : homeToolBar.left
//        //width: 200
//        RowLayout {
//            spacing: 0
//          //  ToolButton { action: bindAction }
//            ToolButton { action: playAction }
//           // ToolButton { action: pauseAction }
//            //ToolButton { action: homeAction }
//        }
//    }
//    Action {
//        id: homeAction
//        text: "Home"
//        shortcut: "ctrl+H"
//        iconSource: "qrc:images/go-home.png"
//        iconName: "Bind "
//        onTriggered: uiControler.home()
//    }
//

