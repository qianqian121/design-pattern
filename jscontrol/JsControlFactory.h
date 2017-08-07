//
// Created by smartmachines on 8/5/17.
//

#ifndef DESIGN_PATTERN_JSCONTROLFACTORY_H
#define DESIGN_PATTERN_JSCONTROLFACTORY_H

#include "G29Control.h"
#include "F310Control.h"

class JsControlFactory {
public:
    static JsControl* createJsControl(Joystick& joystick);
};


#endif //DESIGN_PATTERN_JSCONTROLFACTORY_H
