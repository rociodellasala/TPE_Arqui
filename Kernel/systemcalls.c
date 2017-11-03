#include <types.h>
#include <interrupts.h>
#include <keyboard_driver.h>
#include <time.h>
#include <vsa_driver.h>

typedef qword (*sys)(qword rsi, qword rdx, qword rcx, qword r8, qword r9);

static sys sysCalls[11]; //Change this number to the total of the system calls - actualmente son 4

void sys_clear(qword rsi, qword rdx, qword rcx, qword r8, qword r9) {
	clear_screen();
}

void sys_write(qword buffer, qword size, qword rcx, qword r8, qword r9) {
	
	if(size == 1)
		print_char(buffer);
	else 
		print_string(buffer);
}

void sys_read(qword file, qword buffer, qword size, qword r8, qword r9) {
	read_buffer((char*) buffer, (int) size);   
}

void sys_fontColor(qword color, qword rdx, qword rcx, qword r8, qword r9) {
	changeFontColor(color);  
}

void sys_sleep(qword time, qword rdx, qword rcx, qword r8, qword r9){	
	sleep(time);
}

void sys_delete(qword rsi, qword rdx, qword rcx, qword r8, qword r9) {
	delete();
}

void sys_nextLine(qword rsi, qword rdx, qword rcx, qword r8, qword r9) {
    nextLine();
}

void load_systemcalls(){
 
	sysCalls[1] = &sys_write;
	sysCalls[2] = &sys_clear;
	sysCalls[3] = &sys_read;
	sysCalls[4] = &sys_fontColor;
	sysCalls[5] = &sys_nextLine;
	sysCalls[6] = &sys_sleep;
	sysCalls[7] = &sys_delete;

	 setup_IDT_entry(0x80, (qword)&_irq80Handler); 
}


void syscall_handler(qword rdi,qword rsi, qword rdx, qword rcx, qword r8, qword r9) {

	    if(rdi < 0 || rdi >= 11) { //Change this number to the total of the system calls
		return;
	    }

	    sysCalls[rdi](rsi,rdx,rcx,r8,r9);
}
