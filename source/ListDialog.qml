import QtQuick 2.0

Item {
    property var out_model;
    property var title;

    signal selected(string str);

    ListView
    {
        id: view
        anchors.margins: 10
        anchors.fill: parent
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
                anchors.margins: 5
                anchors.fill: parent
                radius: height / 2
                //color: model.color
                border {
                    color: "black"
                    width: 1
                }
                Text {
                    text: modelData
                    anchors.centerIn: parent
                    renderType: Text.NativeRendering
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        view.currentIndex = model.index;
                        selected(modelData);
                    }
                }
            }
        }

        header: Rectangle {
            width: parent.width
            height: 40
            border {
                color: "black"
                width: 1
            }
            radius: 10
            Text {
                anchors.centerIn: parent
                renderType: Text.NativeRendering
                text: title
            }
        }
    }
}
