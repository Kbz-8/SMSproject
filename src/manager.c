#include "manager.h"
#include "md5.h"

void initManager(void)
{
	if((port = serialOpen("/dev/serial0", 9600)) < 0) // Open new serial port with 9600 bauds
	{
        printf("ERREUR: impossible d'ouvrir le port de serie\n");
        exit(1);
    }

    initSMSmanager(port);
}

void loop(void)
{
	char* finder = malloc(sizeof(char) * 255);
	bool looping = true;
	while(looping)
	{
		getter = getSMS(port);
		finder = strtok(getter, " ");
		while(finder != NULL)
		{
			for(int i = 0; i < (int)strlen(finder); i++)
			{
				printf("%c\n", finder[i]);
				if(finder[i] == *"!")
				{
					printf("test\n");
					if(strstr(finder, "break") != NULL)
					{
						printf("break command\n");
						sendSMS(port, "BREAK COMMAND", "0766614647");
						looping = false;
						break;
					}
				}
			}
			finder = strtok(NULL, " ");
		}
	}
	free(finder);
	free(getter);
	printf("Variables liberees\n");
}

void clearManager(void)
{
	serialClose(port);
}
