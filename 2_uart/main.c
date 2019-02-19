#include <stdint.h>
#include "uart.h"
#include "gpio.h"
#include "stdio.h"

ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for (int i = 0; i<count;i++) {
		uart_send(*letter);
		letter++;
	}
	return count;
}

int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 12; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTSET = (1 << i);
	}
	for(int i = 13; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	
	int sleep = 0;

	uart_init();

	while(1) {
		char c = uart_read();

		/*
		if (!(GPIO->IN & (1 << 17))) { //A
			//uart_send('A');
			GPIO->OUTCLR = (1 << 6);
			GPIO->OUTSET = (1 << 13);
		}
		if (!(GPIO->IN & (1 << 26))) { //Bb
			//uart_send('B');
			GPIO->OUTSET = (1 << 6);
			GPIO->OUTCLR = (1 << 13);
		}*/

		if (c == 'a') { //A
			GPIO->OUTCLR = (1 << 6);
			GPIO->OUTSET = (1 << 13);
			iprintf("kjnk %d ijo\n\r", 878398);
		}
		if (c == 'b') { //B
			GPIO->OUTSET = (1 << 6);
			GPIO->OUTCLR = (1 << 13);
		}

		sleep = 10000;
		while(--sleep);
	}



	return 0;
}
