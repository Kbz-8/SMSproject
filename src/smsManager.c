#include "smsManager.h"

void printfCharSerial(int port) // Function to print what is available on the sertial port
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
	// Concatenates strings to give the targeted phone number to the SIM800L
	char str[255];
	strcpy(str, "AT+CMGS=\"");
	strcat(str, num);
	strcat(str, "\"\r");

	serialPuts(port, str); // Gives the targeted phone number
	sleep(1);
	printfCharSerial(port);

	serialPuts(port, message); // Enter the message to send
	sleep(1);
	printfCharSerial(port);

	serialPuts(port, ctrl_z); // Send the SMS
	sleep(1);
	printfCharSerial(port);
}


char* getSMS(int port)
{
	serialPuts(port, "AT+CNMI=1,2,0,0,0\r"); // Decides how newly arrived SMS messages should be handled
	serialPuts(port, "AT+CMGL=\"ALL\"\r");
	sleep(1);
	char* str;
	char tempo;
	while(serialDataAvail(port))
	{
		tempo = serialGetchar(port);
		strcat(str, &tempo);
	}
	serialPuts(port, "AT+CMDA=\"DEL READ\"\r");
	return str;
}
