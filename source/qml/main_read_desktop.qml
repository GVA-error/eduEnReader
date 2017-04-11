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

    function goHome(){
        pageView.setCurrentIndex(1)
        homePage.showComments()
        homePage.homeUiControler.home()
    }
    function goSettings(){
        homePage.homeUiControler.saveHome()
        homePage.homeUiControler.goOutHome()
        pageView.setCurrentIndex(3)
        homePage.homeSoundStore.stop()
      //  homePage.homeUiControler.makeBind()
    }
    function goExamples(){
          homePage.homeUiControler.saveHome()
          homePage.showExamples()
    }
    function goTranslitionHelp(){
        homePage.homeUiControler.saveHome()
        homePage.homeUiControler.goOutHome()
        pageView.setCurrentIndex(2)
        homePage.homeSoundStore.stop()
      //  homePage.homeUiControler.makeBind()
    }

    function goOpenFile(){
        homePage.homeUiControler.synchBndFileList()
        pageView.setCurrentIndex(0)
        //openBindFileDialog.showDialog()
    }

    header : TopToolBar { id : mainToolBar }
    SwipeView  /*StackView*/ {
        id: pageView
        anchors.fill: parent
        currentIndex : 0
        PageOpen_read { id : openPage }
        PageHome_Read { id : homePage }
        PageTranslationHelp { id : translitionHelpPage }
        PageSettings_Read { id : settingPage }
    }

    //MessageDialog { id : errorDialog }
}

