#include <time.h>

#include "ArduinoTimeAPI.h"

#define YEAR_OFFSET     1900
#define MONTH_OFFSET    1

unsigned long now()
{
    if (rtcAPI) {
        return rtcAPI->getTime();
    } else {
        return 0;
    }
}

struct tm* tTm(unsigned long  t)
{
    time_t time = t;
  
    return gmtime(&time);
}

int year(unsigned long t)
{
    struct tm* tm = tTm(t);

    return (tm->tm_year + YEAR_OFFSET);
}

int year()
{
    unsigned long t = now();

    return year(t);
}

int month(unsigned long t)
{
    struct tm* tm = tTm(t);

    return (tm->tm_mon + MONTH_OFFSET);
}

int month()
{
    unsigned long t = now();

    return month(t);
}

int day(unsigned long t)
{
    struct tm* tm = tTm(t);

    return tm->tm_mday;
}

int day()
{
    unsigned long t = now();

    return day(t);
}

int hour(unsigned long t)
{
    struct tm* tm = tTm(t);

    return tm->tm_hour;
}

int hour()
{
    unsigned long t = now();

    return hour(t);
}

int minute(unsigned long t)
{
    struct tm* tm = tTm(t);

    return tm->tm_min;
}

int minute()
{
    unsigned long t = now();

    return minute(t);
}

int second(unsigned long t)
{
    struct tm* tm = tTm(t);

    return tm->tm_sec;
}

int second()
{
    unsigned long t = now();

    return second(t);
}

void setTime(unsigned long t)
{
  if (rtcAPI) {
    rtcAPI->setTime(t);
  }
}

unsigned long convertTime(int hour, int minute, int second, int day, int month, int year)
{
    struct tm tm;

    tm.tm_year = year - YEAR_OFFSET;
    tm.tm_mon = month - MONTH_OFFSET;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;
    tm.tm_isdst = -1;

    return mktime(&tm);
}

void setTime(int hour, int minute, int second, int day, int month, int year)
{
    time_t t = convertTime(hour, minute, second, day, month, year);

    setTime(t);
}
