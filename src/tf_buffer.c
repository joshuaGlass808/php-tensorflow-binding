#ifndef HAVE_TF_BUFFER
#define HAVE_TF_BUFFER

#include "tf_buffer.h"
#include "tf_arginfo.h"

static void tf_buffer_free_storage(zend_object* object) 
{
    tf_buffer_t* obj = (tf_buffer_t*) ((char*)object - XtOffsetOf(tf_buffer_t, std));

    zend_object_std_dtor(&obj->std);
}

zend_object* tf_buffer_create(zend_class_entry* ce)
{
    tf_buffer_t* buffer = (tf_buffer_t*) ecalloc(
        1,
        sizeof(tf_buffer_t) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&buffer->std, ce);
    object_properties_init(&buffer->std, ce);

    buffer->std.handlers = &tf_buffer_handlers;

    return &buffer->std;
}

void tf_buffer_construct(zval* b) 
{
    tf_buffer_t* buffer = BUFFER_FETCH(b);
    buffer->tf_buffer = TF_NewBuffer();
}

void tf_buffer_construct_from_string(zval* b, void* str, size_t str_s)
{
    tf_buffer_t* buffer = BUFFER_FETCH(b);

    TF_Buffer* buff = TF_NewBufferFromString(str, str_s);
}

void tf_buffer_destruct(zval* b)
{
    tf_buffer_t* buffer = BUFFER_FETCH(b);

    TF_DeleteBuffer(buffer->tf_buffer);
}

PHP_METHOD(TFBuffer, __construct)
{
    if (ZEND_NUM_ARGS() > 0) {
        char* str;
        size_t str_s;
        ZEND_PARSE_PARAMETERS_START(0, 1)
            Z_PARAM_OPTIONAL
            Z_PARAM_STRING(str, str_s)
        ZEND_PARSE_PARAMETERS_END();

        tf_buffer_construct_from_string(getThis(), str, str_s);
    } else {
        tf_buffer_construct(getThis());
    }
}

PHP_METHOD(TFBuffer, __destruct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    tf_buffer_destruct(getThis());
}

PHP_MINIT_FUNCTION(TF_BUFFER)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "TFBuffer", class_TFBuffer_methods);
    tf_buffer_ce = zend_register_internal_class(&ce);
    tf_buffer_ce->create_object = tf_buffer_create;

    memcpy(
        &tf_buffer_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    tf_buffer_handlers.offset = XtOffsetOf(tf_buffer_t, std);
    tf_buffer_handlers.free_obj = tf_buffer_free_storage;

    return SUCCESS;
}

#endif