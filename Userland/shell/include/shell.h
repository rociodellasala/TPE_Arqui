#ifndef SHELL_H
#define SHELL_H

void initShell();
int callfunction(char* buffer, int *currColor);
void echo(char * buffer, int currColor);
void printHelp(int currColor);
int changeFontColor(char* color, int* currColor) ;


#endif
