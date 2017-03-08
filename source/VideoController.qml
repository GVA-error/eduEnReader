import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle { // Ползунок
    property var source;
    property int size_height;
    property int size_width;
    property int pos_x;
    property int pos_y;

    x : pos_x;//130
    y : pos_y;//200
    //anchors.top: videoRect.
    //anchors.right: parent.right
    id: soundGraph
    height: size_height
    width: size_width
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
