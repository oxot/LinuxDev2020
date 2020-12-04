#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Number Guess], [0.1], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([guess.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

define(C, [\/\* COMMENT:: AC_PACKAGE_NAME, AC_PACKAGE_VERSION: $(date) \*\/])
define(V, ["1 s/^\/\* COMMENT::.*\*\//C/; t; 1 s/^/C\n/;"])

sed -i V *.c
sed -i V *.h