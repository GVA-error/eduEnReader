import QtQuick 2.5
import QtMultimedia 5.8
import SoundStoreModul 1.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle{
    id : root
    VideoOutput {
       id : videoOutput;
       anchors.fill: parent;
    //   width: 800;
    //   height: 600
       source: soundStore
   }
   MouseArea{
        anchors.fill: parent
        onClicked: {
            if (soundStore.state == SoundStore.PlayingState)
                soundStore.stop()
            else
                soundStore.start()
        }
   }
}
