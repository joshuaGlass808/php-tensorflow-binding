#ifndef HAVE_TF_OPERATION_H
#define HAVE_TF_OPERATION_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define OPERATION_FETCH_FROM(o)	((tf_operation_t*) (((char*)o) - XtOffsetOf(tf_operation_t, std)))
#define OPERATION_FETCH(z)		OPERATION_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _tf_operation_t {
    TF_Operation* tf_operation;
    zend_object std;
} tf_operation_t;

zend_class_entry* tf_operation_ce;
zend_object_handlers tf_operation_handlers;

zend_object* tf_operation_create(zend_class_entry*);
void tf_operation_free_storage(zend_object*);

PHP_MINIT_FUNCTION(TF_OPERATION);
PHP_METHOD(TFOperation, __construct);
PHP_METHOD(TFOperation, finishOperation);
PHP_METHOD(TFOperation, graphOperationByName);
PHP_METHOD(TFOperation, graphNextOperation);

#endif
