#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
Habria q ver de pasar la hora de formato BCD a decimal en vez de
restar manualmente.
*/

int main (void){

	clear_screen();
	char * hh;
	char * mm;
	char * ss;
	int h = hour();
	int m = minutes();
	int s = seconds();

	if(h == 1){
		h = 22;
	}else if(h == 2){
		h = 23;
	}else if(h == 0){
		h = 21;
	}else{
		h = h - 3;
	}
	
	printf("Local time is %d:", h);
	if(m < 10){
		printf("0");
	}
	printf("%d:", m);
	if(s < 10){
		printf("0");
	}
	printf("%d", s);

	int i = 0;
	while(i < 500000000){
		i++;
	}

	return 0;
}







