#include <stdlib.h>

/**COPIADO DE NICO, CAMBIARRRRRRRR O NO SE */
void intToString(int num, char * str){
	int dig = 0;
	char aux;
	if(num != 0){
		if(num < 0){
			num = -num;
			str[0] = '-';
			dig++;
		}
		while(num != 0){
			str[dig] = (num % 10) + '0';
			num = num / 10;
			dig++;
		}
		for(int x = 0; x < dig / 2; x++){
			aux = str[x];
			str[x] = str[dig - x - 1];
			str[dig - x - 1] = aux;
		}
		str[dig] = 0;
	}else{
		str[0] = '0';
	}	
}
