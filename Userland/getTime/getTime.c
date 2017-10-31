#include <stdarg.h>
unsigned int month();
unsigned int seconds();
unsigned int minutes();
unsigned int hour();

/*
Estas cosas hay q separarlos en .h y otros archivos
Habria q ver de pasar la hora de formato BCD a decimal en vez de
restar manualmente.
Pone como un signo grados cuando imprime. 
*/
void intostr(int num,char * ret);
void printf(const char * str,...);

int strlen(const char* str) {
  int length = 0;
  while(*str != '\0') {
    str++;
    length++;
  }
  return length;
}

void putchar(const char c) {
	int80(1, 1, &c, 1, 0, 0);
}


void clearScreen() {
	int80(2, 1, 0, 0, 0, 0);
}

int main (void){
	clearScreen();
	//int mes = month();
	int h = hour();
	int m = minutes();
	int s = seconds();
	
	if(h == 1){
		h = 22;
	}
	else if(h == 0){
		h = 21;
	}
	else{
		h = h-3;
	}
	printf("%d",h);
	printf(":");
	printf("%d",m);
	printf(":");
	printf("%d\n",s);

	int i=0;
	while(i<500000000) {
		i++;
	}

	return 0;
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




