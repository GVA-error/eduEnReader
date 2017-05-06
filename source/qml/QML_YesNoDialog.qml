import QtQuick 2.0

import QtQuick 2.2
import QtQuick.Dialogs 1.1

MessageDialog {
    id: messageDialog
    standardButtons: StandardButton.Yes | StandardButton.No
    icon: StandardIcon.Question
    function show()
    {
        visible = true
    }
}
