#ifndef TF_SESSION_OPTIONS
#define TF_SESSION_OPTIONS

#include "tf_session_options.h"
#include "tf_arginfo.h"

static void tf_session_options_free_storage(zend_object *object)
{
    tf_session_options_t *options = (tf_session_options_t*) ((char*)object - XtOffsetOf(tf_session_options_t, std));

    zend_object_std_dtor(&options->std);
}

zend_object* tf_session_options_create(zend_class_entry* ce)
{
    tf_session_options_t* options = (tf_session_options_t*) ecalloc(
        1,
        sizeof(tf_session_options_t) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&options->std, ce);
    object_properties_init(&options->std, ce);

    options->std.handlers = &tf_session_options_handlers;

    return &options->std;
}

void tf_session_options_construct(zval* s)
{
    tf_session_options_t *sessionOptions = SESSION_OPTIONS_FETCH(s);

    sessionOptions->tf_session_options = TF_NewSessionOptions();
    sessionOptions->target = "";
}

void tf_session_options_destruct(zval* s)
{
    tf_session_options_t *sessionOptions = SESSION_OPTIONS_FETCH(s);
    TF_DeleteSessionOptions(sessionOptions->tf_session_options);
}

void tf_session_options_set_target(zval* s, char* target)
{
    tf_session_options_t* so = SESSION_OPTIONS_FETCH(s);
    so->target = target;
    TF_SetTarget(so->tf_session_options, target);
}

PHP_METHOD(TFSessionOptions, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();
    tf_session_options_construct(getThis());
}

PHP_METHOD(TFSessionOptions, __destruct)
{
    ZEND_PARSE_PARAMETERS_NONE();
    tf_session_options_destruct(getThis());
}

PHP_METHOD(TFSessionOptions, setTarget)
{
    char* target;
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &target) == FAILURE) {
        return;
    }

    tf_session_options_set_target(getThis(), target);
}

PHP_MINIT_FUNCTION(TF_SESSION)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "TFSessionOptions", class_TFSessionOptions_methods);
    tf_session_options_ce = zend_register_internal_class(&ce);
    tf_session_options_ce->create_object = tf_session_options_create;

    memcpy(
        &tf_session_options_handlers, 
        zend_get_std_object_handlers(), 
        sizeof(zend_object_handlers)
    );

    tf_session_options_handlers.offset = XtOffsetOf(tf_session_options_t, std);
    tf_session_options_handlers.free_obj = tf_session_options_free_storage;

    return SUCCESS;
}

#endif