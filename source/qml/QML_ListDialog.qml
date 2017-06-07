import QtQuick 2.0

ListView
{
    property var out_model;
    property var title;
    property bool showDeleteButton: false

    signal selected(string str);
    signal deleteClicked(string str);
    signal enteredOnString(string str);
    signal exitedFromString(string str);
    id: view
    anchors.margins: 10
    //anchors.fill: parent
    spacing: 10
    model: out_model
    clip: true

    highlight: Rectangle {
        color: "skyblue"
    }
    highlightFollowsCurrentItem: true

    delegate: Item {
        id: listDelegate

        property var view: ListView.view
        property var isCurrent: ListView.isCurrentItem

        width: parent.width
        height: 40

        Rectangle {
            id: delegateRectangle
            anchors.margins: 5
            anchors.right: deleteButton.left
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            radius: 3
            //color: model.color
            border {
                color: "black"
                width: 1
            }
            Text {
                text: modelData
                anchors.fill: parent
                renderType: Text.NativeRendering
                anchors.margins: 10
                anchors.topMargin: 5
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    view.currentIndex = model.index
                    selected(modelData)
                }
                onEntered: enteredOnString(modelData)
                onExited: exitedFromString(modelData)
            }
        }
        Rectangle{
            id : deleteButton
            height: parent.height
            width: showDeleteButton ? parent.height : 0
            visible: showDeleteButton
            anchors.right: parent.right
            anchors.topMargin: 3
            anchors.bottomMargin: 3
            QML_ImageButton {
                anchors.fill: parent
                backgroundImage: "images/trash-empty.png"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: deleteClicked(modelData)
            }
        }
    }

    header: Rectangle {
        width: parent.width
        height: 40
        visible: title !== ""
        border {
            color: "black"
            width: 1
        }

        Text {
            anchors.centerIn: parent
            renderType: Text.NativeRendering
            text: title
        }
    }
}
