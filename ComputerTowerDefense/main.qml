import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 500
    height: 500
    title: qsTr("Computer Tower Defense YEAH")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Text {
        text: qsTr("Computer Tower Defense YEAH")
        anchors.centerIn: parent
    }

    // background image
    Image {
        id: image1
        x: 0
        y: 0
        width: 500
        height: 500
        source: "img/bg_rs.png"
    }
}
