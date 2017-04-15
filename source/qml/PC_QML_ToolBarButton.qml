import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1

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
    }
}
