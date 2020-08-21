#ifndef HAVE_TF_OUTPUT_H
#define HAVE_TF_OUTPUT_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define OUTPUT_FETCH_FROM(o)	((tf_output_t*) (((char*)o) - XtOffsetOf(tf_output_t, std)))
#define OUTPUT_FETCH(z)		OUTPUT_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _tf_output_t {
    TF_Output   tf_output;
    zend_object std;
} tf_output_t;

zend_class_entry* tf_output_ce;
zend_object_handlers tf_output_handlers;

zend_object* tf_output_create(zend_class_entry*);
void tf_output_free_storage(zend_object*);

PHP_MINIT_FUNCTION(TF_OUTPUT);
PHP_METHOD(TFOutput, __construct);

#endif