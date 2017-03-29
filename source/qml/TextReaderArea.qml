import QtQuick 2.8
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
    baseUrl: "qrc:/"
    leftPadding: 6
    rightPadding: 6
    topPadding: 0
    bottomPadding: 0
    background: null
    readOnly: true
    mouseSelectionMode : TextInput.SelectWords

    text: document.text

    property int cynhTopPading : 45
    property int cynhBottpmPading : 55

    function syncSoundAndSliderPosition()
    {
        if (homePage.homeUiControler.dontSynch)
            return;
        var mid = uiControler.getMidMarkable();
        var begin = uiControler.getBeginMarkable();
        var end = uiControler.getEndMarkable();
        var midY = positionToRectangle(mid).y;
        var beginY = positionToRectangle(begin).y;
        var endY = positionToRectangle(end).y;

        var thisYBegin = homePage.textArea.getCurY();
        var thisHeight = homePage.textArea.getCurHeigth();
        var thisYEnd = thisYBegin + thisHeight - cynhBottpmPading;

        if (endY - beginY > thisHeight - cynhTopPading)
            homePage.textArea.setCurY(beginY - cynhTopPading)
        else
        {
            if (beginY < thisYBegin)
                homePage.textArea.setCurY(beginY - cynhTopPading)
            if (endY > thisYEnd)
                homePage.textArea.setCurY(endY - thisHeight + cynhBottpmPading)
        }
        //uiControler.markCurText()
    }


    MouseArea {
        acceptedButtons: Qt.RightButton
        anchors.fill: parent
        propagateComposedEvents: true
        onClicked: {
            if (selectedText.length == 0)
            {
                var textPos = root.positionAt(mouseX, mouseY)
                document.setSelectionByWord(textPos)
            }
            contextMenue.open()
        }
    }

    onLinkActivated: Qt.openUrlExternally(link)
    Menu {
        id : contextMenue
        MenuItem {
            text: "Translate"
            onTriggered: {
                var translateUrl = uiControler.formUrlToTranslateSellected();
                translateDialog.setUrl(translateUrl)
                translateDialog.showDialog()
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

        ColorDialog {
            id: colorDialog
            color: homePage.homeDocument.markColor
            onAccepted: {
                document.setTextColor(color)
            }
        }
    }
}

