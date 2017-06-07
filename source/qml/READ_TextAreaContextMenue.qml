import QtQml 2.2
import QtQuick 2.0
import Qt.labs.platform 1.0

// TODO указывать новый uiController?
Menu {
    id : contextMenue
    property var textStore
    MenuItem {
        text: "Translation/Synonyms"
        onTriggered: {
            getTrnaslation()
        }
    }
    MenuItem {
        text: "Example"
        onTriggered: {
            var selectedString = textStore.getSellectedStreing()
            mainToolBar.setExampleText(selectedString)
            showExamples();
        }
    }
    Instantiator {
        model: homeUiController.matirealsListModel
        MenuItem {
            text: modelData
            onTriggered: {
                if (settingPage.showTranslateDialog)
                    translationHelpDialog.setSource(text)
                else
                    translitionHelpPage.setSource(text)
                getTrnaslation()
            }
        }
        onObjectAdded: contextMenue.insertItem(2+index, object)
        onObjectRemoved: contextMenue.removeItem(object)
    }
    function getTrnaslation(){
        var selectedString = textStore.getSellectedStreing()
        console.log(selectedString)
        if (settingPage.showTranslateDialog)
            translationHelpDialog.phrase = selectedString
        else
            translitionHelpPage.phrase = selectedString
        goTranslitionHelp()
    }
}
