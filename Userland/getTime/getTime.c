
#include "./include/stdio.h"
#include "./include/time.h"

/*
Habria q ver de pasar la hora de formato BCD a decimal en vez de
restar manualmente.
Pone como un signo grados cuando imprime. 
*/



int main (void){
	clearScreen();
	int h = hour();
	int m = minutes();
	int s = seconds();

	
	if(h == 1){
		h = 22;
	}
	else if(h == 2)
	{
		h = 23;
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






