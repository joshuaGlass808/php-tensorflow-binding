#ifndef HAVE_TF_FUNCTION
#define HAVE_TF_FUNCTION

#include "php.h"
#include "tf_function.h"
#include "tf_arginfo.h"

void tf_function_free_storage(zend_object* object)
{
    tf_function_t* tfFunction = (tf_function_t*) ((char*)object - XtOffsetOf(tf_function_t, std));
    zend_object_std_dtor(&tfFunction->std);
}

zend_object* tf_function_create(zend_class_entry* ce)
{
    tf_function_t* tfFunction = (tf_function_t*) ecalloc(
        1,
        sizeof(tf_function_t) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&tfFunction->std, ce);
    object_properties_init(&tfFunction->std, ce);
    tfFunction->std.handlers = &tf_function_handlers;

    return &tfFunction->std;
}

PHP_METHOD(TFFunction, __construct)
{
    tf_function_t* tfFunction = FUNCTION_FETCH(getThis());
    zval* operDesc = NULL;
    zval* status = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(operDesc, tf_input_ce);
    ZEND_PARSE_PARAMETERS_END();

    tfFunction->tf_function = TF_FinishOperation(operDesc->tf_function_description, status->tf_status);
}

PHP_MINIT_FUNCTION(TF_FUNCTION)
{
    zend_class_entry function_ce;
    INIT_CLASS_ENTRY(function_ce, "TFOperation", class_TFOperation_methods);
    tf_function_ce = zend_register_internal_class(&function_ce);
    tf_function_ce->create_object = tf_function_create;

    memcpy(&tf_function_handlers,
        zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    tf_function_handlers.offset = XtOffsetOf(tf_function_t, std);
    tf_function_handlers.free_obj = tf_function_free_storage;
}

#endif