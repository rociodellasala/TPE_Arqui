#ifndef STDIO_H
#define STDIO_H

#include <types.h>

void free(void * x);
int sscanf(char format[90],char str[90], ...);
int scanf(const char* format,...);
int abs(int a);
void intostr(int num,char*a);
void printf(const char* str,...);
void time(char* m,char* h,char* d,char* mo,char* y);
void clearScreen();
char getchar();
void backspace() ;
void newLine();
void putchar(const char a);
int changeFontColor(char* color);
char* readLine();
char* readInt(char* string, int* num);
int isNum(char c);
#endif
