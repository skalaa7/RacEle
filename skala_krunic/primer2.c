#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <stdlib.h>
int main()
{
	int i=0, taster_pritisnut=0;
	int r_value;
	if(wiringPiSetup() == -1)
		exit(1);
	pinMode(22, INPUT);
	pinMode(25, OUTPUT);
	
	digitalWrite(25, HIGH);
	if(softPwmCreate(28, 0, 100) != 0)
		exit(2);
	
	i=0;
	taster_pritisnut = 0;
	while(1)
	{
	r_value=digitalRead(22);
	digitalWrite(25,r_value);
	if(!r_value && !taster_pritisnut)
		{
		taster_pritisnut=1;
		i+=10;
		if(i>100)
			i=0;
		printf("i= %d\n",i);
		fflush(stdout);
		softPwmWrite(28, i);
	
		}
	if(r_value)
		taster_pritisnut=0;
	}
	return 0;
}
