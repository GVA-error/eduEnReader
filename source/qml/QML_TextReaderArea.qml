import QtQuick 2.8
import QtQml 2.2
import QtWebEngine 1.4

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import TextStoreModul 1.0
import UiControllerModul 1.1
Flickable {
    id: frickableRoot

    property int cynhTopPading : 45
    property int cynhBottpmPading : 55
    property int lastMidY : 0 // нужно чтобы уменьшить частоту синхронизации
    property int minDY : 1 // и это тоже
    property bool mouseLeftPresed: mouseArea.pressed
    property var textArea: frickableTextArea
    property var sourceDocument
    property var uiController
    property var contextMenue
    property bool allowSellectOnlyWord: true

    Behavior on contentY {
         NumberAnimation {
             duration: 600
         }
     }

    flickableDirection: Flickable.VerticalFlick
    TextArea.flickable: TextArea {
        id: frickableTextArea
        Accessible.name: "document"
        //visible: homePage.curRightList == 1
        textFormat: Qt.RichText
        text: sourceDocument.text
        wrapMode: TextArea.Wrap
        focus: true
        selectByMouse: true
        selectByKeyboard: true
        persistentSelection: true
        onSelectionStartChanged: {
            sourceDocument.setSelectionStart(selectionStart);
        }
        onSelectionEndChanged: {
            sourceDocument.setSelectionEnd(selectionEnd);
        }

        //baseUrl: "qrc:/"
        leftPadding: 10
        rightPadding: 10
        topPadding: 0
        bottomPadding: 0
        background: null
        readOnly: true
        mouseSelectionMode : TextInput.SelectWords

        // Обеспечивают правку биндов
        property bool bindEditingEnd: false
        property bool bindEditingBegin: false
       // property int lastMouseX : 0
       // property int lastMouseY : 0
        onBaseUrlChanged: {
            frickableRoot.setCurY(0)
        }

        function undoBindEditing()
        {
            stopBindEditingAll()
        }
        function stopBindEditingAll(){
            bindEditingEnd = false
            bindEditingBegin = false
            var defaultColor = sourceDocument.getDefaultMarkColor()
            sourceDocument.setMarkCalor(defaultColor)
            uiController.markCurText()
        }
        function stopBindEdting(){
            var textPos = positionAt(mouseArea.mouseX, mouseArea.mouseY);
            uiController.unmarkLastText()
            if (bindEditingEnd)
                uiController.setCurBindEnd(textPos)
            if (bindEditingBegin)
                uiController.setCurBindBegin(textPos)
            stopBindEditingAll()
        }
        function startBindEdtingEnd(){
            bindEditingEnd = true
            setTmpMartColor()
        }
        function startBindEdtingBegin(){
            bindEditingBegin = true
            setTmpMartColor()
        }
        function setTmpMartColor()
        {
            sourceDocument.setMarkCalor("skyblue")
            uiController.markCurText()
        }

        // f_pushSynch - синхронизировать независимо от lastMidY
        function syncSoundAndSliderPosition(f_pushSynch)
        {
            if (uiController.dontSynch || uiController.isExample)
                return;

            var mid = uiController.getMidMarkable();
            var midY = positionToRectangle(mid).y;
            if (Math.abs(lastMidY - midY) < minDY && f_pushSynch === false)
                return;
            lastMidY = midY;
            if (midY < 0)
                midY = 0;

            var begin = uiController.getBeginMarkable();
            var end = uiController.getEndMarkable();
            var beginY = positionToRectangle(begin).y;
            var endY = positionToRectangle(end).y;

            var thisYBegin = frickableRoot.getCurY();
            var thisHeight = frickableRoot.getCurHeigth();
            var thisYEnd = thisYBegin + thisHeight - cynhBottpmPading;

            if (endY - beginY >= thisHeight - cynhTopPading)
                frickableRoot.setCurY(beginY - cynhTopPading)
            else
            {
                if (beginY <= thisYBegin)
                    frickableRoot.setCurY(beginY - cynhTopPading)
                if (endY > thisYEnd && endY - thisHeight + cynhBottpmPading > thisYBegin)
                    frickableRoot.setCurY(endY - thisHeight + cynhBottpmPading)
            }
            uiController.markCurText()
        }
        function sellectCurWord(){
            var curPos = textArea.positionAt(mouseArea.mouseX, mouseArea.mouseY)
            sourceDocument.setSelectionByWord(curPos)
        }

        onCursorPositionChanged: {
    //        if (mouseLeftPresed)
    //        {
    //            uiControler.setTimePosInCursorPos();
    //        }
        }

        MouseArea{
            acceptedButtons: Qt.LeftButton
            anchors.fill: frickableTextArea
            id : mouseArea
            Component.onCompleted: contentItem.interactive = false
            onPressed: {
                if (frickableTextArea.bindEditingBegin || frickableTextArea.bindEditingEnd)
                    frickableTextArea.stopBindEdting()

                var clickedTextPos = frickableTextArea.positionAt(mouseX, mouseY)
                sourceDocument.setCursorPosition(clickedTextPos);
                uiController.setTimePosInCursorPos()
                mouse.accepted = false
            }
        }

        MouseArea {
            //Component.onCompleted: contentItem.interactive = false
            acceptedButtons: Qt.RightButton
            anchors.fill: frickableTextArea
            propagateComposedEvents: true
            onClicked: {
                frickableTextArea.undoBindEditing()
                var selectedText;
                if (frickableTextArea.selectedText.length === 0 && allowSellectOnlyWord)
                {
                    var textPos = frickableTextArea.positionAt(mouseX, mouseY)
                    sourceDocument.setSelectionByWord(textPos)
                    selectedText = sourceDocument.getSellectedStreing()
                }
                else
                    selectedText = frickableTextArea.selectedText
                homeUiController.getMatirealsFor(selectedText);
                contextMenue.open()
            }
        }
        onLinkActivated: Qt.openUrlExternally(link)
    }
    ScrollBar.vertical: ScrollBar{
        width: 20
    }
    function synch(f_pushSynch) { frickableTextArea.syncSoundAndSliderPosition(f_pushSynch) }
    function getCurY() { return contentY }
    function setCurY(newY) {
        contentY = newY
    }
    function getCurHeigth() { return height }
}
