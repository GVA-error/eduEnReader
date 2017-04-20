import QtQuick 2.8
import QtQml 2.2
import QtWebEngine 1.4

import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import Qt.labs.platform 1.0

import TextStoreModul 1.0
import UiControlerModul 1.1


TextArea {
    id: root
    Accessible.name: "document"
    //visible: homePage.curRightList == 1
    textFormat: Qt.RichText
    wrapMode: TextArea.Wrap
    focus: true
    selectByMouse: true
    persistentSelection: true
    //baseUrl: "qrc:/"
    leftPadding: 6
    rightPadding: 6
    topPadding: 0
    bottomPadding: 0
    background: null
    readOnly: true
    mouseSelectionMode : TextInput.SelectWords

    Component.onCompleted: contentItem.interactive = false

    text: document.text

    property int cynhTopPading : 45
    property int cynhBottpmPading : 55
    property int lastMidY : 0 // нужно чтобы уменьшить частоту синхронизации
    property int minDY : 1 // и это тоже
    property bool mouseLeftPresed: mouseArea.pressed

    // f_pushSynch - синхронизировать независимо от lastMidY
    function syncSoundAndSliderPosition(f_pushSynch)
    {
        if (homePage.homeUiControler.dontSynch || homePage.homeSoundStore.isExample)
            return;

        var mid = uiControler.getMidMarkable();
        var midY = positionToRectangle(mid).y;
        if (Math.abs(lastMidY - midY) < minDY && f_pushSynch === false)
            return;
        lastMidY = midY;
        if (midY < 0)
            midY = 0;

        var begin = uiControler.getBeginMarkable();
        var end = uiControler.getEndMarkable();
        var beginY = positionToRectangle(begin).y;
        var endY = positionToRectangle(end).y;

        var thisYBegin = homePage.textArea.getCurY();
        var thisHeight = homePage.textArea.getCurHeigth();
        var thisYEnd = thisYBegin + thisHeight - cynhBottpmPading;

        if (endY - beginY >= thisHeight - cynhTopPading)
            homePage.textArea.setCurY(beginY - cynhTopPading)
        else
        {
            if (beginY <= thisYBegin)
                homePage.textArea.setCurY(beginY - cynhTopPading)
            if (endY > thisYEnd && endY - thisHeight + cynhBottpmPading > thisYBegin)
                homePage.textArea.setCurY(endY - thisHeight + cynhBottpmPading)
        }
        uiControler.markCurText()
    }
    onCursorPositionChanged: {
//        if (mouseLeftPresed)
//        {
//            uiControler.setTimePosInCursorPos();
//        }
    }

    MouseArea{
        acceptedButtons: Qt.LeftButton
        anchors.fill: parent
        id : mouseArea
        Component.onCompleted: contentItem.interactive = false
        onPressed: {
          //  console.log("CLICKED")
            var clickedTextPos = positionAt(mouseX, mouseY)
            document.setCursorPosition(clickedTextPos);
            uiControler.setTimePosInCursorPos()
            mouse.accepted = false
        }
    }

    MouseArea {
        Component.onCompleted: contentItem.interactive = false
        acceptedButtons: Qt.RightButton
        anchors.fill: root
        propagateComposedEvents: true
        onClicked: {
            if (selectedText.length == 0)
            {
                var textPos = root.positionAt(mouseX, mouseY)
                document.setSelectionByWord(textPos)
            }
            translitionHelpPage.phrase = document.getSellectedStreing();
            contextMenue.open()
        }
    }

    onLinkActivated: Qt.openUrlExternally(link)
    Menu {
        id : contextMenue
        MenuItem {
            text: "Translation/Synonyms"
            onTriggered: {
                //var translateUrl = uiControler.formUrlToTranslateSellected();
                //translateDialog.setUrl(translateUrl)
                //translateDialog.showDialog()
                goTranslitionHelp()
            }
        }
        MenuItem {
            text: "Example"
            onTriggered: {
                //uiControler.getExample()
                mainToolBar.setExampleText(document.getSellectedStreing())
                showExamples();
            }
        }
/*
        MenuSeparator {
            visible: recentFilesModel.count > 0
        }
*/
        Instantiator {
                model: homePage.homeUiControler.matirealsListModel
                MenuItem {
                    text: modelData
                    onTriggered: {
                        translitionHelpPage.setSource(text);
                        goTranslitionHelp()
                    }
                }
                onObjectAdded: contextMenue.insertItem(2+index, object)
                onObjectRemoved: contextMenue.removeItem(object)
        }


//        MenuItem {
//            text: "Set color"
//            onTriggered: {
//                colorDialog.open()
//            }
//        }

//        MenuItem {
//            text: "Add comment"
//            onTriggered: {
//                commentFileDialog.open()
//            }
//        }

        FileDialog {
            id: commentFileDialog
            fileMode: FileDialog.OpenFile
            selectedNameFilter.index: 1
            nameFilters : ["Bind file (*.html)"]
            folder: appPath
            property int number: 100
            onAccepted : {
                homePage.homeUiControler.addComment(file, "comment_" + number.toString())
                number += 1
            }
        }
/*
        ColorDialog {
            id: colorDialog
            color: homePage.homeDocument.markColor
            onAccepted: {
                document.setTextColor(color)
            }
        }*/
    }
}

