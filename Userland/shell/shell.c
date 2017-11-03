#include <types.h>
#include <shell.h>
#include <stdio.h>
#include <string.h>

int main() {

	initShell();
  
	return 0;
}

void initShell() {

  clear_screen();
  char buffer[25*80];
  int index=1;
  char c;
  int state;
  int currColor = 0xFFFFFF;
  boolean first=true;

	nextLine();

  while(1) {
    if ((c = getchar()) != EOF) {
    	if(c=='\b'){
    		if(index!=0){
    			index--;
    			buffer[index]=0;
    			backspace();
    		}
    	}
      	else{
      		if(c=='\n'){
      			nextLine();
      			buffer[index]=0;
      			state=callfunction(buffer, &currColor);
				if(state == 1){
					print_string("Unknown command: Type help to see the different functionalities", currColor);
					//printf();
					nextLine();
				} else if(state == 2) {
					return 0;
				}
				index=0;
				buffer[0]=0;
      		}else{
	      		buffer[index]=c;
	      		index++;
	      		buffer[index]=0;
	     		print_char(buffer[index-1], currColor);	
	  		}	   
	  	}
		}
		if(first){
			backspace();
			index--;
			buffer[index]=0;
			first=false;
		}
	}
	
}

int callfunction(char* buffer, int *currColor) {
	int x=0;
	char function[10];
	//printf("%s",buffer);
	while(buffer[x]!=' ' && buffer[x]!=0) {
		function[x]=buffer[x];
		x++;
		if(x>9)
			return 1;
	}
	function[x]=0;
	if(strcmp(function, "echo")) {
		echo(buffer+x+1, *currColor);
		return 0;
	}
	if(strcmp(function, "fontColor")) {
		return changeFontColor(buffer+x+1, currColor);
	}
	if(strcmp(function, "clear")) {
		 clear_screen();
		nextLine();
		 return 0;
	}
	if(strcmp(function, "help")) {
		printHelp(*currColor); 
		return 0;
	}
	if(strcmp(function, "exit")) {
		return 2;
	}
	
	return 1;
}

void echo(char * buffer, int currColor){
	print_string(buffer, currColor);
	//printf(buffer); //!!!
	nextLine();
}


void printHelp(int currColor) {
	//clearTerminal();
	print_string("\n", 0xFFFFFF);
	print_string("clear:                  Clears the screen.\n", currColor);
	print_string("echo [message]:         Prints message.\n", currColor);
	print_string("fontColor [color]:      Change the font color, ex: red,blue or white.\n", currColor);
	print_string("help:                   Displays manual.\n", currColor);
	print_string("exit:                   Goes back and displays the menu again.\n", currColor);
	nextLine();
}

int changeFontColor(char* color, int* currColor) {
	if(strcmp(color, "blue")) {
		*currColor = 0x0000FF;
	} else if(strcmp(color, "red")) {
		*currColor = 0xFF0000;
	} else if(strcmp(color, "violet")) {
		*currColor =  0x9900FF;
	} else if(strcmp(color, "yellow")) {
		*currColor = 0xFFFF00;
	} else if(strcmp(color, "white")) {
		*currColor = 0xFFFFFF;
	} else {
		return 1;
	}
	return 0;
}
