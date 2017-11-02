#include <types.h>
#include <terminal.h>
#include <keyboard_driver.h>
#include <video_driver.h>

static char buffer[2000];


void copyToBuffer(){
	copyscreen(buffer);
}

void printCopy(){
	add_buffer(buffer);
	buffer[0] =  0;
}






