import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1
import QtQuick.Window 2.1
import TextStoreModul 1.0
import UiControlerModul 1.0

ApplicationWindow {

    visible: true
    width: 1024
    height: 768

    title: document.documentTitle + " - Text Editor Example"

    UiControler{
        id: uiControler
        oldXSoundPos: 0
        mouseIsPressed: false
        document : document
        // переместить сюда сaунд как документ
        onOldXSoundPosChanged:
        {
             selectRect.x = oldXSoundPos;
        }
        onNewXSoundPosChanged:
        {
            selectRect.width = Math.abs(oldXSoundPos-newXSoundPos);
        }
    }
    MessageDialog {
        id: aboutBox
        title: "About Text"
        text: "This is a basic text editor \nwritten with Qt Quick Controls"
        icon: StandardIcon.Information
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
    FileDialog {
        id: fileDialog
        nameFilters: ["Text files (*.txt)", "HTML files (*.html, *.htm)"]
        onAccepted: {
            if (fileDialog.selectExisting)
                document.fileUrl = fileUrl
            else
                document.saveAs(fileUrl, selectedNameFilter)
        }
    }
    ColorDialog {
        id: colorDialog
        color: "black"
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

    menuBar: MenuBar {
        Menu {
            title: "&File"
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
                    colorDialog.color = document.textColor
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
        width: parent.width
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
                    colorDialog.color = document.textColor
                    colorDialog.open()
                }
            }
            Item { Layout.fillWidth: true }
        }
    }

    ToolBar {
        id: secondaryToolBar
        width: parent.width

        RowLayout {
            anchors.fill: parent
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
        anchors.top: secondaryToolBar.bottom
        anchors.bottom: parent.bottom
        width: parent.width

        radius: 10

        QMLSoundGraph {
            id : soundPanel
            width: parent.width
            height: parent.height/10


            Action {
                id: playAction
                text: "Play"
                shortcut: "ctrl+p"
                iconSource: "images/editcut.png"
                iconName: "edit-cut"
                onTriggered: textArea.cut()
            }

            Action {
                id: bindAction
                text: "Bind"
                shortcut: "Ctrl+C"
                iconSource: "images/editcopy.png"
                iconName: "edit-copy"
                onTriggered: uiControler.makeBind();
            }

            Action {
                id: openAction
                text: "Open"
                shortcut: "ctrl+v"
                iconSource: "qrc:images/editpaste.png"
                iconName: "edit-paste"
                onTriggered: textArea.paste()
            }

            ToolBar
            {
                id : soundToolBar
                width: 150

                RowLayout {
                    spacing: 0

                    ToolButton { action: playAction }
                    ToolButton { action: bindAction }
                    ToolButton { action: openAction }

                    Item { Layout.fillWidth: true }
                }

            }


            Rectangle {
                anchors.left: soundToolBar.right
                anchors.right: parent.right
                id: soundGraph
                height: soundToolBar.height
                color: "blue"

                radius: 10

                Rectangle{
                    id : selectRect
                    x: 0
                    y: 0
                    width: 3
                    height: soundGraph.height
                    color: "red"
                    opacity : 0.5
                }

                MouseArea {
                    anchors.fill: parent
                    onReleased: {
                        uiControler.mouseIsPressed = false;
                        var oldPos, newPos;
                        if (selectRect.x === uiControler.oldXSoundPos)
                        {
                            oldPos = selectRect.x;
                            newPos = selectRect.x + selectRect.width;
                        }
                        else
                        {
                            oldPos = uiControler.oldXSoundPos - selectRect.width;
                            newPos = uiControler.oldXSoundPos;
                        }
                        uiControler.oldXSoundPos = oldPos;
                        uiControler.newXSoundPos = newPos;
                    }
                    onMouseXChanged:{
                        if (!uiControler.mouseIsPressed)
                            return;
                        var x = mouseX;
                        var w = x - uiControler.oldXSoundPos;
                        if (w < 0)
                        {
                            w = Math.abs(w);
                            selectRect.x = uiControler.oldXSoundPos - w;
                            if (selectRect.x < 0)
                                selectRect.x = 0;
                        }
                        if (w < 5)
                            w = 3;
                       // selectRect.width = w;
                        //uiControler.oldXSoundPos = selectRect.x;
                        selectRect.width = w;
                    }

                    onPressed:{
                        var x = mouseX;
                        selectRect.x = x;
                        uiControler.oldXSoundPos = x;
                        uiControler.mouseIsPressed = true;
                    }
                }
            }
        }
        TextArea {
            width: parent.width
            anchors.top: soundPanel.bottom
            anchors.bottom: parent.bottom
            Accessible.name: "document"
            id: textArea
            frameVisible: false
            baseUrl: "qrc:/"
            text: document.text
            textFormat: Qt.RichText
            Component.onCompleted: forceActiveFocus()
        }

    }

    MessageDialog {
        id: errorDialog
    }

    TextStore {
        id: document
        target: textArea
        cursorPosition: textArea.cursorPosition
        selectionStart: textArea.selectionStart
        selectionEnd: textArea.selectionEnd
        textColor: colorDialog.color
        Component.onCompleted: document.fileUrl = "qrc:/example.html"
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

}

