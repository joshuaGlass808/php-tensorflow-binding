#ifndef HAVE_TF_STATUS_H
#define HAVE_TF_STATUS_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define STATUS_FETCH_FROM(o) ((tf_status_t*) (((char*)o) - XtOffsetOf(tf_status_t, std)))
#define STATUS_FETCH(z)		 STATUS_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _tf_status_t {
    TF_Status*  tf_status;
    zend_object std;
} tf_status_t;

zend_class_entry* tf_status_ce;
zend_object_handlers tf_status_handlers;

zend_object* tf_status_create(zend_class_entry*);
void tf_status_construct(zval*);
void tf_status_destruct(zval*);

PHP_MINIT_FUNCTION(TF_STATUS);
PHP_METHOD(TFStatus, __construct);
PHP_METHOD(TFStatus, __destruct);


#endif