

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from GamePad.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <string.h>

#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "GamePadPlugin.h"

/* ----------------------------------------------------------------------------
*  Type TwistCommands
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

TwistCommands*
TwistCommandsPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params){
    TwistCommands *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, TwistCommands);

    if(sample != NULL) {
        if (!TwistCommands_initialize_w_params(sample,alloc_params)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }        
    return sample; 
} 

TwistCommands *
TwistCommandsPluginSupport_create_data_ex(RTIBool allocate_pointers){
    TwistCommands *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, TwistCommands);

    if(sample != NULL) {
        if (!TwistCommands_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }
    return sample; 
}

TwistCommands *
TwistCommandsPluginSupport_create_data(void)
{
    return TwistCommandsPluginSupport_create_data_ex(RTI_TRUE);
}

void 
TwistCommandsPluginSupport_destroy_data_w_params(
    TwistCommands *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {

    TwistCommands_finalize_w_params(sample,dealloc_params);

    RTIOsapiHeap_freeStructure(sample);
}

void 
TwistCommandsPluginSupport_destroy_data_ex(
    TwistCommands *sample,RTIBool deallocate_pointers) {

    TwistCommands_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}

void 
TwistCommandsPluginSupport_destroy_data(
    TwistCommands *sample) {

    TwistCommandsPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
TwistCommandsPluginSupport_copy_data(
    TwistCommands *dst,
    const TwistCommands *src)
{
    return TwistCommands_copy(dst,src);
}

void 
TwistCommandsPluginSupport_print_data(
    const TwistCommands *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILog_debug("%s:\n", desc);
    } else {
        RTILog_debug("\n");
    }

    if (sample == NULL) {
        RTILog_debug("NULL\n");
        return;
    }

    if (sample->prefix==NULL) {
        RTICdrType_printString(
            NULL,"prefix", indent_level + 1);
    } else {
        RTICdrType_printString(
            sample->prefix,"prefix", indent_level + 1);    
    }

    RTICdrType_printLong(
        &sample->sampleId, "sampleId", indent_level + 1);    

    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->payload) != NULL) {
        RTICdrType_printArray(
            DDS_OctetSeq_get_contiguous_bufferI(&sample->payload),
            DDS_OctetSeq_get_length(&sample->payload),
            RTI_CDR_OCTET_SIZE,
            (RTICdrTypePrintFunction)RTICdrType_printOctet,
            "payload", indent_level + 1);
    } else {
        RTICdrType_printPointerArray(
            DDS_OctetSeq_get_discontiguous_bufferI(&sample->payload),
            DDS_OctetSeq_get_length(&sample->payload ),
            (RTICdrTypePrintFunction)RTICdrType_printOctet,
            "payload", indent_level + 1);
    }

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
TwistCommandsPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void 
TwistCommandsPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

    PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
TwistCommandsPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedSampleMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        TwistCommandsPluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        TwistCommandsPluginSupport_destroy_data,
        NULL , NULL );

    if (epd == NULL) {
        return NULL;
    } 

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = TwistCommandsPlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            TwistCommandsPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            TwistCommandsPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
TwistCommandsPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
TwistCommandsPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    TwistCommands *sample,
    void *handle)
{

    TwistCommands_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
TwistCommandsPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    TwistCommands *dst,
    const TwistCommands *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return TwistCommandsPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
TwistCommandsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
TwistCommandsPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const TwistCommands *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_sample) {

        if (!RTICdrStream_serializeString(
            stream, sample->prefix, ((HELLODDS_MAX_STRING_SIZE)) + 1)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeLong(
            stream, &sample->sampleId)) {
            return RTI_FALSE;
        }

        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->payload) != NULL) {
            if (!RTICdrStream_serializePrimitiveSequence(
                stream,
                DDS_OctetSeq_get_contiguous_bufferI(&sample->payload),
                DDS_OctetSeq_get_length(&sample->payload),
                ((HELLODDS_MAX_PAYLOAD_SIZE)),
                RTI_CDR_OCTET_TYPE)) {
                return RTI_FALSE;
            } 
        } else {
            if (!RTICdrStream_serializePrimitivePointerSequence(
                stream,
                (const void **) DDS_OctetSeq_get_discontiguous_bufferI(&sample->payload),
                DDS_OctetSeq_get_length(&sample->payload),
                ((HELLODDS_MAX_PAYLOAD_SIZE)), 
                RTI_CDR_OCTET_TYPE)) {
                return RTI_FALSE;
            } 
        } 

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return retval;
}

RTIBool 
TwistCommandsPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    TwistCommands *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if(deserialize_sample) {

        TwistCommands_initialize_ex(sample, RTI_FALSE, RTI_FALSE);

        if (!RTICdrStream_deserializeStringEx(
            stream,&sample->prefix, ((HELLODDS_MAX_STRING_SIZE)) + 1, RTI_FALSE)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeLong(
            stream, &sample->sampleId)) {
            goto fin; 
        }
        {
            RTICdrUnsignedLong sequence_length;
            if (DDS_OctetSeq_get_contiguous_bufferI(&sample->payload) != NULL) {
                if (!RTICdrStream_deserializePrimitiveSequence(
                    stream,
                    DDS_OctetSeq_get_contiguous_bufferI(&sample->payload),
                    &sequence_length,
                    DDS_OctetSeq_get_maximum(&sample->payload),
                    RTI_CDR_OCTET_TYPE)){
                    goto fin; 
                }
            } else {
                if (!RTICdrStream_deserializePrimitivePointerSequence(
                    stream,
                    (void **) DDS_OctetSeq_get_discontiguous_bufferI(&sample->payload),
                    &sequence_length,
                    DDS_OctetSeq_get_maximum(&sample->payload),
                    RTI_CDR_OCTET_TYPE)){
                    goto fin; 
                }
            }
            if (!DDS_OctetSeq_set_length(&sample->payload, sequence_length)) {
                return RTI_FALSE;
            }

        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool
TwistCommandsPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const TwistCommands *sample)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;

    if (length == NULL) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    TwistCommandsPlugin_get_serialized_sample_max_size(
        NULL, RTI_TRUE, RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE, 0);

    if (buffer == NULL) {
        *length = 
        TwistCommandsPlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE,
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = TwistCommandsPlugin_serialize(
        (PRESTypePluginEndpointData)&epd, sample, &stream, 
        RTI_TRUE, RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE, 
        RTI_TRUE, NULL);  

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;     
}

RTIBool
TwistCommandsPlugin_deserialize_from_cdr_buffer(
    TwistCommands *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    return TwistCommandsPlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

RTIBool 
TwistCommandsPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    TwistCommands **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;
    result= TwistCommandsPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;

}

RTIBool TwistCommandsPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipString (stream, ((HELLODDS_MAX_STRING_SIZE))+1)) {
            goto fin; 
        }
        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }
        {
            RTICdrUnsignedLong sequence_length;
            if (!RTICdrStream_skipPrimitiveSequence(
                stream,
                &sequence_length,
                RTI_CDR_OCTET_TYPE)){
                goto fin; 
            }
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

unsigned int 
TwistCommandsPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, ((HELLODDS_MAX_STRING_SIZE))+1);

    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment,((HELLODDS_MAX_PAYLOAD_SIZE)),RTI_CDR_OCTET_TYPE) ;

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
TwistCommandsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = TwistCommandsPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
TwistCommandsPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
    current_alignment +=    RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment,0, RTI_CDR_OCTET_TYPE);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
TwistCommandsPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const TwistCommands * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (sample==NULL) {
        return 0;
    }

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->prefix);
    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getPrimitiveSequenceSerializedSize(
        current_alignment, 
        DDS_OctetSeq_get_length(&sample->payload),
        RTI_CDR_OCTET_TYPE);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
TwistCommandsPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
TwistCommandsPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const TwistCommands *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_key) {

        if (!TwistCommandsPlugin_serialize(
            endpoint_data,
            sample,
            stream,
            RTI_FALSE, encapsulation_id,
            RTI_TRUE,
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool TwistCommandsPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    TwistCommands *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if (deserialize_key) {

        if (!TwistCommandsPlugin_deserialize_sample(
            endpoint_data, sample, stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool TwistCommandsPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    TwistCommands **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= TwistCommandsPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;    

}

unsigned int
TwistCommandsPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += TwistCommandsPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow,RTI_FALSE, encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

unsigned int
TwistCommandsPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = TwistCommandsPlugin_get_serialized_key_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
TwistCommandsPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    TwistCommands *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;

    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }
    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }
        position = RTICdrStream_resetAlignment(stream);
    }

    if (deserialize_key) {

        if (!TwistCommandsPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return error;
    }       

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *TwistCommandsPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    TwistCommandsPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    TwistCommandsPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    TwistCommandsPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    TwistCommandsPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    TwistCommandsPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    TwistCommandsPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    TwistCommandsPlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    TwistCommandsPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    TwistCommandsPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    TwistCommandsPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    TwistCommandsPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    TwistCommandsPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    TwistCommandsPlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    TwistCommandsPlugin_get_key_kind;

    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL ;    
    plugin->deserializeKeyFnc = NULL;  
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;    
    plugin->typeCode =  (struct RTICdrTypeCode *)TwistCommands_get_typecode();

    plugin->languageKind = PRES_TYPEPLUGIN_CPP_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    TwistCommandsPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    TwistCommandsPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    TwistCommandsPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = TwistCommandsTYPENAME;

    return plugin;
}

void
TwistCommandsPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* ----------------------------------------------------------------------------
*  Type ControllerCommands
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

ControllerCommands*
ControllerCommandsPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params){
    ControllerCommands *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, ControllerCommands);

    if(sample != NULL) {
        if (!ControllerCommands_initialize_w_params(sample,alloc_params)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }        
    return sample; 
} 

ControllerCommands *
ControllerCommandsPluginSupport_create_data_ex(RTIBool allocate_pointers){
    ControllerCommands *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, ControllerCommands);

    if(sample != NULL) {
        if (!ControllerCommands_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }
    return sample; 
}

ControllerCommands *
ControllerCommandsPluginSupport_create_data(void)
{
    return ControllerCommandsPluginSupport_create_data_ex(RTI_TRUE);
}

void 
ControllerCommandsPluginSupport_destroy_data_w_params(
    ControllerCommands *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {

    ControllerCommands_finalize_w_params(sample,dealloc_params);

    RTIOsapiHeap_freeStructure(sample);
}

void 
ControllerCommandsPluginSupport_destroy_data_ex(
    ControllerCommands *sample,RTIBool deallocate_pointers) {

    ControllerCommands_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}

void 
ControllerCommandsPluginSupport_destroy_data(
    ControllerCommands *sample) {

    ControllerCommandsPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
ControllerCommandsPluginSupport_copy_data(
    ControllerCommands *dst,
    const ControllerCommands *src)
{
    return ControllerCommands_copy(dst,src);
}

void 
ControllerCommandsPluginSupport_print_data(
    const ControllerCommands *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILog_debug("%s:\n", desc);
    } else {
        RTILog_debug("\n");
    }

    if (sample == NULL) {
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printShort(
        &sample->steer_angle, "steer_angle", indent_level + 1);    

    RTICdrType_printShort(
        &sample->throttle, "throttle", indent_level + 1);    

    RTICdrType_printBoolean(
        &sample->deadswitch, "deadswitch", indent_level + 1);    

    RTICdrType_printShort(
        &sample->desired_speed, "desired_speed", indent_level + 1);    

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
ControllerCommandsPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void 
ControllerCommandsPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

    PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
ControllerCommandsPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedSampleMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        ControllerCommandsPluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        ControllerCommandsPluginSupport_destroy_data,
        NULL , NULL );

    if (epd == NULL) {
        return NULL;
    } 

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = ControllerCommandsPlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            ControllerCommandsPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ControllerCommandsPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
ControllerCommandsPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
ControllerCommandsPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ControllerCommands *sample,
    void *handle)
{

    ControllerCommands_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
ControllerCommandsPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ControllerCommands *dst,
    const ControllerCommands *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ControllerCommandsPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
ControllerCommandsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
ControllerCommandsPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ControllerCommands *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_sample) {

        if (!RTICdrStream_serializeShort(
            stream, &sample->steer_angle)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->throttle)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeBoolean(
            stream, &sample->deadswitch)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->desired_speed)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return retval;
}

RTIBool 
ControllerCommandsPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ControllerCommands *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if(deserialize_sample) {

        ControllerCommands_initialize_ex(sample, RTI_FALSE, RTI_FALSE);

        if (!RTICdrStream_deserializeShort(
            stream, &sample->steer_angle)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->throttle)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeBoolean(
            stream, &sample->deadswitch)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->desired_speed)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool
ControllerCommandsPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ControllerCommands *sample)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;

    if (length == NULL) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    ControllerCommandsPlugin_get_serialized_sample_max_size(
        NULL, RTI_TRUE, RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE, 0);

    if (buffer == NULL) {
        *length = 
        ControllerCommandsPlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE,
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = ControllerCommandsPlugin_serialize(
        (PRESTypePluginEndpointData)&epd, sample, &stream, 
        RTI_TRUE, RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE, 
        RTI_TRUE, NULL);  

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;     
}

RTIBool
ControllerCommandsPlugin_deserialize_from_cdr_buffer(
    ControllerCommands *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    return ControllerCommandsPlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

RTIBool 
ControllerCommandsPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ControllerCommands **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;
    result= ControllerCommandsPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;

}

RTIBool ControllerCommandsPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipBoolean (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

unsigned int 
ControllerCommandsPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
ControllerCommandsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = ControllerCommandsPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
ControllerCommandsPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
ControllerCommandsPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ControllerCommands * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (sample==NULL) {
        return 0;
    }

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
ControllerCommandsPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
ControllerCommandsPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ControllerCommands *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_key) {

        if (!ControllerCommandsPlugin_serialize(
            endpoint_data,
            sample,
            stream,
            RTI_FALSE, encapsulation_id,
            RTI_TRUE,
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool ControllerCommandsPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ControllerCommands *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if (deserialize_key) {

        if (!ControllerCommandsPlugin_deserialize_sample(
            endpoint_data, sample, stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool ControllerCommandsPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ControllerCommands **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= ControllerCommandsPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;    

}

unsigned int
ControllerCommandsPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += ControllerCommandsPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow,RTI_FALSE, encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

unsigned int
ControllerCommandsPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = ControllerCommandsPlugin_get_serialized_key_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
ControllerCommandsPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ControllerCommands *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;

    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }
    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }
        position = RTICdrStream_resetAlignment(stream);
    }

    if (deserialize_key) {

        if (!ControllerCommandsPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return error;
    }       

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *ControllerCommandsPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    ControllerCommandsPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    ControllerCommandsPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    ControllerCommandsPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    ControllerCommandsPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    ControllerCommandsPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    ControllerCommandsPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    ControllerCommandsPlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    ControllerCommandsPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    ControllerCommandsPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    ControllerCommandsPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    ControllerCommandsPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    ControllerCommandsPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    ControllerCommandsPlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    ControllerCommandsPlugin_get_key_kind;

    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL ;    
    plugin->deserializeKeyFnc = NULL;  
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;    
    plugin->typeCode =  (struct RTICdrTypeCode *)ControllerCommands_get_typecode();

    plugin->languageKind = PRES_TYPEPLUGIN_CPP_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    ControllerCommandsPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    ControllerCommandsPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    ControllerCommandsPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = ControllerCommandsTYPENAME;

    return plugin;
}

void
ControllerCommandsPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* ----------------------------------------------------------------------------
*  Type VehicleTelemetry
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

VehicleTelemetry*
VehicleTelemetryPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params){
    VehicleTelemetry *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, VehicleTelemetry);

    if(sample != NULL) {
        if (!VehicleTelemetry_initialize_w_params(sample,alloc_params)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }        
    return sample; 
} 

VehicleTelemetry *
VehicleTelemetryPluginSupport_create_data_ex(RTIBool allocate_pointers){
    VehicleTelemetry *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, VehicleTelemetry);

    if(sample != NULL) {
        if (!VehicleTelemetry_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
            RTIOsapiHeap_freeStructure(sample);
            return NULL;
        }
    }
    return sample; 
}

VehicleTelemetry *
VehicleTelemetryPluginSupport_create_data(void)
{
    return VehicleTelemetryPluginSupport_create_data_ex(RTI_TRUE);
}

void 
VehicleTelemetryPluginSupport_destroy_data_w_params(
    VehicleTelemetry *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {

    VehicleTelemetry_finalize_w_params(sample,dealloc_params);

    RTIOsapiHeap_freeStructure(sample);
}

void 
VehicleTelemetryPluginSupport_destroy_data_ex(
    VehicleTelemetry *sample,RTIBool deallocate_pointers) {

    VehicleTelemetry_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}

void 
VehicleTelemetryPluginSupport_destroy_data(
    VehicleTelemetry *sample) {

    VehicleTelemetryPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
VehicleTelemetryPluginSupport_copy_data(
    VehicleTelemetry *dst,
    const VehicleTelemetry *src)
{
    return VehicleTelemetry_copy(dst,src);
}

void 
VehicleTelemetryPluginSupport_print_data(
    const VehicleTelemetry *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILog_debug("%s:\n", desc);
    } else {
        RTILog_debug("\n");
    }

    if (sample == NULL) {
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printShort(
        &sample->velocity_mph, "velocity_mph", indent_level + 1);    

    RTICdrType_printShort(
        &sample->velocity_kph, "velocity_kph", indent_level + 1);    

    RTICdrType_printShort(
        &sample->throttle, "throttle", indent_level + 1);    

    RTICdrType_printShort(
        &sample->brake, "brake", indent_level + 1);    

    RTICdrType_printShort(
        &sample->steering, "steering", indent_level + 1);    

    RTICdrType_printShort(
        &sample->roadWheel, "roadWheel", indent_level + 1);    

    RTICdrType_printBoolean(
        &sample->isMoving, "isMoving", indent_level + 1);    

    RTICdrType_printBoolean(
        &sample->EStop, "EStop", indent_level + 1);    

    RTICdrType_printShort(
        &sample->vehicleStatus, "vehicleStatus", indent_level + 1);    

    RTICdrType_printShort(
        &sample->vehicleState, "vehicleState", indent_level + 1);    

    RTICdrType_printShort(
        &sample->gear, "gear", indent_level + 1);    

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
VehicleTelemetryPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void 
VehicleTelemetryPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

    PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
VehicleTelemetryPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedSampleMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        VehicleTelemetryPluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        VehicleTelemetryPluginSupport_destroy_data,
        NULL , NULL );

    if (epd == NULL) {
        return NULL;
    } 

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = VehicleTelemetryPlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            VehicleTelemetryPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            VehicleTelemetryPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
VehicleTelemetryPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
VehicleTelemetryPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    VehicleTelemetry *sample,
    void *handle)
{

    VehicleTelemetry_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
VehicleTelemetryPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    VehicleTelemetry *dst,
    const VehicleTelemetry *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return VehicleTelemetryPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
VehicleTelemetryPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
VehicleTelemetryPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const VehicleTelemetry *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_sample) {

        if (!RTICdrStream_serializeShort(
            stream, &sample->velocity_mph)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->velocity_kph)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->throttle)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->brake)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->steering)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->roadWheel)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeBoolean(
            stream, &sample->isMoving)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeBoolean(
            stream, &sample->EStop)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->vehicleStatus)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->vehicleState)) {
            return RTI_FALSE;
        }

        if (!RTICdrStream_serializeShort(
            stream, &sample->gear)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return retval;
}

RTIBool 
VehicleTelemetryPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    VehicleTelemetry *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if(deserialize_sample) {

        VehicleTelemetry_initialize_ex(sample, RTI_FALSE, RTI_FALSE);

        if (!RTICdrStream_deserializeShort(
            stream, &sample->velocity_mph)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->velocity_kph)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->throttle)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->brake)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->steering)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->roadWheel)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeBoolean(
            stream, &sample->isMoving)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeBoolean(
            stream, &sample->EStop)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->vehicleStatus)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->vehicleState)) {
            goto fin; 
        }
        if (!RTICdrStream_deserializeShort(
            stream, &sample->gear)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool
VehicleTelemetryPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const VehicleTelemetry *sample)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;

    if (length == NULL) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    VehicleTelemetryPlugin_get_serialized_sample_max_size(
        NULL, RTI_TRUE, RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE, 0);

    if (buffer == NULL) {
        *length = 
        VehicleTelemetryPlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE,
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = VehicleTelemetryPlugin_serialize(
        (PRESTypePluginEndpointData)&epd, sample, &stream, 
        RTI_TRUE, RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE, 
        RTI_TRUE, NULL);  

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;     
}

RTIBool
VehicleTelemetryPlugin_deserialize_from_cdr_buffer(
    VehicleTelemetry *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    return VehicleTelemetryPlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

RTIBool 
VehicleTelemetryPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    VehicleTelemetry **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;
    result= VehicleTelemetryPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;

}

RTIBool VehicleTelemetryPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipBoolean (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipBoolean (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

unsigned int 
VehicleTelemetryPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
VehicleTelemetryPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = VehicleTelemetryPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
VehicleTelemetryPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
VehicleTelemetryPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const VehicleTelemetry * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (sample==NULL) {
        return 0;
    }

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
    current_alignment += RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
VehicleTelemetryPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
VehicleTelemetryPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const VehicleTelemetry *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_key) {

        if (!VehicleTelemetryPlugin_serialize(
            endpoint_data,
            sample,
            stream,
            RTI_FALSE, encapsulation_id,
            RTI_TRUE,
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool VehicleTelemetryPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    VehicleTelemetry *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if (deserialize_key) {

        if (!VehicleTelemetryPlugin_deserialize_sample(
            endpoint_data, sample, stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool VehicleTelemetryPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    VehicleTelemetry **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= VehicleTelemetryPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;    

}

unsigned int
VehicleTelemetryPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += VehicleTelemetryPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow,RTI_FALSE, encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

unsigned int
VehicleTelemetryPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = VehicleTelemetryPlugin_get_serialized_key_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
VehicleTelemetryPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    VehicleTelemetry *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;

    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }
    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }
        position = RTICdrStream_resetAlignment(stream);
    }

    if (deserialize_key) {

        if (!VehicleTelemetryPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return error;
    }       

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *VehicleTelemetryPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    VehicleTelemetryPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    VehicleTelemetryPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    VehicleTelemetryPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    VehicleTelemetryPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    VehicleTelemetryPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    VehicleTelemetryPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    VehicleTelemetryPlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    VehicleTelemetryPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    VehicleTelemetryPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    VehicleTelemetryPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    VehicleTelemetryPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    VehicleTelemetryPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    VehicleTelemetryPlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    VehicleTelemetryPlugin_get_key_kind;

    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL ;    
    plugin->deserializeKeyFnc = NULL;  
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;    
    plugin->typeCode =  (struct RTICdrTypeCode *)VehicleTelemetry_get_typecode();

    plugin->languageKind = PRES_TYPEPLUGIN_CPP_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    VehicleTelemetryPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    VehicleTelemetryPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    VehicleTelemetryPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = VehicleTelemetryTYPENAME;

    return plugin;
}

void
VehicleTelemetryPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

