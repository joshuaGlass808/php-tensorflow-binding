#ifndef TF_SESSION_OPTIONS_H
#define TF_SESSION_OPTIONS_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define SESSION_OPTIONS_FETCH_FROM(o) ((tf_session_options_t*) (((char*)o) - XtOffsetOf(tf_session_options_t, std)))
#define SESSION_OPTIONS_FETCH(z)	  SESSION_OPTIONS_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _tf_session_options_t {
    TF_SessionOptions* tf_session_options;
    zend_object        std;
    char*              target;
} tf_session_options_t;

zend_class_entry* tf_session_options_ce;
zend_object_handlers tf_session_options_handlers;

void tf_session_options_construct(zval*);
void tf_session_options_destruct(zval*);
void tf_session_options_set_target(zval*, char*);

PHP_MINIT_FUNCTION(TF_SESSION);
PHP_METHOD(TFSessionOptions, __construct);
PHP_METHOD(TFSessionOptions, __destruct);
PHP_METHOD(TFSessionOptions, setTarget);

#endif