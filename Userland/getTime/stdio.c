#include <types.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

extern void int80(qword rdi, qword rsi, qword rdx, qword rcx, qword r8, qword r9);

/* Esto esta mal, printf recibe formato pero no se q hacer :(  PREGUNTARRR */
void printf(const char * str){
	int size = strlen(str);	
	int80(1, str, size, 0, 0, 0);
}

void clear_screen(){
	int80(2, 1, 0, 0, 0, 0);
}



