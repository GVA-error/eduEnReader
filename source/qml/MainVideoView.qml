import QtQuick 2.5
import QtMultimedia 5.8
import QtQuick.Controls 2.1
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import SoundStoreModul 1.1

Rectangle{
    id : root
    property var source;
    SoundStore {
       id : soundStore;
       anchors.fill: parent;
       //source: root.source
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            if (source.state === SoundStore.PlayingState)
                source.pause()
            else
                source.start()
        }
    }
}
