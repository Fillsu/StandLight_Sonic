#ifndef CONTROLER_H
#define CONTROLER_H


#include <string>
#include "Service.h"
#include "Clock_Service.h"
#include "TH_Service.h"
#include "Sonic_Service.h"

#include "DHT11.h"//This data, not Service 

class Controler
{
private:
    int lightState;
    Service *service;
    Clock_Service *Clock_servicer;
    TH_Service *TH_servicer;
    Sonic_Service *Sonic_servicer;
    DHT_Data *dht_data;
   
public:
    
    virtual ~Controler();
    void updateEvent(std::string strBtn);
     Controler(Service *servi,Clock_Service *Clock_service,TH_Service *TH_service,Sonic_Service *Sonic_service,DHT_Data *dht);
     int distance;
     int distance_empty;
};

#endif