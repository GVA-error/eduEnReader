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

QML_main {
    id : mainRoot
    visible: true
    width: 1024
    height: 768
    title: homeTextStore.documentTitle

    homeUiController: homePage.uiController
    homeTextStore: homePage.textStore
    homeTextArea: homePage.textArea
    homeSoundStore: homePage.soundStore
    pageView: pageView

    function goSettings(){
//        if (settingPage.showTranslateDialog)
//            translationHelpDialog.hideDialog()
//        homeUiController.saveHome()
//        homeUiController.goOutHome()
//        pageView.setCurrentIndex(3)
//        homeSoundStore.stop()
    }
    function goExamples(){
//          homeUiController.saveHome()
//          homePage.showExamples()
    }
    function goTranslitionHelp(){
//        homeUiController.saveHome()
//        homeUiController.goOutHome()
//        if (settingPage.showTranslateDialog)
//            translationHelpDialog.showDialog()
//        else
//            pageView.setCurrentIndex(2)
//        homeSoundStore.stop()
    }
    function goExercises(){
//        homeUiController.saveHome()
//        homeUiController.goOutHome()
//        homeSoundStore.stop()
//        pageView.setCurrentIndex(4)
    }

    header : READ_TopToolBar {
        id : mainToolBar
        pageView: pageView
    }
    SwipeView  /*StackView*/ {
        id: pageView
        anchors.fill: parent
        currentIndex : 0
        QML_PageOpen {
            id: openPage
            readOnly: true
        }
//        QML_PageHome {
//            id : homePage
//            readOnly: true
//        }
//        QML_PageTranslationHelp {
//            id : translitionHelpPage
//            readOnly: true
//        }
//        QML_PageSettings {
//            id : settingPage
//            readOnly: true
//        }
//        QML_PageExercises{
//            id : exercisesPage
//            readOnly: true
//        }

    }
    QML_TranslationHelpDialog{
        id: translationHelpDialog
    }
}

