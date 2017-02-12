import QtQuick 2.5
import QtWebEngine 1.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.1
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import TextStoreModul 1.0
import SoundStoreModul 1.1
import UiControlerModul 1.1


// TODO РЕФАКТОРИНГ

/*
При вызове контексного меню MenuContentItem.qml:178: ReferenceError: Acccessible is not defined

*/

ApplicationWindow {
    visible: true
    width: 1024
    height: 768
    title: document.documentTitle + " - Text Editor Example"

    UiControler{
        id: uiControler
        mouseIsPressed: false
        document : document
        soundStore : soundStore
    }

    MessageDialog {
        id: aboutBox
        title: "About Text"
        text: "Autor: Golubtsov Vasiliy Anatolievich.
            \n e-mail - vsv10000ego@gmail.com";
        icon: StandardIcon.Information
    }
    Action{
        id: translateAction
        text: "Translate"
        shortcut: "ctrl+t"
        iconSource: "images/editcut.png" // TODO придумать иконку
        iconName: "edit-cut"
        onTriggered: {
            var translateUrl = uiControler.formUrlToTranslateSellected();
            translateDialog.setUrl(translateUrl)
            translateDialog.showDialog()
        }
    }
    Action {
        id: cutAction
        text: "Cut"
        shortcut: "ctrl+x"
        iconSource: "images/editcut.png"
        iconName: "edit-cut"
        onTriggered: textArea.cut()
    }
    Action {
        id: copyAction
        text: "Copy"
        shortcut: "Ctrl+C"
        iconSource: "images/editcopy.png"
        iconName: "edit-copy"
        onTriggered: textArea.copy()
    }
    Action {
        id: pasteAction
        text: "Paste"
        shortcut: "ctrl+v"
        iconSource: "qrc:images/editpaste.png"
        iconName: "edit-paste"
        onTriggered: textArea.paste()
    }
    Action {
        id: alignLeftAction
        text: "&Left"
        iconSource: "images/textleft.png"
        iconName: "format-justify-left"
        shortcut: "ctrl+l"
        onTriggered: document.alignment = Qt.AlignLeft
        checkable: true
        checked: document.alignment == Qt.AlignLeft
    }
    Action {
        id: alignCenterAction
        text: "C&enter"
        iconSource: "images/textcenter.png"
        iconName: "format-justify-center"
        onTriggered: document.alignment = Qt.AlignHCenter
        checkable: true
        checked: document.alignment == Qt.AlignHCenter
    }
    Action {
        id: alignRightAction
        text: "&Right"
        iconSource: "images/textright.png"
        iconName: "format-justify-right"
        onTriggered: document.alignment = Qt.AlignRight
        checkable: true
        checked: document.alignment == Qt.AlignRight
    }
    Action {
        id: alignJustifyAction
        text: "&Justify"
        iconSource: "images/textjustify.png"
        iconName: "format-justify-fill"
        onTriggered: document.alignment = Qt.AlignJustify
        checkable: true
        checked: document.alignment == Qt.AlignJustify
    }
    Action {
        id: boldAction
        text: "&Bold"
        iconSource: "images/textbold.png"
        iconName: "format-text-bold"
        onTriggered: document.bold = !document.bold
        checkable: true
        checked: document.bold
    }
    Action {
        id: italicAction
        text: "&Italic"
        iconSource: "images/textitalic.png"
        iconName: "format-text-italic"
        onTriggered: document.italic = !document.italic
        checkable: true
        checked: document.italic
    }
    Action {
        id: underlineAction
        text: "&Underline"
        iconSource: "images/textunder.png"
        iconName: "format-text-underline"
        onTriggered: document.underline = !document.underline
        checkable: true
        checked: document.underline
    }
    Action {
        id: fileCreateAction
        iconSource: "images/fileopen.png"
        iconName: "document-open"
        text: "Create"
        onTriggered: {
            soundFileDialog.open()
        }
    }
    Action {
        id: fileOpenAction
        iconSource: "images/fileopen.png"
        iconName: "document-open"
        text: "Open"
        onTriggered: {
            fileDialog.selectExisting = true
            fileDialog.open()
        }
    }
    Action {
        id: fileSaveAsAction
        iconSource: "images/filesave.png"
        iconName: "document-save"
        text: "Save As…"
        onTriggered: {
            fileDialog.selectExisting = false
            fileDialog.open()
        }
    }

    FileDialog {
        id: fileDialog
        nameFilters: ["Bind file (*.bnd)"]
        onAccepted: {
            if (fileDialog.selectExisting)
                uiControler.openBindFile(fileUrl)
            else
                uiControler.saveBindFile(fileUrl)
        }
    }
    FileDialog {
        id: soundFileDialog
        nameFilters: ["Sound File (*.wav)"]
        selectExisting : true
        onAccepted: {
            uiControler.createBindFile(fileUrl)
        }
    }
    ColorDialog {
        id: colorDialog
        color: "black"
    }

    menuBar: MenuBar {
        Menu {
            title: "&File"
            MenuItem { action: fileCreateAction}
            MenuItem { action: fileOpenAction }
            MenuItem { action: fileSaveAsAction }
            MenuItem { text: "Quit"; onTriggered: Qt.quit() }
        }
        Menu {
            title: "&Edit"
            MenuItem { action: copyAction }
            MenuItem { action: cutAction }
            MenuItem { action: pasteAction }
        }
        Menu {
            title: "F&ormat"
            MenuItem { action: boldAction }
            MenuItem { action: italicAction }
            MenuItem { action: underlineAction }
            MenuSeparator {}
            MenuItem { action: alignLeftAction }
            MenuItem { action: alignCenterAction }
            MenuItem { action: alignRightAction }
            MenuItem { action: alignJustifyAction }
            MenuSeparator {}
            MenuItem {
                text: "&Color ..."
                onTriggered: {
                    //colorDialog.color = document.textColor
                    colorDialog.open()
                }
            }
        }
        Menu {
            title: "&Help"
            MenuItem { text: "About..." ; onTriggered: aboutBox.open() }
        }
    }

    toolBar: ToolBar {
        id: mainToolBar
        width: parent.width// - videoRect.width
        //anchors.right: videoRect.left

        RowLayout {
            anchors.fill: parent
            spacing: 0
            ToolButton { action: fileOpenAction }
            QMLToolBarSeparator {}
            ToolButton { action: copyAction }
            ToolButton { action: cutAction }
            ToolButton { action: pasteAction }
            QMLToolBarSeparator {}
            ToolButton { action: boldAction }
            ToolButton { action: italicAction }
            ToolButton { action: underlineAction }
            QMLToolBarSeparator {}
            ToolButton { action: alignLeftAction }
            ToolButton { action: alignCenterAction }
            ToolButton { action: alignRightAction }
            ToolButton { action: alignJustifyAction }
            QMLToolBarSeparator {}
            ToolButton {
                id: colorButton
                property var color : document.textColor
                Rectangle {
                    id: colorRect
                    anchors.fill: parent
                    anchors.margins: 8
                    color: Qt.darker(document.textColor, colorButton.pressed ? 1.4 : 1)
                    border.width: 1
                    border.color: Qt.darker(colorRect.color, 2)
                }
                onClicked: {
                    //colorDialog.color = document.textColor
                    colorDialog.open()
                }
            }
            ComboBox {
                id: fontFamilyComboBox
                implicitWidth: 150
                model: Qt.fontFamilies()
                property bool special : false
                onActivated: {
                    if (special == false || index != 0) {
                        document.fontFamily = textAt(index)
                    }
                }
            }
            SpinBox {
                id: fontSizeSpinBox
                activeFocusOnPress: false
                implicitWidth: 50
                value: 0
                property bool valueGuard: true
                onValueChanged: if (valueGuard) document.fontSize = value
            }

            Item { Layout.fillWidth: true }
        }
    }

    Rectangle{
        id : videoRect
        anchors.top : parent.top;
        anchors.bottom: soundToolBar.top;
        //anchors.right : soundToolBar.right
        x : (parent.width - width) / 2
        //y : 0
        width: 640
        height: 480
        color: "black"
        VideoOutput {
           anchors.fill: parent;
        //   width: 800;
        //   height: 600
           source: soundStore
       }
       MouseArea
       {
            anchors.fill: parent
            onClicked: {
                soundStore.play()
            }
       }
    }

    Rectangle{
        id : soundToolBar
        anchors.top: videoRect.bottom
        //anchors.bottom: parent.bottom
        width: parent.width
        //anchors.fill: parent
        height: 50

        QMLSoundGraph {
            id : soundPanel
            anchors.fill: parent
            Action {
                id: bindAction
                text: "Bind"
                shortcut: "ctrl+B"
                iconSource: "images/bind.png"
                iconName: "Bind "
                onTriggered: uiControler.makeBind()
            }
            Action {
                id: playAction
                text: "Play"
                shortcut: "Ctrl+P"
                iconSource: "images/play.png"
                iconName: "Play"
                onTriggered: {
                    soundStore.start();
                }
            }
            Action {
                id: pauseAction
                text: "Pause"
                shortcut: "ctrl+O"
                iconSource: "qrc:images/stop.png"
                iconName: "Pause"
                onTriggered: soundStore.stop()
            }

            ToolBar
            {
                anchors.fill: parent
                RowLayout {
                    spacing: 0
                    ToolButton { action: bindAction }
                    ToolButton { action: playAction }
                    ToolButton { action: pauseAction }
                    Item { Layout.fillWidth: true }
                }

            }


        }

        Rectangle {
            x : 130
            y : 200
            //anchors.top: videoRect.
            anchors.bottom:  soundToolBar.bottom
            //anchors.right: parent.right
            id: soundGraph
            height: soundToolBar.height
            width: soundToolBar.width - x - 20
            color : "transparent"
            Slider {
                id: soundSlider
                anchors.left: parent.left
                anchors.right: parent.right
                height: soundToolBar.height
                value: soundStore.position
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
                onValueChanged:
                {
                    if (!pressed)
                        uiControler.setCursorPosInTimePos();
                }

                onPressedChanged:
                {
                    if (pressed)
                        soundStore.setPosPersent(soundSlider.value);
                }
            }
        }

    }

    TextStore {
        id: document
        target: textArea
        cursorPosition: textArea.cursorPosition
        selectionStart: textArea.selectionStart
        selectionEnd: textArea.selectionEnd
        textColor: colorDialog.color
        //Component.onCompleted: document.fileUrl = "qrc:/example.html"
        onFontSizeChanged: {
            fontSizeSpinBox.valueGuard = false
            fontSizeSpinBox.value = document.fontSize
            fontSizeSpinBox.valueGuard = true
        }
        onFontFamilyChanged: {
            var index = Qt.fontFamilies().indexOf(document.fontFamily)
            if (index == -1) {
                fontFamilyComboBox.currentIndex = 0
                fontFamilyComboBox.special = true
            } else {
                fontFamilyComboBox.currentIndex = index
                fontFamilyComboBox.special = false
            }
        }
        onError: {
            errorDialog.text = message
            errorDialog.visible = true
        }
    }

    TextArea {
        width: parent.width
        anchors.top: soundToolBar.bottom
        anchors.bottom: parent.bottom
        Accessible.name: "document"
        id: textArea
        frameVisible: false
        baseUrl: "qrc:/"
        text: document.text
        textFormat: Qt.RichText
        Component.onCompleted: forceActiveFocus()
    }

    Menu {
        id : contextMenue
        title: "Edit"

        MenuItem {
            text: "Translate"
            action: translateAction
        }
       // MenuSeparator { }
        MenuItem {
            text: "Cut"
            action: cutAction
        }
        MenuItem {
            text: "Copy"
            action: copyAction
        }
        MenuItem {
            text: "Paste"
            action: pasteAction // ТУТ ГЛЮК!!
        }
    }
    MouseArea{
        acceptedButtons: Qt.RightButton
        anchors.fill: textArea
        cursorShape: Qt.IBeamCursor
        onClicked: {
            if (mouse.button == Qt.RightButton)
                contextMenue.popup();
        }
        onReleased: {
             if (!propagateComposedEvents) {
                propagateComposedEvents = true
             }
        }
    }

    SimpleDialog
    {
        id: translateDialog
        contentText: qsTr("Translate")
        onBack: hideDialog()
    }
    MessageDialog {
        id: errorDialog
    }

    SoundStore{
        id: soundStore
    }

}
