import QtQuick 2.8

import QtMultimedia 5.8
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import SoundStoreModul 1.1
import UiControlerModul 1.1
import TextStoreModul 1.0

// Ползунок, старт, пауза ..
Rectangle{
    id : root
    height: 50
  //  color:  "#EEEEEE"
    Button {
        id : playButton
        y : 5
        width: 30
        background: Rectangle {
            Image {
                source: soundStore.state === soundStore.playingState() ? "images/stop.png" : "images/play.png"
            }
        }
        onClicked: {
            if (soundStore.state === soundStore.playingState())
                soundStore.stop()
            else
                soundStore.start()
        }
    }
    // Ползуок
    QML_VideoSlider{
        id : videoSlider
        source : soundStore;
        anchors.left: playButton.right
        height: root.height;
        width: mainVideoView.width - playButton.width - centraliseButton.width - homeButton.width
        anchors.bottom:  root.bottom
    }
    Button {
        id : centraliseButton
        y : 5
        width: 40
        anchors.left:  videoSlider.right
        background: Rectangle {
            Image {
                source: homePage.homeUiControler.dontSynch ? "images/not-synch.png" : "images/synch.png"
            }
        }
        onClicked: {
            homePage.homeUiControler.dontSynch = !homePage.homeUiControler.dontSynch
        }
    }
    Button {
        id : homeButton
        y : 5
        width: 30
        anchors.left:  centraliseButton.right
        background: Rectangle {
            Image {
                source: soundStore.isExample === true ? "images/go-home.png" : "images/cant-go-home.png"
            }
        }
        onClicked: {
            if (soundStore.isExample)
                goHome()
        }
    }
}
