lib_LTLIBRARIES = libbuf.la

#bin_PROGRAMS = test1
tests_LDADD = libbuf.la

if COND_GCOV
   CFLAGS += -fprofile-arcs -ftest-coverage -O0 -g
endif

gcov:
	gcov .libs/libnamegen -t -j -k