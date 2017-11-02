#include <video_driver.h>
#include <types.h>
static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static byte * const video = (byte*)0xB8000;
static byte * currentVideo = (byte*)0xB8000;

static byte fontColor = 0xF;
static const dword width = 80;
static const dword height = 25 ;

static char screen[26*160];
static byte * currentScreen=screen;


void updateScreen(){
	for (int i = 0; i < 25; i++) {
		memcpy(video + i*80*2, screen + i*80*2, 80*2);
	}
}


void printString(const char * string) {
	int i;

	for (i = 0; string[i] != 0; i++);
		//printChar(string[i]);
}

void changeFontColor(char newColor) {
	fontColor = newColor;
}

void printChar(char c) {
	if (currentVideo >= ((byte*)0xB8000 + 80*2*25)) {
		scrollDown();
		currentVideo = (byte*)0xB8000 + 80*2*24;
		currentScreen=screen+80*2*24;
	}
	if(c=='\b') {
		backspace();
	} else if(c=='\n') {
		newline();
	} else {
		*currentVideo = c;
		*currentScreen=c;
		currentVideo ++;
		currentScreen++;
		*currentVideo = fontColor;
		*currentScreen=fontColor;
		currentScreen++;
		currentVideo ++;
	}
}
void cleanBack(){
	for(int x=1;x<width*height*2-1;x+=2){
			video[x]=0X07;
			*(screen+x)=0X07;
	}
}

void copyscreen(char *buffer){
	int y=0;
	for (int x=0;x<width*height*2; x+=2)
		if(screen[x+1]==0X6F)
			buffer[y++]=screen[x];
	buffer[y]=0;
}



void scrollDown() {
	for (int i = 0; i < 25; i++) {
		memcpy(video + i*80*2, screen + (i+1)*80*2, 80*2);
		memcpy(screen + i*80*2, screen + (i+1)*80*2, 80*2);
	}
	
	// for (i = 0; i < 25; i++) {
	// 	memcpy(video + i*80*2, video + (i + 1)*80*2, 80*2);
	// }
}

void backspace() {
	if (currentVideo > (byte*)0xB8000) {
		currentVideo -= 2;
		currentScreen-=2;
		printChar(' ');
		currentVideo -= 2;
		currentScreen-=2;
	}
}

void newline() {
	do {
		printChar(' ');
	} while((qword)(currentVideo - video) % (width * 2) != 0);
}

void printDec(qword value) {
	printBase(value, 10);
}

void printHex(qword value) {
	printBase(value, 16);
}

void printBin(qword value) {
	printBase(value, 2);
}

void printBase(qword value, dword base) {
    uintToBase(value, buffer, base);
    printString(buffer);
}

void clear() {
	int i;

	for (i = 0; i < height * width; i++){
		video[i * 2] = ' ';
		screen[i * 2]=' ';
	}
	currentScreen=screen;
	currentVideo = video;
}

static dword uintToBase(qword value, char * buffer, dword base) {
	char *p = buffer;
	char *p1, *p2;
	dword digits = 0;

	//Calculate characters for each digit
	do	{
		dword remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2) {
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}
