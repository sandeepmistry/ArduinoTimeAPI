#ifndef RTC_API_H
#define RTC_API_H

#include "Arduino.h"

class RTCAPI
{
public:
    RTCAPI();

    virtual unsigned long getTime();
    virtual void setTime(unsigned long t);
};

extern RTCAPI* rtcAPI;

#endif // RTC_API_H
