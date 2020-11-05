#include <stdio.h>
#include <stdint.h>
#include <setjmp.h>
#include "libbuf.h"


int aborted;
static jmp_buf escape;
float* a = 0;

#suite testnp
#test null
	buf_clear(a);
	ck_assert_int_eq(buf_size(a), 0);
	ck_assert_ptr_eq(a, 0);

#test bufpush
	long *ai = 0;
    for (int i = 0; i < 10000; i++)
        buf_push(ai, i);
	ck_assert_int_eq(buf_size(ai), 10000);
	int match = 0;
	for (int i = 0; i < (int)(buf_size(ai)); i++)
        match += ai[i] == i;
	ck_assert_int_eq(match, 10000);
	buf_free(ai);