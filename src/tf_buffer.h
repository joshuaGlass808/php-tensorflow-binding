#ifndef HAVE_TF_BUFFER_H
#define HAVE_TF_BUFFER_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define BUFFER_FETCH_FROM(o)	((tf_buffer_t*) (((char*)o) - XtOffsetOf(tf_buffer_t, std)))
#define BUFFER_FETCH(z)		BUFFER_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _tf_buffer_t {
    TF_Buffer* tf_buffer;
    zend_object std;
} tf_buffer_t;

zend_class_entry* tf_buffer_ce;
zend_object_handlers tf_buffer_handlers;

zend_object* tf_buffer_create(zend_class_entry*);
void tf_buffer_construct(zval*);
void tf_buffer_construct_from_string(zval*, void*, size_t);
void tf_buffer_destruct(zval*);

PHP_MINIT_FUNCTION(TF_BUFFER);
PHP_METHOD(TFBuffer, __construct);
PHP_METHOD(TFBuffer, __destruct);

#endif

// Need to create a create function.