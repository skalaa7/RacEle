#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <lcd.h>
#include <unistd.h>
#include <sys/fcntl.h>

const int RS=3;
const int EN=14;
const int D0=4;
const int D1=12;
const int D2=13;
const int D3=6;

double temperatura(void)
{
	FILE *ft;
	char tekst[100];
	ft = fopen("/sys/bus/w1/devices/28-00000cfbb0e4/w1_slave","r");
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

int main()
{
	int lcd;	
	if(wiringPiSetup()<0)
	{
		fprintf(stderr,"Greska: %s\n",strerror(errno));
		return 1;
	}

	lcd=lcdInit(2,16,4,RS,EN,D0,D1,D2,D3,D0,D1,D2,D3);
	while(1){lcdClear(lcd);
	lcdPosition(lcd,0,0);
	lcdPrintf(lcd,"Temperatura= ");
	lcdPosition(lcd,0,1);
	lcdPrintf(lcd,"%.3f 'C",temperatura());
	delay(3000);}
	lcdClear(lcd);
	return 0;

}