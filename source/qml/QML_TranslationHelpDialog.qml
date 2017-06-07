import QtQuick 2.0

QML_SimpleDialog {
    id: root

    property string phrase: translationHelp.phrase
    function setSource(str)
    {
        translationHelp.setSource(str)
    }
    function viewMatireal()
    {
        translationHelp.viewMatireal();
    }

    onBackClicked: {
        hideDialog()
    }

    //contentText: stateText
    baseW : 9/10 * width
    baseH : 9/10 * height

    Rectangle{
        anchors.centerIn: parent
        width: baseW
        height: baseH

        QML_PageTranslationHelp{
            id: translationHelp
            phrase: root.phrase
            anchors.fill: parent
        }
    }
}
