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
import UiControllerModul 1.1

ApplicationWindow {
    title: homePage.textStore.documentTitle

    Material.theme: Material.Light
    Material.background: "#FFFFFF"
    Material.primary : "#FFFFFF"
    Material.accent : Material.LightBlue

    property var homeUiController
    property var homeTextStore
    property var homeTextArea
    property var homeSoundStore
    property var pageView
    property var waitDialog: waitDialog

    Component.onDestruction: {
        homeUiController.stopAllThreads()
    }

    function goHome(){
        if (settingPage.showTranslateDialog)
            translationHelpDialog.hideDialog()
        homePage.showComments()
        homeUiController.home()
        homeTextArea.syncSoundAndSliderPosition(true)
        if (homeUiController.someOpen)
            pageView.setCurrentIndex(1)
        else
            pageView.setCurrentIndex(0)
    }
    function goOpenFile(){
        homeUiController.saveHome()
        homeUiController.goOutHome()
        homeUiController.synchBndFileList()
        homeSoundStore.stop()
        pageView.setCurrentIndex(0)
    }

    QML_WaitDialog{
        id : waitDialog
        anchors.fill: parent
        z : 100
        stateText: homeUiController.curState
    }
    MessageDialog { id : messageDialog }
}

