#include "TH_Service.h"

TH_Service::TH_Service(TH_View *th_view)
{
    th_viewer=th_view;

}

TH_Service::~TH_Service()
{

}

void TH_Service::updateTH(DHT_Data *dht)
{
if(warn==1)
{
     sprintf(th_viewer->TH_buf2,"Waring: %d.%dC",dht->Temp,dht->TempDec);
      th_viewer->Emergency();
}

if(warn==0)
{
 sprintf(th_viewer->TH_buf1,"%d.%d%%",dht->RH,dht->RHDec);
 sprintf(th_viewer->TH_buf2,"%d.%dC",dht->Temp,dht->TempDec);
 th_viewer->updateView();
}

         //     std::printf("RH: %d.%d, Temp: %d.%d\n", 
        //                 dhtData.RH, dhtData.RHDec,
        //                 dhtData.Temp, dhtData.TempDec);
}