/*=================================================*/
// SMS project
//
// AUTHOR: Malo DAVID <bilbo.sacquet@orange.fr
// CREATED: 02/02/2021
// UPDATED: 11/02/2021
/*=================================================*/

#include "src/smsManager.h"

int main(int argc, char *argv[])
{	
	(void)argc;
	(void)argv;
	int port;

	if((port = serialOpen("/dev/serial0", 9600)) < 0)
	{
        printf("ERREUR: impossible d'ouvrir le port de serie\n");
        return -1;
    }
    
	initSMSmanager(port);
	sendSMS(port, "0766614647", "j'aime les pommes");
	getSMS(port);

    serialClose(port);
	
	return 0;
}
