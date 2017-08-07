/*!
 * \copyright	2017 (c) Samsung Semiconductor, Inc. - Strategy & Innovation Center, Smart Machines
 * \brief 		This file contains the implementation of the F310Control class
 *
 * \author      Mike Qi
 * \date        08/07/2017
 * \file        F310Control.cpp
 */

//## auto_generated
#include "F310Control.h"
//## package Default

enum class F310_AXIS_MAP : unsigned char {
    AXIS_LT         = 2,
    AXIS_RSTICK_X   = 3,
    AXIS_RSTICK_Y   = 4
};

enum class F310_BTN_MAP : unsigned char {
    BTN_B       = 1,
    BTN_BACK    = 6,
    BTN_START   = 7
};

#define DEBUG 0

const int THRESHOLD_DEADMAN_SWITCH_ON   = 25000;
const int THRESHOLD_DEADMAN_SWITCH_OFF  = -5000;

//## class F310Control
F310Control::F310Control(Joystick& joystick) : JsControl(joystick) {
    setMax_brake_(20);
    setMax_throttle_(20);
    setMax_steer_angle_(150);
}

F310Control::~F310Control(void) {
}

JsControlState F310Control::singleLoop(void) {
    //#[ operation singleLoop()
    //#]
    JoystickEvent event;
    // Attempt to sample an event from the joystick
    if (joystick_.sample(&event)) {
        switch (state_) {
            case JsControlState::AUTO_ESTOP:
                if (event.type == JS_EVENT_BUTTON) {
                    if (F310_BTN_MAP(event.number) == F310_BTN_MAP::BTN_B) {
                        state_ = JsControlState::AUTO_OFF;
                        return state_;
                    }
                }
            case JsControlState::AUTO_OFF:
                if (event.isAxis()) {
                    if (F310_AXIS_MAP(event.number) == F310_AXIS_MAP::AXIS_LT &&
                        event.value > THRESHOLD_DEADMAN_SWITCH_ON) {
                        state_ = JsControlState::AUTO_ON;
                        setThrottle_(0);
                        setSteer_angle_(0);
                        return state_;
                    }
                }
                break;
            case JsControlState::AUTO_ON:
                if (event.isAxis()) {
                    int throttle_calc;
                    int angle;

                    switch (F310_AXIS_MAP(event.number)) {
                        case F310_AXIS_MAP::AXIS_LT:
                            if (event.value < THRESHOLD_DEADMAN_SWITCH_OFF) {
                                state_ = JsControlState::AUTO_ESTOP;
                                setThrottle_(max_brake_);
                                setSteer_angle_(0);
                                return state_;
                            }
                            break;
                        case F310_AXIS_MAP::AXIS_RSTICK_Y:
                            event.value = -event.value;
                            if (event.value > 0)
                                throttle_calc = (int) event.value * max_throttle_ / 32767;
                            else
                                throttle_calc = (int) event.value * max_brake_ / 32767;
                            setThrottle_(throttle_calc);
                            break;
                        case F310_AXIS_MAP::AXIS_RSTICK_X:
                            angle = (int) (event.value) * max_steer_angle_ / 32767;
                            setSteer_angle_(angle);
                            break;
                    }
                }
                break;
        }
    }

    return state_;
}
