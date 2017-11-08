#include <zeroException.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	divide();

	char c;
	while((c = getchar()) != '\n'){
		if(c == '1')
			return 0;
		if(c == '2')
			divide();
	}
}



void divide(){
	clear_screen();	
	
	printf("Enter two numbers to make an integer division: \n");	
	printf("Dividend: ");	
	
	int dividend = getDivideElement();
	printf("%d\n", dividend);

	printf("Divider: ");	
					
	int divider = getDivideElement();	
	printf("%d\n", divider);
	
	printf("Integer result of dividing %d by %d: %d\n", dividend, divider, dividend/divider);
	
	nextLine();
	nextLine();
	printf("1: EXIT");
	nextLine();
	printf("2: DIVIDE");
}

int getDivideElement(){
	int element = 0;
	char c;

	while((c = getchar()) != '\n'){
		if(isNum(c)){
			element *= 10;	
			element += charToInt(c);
		}
	} 	
	
	return element;
}
