#ifndef HAVE_TF_INPUT
#define HAVE_TF_INPUT

#include "php.h"
#include "tf_input.h"
#include "tf_arginfo.h"

void tf_input_free_storage(zend_object* object)
{
    tf_input_t* input = (tf_input_t*) ((char*)object - XtOffsetOf(tf_input_t, std));
    zend_object_std_dtor(&input->std);
}

zend_object* tf_input_create(zend_class_entry* ce)
{
    tf_input_t* input = (tf_input_t*) ecalloc(
        1,
        sizeof(tf_input_t) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&input->std, ce);
    object_properties_init(&input->std, ce);

    input->std.handlers = &tf_input_handlers;

    return &input->std;
}

PHP_METHOD(TFInput, __construct)
{
    tf_input_t* input = INPUT_FETCH(getThis());
    zval* tfOperation = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(tfOperation, tf_operation_ce);
    ZEND_PARSE_PARAMETERS_END();

    input->tf_input.oper = tfOperation->tf_operation;
}

PHP_MINIT_FUNCTION(TF_INPUT)
{
    zend_class_entry input_ce;
    INIT_CLASS_ENTRY(input_ce, "TFInput", class_TFInput_methods);
    tf_input_ce = zend_register_internal_class(&input_ce);
    tf_input_ce->create_object = tf_input_create;

    memcpy(&tf_input_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers));
    
    tf_input_handlers.offset = XtOffsetOf(tf_input_t, std);
    tf_input_handlers.free_obj = tf_input_free_storage;
}

#endif