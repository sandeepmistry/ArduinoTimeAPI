#ifndef ARDUINO_TIME_API_H
#define ARDUINO_TIME_API_H

#include "RTCAPI.h"

#define ARDUINO_TIME_API_VERSION 010000 // version 1.0.0

unsigned long now(); // current time as seconds since Jan 1 1970 

int year();                     // current year as an integer
int year(unsigned long  t);     // year of t as an integer
int month();                    // current month as an integer (1 - 12)
int month(unsigned long  t);    // month of t as an integer (1 - 12)
int day();                      // current day as an integer (1 - 31)
int day(unsigned long  t);      // day of t as an integer (1 - 31)
int hour();                     // current hour as an integer (0 - 23)
int hour(unsigned long  t);     // hour of t as an integer (0 - 23)
int minute();                   // current minute as an integer (0 - 59)
int minute(unsigned long  t);   // minute of t as an integer (0 - 59)
int second();                   // current second as an integer (0 - 59)
int second(unsigned long  t);   // second of t as an integer (0 - 59)

void setTime(int hour, int minute, int second, int day, int month, int year); // set the current time
void setTime(unsigned long t); // set the current time from seconds since Jan 1 1970

unsigned long convertTime(int hour, int minute, int second, int day, int month, int year);

#endif // ARDUINO_TIME_API_H
