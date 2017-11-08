#ifndef STDIO_H
#define STDIO_H

#define MAX_SIZE 10

/* Prints string with format */
void printf(const char* str,...);

/* Prints character */
void putchar(unsigned char c);

/* Gets a character, an unsigned char, from stdin */
char getchar();

/* Clears the screen, displaying an empty screen */
void clear_screen();

/* Prints a new line */
void nextLine();


int isNum(char c);

#endif
