#ifndef HAVE_TF_INPUT_H
#define HAVE_TF_INPUT_H

#include "php.h"
#include <tensorflow/c/c_api.h>

typedef struct _tf_input_t {
  TF_Input tf_input;
  zend_object std;
} tf_input_t;

#define INPUT_FETCH_FROM(o) ((tf_input_t*) (((char*)o) - XtOffsetOf(tf_intput_t, std)))
#define INPUT_FETCH(z)       INPUT_FETCH_FROM(Z_OBJ_P(z))   

zend_class_entry* tf_input_ce;
zend_object_handlers tf_input_handlers;

zend_object* tf_input_create(zend_class_entry*);
void tf_input_free_storage(zend_object*);

PHP_MINIT_FUNCTION(TF_INPUT);
PHP_METHOD(TFInput, __construct);

#endif