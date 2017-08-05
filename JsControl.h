/*********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: JsControl
//!	Generated Date	: Fri, 4, Aug 2017  
	File Path	: DefaultComponent\DefaultConfig\JsControl.h
*********************************************************************/

#ifndef JsControl_H
#define JsControl_H

enum class JsControlState {AUTO_ON, DEADMAN_SWITCH_NOT_HOLD, AUTO_OFF};

//## class JsControl
class JsControl {
    ////    Constructors and destructors    ////
    
public :

    //## operation JsControl()
    JsControl(void);
    
    //## auto_generated
    ~JsControl(void);
    
    ////    Operations    ////
    
    //## operation getState()
    JsControlState getState(void);
    
    //## operation getSteerAngle()
    int getSteerAngle(void);
    
    //## operation getThrottle()
    int getThrottle(void);
    
    //## operation setMaxBrake()
    void setMaxBrake(void);
    
    //## operation setMaxSteerAngle()
    void setMaxSteerAngle(void);
    
    //## operation setMaxThrottle()
    void setMaxThrottle(void);
    
    //## operation singleLoop()
    virtual JsControlState singleLoop(void) = 0;
    
    //## operation waitForStart()
    virtual void waitForStart(void) = 0;
    
    ////    Additional operations    ////

private :

    //## auto_generated
    const int getMax_brake_(void) const;
    
    //## auto_generated
    void setMax_brake_(const int p_max_brake_);
    
    //## auto_generated
    const int getMax_steer_angle_(void) const;
    
    //## auto_generated
    void setMax_steer_angle_(const int p_max_steer_angle_);
    
    //## auto_generated
    const int getMax_throttle_(void) const;
    
    //## auto_generated
    void setMax_throttle_(const int p_max_throttle_);
    
    //## auto_generated
    const int getSteer_angle_(void) const;
    
    //## auto_generated
    void setSteer_angle_(const int p_steer_angle_);
    
    //## auto_generated
    const int getThrottle_(void) const;
    
    //## auto_generated
    void setThrottle_(const int p_throttle_);
    
    ////    Attributes    ////
    
    int max_brake_;		//## attribute max_brake_
    
    int max_steer_angle_;		//## attribute max_steer_angle_
    
    int max_throttle_;		//## attribute max_throttle_
    
    int steer_angle_;		//## attribute steer_angle_
    
    int throttle_;		//## attribute throttle_
};

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\JsControl.h
*********************************************************************/
