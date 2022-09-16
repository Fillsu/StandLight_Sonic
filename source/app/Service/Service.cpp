#include "Service.h"

Service::Service(View *view)
{
viewer=view;
lightState=LIGHT_OFF;
sonic_warn=0;
led_recover=0;
}

Service::~Service()
{

}

void Service::updateservice(std::string strServ)
{
    // if(warn==1)
    // {
    //     viewer->Emergency();
    // }
    // if(warn==0)
    // {
    // switch(lightState)
    // {
    //     case LIGHT_OFF:
    //     if(strServ=="ServiceOn")
    //     {
    //         //lightState=LIGHT_ON;
    //         viewer->UpdateView("ViewOn");
    //     }
    //     break;

    //     case LIGHT_ON:
    //     if(strServ=="ServiceOff")
    //     {
    //         lightState=LIGHT_OFF;
    //         viewer->UpdateView("ViewOff");
    //     }
    //     break;
    // }
    // }

    if(sonic_warn==1)
    {
        viewer->Emergency();
        led_recover=1;
    }


    if(sonic_warn==0)
    {


        if(led_recover==1)
        {
            viewer->UpdateView("ViewRecover");
            led_recover=0;
        }

    switch(lightState)
    {
        case LIGHT_OFF:
        if(strServ=="ServiceOn")
        {
            //lightState=LIGHT_ON;
            viewer->UpdateView("ViewOn");
        }
        

        break;

        case LIGHT_ON:
        if(strServ=="ServiceOff")
        {
            lightState=LIGHT_OFF;
            viewer->UpdateView("ViewOff");
        }
        break;
    }
    }

}