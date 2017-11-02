#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <keyboard_driver.h>
#include <moduleLoader.h>
#include <video_driver.h>
#include <interrupts.h>
#include <systemcalls.h>

extern byte text;
extern byte rodata;
extern byte data;
extern byte bss;
extern byte endOfKernelBinary;
extern byte endOfKernel;

static const qword PageSize = 0x1000;
extern unsigned int read();

static void * const shell = (void*)0x400000;
static void * const getTime = (void*)0x500000;
static void * const linearGraph = (void*)0x700000;

typedef int (*EntryPoint)();


void clearBSS(void * bssAddress, qword bssSize) {
	memset(bssAddress, 0, bssSize);
}

void * getStackBase() {
	return (void*)(
		(qword)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(qword)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary() {
	

	void * moduleAddresses[] = {
		shell,
		getTime,
		linearGraph,
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	
	clearBSS(&bss, &endOfKernel - &bss);

	return getStackBase();
}


int main()
{	
	_cli();
	load_idt();
	load_systemcalls();
	_sti();
	
	
	
	char opcion = '0';
	
	while(1){
		clear();
		menu();
		int i = 0;
		
		while((opcion = get_buffer()) == EOF || i<1) {
			i++;
		}


		
		switch(opcion) {
			case '1':
				((EntryPoint)shell)();
				break;

			case '2':
				((EntryPoint)getTime)();
				break;

			case '3':
				((EntryPoint)linearGraph)();
				break;
	

	
		}
	}


	return 0;
}
	
void menu(){
	printChar('1');printChar(':');printChar(' ');printChar('S');printChar('H');printChar('E');printChar('L');printChar('L');newline();
	printChar('2');printChar(':');printChar(' ');printChar('T');printChar('I');printChar('M');printChar('E');newline();
	printChar('3');printChar(':');printChar(' ');printChar('L');printChar('I');printChar('N');printChar('E');printChar('A');printChar('R');
	printChar(' ');printChar('G');printChar('R');printChar('A');printChar('P');printChar('H');newline();
	printChar('4');printChar(':');printChar(' ');printChar('P');printChar('A');printChar('R');printChar('A');printChar('B');printChar('O');
	printChar('L');printChar('I');printChar('C');printChar(' ');printChar('G');printChar('R');printChar('A');printChar('P');printChar('H');newline();
	printChar('5');printChar(':');printChar(' ');printChar('V');printChar('E');printChar('R');printChar('I');printChar('F');printChar('Y');
	printChar(' ');printChar('E');printChar('X');printChar('C');newline();
}
