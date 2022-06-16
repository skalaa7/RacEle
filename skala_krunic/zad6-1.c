#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>


int main(int argc,char **argv)
{
	struct lirc_config *config;
	char *code;

	if(lirc_init("lirc",1)==-1)
		return 1;
	
	if(lirc_readconfig(NULL, &config,NULL)==0)
	{
		while(lirc_nextcode(&code)==0)
		{
			int i=0;
			if(code==NULL) continue; {
				printf("0x");
				for(i=12;i<=16;i++)
				{
					printf("%c",code[i]);
				}
				for(i=19;i<=25;i++)
				{
					printf("%c",code[i]);
				}
				printf("\n");
			}
			free(code);
		}
		lirc_freeconfig(config);
	}
	lirc_deinit();
	return 0;
}
