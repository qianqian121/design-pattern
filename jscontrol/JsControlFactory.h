/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the interface for the JsControlFactory class
 *
 * \author      Mike Qi
 * \date        08/05/2017
 * \file        JsControlFactory.h
 */

#ifndef DESIGN_PATTERN_JSCONTROLFACTORY_H
#define DESIGN_PATTERN_JSCONTROLFACTORY_H

#include "G29Control.h"
#include "F310Control.h"

class JsControlFactory {
public:
    static JsControl* createJsControl(Joystick& joystick);
};


#endif //DESIGN_PATTERN_JSCONTROLFACTORY_H
