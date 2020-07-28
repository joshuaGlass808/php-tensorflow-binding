dnl config.m4 for extension tensorflow_binding


PHP_ARG_WITH([tensorflow_binding],
  [for tensorflow_binding support],
  [AS_HELP_STRING([--with-tensorflow_binding],
  [Include tensorflow_binding support])])

if test "$PHP_TENSORFLOW_BINDING" != "no"; then
  SEARCH_PATH="/usr/local /usr"     # you might want to change this
  SEARCH_FOR="/include/tensorflow/c/c_api.h"  # you most likely want to change this
  if test -r $PHP_TENSORFLOW_BINDING/$SEARCH_FOR; then # path given as parameter
    TENSORFLOW_BINDING_DIR=$PHP_TENSORFLOW_BINDING
  else # search default path list
    AC_MSG_CHECKING([for tensorflow_binding files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        TENSORFLOW_BINDING_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi
    if test -z "$TENSORFLOW_BINDING_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the tensorflow_binding distribution])
  fi

  # --with-tensorflow_binding -> add include path
  PHP_ADD_INCLUDE($TENSORFLOW_BINDING_DIR)


  LIBNAME=tensorflow
  LIBSYMBOL=TF_NewGraph

  PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TENSORFLOW_BINDING_DIR/$PHP_LIBDIR, TENSORFLOW_BINDING_SHARED_LIBADD)
    AC_DEFINE(HAVE_TENSORFLOW_BINDING_FEATURE, 1, [ ])
  ],[
    AC_MSG_ERROR([FEATURE not supported by your tensorflow_binding library.])
  ],[
    -L$TENSORFLOW_BINDING_DIR/$PHP_LIBDIR -lm
  ])
  
  PHP_SUBST(TENSORFLOW_BINDING_SHARED_LIBADD)

  AC_DEFINE(HAVE_TENSORFLOW_BINDING, 1, [ Have tensorflow_binding support ])
  PHP_NEW_EXTENSION(tensorflow_binding, tensorflow_binding.c src/tf_graph.c src/tf_session_options.c src/tf_buffer.c src/tf_status.c, $ext_shared)
fi
