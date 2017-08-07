/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the interface for the G29Control class
 *
 * \author      Mike Qi
 * \date        08/07/2017
 * \file        G29Control.h
 */

#ifndef G29Control_H
#define G29Control_H

//## class G29Control
#include "JsControl.h"
//## package Default

//## class G29Control
class G29Control : public JsControl {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    G29Control(Joystick& joystick);
    
    //## auto_generated
    ~G29Control(void);

    //## operation singleLoop()
    JsControlState singleLoop(void);
};

#endif
