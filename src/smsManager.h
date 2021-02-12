#ifndef __SMS_MANAGER__
#define __SMS_MANAGER__

#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void initSMSmanager(int port);
void sendSMS(const int port, const char* num, const char* message);
const char* getSMS(int port);

#endif // __SMS_MANAGER__
