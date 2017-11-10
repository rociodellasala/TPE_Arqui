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

/* ESTO VA A GRAFICAR CON EL EJE Y CRECIENTE HACIA ABAJO  EJE X CRECIENTE A LA DERECHA*/
void coordinates();

int abs( int a ){
	if(a < 0){
		return a*(-1);
	}
	else
	{
		return a;
	}
}



int main (void){
	clear_screen();
	int a; /*Por ahora funciona con int pero en realidad deberian funcionar con doubles*/
	int b;
	int q; //Seria mi c pero como 'c' ya lo uso para getchar uso q
	printf("f(x) = ax^2 + bx + c\n");
	printf("Ingresar valor de 'a':\n");
	char buffer[MAX_SIZE];
	char buffer2[MAX_SIZE];
	char buffer3[MAX_SIZE];
  	int index= 0;
	int index2 = 0;
	int index3 = 0;
  	char c;
  	int state;
	int y;
  
  	
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
		a = a * 10 + buffer[k];
	}
	
	
	int state2 = 0;
	printf("\n");
	printf("Ingresar valor de 'b':\n");
	while(state2 != exit) {

		

		if ((c = getchar()) != EOF) {
    			
    			if(c == '\n'){
	      
	      			buffer2[index2] = 0;
				state2 = exit;

				}
		
      			 else {
		      		buffer2[index2] = c;
		      		index2++;
		      		buffer2[index2] = 0;
		     		putchar(buffer2[index2-1]);	
	  		}	   	
		}	
	}
	for(int k = 0; k < index2; k++){
		buffer2[k] = buffer2[k] - '0';
		b = b * 10 + buffer2[k];
	}
	
	printf("\n");
	state = 0;
	b = b - 80;


	

	printf("Ingresar valor de 'c':\n");
	while(state != exit) {

		

		if ((c = getchar()) != EOF) {
    			
    			if(c == '\n'){
	      
	      			buffer3[index3] = 0;
				state = exit;

				}
		
      			 else {
		      		buffer3[index3] = c;
		      		index3++;
		      		buffer3[index3] = 0;
		     		putchar(buffer3[index3-1]);	
	  		}	   	
		}	
	}

	for(int w = 0; w < index3; w++){
		buffer3[w] = buffer3[w] - '0';
		q = q * 10 + buffer3[w];
	}

	clear_screen();
	printf("A es: %d \n", a);
	printf("B es: %d \n", b );
	printf("C es: %d \n", q );

	coordinates();
	int ejex;
	int ejey;


	for(int i = -(WIDTH/2-HEIGHT/2)  ; i < WIDTH-(WIDTH/2-HEIGHT/2); i++){
		y = a*i*i + b*i + q;

		ejex = i + (2*(WIDTH/2-HEIGHT/2)+ (WIDTH/2 - 2*(WIDTH/2-HEIGHT/2)));
		ejey = HEIGHT/2 - y/25;
		draw_pixel(ejex  , ejey);
	}

	


	

	int i=0;

	
	while(i<5000000000) {
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









