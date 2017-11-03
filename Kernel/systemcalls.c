#include <types.h>
#include <interrupts.h>
#include <keyboard_driver.h>
#include <video_driver.h>
#include "./include/vsa_driver.h"


typedef qword (*sys)(qword rsi, qword rdx, qword rcx, qword r8, qword r9);

static sys sysCalls[10]; //Change this number to the total of the system calls - actualmente son 4

qword sys_clear(qword rsi, qword rdx, qword rcx, qword r8, qword r9) {
    clear(); 
    return 0;
}

qword sys_write(qword file, qword buffer, qword size, qword r8, qword r9) {

    char* charbuffer=(char*)buffer;
    while(size--) {
      printChar(*charbuffer++); //Change this function to something we program
    }

  return 1;
}

qword sys_read(qword file, qword buffer, qword size, qword r8, qword r9) {
    read_buffer((char*) buffer, (int) size);
    return 1;
}

qword sys_fontColor(qword color, qword rdx, qword rcx, qword r8, qword r9) {
    changeFontColor(color);
    return 1;
}

qword sys_clearScreen(qword color, qword rdx, qword rcx, qword r8, qword r9) {
    clear_screen();
    return 1;
}

qword sys_prtString(qword color, qword pal, qword rcx, qword r8, qword r9) {
    print_string(pal, color );
    return 1;
}

qword sys_prtChar(qword color, qword c, qword rcx, qword r8, qword r9) {
    print_char(c, color );
    return 1;
}

qword sys_nextLine(qword color, qword c, qword rcx, qword r8, qword r9) {
    nextLine();
    return 1;
}

void load_systemcalls(){
 
 	sysCalls[1] = &sys_write;
  	sysCalls[2] = &sys_clear;
  	sysCalls[3] = &sys_read;
  	sysCalls[4] = &sys_fontColor;
	sysCalls[5] = &sys_clearScreen;
	sysCalls[6] = &sys_prtString;
	sysCalls[7] = &sys_prtChar;
	sysCalls[8] = &sys_nextLine;

  setup_IDT_entry(0x80, (qword)&_irq80Handler); 
}


void syscallHandler(qword rdi,qword rsi, qword rdx, qword rcx, qword r8, qword r9) {

    if(rdi < 0 || rdi >= 10) { //Change this number to the total of the system calls
        //DO NOTHING
        return;
    }
    sysCalls[rdi](rsi,rdx,rcx,r8,r9);
}
