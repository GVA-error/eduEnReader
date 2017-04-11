import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1

Button {
    id: buttonStyle

    //property variant text
    property int fix_width
    //property bool checked: false

    signal clicked

    height: text.height + 20;
    width: fix_width
   // border.width: 1
   // radius: 4
    smooth: true

    onFocusChanged : {
        if (focus)
            opacity = 0.5;
    }

    SystemPalette { id: activePalette }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: buttonStyle.clicked()
    }
}
