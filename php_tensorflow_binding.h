/* tensorflow_binding extension for PHP */

#ifndef PHP_TENSORFLOW_BINDING_H
# define PHP_TENSORFLOW_BINDING_H

extern zend_module_entry tensorflow_binding_module_entry;
# define phpext_tensorflow_binding_ptr &tensorflow_binding_module_entry

# define PHP_TENSORFLOW_BINDING_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_TENSORFLOW_BINDING)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_TENSORFLOW_BINDING_H */
