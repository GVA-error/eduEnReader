import QtQml 2.2
import QtQuick 2.0
import Qt.labs.platform 1.0

Menu {
    id : contextMenue
    MenuItem {
        text: "Translation/Synonyms"
        onTriggered: {
            translitionHelpPage.phrase = textStore.getSellectedStreing()
            goTranslitionHelp()
        }
    }
    MenuItem {
        text: "Example"
        onTriggered: {
            var selectedString = homeTextStore.getSellectedStreing()
            mainToolBar.setExampleText(selectedString)
            showExamples();
        }
    }
    Instantiator {
        model: homeUiController.matirealsListModel
        MenuItem {
            text: modelData
            onTriggered: {
                translitionHelpPage.setSource(text)
                translitionHelpPage.phrase = textStore.getSellectedStreing()
                goTranslitionHelp()
            }
        }
        onObjectAdded: contextMenue.insertItem(2+index, object)
        onObjectRemoved: contextMenue.removeItem(object)
    }
}
