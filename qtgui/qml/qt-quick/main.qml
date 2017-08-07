import QtQuick 2.0
import QtQuick.Controls 1.1
import backend 1.0

ApplicationWindow
{
    visible: true
    width: 784
    height: 900

    MouseArea {
        id: mouseArea1
        anchors.rightMargin: -73
        anchors.bottomMargin: -146
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Text {
            x: 132
            y: 434
            text: qsTr("Throttle")
        }
        ProgressBar {
            value: backend.throttlePosition
            id: throttleReadingBar
            x: 77
            y: 503
            width: 206
            maximumValue: 100
            visible: true
            clip: false

        }

        Slider {
            value: backend.throttle
            updateValueWhileDragging: true
            id: throttleCommandBar
            x: 77
            y: 461
            maximumValue: 100
            onValueChanged: backend.throttle = value

        }

        Text {
            id: throttleReadingText
            x: 309
            y: 507
            text: backend.throttlePosition
            font.pixelSize: 14


        }

        TextField {
            text: backend.throttle
            id: throttleCommandText
            x: 309
            y: 463
            font.pointSize: 12
            placeholderText: backend.throttle
            onTextChanged: backend.throttle = text
        }

        Text {
            x: 140
            y: 532
            text: qsTr("Brake")
        }

        ProgressBar {
            id: brakeReadingBar
            x: 80
            y: 611
            width: 206
            maximumValue: 100
            value: backend.brakePosition
            clip: false
            visible: true
        }

        Slider {
            id: brakeCommandBar
            x: 77
            y: 560
            maximumValue: 100
            value: backend.brake
            updateValueWhileDragging: true
            onValueChanged: backend.brake = value
        }

        Text {
            id: brakeReadingText
            x: 309
            y: 615
            text: backend.brakePosition
            font.pixelSize: 14
        }

        TextField {
            id: brakeCommandText
            x: 309
            y: 562
            text: backend.brake
            placeholderText: backend.brake
            font.pointSize: 12
            onTextChanged: backend.brake = text
        }

        Text {
            x: 249
            y: 658
            text: qsTr("Steering Angle")
        }

        ProgressBar {
            id: rightSteeringReadingBar
            x: 300
            y: 756
            width: 206
            maximumValue: 500
            minimumValue: -500
            value: backend.handWheelAngle
            clip: false
            visible: true
        }

        Text {
            id: steeringReadingText
            x: 523
            y: 709
            text: backend.steeringAngle
            font.pixelSize: 14
        }

        BackEnd {
            id: backend
        }

        ProgressBar {
            id: leftSteeringReadingBar
            x: 88
            y: 756
            width: 206
            rotation: 180
            orientation: 1
            value: -backend.handWheelAngle
            clip: false
            visible: true
            maximumValue: 500
            minimumValue: -500
        }

        Slider {
            id: rightSteeringCommandBar
            x: 300
            y: 703
            value: backend.steeringAngle
            updateValueWhileDragging: true
            maximumValue: 500
            minimumValue: 0
            onValueChanged: backend.steeringAngle = value
        }

        Slider {
            id: leftSteeringCommandBar
            x: 94
            anchors.right: parent.right
            anchors.rightMargin: 557
            anchors.top: parent.top
            anchors.topMargin: 703
            rotation: 180
            value: -backend.steeringAngle
            updateValueWhileDragging: true
            maximumValue: 500
            minimumValue: 0
            onValueChanged: backend.steeringAngle = -value
        }

        ProgressBar {
            id: rightRoadWheel
            x: 300
            y: 814
            width: 206
            visible: true
            maximumValue: 35
            minimumValue: -35
            clip: false
            value: backend.roadWheelAngle
        }

        ProgressBar {
            id: leftRoadWheel
            x: 88
            y: 814
            width: 206
            visible: true
            maximumValue: 35
            minimumValue: -35
            clip: false
            rotation: 180
            value: -backend.roadWheelAngle
            orientation: 1
        }

        Text {
            id: text4
            x: 241
            y: 737
            text: qsTr("Hand Wheel Angle")
            font.pixelSize: 14
        }

        Text {
            id: text5
            x: 241
            y: 792
            text: qsTr("Road Wheel Angle")
            font.pixelSize: 14
        }

        Text {
            x: 569
            y: 467
            text: qsTr("Throttle State")
        }

        Text {
            x: 75
            y: 199
            text: qsTr("Vehicle State")
        }

        ProgressBar {
            id: velocityMPHBar
            x: 69
            y: 309
            width: 206
            visible: true
            maximumValue: 100
            clip: false
            value: backend.velocityMPH
        }

        Text {
            id: velocityMPHText
            x: 300
            y: 313
            text: backend.velocityMPH
            font.pixelSize: 14
        }

        ProgressBar {
            id: velocityKPHBar
            x: 66
            y: 376
            width: 206
            visible: true
            maximumValue: 160
            clip: false
            value: backend.velocityKPH
        }

        Text {
            id: velocityKPHbar
            x: 300
            y: 380
            text: backend.velocityKPH
            font.pixelSize: 14
        }

        Text {
            x: 300
            y: 199
            text: qsTr("Vehicle Status")
        }

        CheckBox {
            id: checkBox1
            x: 509
            y: 292
            text: qsTr("Is Moving")
            checked: backend.isMoving
        }

        Text {
            id: vehicleStateText
            x: 75
            y: 230
            text: backend.vehicleState
        }

        Text {
            id: vehicleStatusText
            x: 300
            y: 230
            text: backend.vehicleStatus
        }

        Text {
            x: 115
            y: 276
            text: qsTr("Velocity MPH")
        }

        Text {
            x: 128
            y: 348
            text: qsTr("Velocity KPH")
        }

        Text {
            x: 578
            y: 547
            text: qsTr("Brake State")
        }

        Text {
            id: throttleStateText
            x: 532
            y: 503
            text: backend.throttleState
        }

        Text {
            id: brakeStateText
            x: 540
            y: 591
            text: backend.brakeState
        }

        Text {
            x: 564
            y: 628
            text: qsTr("Steer State")
        }

        Text {
            id: steerStateText
            x: 515
            y: 658
            text: backend.steeringState
        }

        Text {
            id: handWheelReadingText
            x: 526
            y: 760
            text: backend.handWheelAngle
            font.pixelSize: 14
        }

        Text {
            id: roadWheelReadingText
            x: 526
            y: 818
            text: backend.roadWheelAngle
            font.pixelSize: 14
        }

        Text {
            id: sysInfoText
            x: 15
            y: 55
            width: 754
            height: 101
            text: backend.sysInfo
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 90
        }
    }
}
