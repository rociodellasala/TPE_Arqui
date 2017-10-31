void putchar(const char c) {
	int80(1, 1, &c, 1, 0, 0);
}


void clearScreen() {
	int80(2, 1, 0, 0, 0, 0);
}

int main (void){
	clearScreen();
	putchar('R');
	int i=0;
	while(i<500000000) {
		i++;
	}
	//printTime();
	return 0;
}


