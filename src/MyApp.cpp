#include "MyApp.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Calc * calc = new Calc(wxT("wxCalculator"));
    calc -> Show(true);
    return true;
    
}