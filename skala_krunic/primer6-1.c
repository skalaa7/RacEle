#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bcm2835.h>
#include <lirc/lirc_client.h>

#define PIN 20

int main(int argc,char **argv)
{
	struct lirc_config *config;
	char *code;

	if(lirc_init("lirc",1)==-1)
		return 1;
	if(!bcm2835_init())
		return 2;
	bcm2835_gpio_fsel(PIN,BCM2835_GPIO_FSEL_OUTP);
	if(lirc_readconfig(NULL, &config,NULL)==0)
	{
		while(lirc_nextcode(&code)==0)
		{
			if(code==NULL) continue; {
				bcm2835_delay(400);
				if(strstr(code,"KEY_0")){
					printf("KEY0\n");
					bcm2835_gpio_write(PIN,LOW);
					bcm2835_delay(500);
				}
				else if(strstr(code,"KEY_1")){
					printf("KEY1\n");
					bcm2835_gpio_write(PIN,HIGH);
					bcm2835_delay(500);
				}
			}
			free(code);
		}
		lirc_freeconfig(config);
	}
	lirc_deinit();
	bcm2835_close();
	return 0;
}
