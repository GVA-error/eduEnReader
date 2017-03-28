import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

// Верхнее меню для пк
MenuBar {
    id: root
        Menu {
            title: "&File"
            MenuItem {
                onTriggered: soundFileDialog.open()
                text: "Create"
            }
//            MenuItem { action: fileOpenAction }
//            MenuItem { action: fileSaveAsAction }
            MenuItem { text: "Quit"; onTriggered: Qt.quit() }
        }
        Menu {
            title: "&Edit"
//            MenuItem { action: copyAction }
//            MenuItem { action: cutAction }
//            MenuItem { action: pasteAction }
        }
        Menu {
            title: "F&ormat"
//            MenuItem { action: boldAction }
//            MenuItem { action: italicAction }
//            MenuItem { action: underlineAction }
//            MenuSeparator {}
//            MenuItem { action: alignLeftAction }
//            MenuItem { action: alignCenterAction }
//            MenuItem { action: alignRightAction }
//            MenuItem { action: alignJustifyAction }
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





//    Action{
//        id: translateAction
//        text: "Translate"
//        shortcut: "ctrl+t"
//        iconSource: "images/editcut.png" // TODO придумать иконку
//        iconName: "edit-cut"
//        onTriggered: {
//            var translateUrl = uiControler.formUrlToTranslateSellected();
//            var loadScript = "document.body.children[0].children[6].outerHTML";
//            translateDialog.postLoadScript = loadScript
//            //translateDialog.runScript(loadScript)
//            translateDialog.setUrl(translateUrl)
//            translateDialog.showDialog()
//            /*
//                    .children[\"0\"].children[\"0\"].children[1]
//                    .children[\"0\"].children[\"0\"].children[\"0\"]
//                    .children[\"0\"].children[\"0\"].children[\"0\"]
//                    .children[1].children[\"0\"].children[\"0\"]
//                    .children[\"0\"].children[\"0\"].children[1]
//                    .innerHTML"*/
//        }
//    }
//    Action{
//        id: commentAddAction
//        text: "Translate"
//        shortcut: "ctrl+k"
//        iconSource: "images/editcut.png" // TODO придумать иконку
//        iconName: "edit-cut"
//        onTriggered: {
//            commentFileDialog.open()

//        }
//    }
//    Action{
//        id: exampleAction
//        text: "Example"
//        shortcut: "ctrl+e"
//        iconSource: "images/editcut.png" // TODO придумать иконку
//        iconName: "edit-cut"
//        onTriggered: { var translateUrl = uiControler.getExample() }
//    }
//    Action {
//        id: cutAction
//        text: "Cut"
//        shortcut: "ctrl+x"
//        iconSource: "images/editcut.png"
//        iconName: "edit-cut"
//        onTriggered: textArea.cut()
//    }
//    Action {
//        id: copyAction
//        text: "Copy"
//        shortcut: "Ctrl+C"
//        iconSource: "images/editcopy.png"
//        iconName: "edit-copy"
//        onTriggered: textArea.copy()
//    }
//    Action {
//        id: pasteAction
//        text: "Paste"
//        shortcut: "ctrl+v"
//        iconSource: "qrc:images/editpaste.png"
//        iconName: "edit-paste"
//        onTriggered: textArea.paste()
//    }
//    Action {
//        id: alignLeftAction
//        text: "&Left"
//        iconSource: "images/textleft.png"
//        iconName: "format-justify-left"
//        shortcut: "ctrl+l"
//        onTriggered: document.alignment = Qt.AlignLeft
//        checkable: true
//        checked: document.alignment == Qt.AlignLeft
//    }
//    Action {
//        id: alignCenterAction
//        text: "C&enter"
//        iconSource: "images/textcenter.png"
//        iconName: "format-justify-center"
//        onTriggered: document.alignment = Qt.AlignHCenter
//        checkable: true
//        checked: document.alignment == Qt.AlignHCenter
//    }
//    Action {
//        id: alignRightAction
//        text: "&Right"
//        iconSource: "images/textright.png"
//        iconName: "format-justify-right"
//        onTriggered: document.alignment = Qt.AlignRight
//        checkable: true
//        checked: document.alignment == Qt.AlignRight
//    }
//    Action {
//        id: alignJustifyAction
//        text: "&Justify"
//        iconSource: "images/textjustify.png"
//        iconName: "format-justify-fill"
//        onTriggered: document.alignment = Qt.AlignJustify
//        checkable: true
//        checked: document.alignment == Qt.AlignJustify
//    }
//    Action {
//        id: boldAction
//        text: "&Bold"
//        iconSource: "images/textbold.png"
//        iconName: "format-text-bold"
//        onTriggered: document.bold = !document.bold
//        checkable: true
//        checked: document.bold
//    }
//    Action {
//        id: italicAction
//        text: "&Italic"
//        iconSource: "images/textitalic.png"
//        iconName: "format-text-italic"
//        onTriggered: document.italic = !document.italic
//        checkable: true
//        checked: document.italic
//    }
//    Action {
//        id: underlineAction
//        text: "&Underline"
//        iconSource: "images/textunder.png"
//        iconName: "format-text-underline"
//        onTriggered: document.underline = !document.underline
//        checkable: true
//        checked: document.underline
//    }
//    Action {
//        id: fileCreateAction
//        iconSource: "images/fileopen.png"
//        iconName: "document-open"
//        text: "Create"
//        onTriggered: {
//            soundFileDialog.open()
//        }
//    }
//    Action {
//        id: fileOpenAction
//        iconSource: "images/fileopen.png"
//        iconName: "document-open"
//        text: "Open"
//        onTriggered: {
//            fileDialog.selectExisting = true
//            fileDialog.open()
//        }
//    }
//    Action {
//        id: fileSaveAsAction
//        iconSource: "images/filesave.png"
//        iconName: "document-save"
//        text: "Save As…"
//        onTriggered: {
//            fileDialog.selectExisting = false
//            fileDialog.open()
//        }
//    }

}
