/*=================================================*/
// SMS project
//
// AUTHOR: Malo DAVID <bilbo.sacquet@orange.fr>
// CREATED: 02/02/2021
// UPDATED: 24/02/2021
/*=================================================*/

#include "src/manager.h"

int main(int argc, char *argv[])
{	
	(void)argc;
	(void)argv;
	
	initManager();

	loop();

    serialClose(port);
	
	return 0;
}
