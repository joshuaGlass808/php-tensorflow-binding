/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 989b917cbdb35b28af7d762df3368e80247eb212 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_TFOperation___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_TFOperation___destruct arginfo_class_TFOperation___construct

#define arginfo_class_TFOperationDescription___construct arginfo_class_TFOperation___construct

#define arginfo_class_TFOperationDescription___destruct arginfo_class_TFOperation___construct

#define arginfo_class_TFInput___construct arginfo_class_TFOperation___construct

#define arginfo_class_TFInput___destruct arginfo_class_TFOperation___construct

#define arginfo_class_TFOutput___construct arginfo_class_TFOperation___construct

#define arginfo_class_TFOutput___destruct arginfo_class_TFOperation___construct

#define arginfo_class_TFFuntion___construct arginfo_class_TFOperation___construct

#define arginfo_class_TFFuntion___destruct arginfo_class_TFOperation___construct

#define arginfo_class_TFFunctionOperations___construct arginfo_class_TFOperation___construct

#define arginfo_class_TFFunctionOperations___destruct arginfo_class_TFOperation___construct

#define arginfo_class_TFGraph___construct arginfo_class_TFOperation___construct

#define arginfo_class_TFGraph___destruct arginfo_class_TFOperation___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFGraph_setTensorShape, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, output, TFOutput, 0)
	ZEND_ARG_TYPE_INFO(0, dims, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, numDims, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, status, TFStatus, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_TFSessionOptions___construct arginfo_class_TFOperation___construct

#define arginfo_class_TFSessionOptions___destruct arginfo_class_TFOperation___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFSessionOptions_setTarget, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_TFBuffer___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_TFBuffer___destruct arginfo_class_TFOperation___construct

#define arginfo_class_TFStatus___construct arginfo_class_TFOperation___construct

#define arginfo_class_TFStatus___destruct arginfo_class_TFOperation___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFStatus_setStatusCode, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, errorCode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFStatus_getStatusMessage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFStatus_getStatusCode, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(TFOperation, __construct);
ZEND_METHOD(TFOperation, __destruct);
ZEND_METHOD(TFOperationDescription, __construct);
ZEND_METHOD(TFOperationDescription, __destruct);
ZEND_METHOD(TFInput, __construct);
ZEND_METHOD(TFInput, __destruct);
ZEND_METHOD(TFOutput, __construct);
ZEND_METHOD(TFOutput, __destruct);
ZEND_METHOD(TFFuntion, __construct);
ZEND_METHOD(TFFuntion, __destruct);
ZEND_METHOD(TFFunctionOperations, __construct);
ZEND_METHOD(TFFunctionOperations, __destruct);
ZEND_METHOD(TFGraph, __construct);
ZEND_METHOD(TFGraph, __destruct);
ZEND_METHOD(TFGraph, setTensorShape);
ZEND_METHOD(TFSessionOptions, __construct);
ZEND_METHOD(TFSessionOptions, __destruct);
ZEND_METHOD(TFSessionOptions, setTarget);
ZEND_METHOD(TFBuffer, __construct);
ZEND_METHOD(TFBuffer, __destruct);
ZEND_METHOD(TFStatus, __construct);
ZEND_METHOD(TFStatus, __destruct);
ZEND_METHOD(TFStatus, setStatusCode);
ZEND_METHOD(TFStatus, getStatusMessage);
ZEND_METHOD(TFStatus, getStatusCode);


static const zend_function_entry class_TFOperation_methods[] = {
	ZEND_ME(TFOperation, __construct, arginfo_class_TFOperation___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFOperation, __destruct, arginfo_class_TFOperation___destruct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFOperationDescription_methods[] = {
	ZEND_ME(TFOperationDescription, __construct, arginfo_class_TFOperationDescription___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFOperationDescription, __destruct, arginfo_class_TFOperationDescription___destruct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFInput_methods[] = {
	ZEND_ME(TFInput, __construct, arginfo_class_TFInput___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFInput, __destruct, arginfo_class_TFInput___destruct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFOutput_methods[] = {
	ZEND_ME(TFOutput, __construct, arginfo_class_TFOutput___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFOutput, __destruct, arginfo_class_TFOutput___destruct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFFuntion_methods[] = {
	ZEND_ME(TFFuntion, __construct, arginfo_class_TFFuntion___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFFuntion, __destruct, arginfo_class_TFFuntion___destruct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFFunctionOperations_methods[] = {
	ZEND_ME(TFFunctionOperations, __construct, arginfo_class_TFFunctionOperations___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFFunctionOperations, __destruct, arginfo_class_TFFunctionOperations___destruct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFGraph_methods[] = {
	ZEND_ME(TFGraph, __construct, arginfo_class_TFGraph___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFGraph, __destruct, arginfo_class_TFGraph___destruct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFGraph, setTensorShape, arginfo_class_TFGraph_setTensorShape, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFSessionOptions_methods[] = {
	ZEND_ME(TFSessionOptions, __construct, arginfo_class_TFSessionOptions___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFSessionOptions, __destruct, arginfo_class_TFSessionOptions___destruct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFSessionOptions, setTarget, arginfo_class_TFSessionOptions_setTarget, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFBuffer_methods[] = {
	ZEND_ME(TFBuffer, __construct, arginfo_class_TFBuffer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFBuffer, __destruct, arginfo_class_TFBuffer___destruct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TFStatus_methods[] = {
	ZEND_ME(TFStatus, __construct, arginfo_class_TFStatus___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFStatus, __destruct, arginfo_class_TFStatus___destruct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFStatus, setStatusCode, arginfo_class_TFStatus_setStatusCode, ZEND_ACC_PUBLIC)
	ZEND_ME(TFStatus, getStatusMessage, arginfo_class_TFStatus_getStatusMessage, ZEND_ACC_PUBLIC)
	ZEND_ME(TFStatus, getStatusCode, arginfo_class_TFStatus_getStatusCode, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
