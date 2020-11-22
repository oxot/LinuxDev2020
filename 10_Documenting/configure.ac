#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Number guessr], [0.0], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN(guess)
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/guess.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([string.h libintl.h locale.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile
				Doxyfile
				src/Makefile
				])
AC_OUTPUT
