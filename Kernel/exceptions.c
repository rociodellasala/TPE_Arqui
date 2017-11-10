#include <vsa_driver.h>
#include <registers.h>

#define ZERO_EXCEPTION_ID 0
#define OVERFLOW_EXCEPTION_ID 4
#define INVALID_OPCODE_EXCEPTION_ID 6

static void zero_division();
static void overflow();
static void invalid_opcode();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
	else if (exception == OVERFLOW_EXCEPTION_ID)
		overflow();
	else if (exception == INVALID_OPCODE_EXCEPTION_ID)
		invalid_opcode();
}

static void zero_division() {
	clear_screen();
	print_string("EXCEPTION: DIVIDE ERROR");	
}

static void overflow() {
	clear_screen();
	print_string("EXCEPTION: OVERFLOW");	
}

static void invalid_opcode() {
	clear_screen();
	print_string("EXCEPTION: INVALID OPCODE");	
}
