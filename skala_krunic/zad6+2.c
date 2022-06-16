#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <stdlib.h>
#include <lirc/lirc_client.h>
#include <string.h>
int main()
{
	struct lirc_config *config;
	char *code;

	if(lirc_init("lirc",1)==-1)
		return 1;
	int i=0;
	int taster1=0;
	int taster2=0;
	int r_value,m_value;
	if(wiringPiSetup() == -1)
		exit(1);
	pinMode(25, OUTPUT);
	
	digitalWrite(25, HIGH);
	if(softPwmCreate(28, 0, 100) != 0)
		exit(2);
	
	i=0;
	
	if(lirc_readconfig(NULL, &config,NULL)==0)
	{
		while(lirc_nextcode(&code)==0)
		{
			//if(code==NULL) continue;
			{
				//printf("%s\n",code);
				delay(100);
				if(strstr(code,"00 KEY_UP") && !taster1){
					printf("KEYUP\n");
					taster1=1;
					i+=20;
					if(i>100)
						i=100;
					printf("i= %d\n",i);
					softPwmWrite(28, i);
					//printf("%s\n",code);
				}
				if(!strstr(code,"00 KEY_UP"))
					taster1=0;
					
				if(strstr(code,"00 KEY_DOWN") && !taster2){
					printf("KEYDOWN\n");
					taster2=1;
					i-=20;
					if(i<0)
						i=0;
					printf("i= %d\n",i);
					softPwmWrite(28, i);
					
				}
				if (!strstr(code,"00 KEY_DOWN"))taster2=0;
				
			
			}

			free(code);
		}
		lirc_freeconfig(config);
	}
	lirc_deinit();
	/*while(1)
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

	}*/
	return 0;
}
