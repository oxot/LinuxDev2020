TESTS = test1 test2 testnp testgtp
check_PROGRAMS = test1 test2 testnp testgtp
CFLAGS = @CHECK_CFLAGS@ -I../src
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@

.ts.c:
		checkmk $< > $@