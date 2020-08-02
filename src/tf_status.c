#ifndef HAVE_TF_STATUS
#define HAVE_TF_STATUS

#include "php.h"
#include "tf_status.h"
#include "tf_arginfo.h"

static void tf_status_free_storage(zend_object* object)
{
    tf_status_t* status = (tf_status_t*) ((char*)object - XtOffsetOf(tf_status_t, std));

    zend_object_std_dtor(&status->std);
}

zend_object* tf_status_create(zend_class_entry* ce)
{
    tf_status_t* status = (tf_status_t*) ecalloc(
        1,
        sizeof(tf_status_t) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&status->std, ce);
    object_properties_init(&status->std, ce);

    status->std.handlers = &tf_status_handlers;

    return &status->std;   
}

void tf_status_construct(zval* s)
{
    tf_status_t* status = STATUS_FETCH(s);
    status->tf_status = TF_NewStatus();
}

void tf_status_destruct(zval* s)
{
    tf_status_t* status = STATUS_FETCH(s);
    TF_DeleteStatus(status->tf_status);
}

void tf_set_status(zval* s, int errorCode, const char* context)
{
    tf_status_t* status = STATUS_FETCH(s);
    TF_Code code;
    switch (errorCode) {
        case 0:  code = TF_OK; break;
        case 1:  code = TF_CANCELLED; break;
        case 2:  code = TF_UNKNOWN; break;
        case 3:  code = TF_INVALID_ARGUMENT; break;
        case 4:  code = TF_DEADLINE_EXCEEDED; break;
        case 5:  code = TF_NOT_FOUND; break;
        case 6:  code = TF_ALREADY_EXISTS; break;
        case 7:  code = TF_PERMISSION_DENIED; break;
        case 8:  code = TF_RESOURCE_EXHAUSTED; break;
        case 9:  code = TF_FAILED_PRECONDITION; break;
        case 10: code = TF_ABORTED; break;
        case 11: code = TF_OUT_OF_RANGE; break;
        case 12: code = TF_UNIMPLEMENTED; break;
        case 13: code = TF_INTERNAL; break;
        case 14: code = TF_UNAVAILABLE; break;
        case 15: code = TF_DATA_LOSS; break;
        case 16: code = TF_UNAUTHENTICATED; break;
    }
    TF_SetStatus(status->tf_status, code, context);
}

TF_Code tf_get_code(zval* s) 
{
    tf_status_t* status = STATUS_FETCH(s);

    return TF_GetCode(status->tf_status);
}

char* tf_get_status_message(zval* s) 
{
    tf_status_t* status = STATUS_FETCH(s);

    return (char*) TF_Message(status->tf_status);
}

PHP_METHOD(TFStatus, getStatusMessage)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING(tf_get_status_message(getThis()));
}

PHP_METHOD(TFStatus, getStatusCode)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG((int) tf_get_code(getThis()));
}

PHP_METHOD(TFStatus, setStatusCode)
{
    char* context = NULL;
    size_t len;
    int errorCode;
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "ls", &errorCode, &context, &len) == FAILURE) {
        return;
    }

    tf_set_status(getThis(), errorCode, (const char*) context);
}

PHP_METHOD(TFStatus, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    tf_status_construct(getThis());
}

PHP_METHOD(TFStatus, __destruct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    tf_status_destruct(getThis());
}

PHP_MINIT_FUNCTION(TF_STATUS)
{
	zend_class_entry status_ce;
    INIT_CLASS_ENTRY(status_ce, "TFStatus", class_TFStatus_methods);
    tf_status_ce = zend_register_internal_class(&status_ce);
    tf_status_ce->create_object = tf_status_create;
    
    memcpy(
        &tf_status_handlers,
        zend_get_std_object_handlers(), 
        sizeof(zend_object_handlers)
    );

    tf_status_handlers.offset = XtOffsetOf(tf_status_t, std);
    tf_status_handlers.free_obj = tf_status_free_storage;

    return SUCCESS;
}

#endif