import QtQuick 2.8

import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2
import TextStoreModul 1.0
import UiControlerModul 1.1

Page {
    title: "settings"
    property var uiController
    signal ok
    padding: 10
    Component.onCompleted: contentItem.interactive = false

    onVisibleChanged:
    {
        if (visible === true)
        {

            gridBox.sourceChanged = false
            gridBox.previewChanged = false
        }
    }

    header: ToolBar{
        height: 50
            ToolButton {
                id: saveAndExitButton
                anchors.right: parent.right
                text: "ok" // icon-align-justify
                font.family: "fontello"
                focusPolicy: Qt.TabFocus
                onClicked: {
                    if (gridBox.sourceChanged)
                    {
                        var newSource = source.text
                        uiController.soundSource = newSource
                    }
                    if (gridBox.previewChanged)
                    {
                        uiControler.synchBndFileList()
                        homePage.update()
                    }
                    ok()
                }
             }
    }

    GroupBox {
        id: gridBox
        Layout.fillWidth: true
        width: 2 / 3 * parent.width
        leftPadding: 50
        rightPadding: 50
        property bool sourceChanged: false
        property bool previewChanged: false

        GridLayout {
            id: gridLayout
            rows: 3
            flow: GridLayout.TopToBottom
            width: parent.width
            rowSpacing: 10
            columnSpacing: 30

            Label { text: "Title" }
            Label { text: "Source" }
            Label { text: "Preview" }

            TextField {
                id : title
                text: uiController.title
                Layout.fillWidth: true
                wrapMode: TextArea.Wrap
                width: 500
                //anchors.right: parent.right
                selectByMouse: true
                onTextChanged: {
                    uiController.title = text
                }
            }
            TextField {
                id : source
                text: uiController.soundSource
                Layout.fillWidth: true;
                wrapMode: TextArea.Wrap
                selectByMouse: true
                onTextChanged: gridBox.sourceChanged = true
            }
            Button{
                text: ".."
                onClicked: previewDialog.open()
            }
        }
    }
    FileDialog
    {
        id: previewDialog
        title: "Please choose a preview file"
        nameFilters: [ "Image files (*.jpeg)" ]
        //folder: shortcuts.home

        onAccepted: {
            uiController.setPreviewForCurLecture(fileUrl)
            previewChanged = true
        }
    }
}
