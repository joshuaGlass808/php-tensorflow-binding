#ifndef HAVE_TF_OP_DESC
#define HAVE_TF_OP_DESC

#include "php.h"
#include "tf_operations_description.h"
#include "tf_arginfo.h"
#include "tf_status.h"
#include "tf_graph.h"

/*

Not sure if below should some how be apart of freeing the description or not.

Best guess is to not touch it.

// If this function succeeds:
//   * *status is set to an OK value,
//   * a TF_Operation is added to the graph,
//   * a non-null value pointing to the added operation is returned --
//     this value is valid until the underlying graph is deleted.
// Otherwise:
//   * *status is set to a non-OK value,
//   * the graph is not modified,
//   * a null value is returned.
// In either case, it deletes `desc`.
TF_CAPI_EXPORT extern TF_Operation* TF_FinishOperation(
    TF_OperationDescription* desc, TF_Status* status);
*/
void tf_operation_desc_free_storage(zend_object* object)
{
    tf_operation_desc_t* oper_desc = (tf_operation_desc_t*) ((char*)object - XtOffsetOf(tf_operation_desc_t, std));
    zend_object_std_dtor(&oper_desc->std);
}

zend_object* tf_operation_desc_create(zend_class_entry* ce)
{
    tf_operation_desc_t* oper_desc = (tf_operation_desc_t*) ecalloc(
        1,
        sizeof(tf_operation_desc_t*) + zend_object_properties_size(ce)
    );

    zend_object_std_init(&oper_desc->std, ce);
    object_properties_init(&oper_desc->std, ce);

    oper_desc->std.handlers = &tf_operation_desc_handlers;

    return &oper_desc->std;
}

PHP_METHOD(TFOperationDescription, __construct)
{
    tf_operation_desc_t* oper_desc = OPER_DESC_FETCH(getThis());
    zval* tfGraph = NULL;
    zend_string *operType, *operName;
    size_t typeSize, nameSize;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS(tfGraph, tf_graph_ce)
        Z_PARAM_STRING(operType, typeSize)
        Z_PARAM_STRING(operName, nameSize)
    ZEND_PARSE_PARAMETERS_END();

    php_tf_graph_t* tfRGraph;
    tfRGraph = GRAPH_FETCH(tfGraph);

    oper_desc->tf_oper_desc = TF_NewOperation(
        tfRGraph->tf_graph,
        (char*) operType,
        (char*) operName
    );
}

PHP_MINIT_FUNCTION(TF_OPERATION_DESCRIPTION)
{
    zend_class_entry oper_desc_ce;
    INIT_CLASS_ENTRY(oper_desc_ce, "TFOperationDescription", class_TFOperationDescription_methods);
    tf_operation_desc_ce = zend_register_internal_class(&oper_desc_ce);
    tf_operation_desc_ce->create_object = tf_operation_desc_create;

    memcpy(
        &tf_operation_desc_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );
    tf_operation_desc_handlers.offset = XtOffsetOf(tf_operation_desc_t, std);
    tf_operation_desc_handlers.free_obj = tf_operation_desc_free_storage;
}

#endif