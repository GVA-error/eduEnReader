import QtQuick 2.8
import QtWebEngine 1.4

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

    function goHome(){
        pageView.setCurrentIndex(0);
        homePage.showComments()
        homePage.homeUiControler.home()
    }
    function goSettings(){
        pageView.setCurrentIndex(1)
        homePage.homeSoundStore.stop()
    }
    function goExamples(){
          homePage.showExamples()
    }

    header : TopToolBar{ id : mainToolBar }
    SwipeView  /*StackView*/ {
        id: pageView
        anchors.fill: parent
        PageHome_Read{ id : homePage }
        PageSettings_Read{}
    }

    //MessageDialog { id : errorDialog }
}

