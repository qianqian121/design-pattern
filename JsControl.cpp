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
JsControl::JsControl(void) {
    //#[ operation JsControl()
    //#]
}

JsControl::~JsControl(void) {
}

void JsControl::getState(void) {
    //#[ operation getState()
    //#]
}

//JsControlState JsControl::singleLoop(void) {
//    //#[ operation singleLoop()
//    //#]
//}
//
//void JsControl::waitForStart(void) {
//    //#[ operation waitForStart()
//    //#]
//}

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

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\JsControl.cpp
*********************************************************************/
