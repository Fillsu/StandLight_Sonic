#include "TH_View.h"

TH_View::TH_View(LCD *lcd)
{
this->lcd=lcd;
}

TH_View::~TH_View()
{

}

void TH_View::updateView()
{
    //std::cout<<buf<<std::endl;
    lcd->WriteStringXY(0, 10, TH_buf1);
    lcd->WriteStringXY(1, 10, TH_buf2);
}
void TH_View::Emergency()
{
lcd->WriteStringXY(0, 10, TH_buf2);
lcd->backLightOff();
}