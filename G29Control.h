/*********************************************************************
	Rhapsody	: 8.2.1 
	Login		: alfred.qiao
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: G29Control
//!	Generated Date	: Fri, 4, Aug 2017  
	File Path	: DefaultComponent\DefaultConfig\G29Control.h
*********************************************************************/

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
    G29Control(void);
    
    //## auto_generated
    ~G29Control(void);

    //## operation singleLoop()
    JsControlState singleLoop(void);

    //## operation waitForStart()
    void waitForStart(void);
};

#endif
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\G29Control.h
*********************************************************************/
