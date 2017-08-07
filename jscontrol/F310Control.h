/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the interface for the F310Control class
 *
 * \author      Mike Qi
 * \date        08/07/2017
 * \file        F310Control.h
 */

#ifndef F310Control_H
#define F310Control_H

//## class F310Control
#include "JsControl.h"
//## package Default

//## class F310Control
class F310Control : public JsControl {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    F310Control(Joystick& joystick);
    
    //## auto_generated
    ~F310Control(void);

    //## operation singleLoop()
    JsControlState singleLoop(void);
};

#endif
