import QtQuick 2.8

import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtWebEngine 1.4

import UiControlerModul 1.1

Page {
    Rectangle {
        id: input
        height: textField.height + 10
        width: parent.width
        z:1
        anchors.top: parent.top
        Component.onCompleted: {
            homePage.homeUiControler.getMatirealsFor("");
        }

        Rectangle{
            //anchors.centerIn: parent
            x : parent.width / 3
            y : 10
            width: parent.width / 3
            TextField {
                id: textField
                padding: 10
                z: 1
                width: parent.width / 3
                anchors.left: parent.left
                placeholderText: qsTr("Enter word or phrase")
                background: Rectangle {
                    implicitWidth: 200
                    implicitHeight: 40
                    color: input.enabled ? "transparent" : "#353637"
                    border.color: "black"
                }
                text: "eample"
                onTextChanged: {
                    homePage.homeUiControler.getMatirealsFor(text)
                }
            }

            Rectangle{
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: textField.right
                anchors.right: parent.right
                //width: parent.width * 2 / 3
                border.color: "skyblue"
                border.width: 1
                z : 3
                ComboBox {
                    padding: 10
                    id: control
                    anchors.fill: parent
                    model: homePage.homeUiControler.matirealsListModel

                    delegate: ItemDelegate {
                        width: control.width
                        contentItem: Text {
                            text: modelData
                            color: "skyblue"
                            font: control.font
                            elide: Text.ElideRight
                            verticalAlignment: Text.AlignVCenter
                        }
                        highlighted: control.highlightedIndex == index
                        onClicked: {
                            homePage.homeUiControler.getM

                        }
                    }

                    indicator: Canvas {
                        id: canvas
                        x: control.width - width - control.rightPadding
                        y: control.topPadding + (control.availableHeight - height) / 2
                        width: 12
                        height: 8
                        contextType: "2d"

                        Connections {
                            target: control
                            onPressedChanged: canvas.requestPaint()
                        }

                        onPaint: {
                            context.reset();
                            context.moveTo(0, 0);
                            context.lineTo(width, 0);
                            context.lineTo(width / 2, height);
                            context.closePath();
                            context.fillStyle = control.pressed ? "blue" : "skyblue";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 0
                        rightPadding: control.indicator.width + control.spacing

                        text: control.displayText
                        font: control.font
                        color: control.pressed ? "blue" : "skyblue"
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: control.pressed ? "blue" : "skyblue"
                        border.width: control.visualFocus ? 2 : 1
                        radius: 2
                    }

                    popup: Popup {
                        y: control.height - 1
                        width: control.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1

                        contentItem: ListView {
                            clip: true
                            implicitHeight: contentHeight
                            model: control.popup.visible ? control.delegateModel : null
                            currentIndex: control.highlightedIndex

                            ScrollIndicator.vertical: ScrollIndicator { }
                        }

                        background: Rectangle {
                            border.color: "skyblue"
                            radius: 2
                        }
                    }
                }
            }
        }
    }

    Rectangle{
        //anchors.left: parent.left
        //anchors.right: parent.right
        width: parent.width// * 2 / 3
        //x : parent.width * 1 / 6
        anchors.top: input.bottom
        anchors.bottom: parent.bottom
        //color: "black"
        z: 0
        id: webViewRect
        visible: textField.text != ""
        anchors.fill: parent
        color: "black"

        WebEngineView{
            id: webView
            anchors.fill : parent
            url: "https://www.dictionary.com"
        }

    }

}
