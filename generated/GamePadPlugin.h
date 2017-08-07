

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from GamePad.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef GamePadPlugin_726381814_h
#define GamePadPlugin_726381814_h

#include "GamePad.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

extern "C" {

    #define TwistCommandsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define TwistCommandsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define TwistCommandsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define TwistCommandsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define TwistCommandsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern TwistCommands*
    TwistCommandsPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern TwistCommands*
    TwistCommandsPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern TwistCommands*
    TwistCommandsPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    TwistCommandsPluginSupport_copy_data(
        TwistCommands *out,
        const TwistCommands *in);

    NDDSUSERDllExport extern void 
    TwistCommandsPluginSupport_destroy_data_w_params(
        TwistCommands *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    TwistCommandsPluginSupport_destroy_data_ex(
        TwistCommands *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    TwistCommandsPluginSupport_destroy_data(
        TwistCommands *sample);

    NDDSUSERDllExport extern void 
    TwistCommandsPluginSupport_print_data(
        const TwistCommands *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    TwistCommandsPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    TwistCommandsPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    TwistCommandsPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    TwistCommandsPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    TwistCommandsPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        TwistCommands *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    TwistCommandsPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        TwistCommands *out,
        const TwistCommands *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    TwistCommandsPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const TwistCommands *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    TwistCommandsPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        TwistCommands *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    TwistCommandsPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const TwistCommands *sample); 

    NDDSUSERDllExport extern RTIBool 
    TwistCommandsPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        TwistCommands **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    TwistCommandsPlugin_deserialize_from_cdr_buffer(
        TwistCommands *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    TwistCommandsPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    TwistCommandsPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    TwistCommandsPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    TwistCommandsPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    TwistCommandsPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const TwistCommands * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    TwistCommandsPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    TwistCommandsPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    TwistCommandsPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    TwistCommandsPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const TwistCommands *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    TwistCommandsPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        TwistCommands * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    TwistCommandsPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        TwistCommands ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    TwistCommandsPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        TwistCommands *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    TwistCommandsPlugin_new(void);

    NDDSUSERDllExport extern void
    TwistCommandsPlugin_delete(struct PRESTypePlugin *);

    #define ControllerCommandsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define ControllerCommandsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ControllerCommandsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define ControllerCommandsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ControllerCommandsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ControllerCommands*
    ControllerCommandsPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ControllerCommands*
    ControllerCommandsPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ControllerCommands*
    ControllerCommandsPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ControllerCommandsPluginSupport_copy_data(
        ControllerCommands *out,
        const ControllerCommands *in);

    NDDSUSERDllExport extern void 
    ControllerCommandsPluginSupport_destroy_data_w_params(
        ControllerCommands *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ControllerCommandsPluginSupport_destroy_data_ex(
        ControllerCommands *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ControllerCommandsPluginSupport_destroy_data(
        ControllerCommands *sample);

    NDDSUSERDllExport extern void 
    ControllerCommandsPluginSupport_print_data(
        const ControllerCommands *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ControllerCommandsPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ControllerCommandsPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ControllerCommandsPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ControllerCommandsPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ControllerCommandsPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ControllerCommands *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ControllerCommandsPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ControllerCommands *out,
        const ControllerCommands *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    ControllerCommandsPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const ControllerCommands *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ControllerCommandsPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        ControllerCommands *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ControllerCommandsPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ControllerCommands *sample); 

    NDDSUSERDllExport extern RTIBool 
    ControllerCommandsPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ControllerCommands **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ControllerCommandsPlugin_deserialize_from_cdr_buffer(
        ControllerCommands *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    ControllerCommandsPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    ControllerCommandsPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    ControllerCommandsPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ControllerCommandsPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    ControllerCommandsPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const ControllerCommands * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ControllerCommandsPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ControllerCommandsPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ControllerCommandsPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ControllerCommandsPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const ControllerCommands *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ControllerCommandsPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        ControllerCommands * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ControllerCommandsPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ControllerCommands ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ControllerCommandsPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ControllerCommands *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ControllerCommandsPlugin_new(void);

    NDDSUSERDllExport extern void
    ControllerCommandsPlugin_delete(struct PRESTypePlugin *);

    #define VehicleTelemetryPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define VehicleTelemetryPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define VehicleTelemetryPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define VehicleTelemetryPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define VehicleTelemetryPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern VehicleTelemetry*
    VehicleTelemetryPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern VehicleTelemetry*
    VehicleTelemetryPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern VehicleTelemetry*
    VehicleTelemetryPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    VehicleTelemetryPluginSupport_copy_data(
        VehicleTelemetry *out,
        const VehicleTelemetry *in);

    NDDSUSERDllExport extern void 
    VehicleTelemetryPluginSupport_destroy_data_w_params(
        VehicleTelemetry *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    VehicleTelemetryPluginSupport_destroy_data_ex(
        VehicleTelemetry *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    VehicleTelemetryPluginSupport_destroy_data(
        VehicleTelemetry *sample);

    NDDSUSERDllExport extern void 
    VehicleTelemetryPluginSupport_print_data(
        const VehicleTelemetry *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    VehicleTelemetryPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    VehicleTelemetryPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    VehicleTelemetryPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    VehicleTelemetryPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    VehicleTelemetryPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        VehicleTelemetry *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    VehicleTelemetryPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        VehicleTelemetry *out,
        const VehicleTelemetry *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    VehicleTelemetryPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const VehicleTelemetry *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    VehicleTelemetryPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        VehicleTelemetry *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    VehicleTelemetryPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const VehicleTelemetry *sample); 

    NDDSUSERDllExport extern RTIBool 
    VehicleTelemetryPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        VehicleTelemetry **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    VehicleTelemetryPlugin_deserialize_from_cdr_buffer(
        VehicleTelemetry *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    VehicleTelemetryPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    VehicleTelemetryPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    VehicleTelemetryPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    VehicleTelemetryPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    VehicleTelemetryPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const VehicleTelemetry * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    VehicleTelemetryPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    VehicleTelemetryPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    VehicleTelemetryPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    VehicleTelemetryPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const VehicleTelemetry *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    VehicleTelemetryPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        VehicleTelemetry * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    VehicleTelemetryPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        VehicleTelemetry ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    VehicleTelemetryPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        VehicleTelemetry *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    VehicleTelemetryPlugin_new(void);

    NDDSUSERDllExport extern void
    VehicleTelemetryPlugin_delete(struct PRESTypePlugin *);

}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* GamePadPlugin_726381814_h */

