/*Povezati izlaz DAC-a sa AIN2 (koji je slobodan)
* očitavati trimer potenciometar koji je na AIN3
* upisati tu vrednost u DAC,
* očitati DAC preko AIN2
* DAC izlaz je validan do oko ~220
*/
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <lcd.h>

const int RS=3;
const int EN=14;
const int D0=4;
const int D1=12;
const int D2=13;
const int D3=6;
const char PCF8591 = 0x48; // adresa
int fd, adcVal;
float voltage;
int main() {
 if (wiringPiSetup () == -1) exit (1);
 fd = wiringPiI2CSetup(PCF8591);
int lcd;
lcd=lcdInit(2,16,4,RS,EN,D0,D1,D2,D3,D0,D1,D2,D3);
 while (1) {
 // procitaj trimer pot sa AIN3 ulaza
 wiringPiI2CReadReg8(fd, PCF8591 + 3) ; // dummy
 adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 3) ;
voltage=(float)adcVal/256*3.3;
 printf("Pot ADC vrednost = %d ", adcVal);
 printf("Voltage = %f ", voltage);
 lcdPosition(lcd,0,0);
lcdPrintf(lcd,"%f V",voltage);

 // upisi tu vrednost u DAC reg, 0x04
 wiringPiI2CWriteReg8 (fd, PCF8591 + 4, adcVal) ;
 // procitaj DAC preko AIN2
 wiringPiI2CReadReg8(fd, PCF8591 + 2) ; // dummy
 adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 2);
 printf("DAC vrednost = %d \n\n" , adcVal);
 delay(500);
lcdClear(lcd);
 }
 return 0;
}