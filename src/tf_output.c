#ifndef HAVE_TF_OUTPUT
#define HAVE_TF_OUTPUT

#include "php.h"
#include "tf_output.h"
#include "tf_arginfo.h"

void tf_output_free_storage(zend_object* object)
{
    tf_output_t* output = (tf_output_t*) ((char*)object - XtOffsetOf(tf_output_t, std));

    zend_object_std_dtor(&output->std);
}

zend_object* tf_output_create(zend_class_entry* ce)
{
    tf_output_t* output = (tf_output_t*) ecalloc(
        1,
        sizeof(tf_output_t) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&output->std, ce);
    object_properties_init(&output->std, ce);

    output->std.handlers = &tf_output_handlers;

    return &output->std;
}

PHP_METHOD(TFOutput, __construct)
{
    tf_output_t* output = OUTPUT_FETCH(getThis());
    zval* tfInput = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(tfInput, tf_input_ce);
    ZEND_PARSE_PARAMETERS_END();

    output->tf_output = TF_OperationInput((TF_Input) tfInput->tf_input);
}

PHP_MINIT_FUNCTION(TF_OUTPUT)
{
    zend_class_entry output_ce;
    INIT_CLASS_ENTRY(output_ce, "TFOutput", class_TFOutput_methods);
    tf_output_ce = zend_register_internal_class(&output_ce);
    tf_output_ce->create_object = tf_output_create;

    memcpy(&tf_output_handlers,
        zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    tf_output_handlers.offset = XtOffsetOf(tf_output_t, std);
    tf_output_handlers.free_obj = tf_output_free_storage;
}

#endif