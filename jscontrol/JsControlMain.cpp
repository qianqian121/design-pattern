//
// Created by smartmachines on 8/5/17.
//
#include "JsControlFactory.h"
#include <GamePad.h>
#include <GamePadSupport.h>
#include <DDSNodeInterface.h>

int main(int argc, char **argv) {
    Joystick joystick;
    JsControl *jsControl = JsControlFactory::createJsControl(joystick);
    if (jsControl == nullptr)
        return -1;

    DDSNodeInterface nodeInterface;
    DDS::DataWriter *twist_pub = nodeInterface.advertise<ControllerCommands>("JsCommands");
    DdsAutoType<ControllerCommands> controlCommand;

    DDS_Duration_t send_period = {0, 10000000};

    std::cout <<"waiting game controller safety switch " << std::endl;
    while(jsControl->singleLoop() == JsControlState::AUTO_OFF)
        NDDSUtility::sleep(send_period);
    std::cout <<"waiting game controller safety switch [done] " << std::endl;

    JsControlState state;
    while (true) {
        state = jsControl->singleLoop();
        if (state == JsControlState::AUTO_OFF) {
            break;
        }
        else if (state == JsControlState::AUTO_ESTOP) {
            // brake
            controlCommand.throttle = -20;
            // Write the data to the network.
            nodeInterface.pub<ControllerCommands>(twist_pub, controlCommand);
            NDDSUtility::sleep(send_period);
        }
        else
        {
            std::cout << "Steering: " << jsControl->getSteer_angle_() << std::endl;
//            std::cout << "Throttle: " << jsControl->getThrottle_() << std::endl;
            // publish topic
            controlCommand.steer_angle = (short)jsControl->getSteer_angle_();
            controlCommand.throttle = (short)jsControl->getThrottle_();
            // Write the data to the network.
            nodeInterface.pub<ControllerCommands>(twist_pub, controlCommand);

            NDDSUtility::sleep(send_period);
        }
    }

//    static SMController *ctrl = PlexusController::getInstance();
//
//    _controller = ctrl;
//    ctrl->controllerOFF();
//
//    std::cout <<"waiting game controller safety switch " << std::endl;
//    jsControl->waitForStart();
//    std::cout <<"joystickloop controller on start " << std::endl;
//    ctrl->controllerON();
//    std::cout <<"joystickloop controller on finished " << std::endl;
//
//    while (true) {
//        jsControl->singleLoop();
////        car_joystick.HelperPrintAllControls();
////        car_joystick.PlexusControls(ctrl);
//        if (car_joystick.PlexusControls(ctrl) == -1)
//            break;
//    }
//    ctrl->controllerOFF();
    std::cout <<"exit " << std::endl;

    return 0;
}
