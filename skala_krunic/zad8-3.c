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

 const char PCF8563 =0x51;
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
wiringPiI2CWriteReg8(fd,WriteBuf[0],WriteBuf[1]);
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
 //bcm2835_i2c_write(WriteBuf,2);
 wiringPiI2CWriteReg8(fd,WriteBuf[0],WriteBuf[1]);
//wiringPiI2CWriteReg8(fd,PCF8563+1,WriteBuf[1]);
}
void P8563_Readtime()
{
 unsigned char time[7];
 //WriteBuf[0] = SEK;
 //bcm2835_i2c_write_read_rs(WriteBuf, 1, time, 7);
//wiringPiI2CWriteReg8(fd,PCF8563+2,1);
time[0]=wiringPiI2CReadReg8(fd,SEK);
time[1]=wiringPiI2CReadReg8(fd,MIN);changeHexToInt
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
 //bcm2835_i2c_begin();
// adresa PCF8563 na I2C magistrali
 //bcm2835_i2c_setSlaveAddress(0x51);
 //bcm2835_i2c_set_baudrate(10000);
 printf("start..........\n");
 P8563_init() ;
 

 while(1)
 {
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