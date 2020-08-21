/**
 *   TF_Operation* TF_FinishOperation(
    TF_OperationDescription* desc, TF_Status* status);
 */

#ifndef HAVE_TF_OPERATION
#define HAVE_TF_OPERATION

#include "php.h"
#include "tf_operation.h"
#include "tf_arginfo.h"

void tf_operation_free_storage(zend_object* object)
{
    tf_operation_t* operation = (tf_operation_t*) ((char*)object - XtOffsetOf(tf_operation_t, std));

    zend_object_std_dtor(&operation->std);
}

zend_object* tf_operation_create(zend_class_entry* ce)
{
    tf_operation_t* operation = (tf_operation_t*) ecalloc(
        1,
        sizeof(tf_operation_t) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&operation->std, ce);
    object_properties_init(&operation->std, ce);

    operation->std.handlers = &tf_operation_handlers;

    return &operation->std;
}

PHP_METHOD(TFOperation, __construct)
{
    tf_operation_t* operation = OPERATION_FETCH(getThis());
    zval* operDesc = NULL;
    zval* status = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(operDesc, tf_input_ce);
    ZEND_PARSE_PARAMETERS_END();

    operation->tf_operation = TF_FinishOperation(operDesc->tf_operation_description, status->tf_status);
}

PHP_MINIT_FUNCTION(TF_OPERATION)
{
    zend_class_entry operation_ce;
    INIT_CLASS_ENTRY(operation_ce, "TFOperation", class_TFOperation_methods);
    tf_operation_ce = zend_register_internal_class(&operation_ce);
    tf_operation_ce->create_object = tf_operation_create;

    memcpy(&tf_operation_handlers,
        zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    tf_operation_handlers.offset = XtOffsetOf(tf_operation_t, std);
    tf_operation_handlers.free_obj = tf_operation_free_storage;
}

#endif