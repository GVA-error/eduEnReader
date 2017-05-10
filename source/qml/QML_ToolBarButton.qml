import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtGraphicalEffects 1.0

Button {
    id: buttonStyle
    property int fix_width
    signal clicked
    height: text.height + 20
    width: fix_width
    smooth: true
    SystemPalette { id: activePalette }
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: buttonStyle.clicked()

//        hoverEnabled: true
//        property bool f_entered: false
//        onEntered: f_entered = true
//        onExited: f_entered = false
    }
//    BrightnessContrast {
//        id: lightEffect
//        anchors.fill: parent
//        source: buttonStyle
//        brightness: 0.0
//        contrast: 0.0
//    }
//    states: [
//        State {
//            name: "lighter"; when: mouseArea.f_entered && !mouseArea.pressed
//            PropertyChanges {
//                target: lightEffect;
//                brightness: -0.1
//                contrast: 0.07
//            }
//        },
//        State {
//            name: "darker"; when: mouseArea.pressed
//            PropertyChanges {
//                target: lightEffect;
//                brightness: -0.0
//                contrast: -0.07
//            }
//        }
//    ]
}
