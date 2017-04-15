import QtQuick 2.8

import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtWebEngine 1.4

import UiControlerModul 1.1

Page {
    property string phrase

    function setSource(str)
    {
        for (var i = 0 ; i<curSource.count; i++)
        {
            var curText = curSource.textAt(i);
            if (curText === str)
            {
                curSource.currentIndex = i;
                return;
            }
        }
        curSource.currentIndex = 0;
    }

    function viewMatireal()
    {
        var sellectedString = curSource.currentText
        var phraseForSeeking = textField.text
        var url = homePage.homeUiControler.getMatirealUrlWithName(sellectedString);
        webView.url = url
    }

    Rectangle {
        id: input
        height: textField.height + 20
        width: parent.width
        anchors.top: parent.top
        Component.onCompleted: {
            homePage.homeUiControler.getMatirealsFor("");
        }

        Rectangle{
            //anchors.centerIn: parent
            x : parent.width / 4
            y : 10
            width: parent.width * 1 / 2
            Rectangle{
                id : curSourceRect
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                width: curSource.width
                border.color: "skyblue"
                border.width: 1
                QML_ComboBox{
                    id : curSource
                    width: 300
                    model: homePage.homeUiControler.matirealsListModel
                    onCurrentTextChanged: {
                        viewMatireal()
                    }
                }
            }

            TextField {
                id: textField
                padding: 10
                focus: visible
                Material.accent: Material.LightBlue
                anchors.left: curSourceRect.right
                anchors.right: parent.right
                placeholderText: qsTr("Enter word or phrase")
                horizontalAlignment : TextInput.AlignLeft
                text: phrase
                onFocusChanged:
                {
                    focus = true
                }
                onTextChanged: {
                    homePage.homeUiControler.getMatirealsFor(text)
                    viewMatireal()
                }
                Component.onCompleted: focus = true
            }

        }
    }

    Rectangle{
        id: webViewRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: input.bottom
        anchors.bottom: parent.bottom
        visible: textField.text != ""
        color: "black"

        WebEngineView{
            id: webView
            focus: false
            anchors.fill : webViewRect
            url: "http://www.dictionary.com"

        }

    }

}
