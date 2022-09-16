#include "Clock_View.h"

Clock_View::Clock_View(LCD *lcd)
{
 this->lcd=lcd;
led_lcd[17]={};
}

Clock_View::~Clock_View()
{

}

void Clock_View:: updateTime(struct tm *timeData)
{

     char buff[50];
     
     //std::cout << timeData->tm_min << std::endl;
     sprintf(buff,"%d %d %d  ",timeData->tm_hour,timeData->tm_min,timeData->tm_sec);
     lcd->WriteStringXY(1,0,buff);
     lcd->WriteStringXY(0,0,led_lcd);
     //printf("dd\n");

}

void Clock_View::off_lcd()
{

     lcd->backLightOff();
}

void Clock_View::on_lcd()
{

     lcd->backLightOn();
}