import QtQuick 2.0

Rectangle {
    id: buttonStyle

    property variant text
    property int fix_width
    property bool checked: false

    signal clicked

    height: text.height + 20;
    width: fix_width
    border.width: 1
    radius: 4
    smooth: true

    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: !mouseArea.pressed && !checked ? activePalette.light : activePalette.button
        }
        GradientStop {
            position: 1.0
            color: !mouseArea.pressed && !checked ? activePalette.button : activePalette.dark
        }
    }

    SystemPalette { id: activePalette }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: buttonStyle.clicked()
    }

    Text {
        id: text
        anchors.centerIn:parent
        font.pointSize: 10
        text: parent.text
        color: activePalette.buttonText
    }
}
