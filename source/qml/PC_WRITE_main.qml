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
import UiControlerModul 1.1

ApplicationWindow {
    id : mainRoot
    visible: true
    width: 1024
    height: 768
    title: homePage.homeDocument.documentTitle

    Material.theme: Material.Light
    Material.background: "#FFFFFF"
    Material.primary : "#FFFFFF"
    Material.accent : Material.LightBlue

    property var uiController: homePage.homeUiControler
    property var document: homePage.homeDocument

    Component.onDestruction: {
        homePage.homeUiControler.stopAllThreads()
    }

    function goHome(){
        if (commentEditor.visible === true)
            return;
        pageView.setCurrentIndex(1)
        homePage.showComments()
        homePage.homeUiControler.home()
        homePage.textArea.syncSoundAndSliderPosition(true)
    }
    function goSettings(){
        if (commentEditor.visible === true)
            return;
        homePage.homeUiControler.saveHome()
        homePage.homeUiControler.goOutHome()
        pageView.setCurrentIndex(2)
        homePage.homeSoundStore.stop()
        //homePage.homeUiControler.makeBind()
    }
    function goOpenFile(){
        if (commentEditor.visible === true)
            return;
        homePage.homeUiControler.saveHome()
        homePage.homeUiControler.goOutHome()
        homePage.homeUiControler.synchBndFileList()
        homePage.homeSoundStore.stop()
        pageView.setCurrentIndex(0)
        //openBindFileDialog.showDialog()
    }

    header : PC_WRITE_TopToolBar { id : mainToolBar }
    SwipeView  /*StackView*/ {
        id: pageView
        anchors.fill: parent
        currentIndex : 0
        onCurrentIndexChanged: {
            if (currentIndex === 1)
                homePage.homeSoundStore.start()
            else
                homePage.homeSoundStore.stop()
        }
        PC_WRITE_PageOpen { id : openPage }
        PC_WRITE_PageHome { id : homePage }
        PC_READ_PageSettings { id : settingPage }    
    }

    QML_WaitDialog{
        id : waitDialog
        anchors.fill: parent
        z : 100
        stateText: homePage.homeUiControler.curState
    }
    PC_WRITE_PropertyDialog{
        id: propertyDialog
        uiController: mainRoot.uiController
        anchors.fill: parent
        Component.onCompleted: contentItem.interactive = false
        z:5
    }
    QML_TextEditorDialog{
        id: mainEditor
        contentText: uiController.title
        anchors.fill: parent
        Component.onCompleted: contentItem.interactive = false
        //text: document.text
        z : 4
        onVisibleChanged: {
            document.setAllUnMarkText()
            setText(homePage.textArea.text)
        }

        onOk: {
            var newText = getText();
            homePage.textArea.text = newText
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
                uiController.saveHome()
        }
    }

    //MessageDialog { id : errorDialog }
}

