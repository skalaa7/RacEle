#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

char LED = 25;

double temperatura(void)
{
	FILE *ft;
	char tekst[100];
	ft = fopen("/sys/bus/w1/devices/28-000007237df2/w1_slave","r");
	if(ft == NULL)
		return 0;
	int i = 0;
	for(i=0;i<22;i++)
		fscanf(ft, "%s", tekst);
	fclose(ft);
	
	for(i=0;i<10;i++)
	{
		tekst[i]=tekst[i+2];
	}
	int temp=atoi(tekst);
	double tem=(double)temp/1000;
	
	return tem;
};
int main(void)
{
	wiringPiSetup();
	pinMode(LED,OUTPUT);
	
	while(1)
	{
		printf("\n Merenje \tTemp = %.3f\xC2\xB0 C",temperatura());
		if(temperatura()>25)
		{
			digitalWrite(LED,1);
			delay(100);
			digitalWrite(LED,0);
			delay(100);
		}
		else
		{
			digitalWrite(LED,0);
			delay(100);
		}
	}
	return 0;
	}
