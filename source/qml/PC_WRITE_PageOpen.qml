import QtQuick 2.8

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3

import UiControlerModul 1.1

Page {
    id : root
    padding: 30
    Rectangle {
        id: buttonPanel
        anchors.right: parent.right
        anchors.top: parent.top
        width: 50
        height: 60
        radius: 10
        border.color: "skyblue"

        QML_ImageButton{
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.left: parent.left
            height: 50
            anchors.margins: 5
            backgroundImage: "images/bind.png"
            onTrigered: tsBindingStart.show()
        }
    }

    GridView {
        id: view
        anchors.margins: 10
        anchors.left: parent.left
        anchors.right: buttonPanel.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom

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
                    QML_ImageButton {
                        anchors.fill: image
                        backgroundImage: homePage.homeUiControler.getImageUrl(modelData)
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
                    anchors.right : trashButton.left
                    anchors.bottom: parent.bottom
                    renderType: Text.NativeRendering
                    padding: 10
                    visible: modelData != "."
                    wrapMode: Text.Wrap
                    text: homePage.homeUiControler.getTitle(modelData)
                }
                Rectangle{
                    id : trashButton
                    visible: modelData != "."
                    anchors.top : image.bottom
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    width: height
                    QML_ImageButton {
                        anchors.fill: parent
                        backgroundImage: "images/trash.jpg"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            deleteDialog.deleteName = modelData;
                            deleteDialog.title = "Delete?";
                            deleteDialog.text = "Do you wanna delete " + modelData + "?  You can\'t undo it";
                            deleteDialog.show()
                        }
                    }

                }

                MouseArea {
                    anchors.fill: image
                    onClicked: {
                        view.currentIndex = model.index
                        if (homePage.homeUiControler.isDir(modelData))
                            homePage.homeUiControler.setCurDir(modelData)
                        else
                        {
                            goHome()
                            var url = homePage.homeUiControler.getBindFileUrlWithName(modelData)
                            //openTimer.url = url
                         //   console.log(url)
                            homePage.homeUiControler.setForOpening(url)
                         //   waitOpeningDialog.contentText = "Preparation: " + modelData
                           // waitDialog.curStateFunction = homePage.homeUiControler.openState()
                           // waitDialog.doFunction = homePage.homeUiControler.openWaited()
                         //   waitOpeningDialog.start()
                            homePage.homeUiControler.openWaited()
                        }
                    }
                }
            }
        }
    }
    QML_YesNoDialog{
        id : deleteDialog
        property string deleteName
        onYes: {
            homePage.homeUiControler.deleteBindWithName(deleteName)
            homePage.homeUiControler.synchBndFileList()
        }
    }
    QML_YesNoDialog{
        id: tsBindingStart
        title: "Start?"
        text: "Do you wanna start handling for all new mp4 files?\n ATENTION: It's spend many time."
        onYes:{
            waitDialog.showDialog()
            homePage.homeUiControler.allTsBinding()
        }
    }


}
