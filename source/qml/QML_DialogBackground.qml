import QtQuick 2.0

Rectangle {
    id: root

    signal backClicked

    color: "#333"
    anchors.fill: parent
    opacity: 0
    state: "hideBack"
    visible: false

    states: [
        State {
            name: "hideBack"
            PropertyChanges { target: root; opacity: 0;}
        },
        State {
            name: "showBack"
            PropertyChanges { target: root; opacity: 0.7;}
        }
    ]

    transitions: Transition {
        from: "hideBack"; to: "showBack"; reversible: true
        NumberAnimation { properties: "opacity"; duration: 450;}
    }

    MouseArea {
        anchors.fill: parent
        onClicked: backClicked()
    }

    function show(){
        root.visible = true
        root.state = "showBack"
    }

    function hide(){
        root.visible = false
        root.state = "hideBack"
    }
}
