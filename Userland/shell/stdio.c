#include <types.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

extern void int80(qword rdi, qword rsi, qword rdx, qword rcx, qword r8, qword r9);



void printf(const char * str,...){
	char num[12];
	va_list arguments;
	va_start ( arguments,str);
	int length=strlen(str);
	int state=0;
	for(int x=0;x<length;x++){
		if(state==0){
			if(str[x]!= '%')
				putchar(str[x]);
			else
				state=1;
		}else{
			switch(str[x]){
				case 'd':
					intostr(va_arg ( arguments, int),num);
					int index=0;
					while(num[index]!=0)
						putchar(num[index++]);
					state=0;
					break;
				case 'c':
					putchar((char)(va_arg(arguments,int)));
					state=0;
					break;
				case 's':
					printf(va_arg(arguments, char*));
					state = 0;
					break;
				default:	
					putchar('%');
					putchar(str[x]);
					state=0;
					break;
			}
		}

	}	
	va_end(arguments);


}


void clearScreen() {
	int80(2, 1, 0, 0, 0, 0);
	printf("$>:  ");
}

void clearTerminal(){
	int80(2, 1, 0, 0, 0, 0);
}

void putchar(const char c) {
	int80(1, 1, &c, 1, 0, 0);
}


char getchar() {
	char a[2];
	int80(3,0,a,2,0,0);
	if(a[0] == 0 ) return EOF;
	return a[0];
}


void backspace() {
	char c='\b';
	int80(1, 0 , &c, 1 ,0, 0);
}


void newLine(){
	char c='\n';
	int80(1, 0 , &c, 1 ,0, 0);
	printf("$>: ");
}


void intostr(int num,char * ret){
	int dig=0;
	char aux;
	if(num!=0){
		if(num<0){
			num=-num;
			ret[0]='-';
			dig++;
		}
		while(num!=0){
			ret[dig]=(num%10)+'0';
			num=num/10;
			dig++;
		}
		for(int x=0;x<dig/2;x++){
			aux=ret[x];
			ret[x]=ret[dig-x-1];
			ret[dig-x-1]=aux;
		}
		ret[dig]=0;
	}else{
		ret[0]='0';
	}	
}



int changeFontColor(char* color) {
	if(strcmp(color, "blue")) {
		int80(4, 1, 0, 0, 0, 0);
	} else if(strcmp(color, "red")) {
		int80(4, 4, 0, 0, 0, 0);
	} else if(strcmp(color, "violet")) {
		int80(4, 5, 0, 0, 0, 0);
	} else if(strcmp(color, "yellow")) {
		int80(4, 0xE, 0, 0, 0, 0);
	} else if(strcmp(color, "white")) {
		int80(4, 0xF, 0, 0, 0, 0);
	} else {
		return 1;
	}
	return 0;
}







