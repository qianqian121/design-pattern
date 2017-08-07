/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the interface for the JsControl class
 *
 * \author      Mike Qi
 * \date        08/07/2017
 * \file        JsControl.h
 */

#ifndef JsControl_H
#define JsControl_H

#include "joystick.hh"

enum class JsControlState {AUTO_ON, AUTO_ESTOP, AUTO_OFF};

//## class JsControl
class JsControl {
    ////    Constructors and destructors    ////
    
public :

    //## operation JsControl()
    JsControl(Joystick& joystick);
    
    //## auto_generated
    ~JsControl(void);
    
    ////    Operations    ////
    const std::string getDeviceName();

    //## auto_generated
    const int getMax_brake_(void) const;

    //## auto_generated
    const int getMax_steer_angle_(void) const;

    //## auto_generated
    const int getMax_throttle_(void) const;

    //## auto_generated
    const int getSteer_angle_(void) const;

    //## auto_generated
    const int getThrottle_(void) const;

    //## operation singleLoop()
    virtual JsControlState singleLoop(void) = 0;

    ////    Additional operations    ////

protected:

    //## auto_generated
    void setMax_brake_(const int p_max_brake_);

    //## auto_generated
    void setMax_steer_angle_(const int p_max_steer_angle_);

    //## auto_generated
    void setMax_throttle_(const int p_max_throttle_);

    //## auto_generated
    void setSteer_angle_(const int p_steer_angle_);

    //## auto_generated
    void setThrottle_(const int p_throttle_);

    ////    Attributes    ////

    Joystick& joystick_;    //## attribute joystick_

    JsControlState state_;  //## attribute state_

    int max_brake_;		//## attribute max_brake_

    int max_steer_angle_;		//## attribute max_steer_angle_

    int max_throttle_;		//## attribute max_throttle_

private :

    ////    Attributes    ////
    
    int steer_angle_;		//## attribute steer_angle_
    
    int throttle_;		//## attribute throttle_
};

#endif
