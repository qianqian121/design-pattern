//
// Created by smartmachines on 8/5/17.
//

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
