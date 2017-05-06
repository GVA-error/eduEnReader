import QtQuick 2.0
import QtQuick.Controls 1.4
import QtWebEngine 1.4

QML_SimpleDialog {
    id: root

    property string stateText

    contentText: stateText
    baseW : 3/7 * width;
    baseH : 3/7 * height;

    onStateTextChanged: {
        if (stateText === "end" || stateText === "")
        {
            homePage.homeUiControler.stopAllThreads()
            hideDialog()
        }
    }
    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {

        }
    }
}
