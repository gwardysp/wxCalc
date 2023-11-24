#ifndef CALC_H
#define CALC_H

#include<wx-3.2/wx/wx.h>

class Calc : public wxFrame
{
    public:
    Calc(const wxString& title);
    void OnQuit(wxCommandEvent& event);
    
    private:
    wxButton * buttons;
};




#endif;