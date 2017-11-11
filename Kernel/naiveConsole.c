#include <naiveConsole.h>
#include <vsa_driver.h>

static dword uintToBase(qword value, char * buffer, dword base);

static char buffer[64] = { '0' };
static byte * const video = (byte*)0xB8000;
static byte * currentVideo = (byte*)0xB8000;
static const dword width = 80;
static const dword height = 25 ;

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncPrintChar(char character)
{
	*currentVideo = character;
	currentVideo += 2;
}

void ncNewline()
{
	do
	{
		ncPrintChar(' ');
	}
	while((qword)(currentVideo - video) % (width * 2) != 0);
}

void ncPrintDec(qword value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(qword value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(qword value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(qword value, dword base)
{
    	uintToBase(value, buffer, base);
   	print_string(buffer);
}

void ncClear()
{
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideo = video;
}

static dword uintToBase(qword value, char * buffer, dword base)
{
	char *p = buffer;
	char *p1, *p2;
	dword digits = 0;

	//Calculate characters for each digit
	do
	{
		dword remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}
