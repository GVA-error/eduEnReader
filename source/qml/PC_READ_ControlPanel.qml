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
    QML_ImageButton {
        id : playButton
        anchors.top: parent.top
        anchors.topMargin: 7
        width: 30
        height: 30
        backgroundImage: soundStore.state === soundStore.playingState() ? "images/stop.png" : "images/play.png"
        onTrigered: {
            if (soundStore.state === soundStore.playingState())
                soundStore.stop()
            else {
                homePage.textArea.undoBindEditing()
                soundStore.start()
            }
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
    QML_ImageButton {
        id : centraliseButton
        anchors.top: parent.top
        anchors.margins : 5
        width: 30
        height: 30
        anchors.left:  videoSlider.right
        backgroundImage: homePage.homeUiControler.dontSynch ? "images/not-synch.png" : "images/synch.png"
        onTrigered: {
            homePage.homeUiControler.dontSynch = !homePage.homeUiControler.dontSynch
        }
    }
    QML_ImageButton {
        id : homeButton
        anchors.top: parent.top
        anchors.margins: 5
        width: 30
        height: 30
        anchors.left:  centraliseButton.right
        backgroundImage: soundStore.isExample === true ? "images/go-home.png" : "images/cant-go-home.png"
        onTrigered: {
            if (soundStore.isExample)
                goHome()
                showComments()
        }
    }
}
