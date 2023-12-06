#include "MyApp.h"

IMPLEMENT_APP(MyApp)

//Implementation
bool MyApp::OnInit()
{
    Calc * calc = new Calc(wxT("wxCalculator"));
    calc -> Show(true);
    return true;
    
}