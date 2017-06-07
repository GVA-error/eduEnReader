import QtQuick 2.8

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3

import UiControllerModul 1.1

Page {
    id : root
    property bool readOnly: false
    padding: 30
    QML_ImageButton{
        id: homeButton
        anchors.right: parent.right
        anchors.top: parent.top
        visible: homeUiController.someOpen
        backgroundImage: "images/go-home.png"
        width: 50
        height: homeUiController.someOpen ? 50 : 0
        onTrigered: goHome()
    }
    QML_ImageButton{
        id: downloadBaseButton
        anchors.right: parent.right
        anchors.top: homeButton.bottom
        backgroundImage: "images/package_internet_p2p.png"
        width: 50
        height: 50
        onTrigered: downloadBaseDialog.open()
    }
    QML_ImageButton{
        id: bindButton
        visible: readOnly === false
        anchors.right: parent.right
        anchors.top: downloadBaseButton.bottom
        width: 50
        height: 50
        anchors.topMargin: 5
        backgroundImage: "images/svn-commit.png"
        onTrigered: uploadBaseDialog.open()
    }
    QML_ImageButton{
        id: uploadButtonButton
        visible: readOnly === false
        anchors.right: parent.right
        anchors.top: bindButton.bottom
        width: 50
        height: 50
        anchors.topMargin: 5
        backgroundImage: "images/bind.png"
        onTrigered: tsBindingStart.show()
    }

    GridView {
        id: view
        anchors.left: parent.left
        anchors.right: homeButton.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        cellWidth: 230
        cellHeight: cellWidth + 25
        model: homePage.uiController.bindFilesListModel
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
                        backgroundImage: homeUiController.getImageUrl(modelData)
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
                    text: homeUiController.getTitle(modelData)
                }
                Rectangle{
                    id : trashButton
                    visible: modelData != "." && readOnly === false
                    anchors.top : image.bottom
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    width: readOnly ? 0 : height
                    QML_ImageButton {
                        anchors.fill: parent
                        backgroundImage: "images/trash-empty.png"
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
                        if (homePage.uiController.isDir(modelData))
                            homePage.uiController.setCurDir(modelData)
                        else
                        {
                            homeUiController.someOpen = true
                            goHome()
                            var url = homeUiController.getBindFileUrlWithName(modelData)
                            //openTimer.url = url
                         //   console.log(url)
                            homeUiController.setForOpening(url)
                            homeUiController.openWaited()
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
            homeUiController.deleteBindWithName(deleteName)
            homeUiController.synchBndFileList()
        }
    }
    QML_YesNoDialog{
        id: tsBindingStart
        title: "Start?"
        text: "Do you wanna start handling for all new mp4 files?\n ATENTION: It's spend many time."
        onYes:{
            waitDialog.showDialog()
            homeUiController.allTsBinding()
        }
    }
    QML_YesNoDialog{
        id: uploadBaseDialog
        title: "Upload?"
        text: "Do you want upload changes in repo?"
        onYes: {
            waitDialog.showDialog()
            homeUiController.uploadBase()
        }
    }
    QML_YesNoDialog{
        id: downloadBaseDialog
        title: "Update?"
        text: "Do you want load update from repo repo?"
        onYes: {
            mainRoot.waitDialog.showDialog()
            homeUiController.downloadBase()
        }
    }
}
