#include <time.h>
#include <keyboard_driver.h>
#include <stdint.h>
#include <types.h>

static void int_20();
static void int_21();

void irqDispatcher(qword irq) {
	
	//Cambiar el switch por un arreglo de punteros a funcion!
	switch (irq) {
		case 0:
			int_20();
			break;
		case 1:
			int_21();
			break;
	}
	return;
}

void int_20(){
	timer_handler();
}

void int_21(){
	keyboard_handler();
}

