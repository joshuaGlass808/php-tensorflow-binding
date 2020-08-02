/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 367c37d82129f78c735b11a868af637fb0eedfbd */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_TFGraph___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_TFGraph___destruct arginfo_class_TFGraph___construct

#define arginfo_class_TFSessionOptions___construct arginfo_class_TFGraph___construct

#define arginfo_class_TFSessionOptions___destruct arginfo_class_TFGraph___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFSessionOptions_setTarget, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_TFBuffer___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_TFBuffer___destruct arginfo_class_TFGraph___construct

#define arginfo_class_TFStatus___construct arginfo_class_TFGraph___construct

#define arginfo_class_TFStatus___destruct arginfo_class_TFGraph___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFStatus_setStatusCode, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, errorCode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFStatus_getStatusMessage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TFStatus_getStatusCode, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(TFGraph, __construct);
ZEND_METHOD(TFGraph, __destruct);
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


static const zend_function_entry class_TFGraph_methods[] = {
	ZEND_ME(TFGraph, __construct, arginfo_class_TFGraph___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TFGraph, __destruct, arginfo_class_TFGraph___destruct, ZEND_ACC_PUBLIC)
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
