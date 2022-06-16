// primer rada sa PCF8563 koji ispisuje tekuce vreme
// u terminalu svakih 5 sekundi
//#include <bcm2835.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <lcd.h>

#define changeHexToInt(hex) ((((hex)>>4) *10 ) +((hex)%16) )
#define chageIntToHex(int) ((int%10)&(int/10<<4))
//adrese registara
#define SEK 0x02
#define MIN 0x03
#define SAT 0x04
#define DAN 0x05
#define MES 0x07
#define GOD 0x08

const int RS=3;
const int EN=14;
const int D0=4;
const int D1=12;
const int D2=13;
const int D3=6;


 int fd;
 unsigned char WriteBuf[2];
 unsigned char ReadBuf;
 unsigned char g8563_Store[6];
 // sec,min,sat
 unsigned char init8563_Store[6]={0x50,0x59,0x23,0x31,0x12,0x22};
void P8563_settime()
{
 WriteBuf[0] = SEK;
 WriteBuf[1] = g8563_Store[0];
//bcm2835_i2c_write(WriteBuf,2);
 wiringPiI2CWriteReg8(fd,WriteBuf[0],WriteBuf[1]);
 WriteBuf[0] = MIN;
 WriteBuf[1] = g8563_Store[1];
 //bcm2835_i2c_write(WriteBuf,2);
wiringPiI2CWriteReg8(fd,WriteBuf[0],WriteBuf[1]);

 WriteBuf[0] = SAT;
 WriteBuf[1] = g8563_Store[2];
 //bcm2835_i2c_write(WriteBuf,2);
wiringPiI2CWriteReg8(fd,WriteBuf[0],WriteBuf[1]);
WriteBuf[0] = DAN;
 WriteBuf[1] = g8563_Store[3];
 //bcm2835_i2c_write(WriteBuf,2);
wiringPiI2CWriteReg8(#include <wiringPi.h>fd,WriteBuf[0],WriteBuf[1]);
WriteBuf[0] = MES;
 WriteBuf[1] = g8563_Store[4];
 //bcm2835_i2c_write(WriteBuf,2);
wiringPiI2CWriteReg8(fd,WriteBuf[0],WriteBuf[1]);
WriteBuf[0] = GOD;
 WriteBuf[1] = g8563_Store[5];
 //bcm2835_i2c_write(WriteBuf,2);
wiringPiI2CWriteReg8(fd,WriteBuf[0],WriteBuf[1]);
}
void P8563_init()
{
 unsigned char i;
 for(i=0;i<=6;i++)
 g8563_Store[i]=init8563_Store[i];

 P8563_settime();
 printf("Postavi početno tekuće vreme\n");

//inicijalizacija RTC-a
 WriteBuf[0] = 0x0;
 WriteBuf[1] = 0x00; //normalni rezim rada
 
 wiringPiI2CWriteReg8(fd,WriteBuf[0],WriteBuf[1]);

}
void P8563_Readtime()
{
 unsigned char time[7];
time[0]=wiringPiI2CReadReg8(fd,SEK);
time[1]=wiringPiI2CReadReg8(fd,MIN);
time[2]=wiringPiI2CReadReg8(fd,SAT);
time[3]=wiringPiI2CReadReg8(fd,DAN);
time[5]=wiringPiI2CReadReg8(fd,MES);
time[6]=wiringPiI2CReadReg8(fd,GOD);
 g8563_Store[0] = time[0] & 0x7f;
 g8563_Store[1] = time[1] & 0x7f;
 g8563_Store[2] = time[2] & 0x3f;
 g8563_Store[3] = time[3] & 0x3f;
 g8563_Store[4] = time[5] & 0x1f;
 g8563_Store[5] = time[6] & 0xff;

 g8563_Store[0] = changeHexToInt(g8563_Store[0]);
 g8563_Store[1] = changeHexToInt(g8563_Store[1]);
 g8563_Store[2] = changeHexToInt(g8563_Store[2]);
g8563_Store[3] = changeHexToInt(g8563_Store[3]);
g8563_Store[4] = changeHexToInt(g8563_Store[4]);
g8563_Store[5] = changeHexToInt(g8563_Store[5]);
}
int main(int argc, char **argv)
{
if (wiringPiSetup()==-1)
 exit(1);
int lcd;
lcd=lcdInit(2,16,4,RS,EN,D0,D1,D2,D3,D0,D1,D2,D3);
 fd=wiringPiI2CSetup(PCF8563);
 pinMode(21, INPUT);
	pinMode(22, INPUT);
	pinMode(23, INPUT);
	pinMode(24, INPUT);
//pinMode(25, OUTPUT);

	//digitalWrite(25, HIGH);

 int i=0, taster_pritisnut1=0, taster_pritisnut2=0, taster_pritisnut3=0, taster_pritisnut4=0;
	int r_value1, r_value2, r_value3, r_value4;
int x,y;
x=0;
y=0;

 printf("start..........\n");
 //P8563_init() ;
 

 while(1)
 {		//P8563_Readtime();
		y=changeHexToInt(init8563_Store[x]);
 		r_value1 = digitalRead(21);
		//digitalWrite(25, r_value1);


		if(!r_value1 && !taster_pritisnut1){
			taster_pritisnut1 = 1;
			delay(20);
			
			x++;
			if(x > 5)
				x=0;

			
		}

		if(r_value1) {
			taster_pritisnut1 = 0;
			delay(20);
		}

		r_value2 = digitalRead(22);
		//digitalWrite(25, r_value2);

		if(!r_value2 && !taster_pritisnut2){
			taster_pritisnut2 = 1;
			delay(20);

			x--;
			if(x < 0 )
				x=5;
			
		}

		if(r_value2){
			taster_pritisnut2 = 0;
			delay(20);
		}
//GORE DOLE
		r_value3 = digitalRead(23);
		//digitalWrite(25, r_value3);

		if(!r_value3 && !taster_pritisnut3){
			taster_pritisnut3 = 1;
			delay(20);

			y++;
			//if(x > 1 )
			//	y = 0;
			//lcdPosition(lcd_h, x, y);
		}

		if(r_value3){
			taster_pritisnut3 = 0;
			delay(20);
		}

		r_value4 = digitalRead(24);
		//digitalWrite(25, r_value4);

		if(!r_value4 && !taster_pritisnut4){
			taster_pritisnut4 = 1;
			delay(20);

			y--;
			//if(y < 0 )
			//	y=1;
			//lcdPosition(lcd_h, x, y);
		}

		if(r_value4){
			taster_pritisnut4 = 0;
			delay(20);
		}
printf("x=%d,y=%d\n",x,y);
init8563_Store[x]=y;
 P8563_init() ;
P8563_Readtime();
 //printf("Sati:%d Minuti:%d Sekunde:%d Dani:%d Meseci:%d Godine:%d\n",
//g8563_Store[2], g8563_Store[1],
//g8563_Store[0], g8563_Store[3], g8563_Store[4], g8563_Store[5]);
 //bcm2835_delay(5000);
 lcdPosition(lcd,0,0);
 lcdPrintf(lcd,"%d:%d:%d",g8563_Store[2], g8563_Store[1],g8563_Store[0]);
lcdPosition(lcd,0,1);
 lcdPrintf(lcd,"%d.%d.%d",g8563_Store[3], g8563_Store[4], g8563_Store[5]);
	delay(5000);
lcdClear(lcd);
}
//bcm2835_i2c_end();
 //bcm2835_close();
 

 return 0;
}