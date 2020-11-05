#include <stdio.h>
#include <stdint.h>
#include <setjmp.h>
#include "libbuf.h"


int aborted;
static jmp_buf escape;
float* a = 0;

#suite testgtp
#test bufgrowtrunc 
	long *ai = 0;
	buf_grow(ai, 1000);
	ck_assert_int_eq(buf_capacity(ai), 1000);
	ck_assert_int_eq(buf_size(ai), 0);
    buf_trunc(ai, 100);
	ck_assert_int_eq(buf_capacity(ai), 100);
    buf_free(ai);

#test bufpop
    buf_push(a, 1.1);
    buf_push(a, 1.2);
    buf_push(a, 1.3);
    buf_push(a, 1.4);
	ck_assert_int_eq(buf_size(a), 4);
    ck_assert_int_eq(buf_pop(a), (float)1.4f);
    buf_trunc(a, 3);
	ck_assert_int_eq(buf_size(a), 3);
    ck_assert_int_eq(buf_pop(a), (float)1.3f);
    ck_assert_int_eq(buf_pop(a), (float)1.2f);
    ck_assert_int_eq(buf_pop(a), (float)1.1f);
	ck_assert_int_eq(buf_size(a), 0);
    buf_free(a);	