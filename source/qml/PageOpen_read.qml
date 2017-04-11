import QtQuick 2.8

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3

import UiControlerModul 1.1

Page {
    id : root
    padding: 30
//    GridView{
//        id: view
//        anchors.fill: parent

//      //  width: root.baseW * 7 / 10
//       // height: root.baseH * 3 / 4
//      //  anchors.centerIn: root
//        model: homePage.homeUiControler.bindFilesListModel
//        //title: "Lectures list in ./"
//        /*onSelected : {
//            var fileUrl = homePage.homeUiControler.getBindFileUrlWithName(str);
//            goHome()
//            //hideDialog()
//            homePage.homeUiControler.openBindFile(fileUrl)
//        }*/
//        delegate: Rectangle {
//            width: view.width * 2 / 3
//            anchors.centerIn: parent
//            height: 150
//            color: "skyblue"
//            radius: 4

//            Text {
//                anchors.centerIn: parent
//                renderType: Text.NativeRendering
//                text: model.index
//            }
//        }
//    }

    GridView {
        id: view

        anchors.margins: 10
        anchors.fill: parent
        cellWidth: 230
        cellHeight: cellWidth + 75
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
               // color: model.color
                border {
                    color: "black"
                    width: 1
                }

                Rectangle{
                    id : image
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.left: parent.left
                    height: view.cellWidth
                    width: view.cellWidth
                    color: "black"
                    Image {
                        anchors.fill: image
                        source: homePage.homeUiControler.getImageUrl(modelData)
                        fillMode: Image.PreserveAspectFit
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
                    wrapMode: Text.Wrap
                    text: homePage.homeUiControler.getTitle(modelData)
                    //modelData + " asd asda sdasdasdasdasdasd as asdsdasd asdasdasd  asdasd"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        view.currentIndex = model.index
                        var url = homePage.homeUiControler.getBindFileUrlWithName(modelData)
                        homePage.homeUiControler.openBindFile(url)
                        goHome()
                    }
                }
            }
        }
    }


}
