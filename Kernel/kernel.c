#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <keyboard_driver.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <systemcalls.h>
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
	
	ncClear();
	menu();
	
	char opcion = '0';
	
	while(1){
		
		int i = 0;
		
		while((opcion = getBuffer()) == EOF || i<1) {
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
	ncPrint("Choose module:");ncNewline();
	ncPrint("1: Shell");ncNewline();
	ncPrint("2: Display time");ncNewline();
	ncPrint("3: Linear Graph");ncNewline();
	ncPrint("4: Parabolic Graph");ncNewline();
	ncPrint("5: Verify exceptions");ncNewline();
}
