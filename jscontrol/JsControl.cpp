/********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: JsControl
//!	Generated Date	: Fri, 4, Aug 2017  
	File Path	: DefaultComponent\DefaultConfig\JsControl.cpp
*********************************************************************/

//## auto_generated
#include "JsControl.h"

//## package Default

//## class JsControl
JsControl::JsControl(Joystick& joystick) :
        joystick_(joystick),
        state_(JsControlState::AUTO_OFF),
        max_brake_(0),
        max_throttle_(0),
        max_steer_angle_(0),
        steer_angle_(0),
        throttle_(0) {
    //#[ operation JsControl()
    //#]

    JoystickEvent event;
    for (int i = 0; i < 32; i++)
        joystick.sample(&event);
}

JsControl::~JsControl(void) {
}

const int JsControl::getMax_brake_(void) const {
    return max_brake_;
}

void JsControl::setMax_brake_(const int p_max_brake_) {
    max_brake_ = p_max_brake_;
}

const int JsControl::getMax_steer_angle_(void) const {
    return max_steer_angle_;
}

void JsControl::setMax_steer_angle_(const int p_max_steer_angle_) {
    max_steer_angle_ = p_max_steer_angle_;
}

const int JsControl::getMax_throttle_(void) const {
    return max_throttle_;
}

void JsControl::setMax_throttle_(const int p_max_throttle_) {
    max_throttle_ = p_max_throttle_;
}

const int JsControl::getSteer_angle_(void) const {
    return steer_angle_;
}

void JsControl::setSteer_angle_(const int p_steer_angle_) {
    steer_angle_ = p_steer_angle_;
}

const int JsControl::getThrottle_(void) const {
    return throttle_;
}

void JsControl::setThrottle_(const int p_throttle_) {
    throttle_ = p_throttle_;
}

const std::string JsControl::getDeviceName() {
    return joystick_.getDeviceName();
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\JsControl.cpp
*********************************************************************/
