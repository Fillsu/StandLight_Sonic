#ifndef LISTENER_H
#define LISTENER_H
#include "Listener.h"
#include "Controler.h"
#include "Button.h"
#include "Clock_Check.h"
#include "Led.h"
#include "DHT11.h"
#include "UltraSonic.h"
#include "wiringPi.h"
#pragma once

class Listener
{
    
  private:
  //listener has tis componet
  //And this must be point, beucause of memory
  int distance;
  
  Button *ledButton;
  Button *powerButton;
  Clock_Check *clkcheck;
  DHT_Data *dht_data;
  UltraSonic *Sonic_Checker;

 Controler *cont;
  
  public :
  Listener(Button *modbutton,Button *powerbutton, Controler *led, Clock_Check *clk,DHT_Data *dht,  UltraSonic *soniccheck);
  ~Listener();
  void checkEvent();

};

#endif