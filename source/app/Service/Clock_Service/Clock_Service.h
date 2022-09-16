#ifndef CLOCK_SERVICE_H
#define CLOCK_SERVICE_H
#include "time.h"
#include "Clock_View.h"
#pragma once

class Clock_Service
{
public:
   
    Clock_Service(Clock_View *clkview);
    ~Clock_Service();
    void updateClock();
    void updatePower();
    int led_count;
    int lcd_toggle;
   
private:
    time_t curTime;
    Clock_View *clkviewer;
     

};

#endif