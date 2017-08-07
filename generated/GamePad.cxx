

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from GamePad.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "GamePad.h"

/* ========================================================================= */
const char *TwistCommandsTYPENAME = "TwistCommands";

DDS_TypeCode* TwistCommands_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode TwistCommands_g_tc_prefix_string = DDS_INITIALIZE_STRING_TYPECODE(((HELLODDS_MAX_STRING_SIZE)));
    static DDS_TypeCode TwistCommands_g_tc_payload_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((HELLODDS_MAX_PAYLOAD_SIZE)),NULL);
    static DDS_TypeCode_Member TwistCommands_g_tc_members[3]=
    {

        {
            (char *)"prefix",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"sampleId",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"payload",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode TwistCommands_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"TwistCommands", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            TwistCommands_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for TwistCommands*/

    if (is_initialized) {
        return &TwistCommands_g_tc;
    }

    TwistCommands_g_tc_payload_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    TwistCommands_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&TwistCommands_g_tc_prefix_string;

    TwistCommands_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    TwistCommands_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& TwistCommands_g_tc_payload_sequence;

    is_initialized = RTI_TRUE;

    return &TwistCommands_g_tc;
}

RTIBool TwistCommands_initialize(
    TwistCommands* sample) {
    return TwistCommands_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool TwistCommands_initialize_ex(
    TwistCommands* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return TwistCommands_initialize_w_params(
        sample,&allocParams);

}

RTIBool TwistCommands_initialize_w_params(
    TwistCommands* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (allocParams) {} /* To avoid warnings */

    if (allocParams->allocate_memory){
        sample->prefix= DDS_String_alloc (((HELLODDS_MAX_STRING_SIZE)));
        if (sample->prefix == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->prefix!= NULL) { 
            sample->prefix[0] = '\0';
        }
    }

    if (!RTICdrType_initLong(&sample->sampleId)) {
        return RTI_FALSE;
    }     

    if (allocParams->allocate_memory) {
        DDS_OctetSeq_initialize(&sample->payload  );
        if (!DDS_OctetSeq_set_maximum(&sample->payload , ((HELLODDS_MAX_PAYLOAD_SIZE)))) {
            return RTI_FALSE;
        }
    } else { 
        DDS_OctetSeq_set_length(&sample->payload, 0);
    }
    return RTI_TRUE;
}

void TwistCommands_finalize(
    TwistCommands* sample)
{

    TwistCommands_finalize_ex(sample,RTI_TRUE);
}

void TwistCommands_finalize_ex(
    TwistCommands* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    TwistCommands_finalize_w_params(
        sample,&deallocParams);
}

void TwistCommands_finalize_w_params(
    TwistCommands* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    if (sample->prefix != NULL) {
        DDS_String_free(sample->prefix);
        sample->prefix=NULL;

    }

    DDS_OctetSeq_finalize(&sample->payload);

}

void TwistCommands_finalize_optional_members(
    TwistCommands* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool TwistCommands_copy(
    TwistCommands* dst,
    const TwistCommands* src)
{

    if (!RTICdrType_copyStringEx (
        &dst->prefix, src->prefix, 
        ((HELLODDS_MAX_STRING_SIZE)) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->sampleId, &src->sampleId)) { 
        return RTI_FALSE;
    }
    if (!DDS_OctetSeq_copy(&dst->payload ,
    &src->payload )) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'TwistCommands' sequence class.
*/
#define T TwistCommands
#define TSeq TwistCommandsSeq
#define T_initialize_w_params TwistCommands_initialize_w_params
#define T_finalize_w_params   TwistCommands_finalize_w_params
#define T_copy       TwistCommands_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *ControllerCommandsTYPENAME = "ControllerCommands";

DDS_TypeCode* ControllerCommands_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ControllerCommands_g_tc_members[4]=
    {

        {
            (char *)"steer_angle",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"throttle",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"deadswitch",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"desired_speed",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode ControllerCommands_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ControllerCommands", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            ControllerCommands_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for ControllerCommands*/

    if (is_initialized) {
        return &ControllerCommands_g_tc;
    }

    ControllerCommands_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    ControllerCommands_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    ControllerCommands_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    ControllerCommands_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &ControllerCommands_g_tc;
}

RTIBool ControllerCommands_initialize(
    ControllerCommands* sample) {
    return ControllerCommands_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool ControllerCommands_initialize_ex(
    ControllerCommands* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ControllerCommands_initialize_w_params(
        sample,&allocParams);

}

RTIBool ControllerCommands_initialize_w_params(
    ControllerCommands* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->steer_angle)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->throttle)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initBoolean(&sample->deadswitch)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->desired_speed)) {
        return RTI_FALSE;
    }     

    return RTI_TRUE;
}

void ControllerCommands_finalize(
    ControllerCommands* sample)
{

    ControllerCommands_finalize_ex(sample,RTI_TRUE);
}

void ControllerCommands_finalize_ex(
    ControllerCommands* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ControllerCommands_finalize_w_params(
        sample,&deallocParams);
}

void ControllerCommands_finalize_w_params(
    ControllerCommands* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void ControllerCommands_finalize_optional_members(
    ControllerCommands* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool ControllerCommands_copy(
    ControllerCommands* dst,
    const ControllerCommands* src)
{

    if (!RTICdrType_copyShort (
        &dst->steer_angle, &src->steer_angle)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->throttle, &src->throttle)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->deadswitch, &src->deadswitch)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->desired_speed, &src->desired_speed)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ControllerCommands' sequence class.
*/
#define T ControllerCommands
#define TSeq ControllerCommandsSeq
#define T_initialize_w_params ControllerCommands_initialize_w_params
#define T_finalize_w_params   ControllerCommands_finalize_w_params
#define T_copy       ControllerCommands_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *VehicleTelemetryTYPENAME = "VehicleTelemetry";

DDS_TypeCode* VehicleTelemetry_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member VehicleTelemetry_g_tc_members[11]=
    {

        {
            (char *)"velocity_mph",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"velocity_kph",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"throttle",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"brake",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"steering",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"roadWheel",/* Member name */
            {
                5,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"isMoving",/* Member name */
            {
                6,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"EStop",/* Member name */
            {
                7,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"vehicleStatus",/* Member name */
            {
                8,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"vehicleState",/* Member name */
            {
                9,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"gear",/* Member name */
            {
                10,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode VehicleTelemetry_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"VehicleTelemetry", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            11, /* Number of members */
            VehicleTelemetry_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for VehicleTelemetry*/

    if (is_initialized) {
        return &VehicleTelemetry_g_tc;
    }

    VehicleTelemetry_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    VehicleTelemetry_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    VehicleTelemetry_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    VehicleTelemetry_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    VehicleTelemetry_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    VehicleTelemetry_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    VehicleTelemetry_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    VehicleTelemetry_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    VehicleTelemetry_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    VehicleTelemetry_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    VehicleTelemetry_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &VehicleTelemetry_g_tc;
}

RTIBool VehicleTelemetry_initialize(
    VehicleTelemetry* sample) {
    return VehicleTelemetry_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool VehicleTelemetry_initialize_ex(
    VehicleTelemetry* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return VehicleTelemetry_initialize_w_params(
        sample,&allocParams);

}

RTIBool VehicleTelemetry_initialize_w_params(
    VehicleTelemetry* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->velocity_mph)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->velocity_kph)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->throttle)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->brake)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->steering)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->roadWheel)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initBoolean(&sample->isMoving)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initBoolean(&sample->EStop)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->vehicleStatus)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->vehicleState)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initShort(&sample->gear)) {
        return RTI_FALSE;
    }     

    return RTI_TRUE;
}

void VehicleTelemetry_finalize(
    VehicleTelemetry* sample)
{

    VehicleTelemetry_finalize_ex(sample,RTI_TRUE);
}

void VehicleTelemetry_finalize_ex(
    VehicleTelemetry* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    VehicleTelemetry_finalize_w_params(
        sample,&deallocParams);
}

void VehicleTelemetry_finalize_w_params(
    VehicleTelemetry* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void VehicleTelemetry_finalize_optional_members(
    VehicleTelemetry* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool VehicleTelemetry_copy(
    VehicleTelemetry* dst,
    const VehicleTelemetry* src)
{

    if (!RTICdrType_copyShort (
        &dst->velocity_mph, &src->velocity_mph)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->velocity_kph, &src->velocity_kph)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->throttle, &src->throttle)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->brake, &src->brake)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->steering, &src->steering)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->roadWheel, &src->roadWheel)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->isMoving, &src->isMoving)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->EStop, &src->EStop)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->vehicleStatus, &src->vehicleStatus)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->vehicleState, &src->vehicleState)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyShort (
        &dst->gear, &src->gear)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'VehicleTelemetry' sequence class.
*/
#define T VehicleTelemetry
#define TSeq VehicleTelemetrySeq
#define T_initialize_w_params VehicleTelemetry_initialize_w_params
#define T_finalize_w_params   VehicleTelemetry_finalize_w_params
#define T_copy       VehicleTelemetry_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

