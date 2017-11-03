#include <unistd.h>
#include <stdio.h>

void sleep(){
	int time = 5000000000;
	int80(6,time,0,0,0,0);
	printf("Dormi 13 segundos");
	nextLine();
}


