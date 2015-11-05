#include <stdio.h>
#include <wiringPi.h>

#define SW1 7 
#define SW2 0 
#define DIRA 5 //indietro
#define DIRB 3 //avanti
#define EN 6 //enable

int main(void){
	printf("Prova Motori 0: Prova Avanti-Retro di un motore in DC\n");
	printf("\tIn base all'inpute di due pulsanti il motore cambia verso di rotazione\n\n");

	wiringPiSetup();

	pinMode(SW1, INPUT);
	pinMode(SW2, INPUT);
	pinMode(DIRA, OUTPUT);
	pinMode(DIRB, OUTPUT);
	pinMode(EN, OUTPUT);
    
    printf("Fine Setup\n");

	digitalWrite(DIRA, 0);
	digitalWrite(DIRB, 0);
	/* digitalWrite(EN, 0); */

	while(1){
		if(digitalRead(SW1==0)){
	        digitalWrite(EN, 1);
			digitalWrite(DIRA, 1);
			digitalWrite(DIRB, 0);
			printf("Motore avanti\n");
			delay(50);
		}
		if(digitalRead(SW2==0)){
	        digitalWrite(EN, 1);
			digitalWrite(DIRA, 0);
			digitalWrite(DIRB, 1);
			printf("Motore inditro\n");
			delay(50);
		}
		delay(10);
	}
}

