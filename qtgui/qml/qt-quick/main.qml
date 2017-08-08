import QtQuick 2.0
import QtQuick.Controls 1.1
import backend 1.0

ApplicationWindow
{
    visible: true
    width: 900
    height: 900

    MouseArea {
        id: mouseArea1
        anchors.rightMargin: -82
        anchors.bottomMargin: -285
        anchors.leftMargin: 9
        anchors.topMargin: 139
        anchors.fill: parent

        Text {
            x: 109
            y: 256
            text: qsTr("Throttle")
        }
        ProgressBar {
            value: backend.throttlePosition
            id: throttleReadingBar
            x: 54
            y: 325
            width: 206
            maximumValue: 100
            visible: true
            clip: false

        }

        Slider {
            value: backend.throttle
            updateValueWhileDragging: true
            id: throttleCommandBar
            x: 54
            y: 283
            width: 220
            maximumValue: 100
            onValueChanged: backend.throttle = value

        }

        Text {
            id: throttleReadingText
            x: 286
            y: 329
            text: backend.throttlePosition
            font.pixelSize: 14



        }

        TextField {
            text: backend.throttle
            id: throttleCommandText
            x: 286
            y: 285
            font.pointSize: 12
            placeholderText: backend.throttle
            onTextChanged: backend.throttle = text
        }

        Text {
            x: 118
            y: 360
            text: qsTr("Brake")
        }

        ProgressBar {
            id: brakeReadingBar
            x: 57
            y: 433
            width: 206
            maximumValue: 100
            value: backend.brakePosition
            clip: false
            visible: true
        }

        Slider {
            id: brakeCommandBar
            x: 54
            y: 382
            width: 220
            maximumValue: 100
            value: backend.brake
            updateValueWhileDragging: true
            onValueChanged: backend.brake = value
        }

        Text {
            id: brakeReadingText
            x: 286
            y: 437
            text: backend.brakePosition
            font.pixelSize: 14
        }

        TextField {
            id: brakeCommandText
            x: 286
            y: 384
            text: backend.brake
            placeholderText: backend.brake
            font.pointSize: 12
            onTextChanged: backend.brake = text
        }

        Text {
            x: 213
            y: 480
            text: qsTr("Steering Angle")
        }

        ProgressBar {
            id: rightSteeringReadingBar
            x: 269
            y: 567
            width: 206
            maximumValue: 500
            minimumValue: -500
            value: backend.handWheelAngle
            clip: false
            visible: true
        }

        Text {
            id: steeringReadingText
            x: 535
            y: 523
            text: backend.steeringAngle
            font.pixelSize: 14
        }

        BackEnd {
            id: backend
        }

        ProgressBar {
            id: leftSteeringReadingBar
            x: 57
            y: 567
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
            x: 269
            y: 516
            width: 220
            value: backend.steeringAngle
            updateValueWhileDragging: true
            maximumValue: 500
            minimumValue: 0
            onValueChanged: backend.steeringAngle = value
        }

        Slider {
            id: leftSteeringCommandBar
            x: 64
            width: 220
            height: 28
            anchors.right: parent.right
            anchors.rightMargin: 703
            anchors.top: parent.top
            anchors.topMargin: 514
            rotation: 180
            value: -backend.steeringAngle
            updateValueWhileDragging: true
            maximumValue: 500
            minimumValue: 0
            onValueChanged: backend.steeringAngle = -value
        }

        ProgressBar {
            id: rightRoadWheel
            x: 269
            y: 625
            width: 206
            visible: true
            maximumValue: 35
            minimumValue: -35
            clip: false
            value: backend.roadWheelAngle
        }

        ProgressBar {
            id: leftRoadWheel
            x: 57
            y: 625
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
            x: 210
            y: 548
            text: qsTr("Hand Wheel Angle")
            font.pixelSize: 14
        }

        Text {
            id: text5
            x: 210
            y: 603
            text: qsTr("Road Wheel Angle")
            font.pixelSize: 14
        }

        Text {
            x: 488
            y: 375
            text: qsTr("Throttle State")
        }

        Text {
            x: 69
            y: 24
            text: qsTr("Vehicle State")
        }

        ProgressBar {
            id: velocityMPHBar
            x: 54
            y: 141
            width: 206
            visible: true
            maximumValue: 100
            clip: false
            value: backend.velocityMPH
        }

        Text {
            id: velocityMPHText
            x: 285
            y: 145
            text: backend.velocityMPH
            font.pixelSize: 14
        }

        ProgressBar {
            id: velocityKPHBar
            x: 51
            y: 208
            width: 206
            visible: true
            maximumValue: 160
            clip: false
            value: backend.velocityKPH
        }

        Text {
            id: velocityKPHbar
            x: 285
            y: 212
            text: backend.velocityKPH
            font.pixelSize: 14
        }

        Text {
            x: 294
            y: 24
            text: qsTr("Vehicle Status")
        }

        CheckBox {
            id: checkBox1
            x: 545
            y: 24
            text: qsTr("Is Moving")
            checked: backend.isMoving
        }

        Text {
            id: vehicleStateText
            x: 69
            y: 55
            text: backend.vehicleState
        }

        Text {
            id: vehicleStatusText
            x: 294
            y: 55
            text: backend.vehicleStatus
        }

        Text {
            x: 100
            y: 108
            text: qsTr("Velocity MPH")
        }

        Text {
            x: 113
            y: 180
            text: qsTr("Velocity KPH")
        }

        Text {
            x: 488
            y: 417
            width: 79
            height: 14
            text: qsTr("Brake State")
        }

        Text {
            id: throttleStateText
            x: 666
            y: 375
            text: backend.throttleState
        }

        Text {
            id: brakeStateText
            x: 665
            y: 417
            text: backend.brakeState
        }

        Text {
            x: 488
            y: 468
            text: qsTr("Steer State")
        }

        Text {
            id: steerStateText
            x: 666
            y: 468
            text: backend.steeringState
        }

        Text {
            id: handWheelReadingText
            x: 535
            y: 574
            text: backend.handWheelAngle
            font.pixelSize: 14
        }

        Text {
            id: roadWheelReadingText
            x: 535
            y: 632
            text: backend.roadWheelAngle
            font.pixelSize: 14
        }

        Text {
            id: sysInfoText
            x: 21
            y: -113
            width: 754
            height: 101
            text: backend.sysInfo
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 90
        }

        TextField {
            id: throttleCommandText1
            x: 714
            y: 137
            text: backend.velocitySetPoint
            readOnly: false
            placeholderText: backend.velocitySetPoint
            font.pointSize: 12
        }

        Text {
            x: 474
            y: 141
            text: qsTr("Velocity Set Point MPH")
        }

        Text {
            x: 474
            y: 220
            text: qsTr("Proportional Gain")
        }

        Text {
            x: 474
            y: 260
            text: qsTr("Integral Gain")
        }

        TextField {
            id: throttleCommandText2
            x: 714
            y: 215
            text: backend.proportionalGain
            placeholderText: backend.proportionalGain
            font.pointSize: 12
            maximumLength: 10
        }

        TextField {
            id: throttleCommandText3
            x: 714
            y: 256
            text: backend.integralGain
            placeholderText: backend.integralGain
            font.pointSize: 12
        }

        Text {
            x: 474
            y: 106
            text: qsTr("Controller")
            font.pointSize: 14
        }

        Text {
            x: 474
            y: 298
            text: qsTr("Integral Effort")
        }

        TextField {
            id: throttleCommandText4
            x: 714
            y: 293
            text: backend.integralEffort
            placeholderText: backend.integralEffort
            font.pointSize: 12
        }

        CheckBox {
            id: checkBox2
            x: 718
            y: 106
            text: qsTr("Deadman's Switch")
            checked: backend.isControllerOn
        }

        Text {
            x: 474
            y: 180
            text: qsTr("Velocity Error MPH")
        }

        TextField {
            id: throttleCommandText5
            x: 714
            y: 176
            text: backend.velocityError
            placeholderText: backend.velocityError
            font.pointSize: 12
            readOnly: false
        }
    }
}
