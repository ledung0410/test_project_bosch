import QtQuick 2.0
import QtQuick.Controls 2.15
import Model 1.0

Item{
    ListView{
        id: listv

        anchors.fill: parent
        snapMode: ListView.SnapOneItem
        orientation: ListView.Horizontal
        model: MyModel {}

        delegate: Rectangle{
            id: rectangle
            color: "lightpink"
            width: ListView.view.width
            height: ListView.view.height
            Image {
                id: img
                scale: parent.height / sourceSize.height / 2
                source: model.img
                anchors {
                    centerIn: parent
                }
            }
            Text {
                id: txt
                text: model.name
                font.pointSize: 20
                anchors {
                    topMargin:30
                    top: parent.top
                    horizontalCenter: parent.horizontalCenter
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: pop.visible ?  pop.close() : pop.open()
            }
            Popup {
                id: pop
                background: Rectangle {
                    id: poprec
                    anchors.fill: parent
                    //opacity: 0.9
                    color: "black"
                }
                width: parent.width
                height: parent.height
                contentItem: Text {
                    color: "white"
                    text: model.detail
                    font.pointSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                }
                Button {
                    anchors.left: parent.Left
                    anchors.top: parent.Top
                    text: "Back"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: pop.visible ?  pop.close() : pop.open()
                    }
                }
            }
        }
        PageIndicator {
            id: indicator
            y: 451
            currentIndex: listv.currentIndex
            count: listv.count
            anchors.bottom: listv.bottom
            anchors.horizontalCenterOffset: 0
            anchors.bottomMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

}
