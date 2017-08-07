/*********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: F310Control
//!	Generated Date	: Fri, 4, Aug 2017  
	File Path	: DefaultComponent\DefaultConfig\F310Control.h
*********************************************************************/

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
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\F310Control.h
*********************************************************************/
