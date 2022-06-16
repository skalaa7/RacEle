#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <stdlib.h>
int main()
{
	int i=0, taster_pritisnut1=0;
	int taster_pritisnut2=0;
	int r_value,m_value;
	if(wiringPiSetup() == -1)
		exit(1);
	pinMode(21, INPUT);
	pinMode(22,INPUT);
	pinMode(25, OUTPUT);
	
	digitalWrite(25, HIGH);
	if(softPwmCreate(28, 0, 100) != 0)
		exit(2);
	
	i=0;
	taster_pritisnut1 = 0;
	taster_pritisnut2 = 0;
	while(1)
	{
	r_value=digitalRead(22);
	digitalWrite(25,r_value);
	if(!r_value && !taster_pritisnut1)
		{
		taster_pritisnut1=1;
		i+=10;
		if(i>100)
			i=100;
		printf("i= %d\n",i);
		fflush(stdout);
		softPwmWrite(28, i);
		delay(100);
	
		}
	if(r_value)
		taster_pritisnut1=0;
				delay(100);

		
		
	m_value=digitalRead(21);
	digitalWrite(25,m_value);
	if(!m_value && !taster_pritisnut2)
		{
		taster_pritisnut2=1;
		i-=10;
		if(i<0)
			i=0;
		printf("i= %d\n",i);
		fflush(stdout);
		softPwmWrite(28, i);
		delay(100);
	
		}
	if(m_value)
		taster_pritisnut2=0;
				delay(100);

	}
	return 0;
}
