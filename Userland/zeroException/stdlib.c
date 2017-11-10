#include <stdlib.h>

/**COPIADO DE NICO, CAMBIARRRRRRRR O NO SE */
void intToString(int num, char* str){
	int dig = 0;
	char aux;
	if(num!=0){
		if(num<0){
			num=-num;
			str[0]='-';
			dig++;
		}
		while(num!=0){
			str[dig]=(num%10)+'0';
			num=num/10;
			dig++;
		}
		for(int x=0;x<dig/2;x++){
			aux=str[x];
			str[x]=str[dig-x-1];
			str[dig-x-1]=aux;
		}
		str[dig]=0;
	}else{
		str[0]='0';
	}	
}

int charToInt(unsigned char c){
	int ret;
 	
	switch(c){
		case '0':	ret = 0;
				break;

		case '1':	ret = 1;
				break;

		case '2':	ret = 2;
				break;

		case '3':	ret = 3;
				break;

		case '4':	ret = 4;
				break;

		case '5':	ret = 5;
				break;

		case '6':	ret = 6;
				break;

		case '7':	ret = 7;
				break;

		case '8':	ret = 8;
				break;

		case '9':	ret = 9;
				break;
		
		
	}
	
	return ret;
	

}	
