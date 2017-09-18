import QtQuick 2.8

import QtMultimedia 5.8
import QtQuick.Controls 2.1
import Qt.labs.platform 1.0

import UiControllerModul 1.2
import SoundStoreModul 1.1
import TextStoreModul 1.0

// TODO Возможность смены размеров
Rectangle { // Ползунок
    property var source;
    //anchors.top: videoRect.
    //anchors.right: parent.right
    id: soundGraph
 //   height: size_height
  //  width: size_width
    color : "transparent"
    Slider {
        id: control
        value: source.position
        anchors.left: parent.left
        anchors.right: parent.right
        property bool oldPlayingStateIsPlaying : false

        background: Rectangle {
            x: control.leftPadding
            y: control.topPadding + control.availableHeight / 2 - height / 2
            implicitWidth: 200
            implicitHeight: 7
            width: control.availableWidth
            height: implicitHeight
            radius: 4
            color: "#f0f0f0"

            Rectangle {
                width: control.visualPosition * parent.width
                height: parent.height
                color: "#bdbebf"
                radius: 2
            }
        }

        handle: Rectangle {
            id: handleRect
            x: control.leftPadding + control.visualPosition * (control.availableWidth - width)
            y: control.topPadding + control.availableHeight / 2 - height / 2
            implicitWidth: 54
            implicitHeight: 34
            radius: 11
            color: control.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
            Component.onCompleted: timeTextTimer.start()
            Text {
                id: handleText
                anchors.centerIn: parent
                text: homeUiController.getCurVideoTime(0)
            }
            Timer{
                id: timeTextTimer
                repeat: true
                interval: 500
                onTriggered: handleRect.synchHandleTime()
            }
            function synchHandleTime(){
                handleText.text = homeUiController.getCurVideoTime(control.visualPosition)
            }
            onXChanged: handleRect.synchHandleTime()
        }

        onPressedChanged: {
            if (pressed)
            {
                if (source.state === 3)
                    oldPlayingStateIsPlaying = true
                else
                    oldPlayingStateIsPlaying = false
                source.stop()
            }
            else
            {
                if (oldPlayingStateIsPlaying)
                    source.start()
                else
                    source.stop()
            }
            textArea.syncSoundAndSliderPosition(true)
        }
        onValueChanged: {
            if (pressed)// && soundStore.state != soundStore.PlayingState)
            {
                source.position = value
                textArea.syncSoundAndSliderPosition(false)
            }
            //if (pressed)
            //uiControler.setCursorPosInTimePos();
        }
    }
}
