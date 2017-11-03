#include <stdarg.h>
#include <stdint.h>
#define FONT_WIDTH     10
#define FONT_HEIGHT 16

#include "./include/stdio.h"
#include "./include/vsa_driver.h"



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
	start_video_mode();
	int dx, dy, p, end;
	float x1, x2, y1, y2, x, y;
	printf("Si estoy en modo texto esta imprimiendo esto y tira excepcion");
	 print_string("Estoy usando print_string de mi vha_driver.c", 0xFF0000 );
	/*
	printf("Enter Value of X1: ");
	scanf("%f", &x1);
	printf("Enter Value of Y1: ");
	scanf("%f", &y1);
	printf("Enter Value of X2: ");
	scanf("%f", &x2);
	printf("Enter Value of Y2: ");
	scanf("%f", &y2);*/
	
	x1 = 2;
	x2 = 100;
	y1 = 2;
	y2 = 100;
	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	p = 2 * dy - dx;
	if(x1 > x2)
	{
		x = x2;
		y = y2;
		end = x1;
	}
	else
	{
		x = x1;
		y = y1;
		end = x2;
      }
	draw_pixel( x, y, 0xFF0000);
	while(x < end)
	{
		x = x + 1;
		if(p < 0)
		{
			p = p + 2 * dy;
		}
		else
		{
			y = y + 1;
			p = p + 2 * (dy - dx);
		}
		draw_pixel(x, y, 0xFF0000);
	}

	int i=0;

	
	while(i<500000000) {
		i++;
	}

	return 0;
	
}







