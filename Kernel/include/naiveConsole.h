#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>
#include <types.h>

void ncPrint(const char * string);
void ncPrintChar(char character);
void ncNewline();
void ncPrintDec(qword value);
void ncPrintHex(qword value);
void ncPrintBin(qword value);
void ncPrintBase(qword value, dword base);
void ncClear();

#endif
