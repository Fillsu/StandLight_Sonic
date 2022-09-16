#include "Controler.h"


Controler::Controler(Service *servi,Clock_Service *Clock_service,TH_Service *TH_service,Sonic_Service *Sonic_service,DHT_Data *dht)
{
Clock_servicer=Clock_service;
service = servi ;
lightState=LIGHT_OFF;
TH_servicer=TH_service;
Sonic_servicer=Sonic_service;
dht_data=dht;


}

Controler::~Controler()
{

}

void Controler::updateEvent(std::string strBtn)
{   

    if(strBtn=="SonicUpdate")
    {   

        Sonic_servicer->sonic_buf=distance;
        Sonic_servicer->updateSonic();


        if(distance<0)
        {
            distance_empty++;
        }
        else
        {
                   
            if(distance>50)
            {
                distance_empty++;
            }

            distance_empty--;
        }


            if(distance_empty<-6)
            {
                    distance_empty=0;
                    Sonic_servicer->sonic_buf=distance;
                    Sonic_servicer->updateSonic();
                    service->sonic_warn=0;
                    service->updateservice("Recover_Led");//실제로는 없는 조건이지만 이렇게 직관적으로 사용할 수있다. 
            }
            if(distance_empty>6)
            {         
                      distance_empty=0;
                      Sonic_servicer->sonic_buf=distance;
                      Sonic_servicer->updateSonic();
                      service->sonic_warn=1;
                      service->updateservice("ServiceOn");
            }
        
    }

    if(strBtn=="THupdate")
    {   
        if((dht_data->Temp)>28)
        {
            TH_servicer->warn=1;
            service->warn=1;
            service->updateservice("ServiceOn");
            TH_servicer->updateTH(dht_data);
        }
        else
        {
            TH_servicer->updateTH(dht_data);
            TH_servicer->warn=0;
            service->warn=0;
        }
        
    }


    if(strBtn=="clockupdate")
    {
        Clock_servicer->updateClock();
    }


    if(strBtn=="powerButton")
    {
        Clock_servicer->updatePower();
    }
    switch(lightState)
    {
        case LIGHT_OFF:
        if(strBtn=="ledButton")
        {
            //lightState=LIGHT_ON;
            service->updateservice("ServiceOn");
            Clock_servicer->led_count++;
            if((Clock_servicer->led_count)>5)
            {
                Clock_servicer->led_count=0;
            }
        }
        break;

        case LIGHT_ON:
        if(strBtn=="powerButton")
        {
            lightState=LIGHT_OFF;
            service->updateservice("ServiceOff");
        }
        break;

        
    }
}