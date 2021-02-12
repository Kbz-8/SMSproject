#include "smsManager.h"

void printfCharSerial(int port)
{
	while(serialDataAvail(port))
	{
		printf("%c", serialGetchar(port));
	}
	printf("\n");
}

void initSMSmanager(int port)
{
	serialPuts(port, "AT+CPIN=5132\r"); // Get SIM card
	sleep(1);
	printfCharSerial(port);

	serialPuts(port, "AT+CMGF=1\r"); // Enable SMS sending
	sleep(1);
	printfCharSerial(port);
}

void sendSMS(const int port, const char* num, const char* message)
{
	// Concatenates strings to give the phone number to the SIM800L
	char str[255];
	strcpy(str, "AT+CMGS=\"");
	strcat(str, num);
	strcat(str, "\"\r");

	serialPuts(port, str); // Gives the phone number
	sleep(1);
	printfCharSerial(port);

	serialPuts(port, message); // Enter the message to send
	sleep(1);
	printfCharSerial(port);

	serialPuts(port, "\x1a"); // Send the SMS
	sleep(1);
	printfCharSerial(port);
}


const char* getSMS(int port)
{
	serialPuts(port, "AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
	int quit;
	while(quit != 1000)
	{
		printfCharSerial(port);
		serialPuts(port, "AT+CMGR=1\r");
		scanf("%d", &quit);
	}
}
