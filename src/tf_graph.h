#ifndef HAVE_TF_GRAPH_H
#define HAVE_TF_GRAPH_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define GRAPH_FETCH_FROM(o)	((php_tf_graph_t*) (((char*)o) - XtOffsetOf(php_tf_graph_t, std)))
#define GRAPH_FETCH(z)		GRAPH_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _php_tf_graph_t {
    TF_Graph*   tf_graph;
    zend_object std;
} php_tf_graph_t;

zend_class_entry* tf_graph_ce;
zend_object_handlers tf_graph_handlers;

zend_object* tf_graph_create(zend_class_entry*);

void tf_graph_construct(zval*);
void tf_graph_destruct(zval*);

PHP_MINIT_FUNCTION(TF_GRAPH);
PHP_METHOD(TFGraph, __construct);
PHP_METHOD(TFGraph, __destruct);
PHP_METHOD(TFGraph, setTensorShape);

#endif