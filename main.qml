import QtQuick 2.15
import QtQuick.Controls 2.15

import Model 1.0
import MyController 1.0

ApplicationWindow{
    width: 680;
    height: 400;
    visible: true
    StackView{
        id: stack
        anchors.fill: parent
        initialItem: "qrc:/firstscreen.qml"
    }

    Mycontroller{
        id: myController
    }

    Item {
        id: item1
        focus: true
        Keys.onPressed:{
            if(myController.getStatus() === true)
            {
                stack.pop(stack.currentItem);
                stack.push("qrc:/swipeview.qml");
                myController.setStatus(false);
                event.accepted = true;
            }
            else
            {
                stack.pop(stack.currentItem);
                stack.push("qrc:/firstscreen.qml");
                myController.setStatus(true);
                event.accepted = true;
            }
        }
    }
}
