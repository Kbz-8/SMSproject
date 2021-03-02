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
	serialPuts(port, "AT+CPIN=1234\r"); // Get SIM card
	sleep(1);
	printfCharSerial(port);

	serialPuts(port, "AT+CMGF=1\r"); // Enable SMS sending
	sleep(1);
	printfCharSerial(port);
	
	serialPuts(port, "AT+CNMI=1,2,0,0,0\r"); // Decides how newly arrived SMS messages should be handled
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
	char* buffer = malloc(sizeof(char) * 255);
	char* finder = malloc(sizeof(char) * 255);
	for(int i = 8; serialDataAvail(port) && i < 255; i++)
	{
		buffer[i] = serialGetchar(port);
		
		finder = strstr(buffer, "+CMT"); // Find +CMT
		if(finder != NULL)
		{
			for(int j = 8; j < (int)strlen(buffer); j++) // Clear the buffer
				buffer[j] = "";
			strcpy(buffer, "NEW SMS: ");
			i = 8;
		}
	}
	free(finder);
	serialPuts(port, "AT+CMDA=\"DEL ALL\"\r"); // Delete all sms
	sleep(1);
	return buffer;
}
