#ifndef HAVE_TF_FUNC_OP_H
#define HAVE_TF_FUNC_OP_H

#include "php.h"
#include <tensorflow/c/c_api.h>

#define FUNC_OP_FETCH_FROM(o)	((tf_func_op_t*) (((char*)o) - XtOffsetOf(tf_func_op_t, std)))
#define FUNC_OP_FETCH(z)		FUNC_OP_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

typedef struct _tf_func_op_t {
    TF_FunctionOptions
} tf_func_op_t;

//@todo - finish this class.


#endif