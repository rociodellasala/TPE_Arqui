#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <types.h>
#include <stdlib.h>
#define FONT_WIDTH     10
#define FONT_HEIGHT 16
#define MAX_SIZE 2000
#define exit 2
#define WIDTH 1024
#define HEIGHT 768

#include "./include/stdio.h"


int main (void){
	clear_screen();
	int y;
	int a = 0; 
	int b = 0;
	printf("f(x) = ax + b\n");
	printf("Ingresar valor de 'a':\n");
  	char c;
  	int state;
  
  	
	getNum(&a);
	printf("\n");
	

	printf("Ingresar valor de 'b':\n");
	getNum(&b);
	clear_screen();
	

	coordinates();

	if( a == 0){
		for(int i = 0; i < WIDTH; i++){

			draw_pixel(i, HEIGHT-b-HEIGHT/2);
		}	
	}else{

	for(int i = 0; i < WIDTH-(WIDTH/2-HEIGHT/2); i++){
		y = a*i + b;
		draw_pixel(i + (WIDTH/2-HEIGHT/2), HEIGHT-y);
	}

	}


	

	int i=0;

	
	while(i<500000000) {
		i++;
	}

	return 0;
	
}

void coordinates() {

	int x = (WIDTH / 2) - 1;
	int y = (HEIGHT / 2) - 1;

	
	for (int j = 0; j < HEIGHT; j++) {

		draw_pixel(x, j);

	}

	for(int i = 0; i < WIDTH; i++){

		draw_pixel(i, y);
	}
}

void getNum(int* a){
	int state = 0;
	char c;
	char buffer[MAX_SIZE];
	int index = 0;

	while(state != exit) {

		

		if ((c = getchar()) != EOF) {
    			
    			if(c == '\n'){
	      
	      			buffer[index] = 0;
				state = exit;

				}
		
      			 else {
		      		buffer[index] = c;
		      		index++;
		      		buffer[index] = 0;
		     		putchar(buffer[index-1]);	
	  		}	   	
		}	
	}
	for(int k = 0; k < index; k++){
		buffer[k] = buffer[k] - '0';
		*a = (*a) * 10 + buffer[k];
	}
}










