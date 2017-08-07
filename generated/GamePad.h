

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from GamePad.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef GamePad_726381814_h
#define GamePad_726381814_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

static const DDS_Short HELLODDS_MAX_PAYLOAD_SIZE= 8192;
static const DDS_Short HELLODDS_MAX_STRING_SIZE= 64;
extern "C" {

    extern const char *TwistCommandsTYPENAME;

}

struct TwistCommandsSeq;
#ifndef NDDS_STANDALONE_TYPE
class TwistCommandsTypeSupport;
class TwistCommandsDataWriter;
class TwistCommandsDataReader;
#endif

class TwistCommands 
{
  public:
    typedef struct TwistCommandsSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef TwistCommandsTypeSupport TypeSupport;
    typedef TwistCommandsDataWriter DataWriter;
    typedef TwistCommandsDataReader DataReader;
    #endif

    DDS_Char *   prefix ;
    DDS_Long   sampleId ;
    DDS_OctetSeq  payload ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* TwistCommands_get_typecode(void); /* Type code */

DDS_SEQUENCE(TwistCommandsSeq, TwistCommands);                                        

NDDSUSERDllExport
RTIBool TwistCommands_initialize(
    TwistCommands* self);

NDDSUSERDllExport
RTIBool TwistCommands_initialize_ex(
    TwistCommands* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool TwistCommands_initialize_w_params(
    TwistCommands* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void TwistCommands_finalize(
    TwistCommands* self);

NDDSUSERDllExport
void TwistCommands_finalize_ex(
    TwistCommands* self,RTIBool deletePointers);

NDDSUSERDllExport
void TwistCommands_finalize_w_params(
    TwistCommands* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void TwistCommands_finalize_optional_members(
    TwistCommands* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool TwistCommands_copy(
    TwistCommands* dst,
    const TwistCommands* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *ControllerCommandsTYPENAME;

}

struct ControllerCommandsSeq;
#ifndef NDDS_STANDALONE_TYPE
class ControllerCommandsTypeSupport;
class ControllerCommandsDataWriter;
class ControllerCommandsDataReader;
#endif

class ControllerCommands 
{
  public:
    typedef struct ControllerCommandsSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef ControllerCommandsTypeSupport TypeSupport;
    typedef ControllerCommandsDataWriter DataWriter;
    typedef ControllerCommandsDataReader DataReader;
    #endif

    DDS_Short   steer_angle ;
    DDS_Short   throttle ;
    DDS_Boolean   deadswitch ;
    DDS_Short   desired_speed ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* ControllerCommands_get_typecode(void); /* Type code */

DDS_SEQUENCE(ControllerCommandsSeq, ControllerCommands);                                        

NDDSUSERDllExport
RTIBool ControllerCommands_initialize(
    ControllerCommands* self);

NDDSUSERDllExport
RTIBool ControllerCommands_initialize_ex(
    ControllerCommands* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool ControllerCommands_initialize_w_params(
    ControllerCommands* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void ControllerCommands_finalize(
    ControllerCommands* self);

NDDSUSERDllExport
void ControllerCommands_finalize_ex(
    ControllerCommands* self,RTIBool deletePointers);

NDDSUSERDllExport
void ControllerCommands_finalize_w_params(
    ControllerCommands* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void ControllerCommands_finalize_optional_members(
    ControllerCommands* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool ControllerCommands_copy(
    ControllerCommands* dst,
    const ControllerCommands* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *VehicleTelemetryTYPENAME;

}

struct VehicleTelemetrySeq;
#ifndef NDDS_STANDALONE_TYPE
class VehicleTelemetryTypeSupport;
class VehicleTelemetryDataWriter;
class VehicleTelemetryDataReader;
#endif

class VehicleTelemetry 
{
  public:
    typedef struct VehicleTelemetrySeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef VehicleTelemetryTypeSupport TypeSupport;
    typedef VehicleTelemetryDataWriter DataWriter;
    typedef VehicleTelemetryDataReader DataReader;
    #endif

    DDS_Short   velocity_mph ;
    DDS_Short   velocity_kph ;
    DDS_Short   throttle ;
    DDS_Short   brake ;
    DDS_Short   steering ;
    DDS_Short   roadWheel ;
    DDS_Boolean   isMoving ;
    DDS_Boolean   EStop ;
    DDS_Short   vehicleStatus ;
    DDS_Short   vehicleState ;
    DDS_Short   gear ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* VehicleTelemetry_get_typecode(void); /* Type code */

DDS_SEQUENCE(VehicleTelemetrySeq, VehicleTelemetry);                                        

NDDSUSERDllExport
RTIBool VehicleTelemetry_initialize(
    VehicleTelemetry* self);

NDDSUSERDllExport
RTIBool VehicleTelemetry_initialize_ex(
    VehicleTelemetry* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool VehicleTelemetry_initialize_w_params(
    VehicleTelemetry* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void VehicleTelemetry_finalize(
    VehicleTelemetry* self);

NDDSUSERDllExport
void VehicleTelemetry_finalize_ex(
    VehicleTelemetry* self,RTIBool deletePointers);

NDDSUSERDllExport
void VehicleTelemetry_finalize_w_params(
    VehicleTelemetry* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void VehicleTelemetry_finalize_optional_members(
    VehicleTelemetry* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool VehicleTelemetry_copy(
    VehicleTelemetry* dst,
    const VehicleTelemetry* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* GamePad */

