import QtQuick 2.12
import QtQuick.Extras 1.4

Item {
    CircularGauge {
        id: gauge
        anchors.centerIn: parent
        width: Math.min(parent.width, parent.height)
        height: width
//        value: dial.value
        value: my.val
        minimumValue: 0
        maximumValue: 180
    }
}
