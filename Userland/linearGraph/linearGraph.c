#include <stdarg.h>
#include "./include/stdio.h"


static void putPixel(unsigned char* screen, int x,int y, int color) {
    unsigned where = x*3 + y*2400;
    screen[where] = color & 255;              // BLUE
    screen[where + 1] = (color >> 8) & 255;   // GREEN
    screen[where + 2] = (color >> 16) & 255;  // RED
}


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
	clearScreen();
	unsigned char *screen = (unsigned char *) 0xA0000000;
	int dx, dy, p, end;
	float x1, x2, y1, y2, x, y;
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
	putPixel(screen, x, y, 10);
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
		putPixel(screen, x, y, 10);
	}

	int i=0;
	while(i<500000000) {
		i++;
	}

	return 0;
}




