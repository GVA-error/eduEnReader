import QtQuick 2.8

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3

import UiControlerModul 1.1

Page {
    id : root
    padding: 30
    GridView {
        id: view
        anchors.margins: 10
        anchors.fill: parent
        cellWidth: 230
        cellHeight: cellWidth + 25
        model: homePage.homeUiControler.bindFilesListModel
        clip: true

        highlight: Rectangle {
            color: "skyblue"
        }

        delegate: Item {
            property var view: GridView.view
            property var isCurrent: GridView.isCurrentItem

            height: view.cellHeight
            width: view.cellWidth

            Rectangle {
                anchors.margins: 5
                anchors.fill: parent
                clip: true
                Rectangle{
                    id : image
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.left: parent.left
                    height: view.cellWidth * 3 / 4
                    width: view.cellWidth
                    color: "transparent"
                    Image {
                        anchors.fill: image
                        source: homePage.homeUiControler.getImageUrl(modelData)
                        z : image.z - 1
                    }
                    border {
                        color: "black"
                        width: 1
                    }
                }

                Text {
                    anchors.top : image.bottom
                    anchors.left: parent.left
                    anchors.right : parent.right
                    renderType: Text.NativeRendering
                    padding: 10
                    visible: modelData != "."
                    wrapMode: Text.Wrap
                    text: homePage.homeUiControler.getTitle(modelData)
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        view.currentIndex = model.index
                        if (homePage.homeUiControler.isDir(modelData))
                            homePage.homeUiControler.setCurDir(modelData)
                        else
                        {
                            goHome()
                            var url = homePage.homeUiControler.getBindFileUrlWithName(modelData)
                            openTimer.url = url
                            console.log(url)
                            waitDialog.contentText = "Preparation: " + modelData
                            waitDialog.showDialog()
                            openTimer.start()
                            //openTimer.
                        }
                    }
                }
            }
        }
    }
    Timer {
        id: openTimer
        repeat: false
        interval: 200
        property url url : ""
        onTriggered: {
            console.log(openTimer.url)
            homePage.homeUiControler.openBindFile(openTimer.url)
            waitDialog.hideDialog()
        }
    }


}
