#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <lcd.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

#define COLUMNS 16
#define RS 3
#define EN 14
#define D4 4
#define D5 12
#define D6 13
#define D7 6

char level10[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111};
char level11[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111,0b11111};
char level12[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b11111,0b11111,0b11111};
char level13[8] = {0b00000,0b00000,0b00000,0b00000,0b11111,0b11111,0b11111,0b11111};
char level14[8] = {0b00000,0b00000,0b00000,0b11111,0b11111,0b11111,0b11111,0b11111};
char level15[8] = {0b00000,0b00000,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
char level16[8] = {0b00000,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
char level17[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};

void memory(void);

void volume(void);

void scrollText(void);

char message[]="Pozdravče!";
int count=0;
int j=0;
FILE *mem_file;
char *temp;
int lcd;

int main()
{
	wiringPiSetup();
	if(lcd=lcdInit(2,16,4,RS,EN,D4,D5,D6,D7,0,0,0,0)){
		printf("lcd nije uspeo\n");
		return -1;
	}
	
	int uptimeTimer;
	while(1){
		lcdClear(lcd);
		volume();
		sleep(1);
		memory();
		sleep(4);
		lcdClear(lcd);
		sleep(1);
		scrollText();}

	return 0;

}

void memory(void)
{
	char MemTotal[35];
	char MemFree[35];
	char total[35];
	char free[35];
	lcdClear(lcd);
	mem_file=fopen("/proc/meminfo","r");
	if(NULL!=mem_file)
	{
		fscanf(mem_file,"%*s%s%*s",MemTotal);
		fscanf(mem_file,"%*s%s%*s",MemFree);
		printf("\x1B[2J");
		lcdPosition(lcd,0,0);
		lcdPrintf(lcd,"MemTotal-%sk",MemTotal);
		lcdPosition(lcd,0,1);
		lcdPrintf(lcd,"MemFree-%sk",MemFree);
		fclose(mem_file);
	}
	else
	{
	printf("Otvaranje fajla\"/proc/meminfo\" nije uspjelo!\n");
	}
}

void volume(void)
{
	lcdCharDef(lcd,0,level10);
	lcdCharDef(lcd,1,level11);
	lcdCharDef(lcd,2,level12);
	lcdCharDef(lcd,3,level13);
	lcdCharDef(lcd,4,level14);
	lcdCharDef(lcd,5,level15);
	lcdCharDef(lcd,6,level16);
	lcdCharDef(lcd,7,level17);

	lcdClear(lcd);
	int i;
	lcdPosition(lcd,9,1);
	lcdPuts(lcd,":Volume");
	for(i=0;i<8;i++)
	{
		lcdPosition(lcd,i,1);
		lcdPutchar(lcd,i);
		usleep(400000);
	}
}

void scrollText(void)
{
	int i ,n;
	int h;
	int tempSpace=0;
	char scrollPadding[]="               ";
	int messageLength=strlen(scrollPadding)+ strlen(message);
	for(n=0;n<messageLength;n++)
	{
	h=COLUMNS;
	usleep(300000);
	printf("\x1B[2J");
	if(j>messageLength) j=0;
	for(i=0;i<j;i++){
	scrollPadding[h-j]=message[i];
	h++;
	}
	lcdPosition(lcd,0,0);
	lcdClear(lcd);
	lcdPrintf(lcd,"%s",scrollPadding);
	j++;
}
}







