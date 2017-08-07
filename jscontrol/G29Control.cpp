/********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: G29Control
//!	Generated Date	: Fri, 4, Aug 2017  
	File Path	: DefaultComponent\DefaultConfig\G29Control.cpp
*********************************************************************/

//## auto_generated
#include "G29Control.h"
//## package Default

enum class G29_AXIS_MAP : unsigned char {
    AXIS_WHEEL      = 0,
    AXIS_CLUTCH     = 1,
    AXIS_THROTTLE   = 2,
    AXIS_BRAKE      = 3
};

enum class G29_BTN_MAP : unsigned char {
    BTN_RETARDER_DECREASE   = 20,
    BTN_RETARDER_INCREASE   = 21,
    BTN_CYCLE_DASH          = 22,
    BTN_CYCLE_DASH_GPS      = 23
};

#define DEBUG 0

const int THRESHOLD_DEADMAN_SWITCH_ON   = -25000;
const int THRESHOLD_DEADMAN_SWITCH_OFF  = -5000;

//## class G29Control
G29Control::G29Control(Joystick& joystick) : JsControl(joystick) {
    setMax_brake_(20);
    setMax_throttle_(30);
    setMax_steer_angle_(470);
}

G29Control::~G29Control(void) {
}

JsControlState G29Control::singleLoop(void) {
    //#[ operation singleLoop()
    //#]
    JoystickEvent event;
    // Attempt to sample an event from the joystick
    if (joystick_.sample(&event)) {
        switch (state_) {
            case JsControlState::AUTO_ESTOP:
                if (event.type == JS_EVENT_BUTTON) {
                    if (G29_BTN_MAP(event.number) == G29_BTN_MAP::BTN_CYCLE_DASH ||
                            G29_BTN_MAP(event.number) == G29_BTN_MAP::BTN_CYCLE_DASH_GPS) {
                        state_ = JsControlState::AUTO_OFF;
                        return state_;
                    }
                }
            case JsControlState::AUTO_OFF:
                if (event.isAxis()) {
                    if (G29_AXIS_MAP(event.number) == G29_AXIS_MAP::AXIS_CLUTCH &&
                        event.value < THRESHOLD_DEADMAN_SWITCH_ON) {
                        state_ = JsControlState::AUTO_ON;
                        return state_;
                    }
                }
                break;
            case JsControlState::AUTO_ON:
                if (event.isAxis()) {
                    float throttle_calc;
                    float brake_calc;
                    int angle;

                    switch (G29_AXIS_MAP(event.number)) {
                        case G29_AXIS_MAP::AXIS_CLUTCH:
                            if (event.value > THRESHOLD_DEADMAN_SWITCH_OFF) {
                                state_ = JsControlState::AUTO_ESTOP;
                                return state_;
                            }
                            break;
                        case G29_AXIS_MAP::AXIS_THROTTLE:
                            throttle_calc = (float) event.value / (float) 65535;
                            throttle_calc = (float) ((0.5 - throttle_calc) * max_throttle_);
                            setThrottle_(int(throttle_calc));
                            break;
                        case G29_AXIS_MAP::AXIS_BRAKE:
                            brake_calc = (float) event.value / (float) 65535;
                            brake_calc = (float) ((0.5 - brake_calc) * max_brake_);
                            setThrottle_(int(-brake_calc));
                            break;
                        case G29_AXIS_MAP::AXIS_WHEEL:
                            angle = (int) (event.value) * max_steer_angle_ / (int) (JoystickEvent::MAX_AXES_VALUE);
                            setSteer_angle_(angle);
                            break;
                    }
                }
                break;
        }
    }

    return state_;
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\G29Control.cpp
*********************************************************************/
