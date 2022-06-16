#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int pin, i;

	if(wiringPiSetup() == -1)
		exit(1);

	pinMode(1, PWM_OUTPUT);

	for(;;) {



			pwmWrite(1, 682);
			
		
		
	}
	
	return 0;
}
