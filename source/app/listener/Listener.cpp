
#include "Listener.h"


Listener::  Listener(Button *modbutton,Button *powerbutton, Controler *led, Clock_Check *clk,DHT_Data *dht,UltraSonic *soniccheck)
{
 ledButton=modbutton;
 powerButton=powerbutton;
 cont = led;
 clkcheck=clk;
 dht_data=dht;
 Sonic_Checker=soniccheck;

distance =0;
}

Listener::~Listener()
{

}

void Listener::checkEvent()
{


       static unsigned preTime=0;
        // if((millis()-preTime)>1000)
        // {
        //         preTime=millis();
        //         if (!(dht_data->error))
        //         {

        //         cont->updateEvent("THupdate");

        //         }

        // }
       
        if((millis()-preTime)>1000)
        {
                preTime=millis();
                distance =Sonic_Checker->readDistance();
                cont->updateEvent("SonicUpdate");
                cont->distance=this->distance;

        }

        if(ledButton->getState()==RELEASE_ACTIVE)
    {
        
            cont->updateEvent("ledButton");

    }
    
    if(clkcheck->Is_Clock_update()==true)
    {
        
            cont->updateEvent("clockupdate");

    }

        if(powerButton->getState()==RELEASE_ACTIVE)
    {
        
            cont->updateEvent("powerButton");

    }
    
}

