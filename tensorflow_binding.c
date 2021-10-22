/* tensorflow_binding extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_tensorflow_binding.h"
#include "tensorflow_binding_arginfo.h"

#include <tensorflow/c/c_api.h>

#include "src/tf_graph.h"
#include "src/tf_session_options.h"
#include "src/tf_buffer.h"
#include "src/tf_status.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif


PHP_FUNCTION(tf_version)
{
	ZEND_PARSE_PARAMETERS_NONE();
	zend_string *v;
	v = strpprintf(0, "%s", TF_Version());

	RETURN_STR(v);
}


PHP_MINIT_FUNCTION(tensorflow_binding)
{
	PHP_MINIT(TF_GRAPH)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(TF_SESSION)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(TF_BUFFER)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(TF_STATUS)(INIT_FUNC_ARGS_PASSTHRU);

    return SUCCESS;
}

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(tensorflow_binding)
{
#if defined(ZTS) && defined(COMPILE_DL_TENSORFLOW_BINDING)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(tensorflow_binding)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "tensorflow_binding support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ tensorflow_binding_module_entry
 */
zend_module_entry tensorflow_binding_module_entry = {
	STANDARD_MODULE_HEADER,
	"tensorflow_binding",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(tensorflow_binding),							/* PHP_MINIT - Module initialization */
	NULL, //							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(tensorflow_binding),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(tensorflow_binding),			/* PHP_MINFO - Module info */
	PHP_TENSORFLOW_BINDING_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};

/* }}} */

#ifdef COMPILE_DL_TENSORFLOW_BINDING
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(tensorflow_binding)
#endif
