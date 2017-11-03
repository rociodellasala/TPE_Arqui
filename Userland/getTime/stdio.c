#include <stdarg.h>
void intostr(int num,char * ret);
void printf(const char * str,...);

void putchar(const char c) {
	int80(1, 1, &c, 1, 0, 0);
}


void clearScreen() {
	int80(2, 1, 0, 0, 0, 0);
}

void clear_screen() {
	int80(5, 1, 0, 0, 0, 0);
}

void print_string(const char * str, int color ) {
	int80(6, color, str, 0, 0, 0);
}

void print_char(unsigned char c, int color) {
	int80(7, color, c, 0, 0, 0);
}

int strlen(const char* str) {
  int length = 0;
  while(*str != '\0') {
    str++;
    length++;
  }
  return length;
}

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
