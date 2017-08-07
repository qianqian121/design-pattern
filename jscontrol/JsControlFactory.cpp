/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the implementation of the JsControlFactory class
 *
 * \author      Mike Qi
 * \date        08/05/2017
 * \file        JsControlFactory.cpp
 */

#include "JsControlFactory.h"

JsControl* JsControlFactory::createJsControl(Joystick& joystick) {
    if (!joystick.isFound()) {
        std::cout <<"failed to open joystick controller!" << std::endl;
        return nullptr;
    }

    const auto devName = joystick.getDeviceName();
    std::cout << devName << std::endl;
    if (devName == "Logitech G29 Driving Force Racing Wheel")
        return new G29Control(joystick);
    else if (devName == "Logitech Gamepad F310")
        return new F310Control(joystick);

    return nullptr;
}
