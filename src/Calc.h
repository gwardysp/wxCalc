#ifndef CALC_H
#define CALC_H


#include<wx/wx.h>
#include<array>

class Calc : public wxFrame
{
    public:
    Calc(const wxString& title);
    void OnQuit(wxCommandEvent& event);
    wxBoxSizer* sizer;
    wxGridSizer* gs;
    wxTextCtrl* display;

    std::array<wxButton*, 9> buttons;


    
   
};




#endif