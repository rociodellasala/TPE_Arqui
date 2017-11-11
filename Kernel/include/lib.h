#ifndef LIB_H
#define LIB_H

#include <types.h>

/* comment */
void * memset(void * destination, dword character, qword length);

/* comment */
void * memcpy(void * destination, const void * source, qword length);

/* comment */
char * cpuVendor(char *result);

#endif
