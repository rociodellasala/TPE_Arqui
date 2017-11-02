#include <types.h>
#include <shell.h>
#include <stdio.h>
#include <string.h>

int main() {

	initShell();
  
	return 0;
}

void initShell() {

  clearScreen();
  char buffer[25*80];
  int index=1;
  char c;
  int state;
  boolean first=true;
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
      			newLine();
      			buffer[index]=0;
      			state=callfunction(buffer);
				if(state == 1){
					printf("Unknown command: Type help to see the different functionalities");
					newLine();
				} else if(state == 2) {
					return 0;
				}
				index=0;
				buffer[0]=0;
      		}else{
	      		buffer[index]=c;
	      		index++;
	      		buffer[index]=0;
	     		putchar(buffer[index-1]);	
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

int callfunction(char* buffer) {
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
		echo(buffer+x+1);
		return 0;
	}
	if(strcmp(function, "fontColor")) {
		return changeFontColor(buffer+x+1);
	}
	if(strcmp(function, "clear")) {
		 clearScreen();
		 return 0;
	}
	if(strcmp(function, "help")) {
		printHelp(); 
		return 0;
	}
	if(strcmp(function, "exit")) {
		return 2;
	}
	
	return 1;
}

void echo(char * buffer){
	printf(buffer);
	newLine();
}


void printHelp() {
	clearTerminal();
	printf("clear:                  Clears the screen.\n");
	printf("echo [message]:         Prints message.\n");
	printf("fontColor [color]:      Change the font color, ex: red,blue or white.\n");
	printf("help:                   Displays manual.\n");
	printf("exit:                   Goes back and displays the menu again.\n");
	newLine();
}
