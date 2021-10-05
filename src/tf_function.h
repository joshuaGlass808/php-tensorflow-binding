#ifndef HAVE_TF_FUNCTION_H
#define HAVE_TF_FUNCTION_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define FUNCTION_FETCH_FROM(o) ((tf_function_t*) (((char*)o) - XtOffsetOf(tf_function_t, std)))
#define FUNCTION_FETCH(z)		FUNCTION_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _tf_function_t {
    TF_Function* tf_function;
    zend_object std;
} tf_function_t;

zend_class_entry* tf_function_ce;
zend_object_handlers tf_function_handlers;

zend_object* tf_function_create(zend_class_entry*);
void tf_function_free_storage(zend_object*);

PHP_MINIT_FUNCTION(TF_FUNCTION);
PHP_METHOD(TFFunction, __construct);

#endif