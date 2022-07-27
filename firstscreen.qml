import QtQuick 2.0
import QtQuick.Controls 2.15

Item {

        Image {
            id: firstscreen
            source: "qrc:Image/kindofcats.jpg"
            scale: parent.height / sourceSize.height
            anchors{
                centerIn: parent
            }
        }
}
