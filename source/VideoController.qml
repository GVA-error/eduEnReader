import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle { // Ползунок
    property var source;
    x : 130
    y : 200
    //anchors.top: videoRect.
    anchors.bottom:  soundToolBar.bottom
    //anchors.right: parent.right
    id: soundGraph
    height: soundToolBar.height
    width: soundToolBar.width - x - 20
    color : "transparent"
    Slider {
        id: soundSlider
        anchors.left: parent.left
        anchors.right: parent.right
        height: soundToolBar.height
        value: source.position
        style: SliderStyle {
                groove: Rectangle {
                    implicitWidth: 200
                    implicitHeight: soundToolBar.height / 2
                    color: "white"
                    radius: 8
                }
                handle: Rectangle {
                    anchors.centerIn: parent
                    color: control.pressed ? "white" : "lightgray"
                    border.color: "gray"
                    border.width: 2
                    implicitWidth: 34
                    implicitHeight: 34
                    radius: 12
                }
            }
        onValueChanged: {
            if (!pressed)
                uiControler.setCursorPosInTimePos();
        }
        onPressedChanged:{
            if (pressed)
                source.setPosPersent(soundSlider.value);
        }
    }
}
