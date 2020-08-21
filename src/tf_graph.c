#ifndef HAVE_TF_GRAPH
#define HAVE_TF_GRAPH

#include "php.h"
#include "tf_graph.h"
#include "tf_status.h"
#include "tf_output.h"
#include "tf_arginfo.h"

static void tf_graph_free_storage(zend_object *object)
{
    php_tf_graph_t* intern = (php_tf_graph_t*) ((char*)object - XtOffsetOf(php_tf_graph_t, std));

    zend_object_std_dtor(&intern->std);
}

zend_object* tf_graph_create(zend_class_entry* ce)
{
    php_tf_graph_t* graph = (php_tf_graph_t*) ecalloc(
        1,
        sizeof(php_tf_graph_t) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&graph->std, ce);
    object_properties_init(&graph->std, ce);

    graph->std.handlers = &tf_graph_handlers;

    return &graph->std;
}

void tf_graph_construct(zval* g) {
	php_tf_graph_t *graph = GRAPH_FETCH(g);
    graph->tf_graph = TF_NewGraph();
}

void tf_graph_destruct(zval* g) {
    php_tf_graph_t *graph = GRAPH_FETCH(g);
    TF_DeleteGraph(graph->tf_graph);
}

PHP_METHOD(TFGraph, setTensorShape)
{
    zval* output = NULL;
    zval* status = NULL;
    php_tf_graph_t *graph = GRAPH_FETCH(getThis());

    long dims, 
         numDims;

    ZEND_PARSE_PARAMETERS_START(4,4)
        Z_PARAM_OBJECT_OF_CLASS(output, tf_output_ce)
        Z_PARAM_LONG(dims)
        Z_PARAM_LONG(numDims)
        Z_PARAM_OBJECT_OF_CLASS(status, tf_status_ce)
    ZEND_PARSE_PARAMETERS_END();

    TF_GraphSetTensorShape(
        graph->tf_graph,
        (OUTPUT_FETCH(output))->tf_output, 
        (int64_t*) dims, 
        (int) numDims, 
        (STATUS_FETCH(status))->tf_status
    );
}

PHP_METHOD(TFGraph, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    tf_graph_construct(getThis());
}

PHP_METHOD(TFGraph, __destruct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    tf_graph_destruct(getThis());
}

PHP_MINIT_FUNCTION(TF_GRAPH)
{
	zend_class_entry graph_ce;
    INIT_CLASS_ENTRY(graph_ce, "TFGraph", class_TFGraph_methods);
    tf_graph_ce = zend_register_internal_class(&graph_ce);
    tf_graph_ce->create_object = tf_graph_create;
    
    memcpy(&tf_graph_handlers,
            zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    tf_graph_handlers.offset = XtOffsetOf(php_tf_graph_t, std);
    tf_graph_handlers.free_obj = tf_graph_free_storage;

    return SUCCESS;
}

#endif