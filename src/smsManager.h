#ifndef __SMS_MANAGER__
#define __SMS_MANAGER__

#include <wiringPi.h>
#include <wiringSerial.h> // Serial communication
#include <stdio.h> // printf(); scanf()...
#include <stdlib.h> // malloc()...
#include <unistd.h> // sleep()
#include <string.h> // strcpy(); strcat()...
#include <stdbool.h>


#define ctrl_z "\x1a"

void initSMSmanager(int port);
void sendSMS(const int port, const char* num, const char* message);
char* getSMS(int port);

#endif // __SMS_MANAGER__
