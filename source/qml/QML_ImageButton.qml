import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle{
    id: root
    property string backgroundImage
    signal trigered()
    Image {
        id: image
        source: backgroundImage
        anchors.fill: root
    }
    MouseArea{
        id: mouseArea
        acceptedButtons: Qt.LeftButton
        anchors.fill: root
        cursorShape: Qt.PointingHandCursor
        hoverEnabled: true
        property bool f_entered: false
        onEntered: f_entered = true
        onExited: f_entered = false
        onClicked: trigered()

    }
    BrightnessContrast {
        id: lightEffect
        anchors.fill: image
        source: image
        brightness: 0.0
        contrast: 0.0
        Behavior on brightness {
             NumberAnimation {
                 duration: 250
             }
        }
        Behavior on contrast {
             NumberAnimation {
                 duration: 250
             }
         }
    }
    states: [
        State {
            name: "lighter"; when: mouseArea.f_entered && !mouseArea.pressed
            PropertyChanges {
                target: lightEffect;
                brightness: 0.2
                contrast: 0.07
            }
        },
        State {
            name: "darker"; when: mouseArea.pressed
            PropertyChanges {
                target: lightEffect;
                brightness: -0.1
                contrast: -0.07
            }
        }
    ]

}

