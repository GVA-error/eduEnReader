import QtQuick 2.8

import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2

import TextStoreModul 1.0
Rectangle {
    id: root
    signal ok()
   // property string text: tmpTextArea.text
    ToolBar{
        id : toolBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 50
        ColorDialog {
            id: colorDialog
            currentColor: "black"
        }
        FontDialog {
            id: fontDialog
            onAccepted: {
                tmpDocument.fontFamily = font.family;
                tmpDocument.fontSize = font.pointSize;
            }
        }
        RowLayout {
           anchors.fill: parent
           Row {
               id: editRow
               ToolButton {
                   id: copyButton
                   text: "\uF0C5" // icon-docs
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   enabled: tmpTextArea.selectedText
                   onClicked: tmpTextArea.copy()
               }
               ToolButton {
                   id: cutButton
                   text: "\uE802" // icon-scissors
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   enabled: tmpTextArea.selectedText
                   onClicked: tmpTextArea.cut()
               }
               ToolButton {
                   id: pasteButton
                   text: "\uF0EA" // icon-paste
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   enabled: tmpTextArea.canPaste
                   onClicked: tmpTextArea.paste()
               }
               ToolSeparator {
                   contentItem.visible: true
               }
               ToolButton {
                   id: boldButton
                   text: "\uE800" // icon-bold
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   checkable: true
                   checked: tmpDocument.bold
                   onClicked: tmpDocument.bold = !tmpDocument.bold
               }
               ToolButton {
                   id: italicButton
                   text: "\uE801" // icon-italic
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   checkable: true
                   checked: tmpDocument.italic
                   onClicked: tmpDocument.italic = !tmpDocument.italic
               }
               ToolButton {
                   id: underlineButton
                   text: "\uF0CD" // icon-underline
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   checkable: true
                   checked: tmpDocument.underline
                   onClicked: tmpDocument.underline = !tmpDocument.underline
               }
               ToolButton {
                   id: fontFamilyToolButton
                   text: qsTr("\uE808") // icon-font
                   font.family: "fontello"
                   font.bold: tmpDocument.bold
                   font.italic: tmpDocument.italic
                   font.underline: tmpDocument.underline
                   onClicked: {
                       fontDialog.currentFont.family = tmpDocument.fontFamily;
                       fontDialog.currentFont.pointSize = tmpDocument.fontSize;
                       fontDialog.open();
                   }
               }
               ToolButton {
                   id: textColorButton
                   text: "\uF1FC" // icon-brush
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   onClicked: colorDialog.open()

                   Rectangle {
                       width: aFontMetrics.width + 3
                       height: 2
                       color: tmpDocument.textColor
                       parent: textColorButton.contentItem
                       anchors.horizontalCenter: parent.horizontalCenter
                       anchors.baseline: parent.baseline
                       anchors.baselineOffset: 6

                       TextMetrics {
                           id: aFontMetrics
                           font: textColorButton.font
                           text: textColorButton.text
                       }
                   }
               }
               ToolSeparator {
                   contentItem.visible: true
               }
               ToolButton {
                   id: alignLeftButton
                   text: "\uE803" // icon-align-left
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   checkable: true
                   checked: tmpDocument.alignment == Qt.AlignLeft
                   onClicked: tmpDocument.alignment = Qt.AlignLeft
               }
               ToolButton {
                   id: alignCenterButton
                   text: "\uE804" // icon-align-center
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   checkable: true
                   checked: tmpDocument.alignment == Qt.AlignHCenter
                   onClicked: tmpDocument.alignment = Qt.AlignHCenter
               }
               ToolButton {
                   id: alignRightButton
                   text: "\uE805" // icon-align-right
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   checkable: true
                   checked: tmpDocument.alignment == Qt.AlignRight
                   onClicked: tmpDocument.alignment = Qt.AlignRight
               }
               ToolButton {
                   id: alignJustifyButton
                   text: "\uE806" // icon-align-justify
                   font.family: "fontello"
                   focusPolicy: Qt.TabFocus
                   checkable: true
                   checked: tmpDocument.alignment == Qt.AlignJustify
                   onClicked: tmpDocument.alignment = Qt.AlignJustify
               }
               ToolSeparator {
                   contentItem.visible: true
                   Layout.fillWidth: true
               }
           }
           ToolButton {
               id: saveAndExitButton
               text: "ok" // icon-align-justify
               font.family: "fontello"
               focusPolicy: Qt.TabFocus
               onClicked: ok()
            }
       }
    }
    TextStore{
        id : tmpDocument
        target: tmpTextArea
        cursorPosition: tmpTextArea.cursorPosition
        selectionStart: tmpTextArea.selectionStart
        selectionEnd: tmpTextArea.selectionEnd
        //text: root.text
        textColor: colorDialog.color
        onError: {
            errorDialog.text = message
            errorDialog.visible = true
        }
    }
    Flickable {
        id: flickableTextArea
        anchors.top: toolBar.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        Component.onCompleted: contentItem.interactive = false
        flickableDirection: Flickable.VerticalFlick
        TextArea.flickable: TextArea{
            id : tmpTextArea
            text : tmpDocument.text
            readOnly: false
            leftPadding: 10
            rightPadding: 10
            topPadding: 10
            bottomPadding: 10
            selectByMouse: true
            persistentSelection: true
            background: null
            textFormat: Qt.RichText
            wrapMode: TextArea.Wrap
            Accessible.name: "tmp_document"
            Component.onCompleted: contentItem.interactive = false
            onVisibleChanged: {
                if (visible == true)
                    focus = true
            }
        }
        ScrollBar.vertical: ScrollBar {
            width: 20
        }
        Behavior on contentY {
                 NumberAnimation {
                     duration: 600
                 }
        }
    }
    MessageDialog {
        id: errorDialog
    }
    function setDocumentText(newText){
        tmpDocument.text = newText
    }
    function getDocumentText(){
        return tmpTextArea.text
    }
    function openFile(fileName){
        tmpDocument.setFileUrl(fileName)
        tmpTextArea.cursorPosition = 0 // TODO кастыль от глюка с позиционированием в камментах
    }
    function save(){
        tmpDocument.save()
    }
}
