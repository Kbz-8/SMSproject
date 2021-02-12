/*=================================================*/
// SMS project
//
// AUTHOR: Malo DAVID <bilbo.sacquet@orange.fr
// CREATED: 02/02/2021
// UPDATED: 11/02/2021
/*=================================================*/

#include "src/smsManager.h"
#include <curses.h> // wgetch(); nodelay()...

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
	char* test = getSMS(port);
	printf("%s", test);

    serialClose(port);
	
	return 0;
}
