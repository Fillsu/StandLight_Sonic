#include "Clock_Service.h"

Clock_Service::Clock_Service(Clock_View *clkview)
{
curTime=0;
clkviewer=clkview;
led_count=0;
lcd_toggle=0;
}

Clock_Service::~Clock_Service()
{

}

 void Clock_Service::updateClock()
{   
    sprintf(clkviewer->led_lcd,"Light:%d ",led_count);
    //std::cout << led_count << std::endl;
    curTime=time(NULL);
    struct tm *timeDate=localtime(&curTime);
    //std::cout << timeDate->tm_hour << std::endl;
    
    clkviewer->updateTime(timeDate);
}

void Clock_Service::updatePower()
{   
    lcd_toggle=!lcd_toggle;
    if(lcd_toggle)
    clkviewer->off_lcd();
    else
    clkviewer->on_lcd();
}