#include "manager.h"

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
	sendSMS(port, "0782509304", "j'aime les pommes test");
	sleep(5);
	char* test = getSMS(port);
	printf("\n%s\n", test);
	sendSMS(port, "0766614647", test);
	free(test);
}
