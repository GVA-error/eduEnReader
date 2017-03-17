import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import SoundStoreModul 1.1
import UiControlerModul 1.1
import TextStoreModul 1.0

// Ползунок, старт, пауза ..
Rectangle{
    id : soundToolBar
    height: 50
    Rectangle {
        id : soundPanel
        anchors.fill: parent
        Action {
            id: bindAction
            text: "Bind"
            shortcut: "ctrl+B"
            iconSource: "images/bind.png"
            iconName: "Bind "
            onTriggered: uiControler.makeBind()
        }
        Action {
            id: playAction
            text: "Play"
            shortcut: "Ctrl+P"
            iconSource: soundStore.state == SoundStore.PlayingState ? "images/stop.png" : "images/play.png"
            iconName: "Play"
            onTriggered: {
                if (soundStore.state == SoundStore.PlayingState)
                    soundStore.stop()
                else
                    soundStore.start()
            }
        }
        Action {
            id: pauseAction
            text: "Pause"
            shortcut: "ctrl+O"
            iconSource: "qrc:images/stop.png"
            iconName: "Pause"
            onTriggered: soundStore.stop()
        }
        ToolBar{
            //anchors.fill: parent
            anchors.left: parent.left
            anchors.right : homeToolBar.left
            //width: 200
            RowLayout {
                spacing: 0
              //  ToolButton { action: bindAction }
                ToolButton { action: playAction }
               // ToolButton { action: pauseAction }
                //ToolButton { action: homeAction }
            }
        }
        Action {
            id: homeAction
            text: "Home"
            shortcut: "ctrl+H"
            iconSource: "qrc:images/go-home.png"
            iconName: "Bind "
            onTriggered: uiControler.home()
        }
        ToolBar{
            id : homeToolBar
            //anchors.fill: parent
            anchors.right: parent.right
            width: 50
            RowLayout {
                spacing: 0
                ToolButton { action: homeAction }
            }
        }
    }

    // Ползуок
    VideoSlider{
        id : videoSlider;
        source : soundStore;
        x : (soundToolBar.width - mainVideoView.width) / 2;
     //   y : 200;
        height: soundToolBar.height;
        width: mainVideoView.width;
        anchors.bottom:  soundToolBar.bottom
    }
}
