import QtQuick 2.8
import QtWebEngine 1.4

import QtMultimedia 5.8
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2

import TextStoreModul 1.0
import SoundStoreModul 1.1
import UiControllerModul 1.2

QML_main {
    id : mainRoot
    visible: true
    width: 1024
    height: 768
    title: homePage.textStore.documentTitle

    homeUiController: homePage.uiController
    homeTextStore: homePage.textStore
    homeTextArea: homePage.textArea
    homeSoundStore: homePage.soundStore
    pageView: pageView

    Component.onDestruction: {
        homeUiController.stopAllThreads()
    }

    function goSettings(){
        if (commentEditor.visible === true)
            return;
        homeUiController.saveHome()
        homeUiController.goOutHome()
        pageView.setCurrentIndex(2)
        homeSoundStore.stop()
    }

    header : WRITE_TopToolBar { id : mainToolBar }
    SwipeView  /*StackView*/ {
        id: pageView
        anchors.fill: parent
        currentIndex : 0
        property var homePage: homePage
        onCurrentIndexChanged: {
            if (currentIndex === 1)
                homeSoundStore.start()
            else
                homeSoundStore.stop()
        }
        QML_PageOpen {
            id: openPage
            readOnly: false
        }
        QML_PageHome {
            id : homePage
            readOnly: false
        }
        QML_PageSettings {
            id : settingPage
            readOnly: false
        }
    }

    WRITE_PropertyDialog{
        id: propertyDialog
        uiController: homeUiController
        anchors.fill: parent
        Component.onCompleted: contentItem.interactive = false
        z:5
    }
    QML_TextEditorDialog{
        id: mainEditor
        contentText: homeUiController.title
        anchors.fill: parent
        Component.onCompleted: contentItem.interactive = false
        //text: document.text
        z : 4
        onVisibleChanged: {
            homeTextStore.setAllUnMarkText()
            setText(homeTextArea.text)
        }
        onOk: {
            var newText = getText();
            homeTextArea.text = newText
            hideDialog()
        }
    }
    QML_TextEditorDialog{
        id : commentEditor
        contentText: "file"
        anchors.fill: parent
        Component.onCompleted: contentItem.interactive = false
        z : 4
        onOk: {
            save()
            hideDialog()
        }
        onVisibleChanged: {
            if (visible === true)
                homeUiController.saveHome()
        }
    }
    MessageDialog { id : messageDialog }
    QML_TranslationHelpDialog{
        id: translationHelpDialog
    }
    QML_YesNoDialog{
        id: curTsBindingStart
        title: "Start?"
        text: "Do you wanna start handling?\n It's spend many time."
        onYes:{
            if (homeUiController.soundSourceIsLocalFile() === false)
            {
                messageDialog.text = "You must have local file to bind it"
                messageDialog.open()
                return;
            }
            homeSoundStore.stop()
            waitDialog.showDialog()
            homeUiController.curTsBinding()
        }
    }
    QML_YesNoDialog{
        id: createNewCommentSplit
        title: "Split?"
        text: "Do you want create new comment split? It delete all your comments in this file."
        onYes: {
            var commentsSize = settingPage.autoCommentNumber
            homeUiController.createAutoComments(commentsSize)
        }
    }
}

