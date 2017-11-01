#ifndef STDIO_H
#define STDIO_H

#include "../types.h"

int strlen(const char* str);
void intostr(int num,char*a);
void printf(const char* str,...);
void clearScreen();
void putchar(const char a);
#endif
