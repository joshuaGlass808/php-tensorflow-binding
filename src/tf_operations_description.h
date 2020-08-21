#ifndef HAVE_TF_OP_DESC_H
#define HAVE_TF_OP_DESC_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define OPERATION_FETCH_FROM(o)	((tf_operation_desc_t*) (((char*)o) - XtOffsetOf(tf_operation_desc_t, std)))
#define OPER_DESC_FETCH(z)		OPERATION_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _tf_operation_desc_t {
    TF_OperationDescription* tf_oper_desc;
    zend_object std;
} tf_operation_desc_t;

zend_class_entry* tf_operation_desc_ce;
zend_object_handlers tf_operation_desc_handlers;

zend_object* tf_operation_desc_create(zend_class_entry*);
void tf_operation_desc_free_storage(zend_object*);

PHP_MINIT_FUNCTION(TF_OPERATION_DESCRIPTION);
PHP_METHOD(TFOperationDescription, __construct);

#endif