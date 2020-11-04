#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <string.h>

typedef int (*wrap)(int dirfd, const char *pathname, int flags);

int unlinkat(int dirfd, const char *pathname, int flags) 
{
    wrap orig_unlinkat = dlsym(RTLD_NEXT, "unlinkat");
    if (strstr(pathname, "FIX") != 0) 
        return EPERM;
    return orig_unlinkat(dirfd, pathname, flags);
}