#ifndef CALC_H
#define CALC_H



#include<wx-3.2/wx/wx.h>
#include<array>

class Calc : public wxFrame
{   
    wxDECLARE_EVENT_TABLE();
    public:
    Calc(const wxString& title);
    void OnQuit(wxCommandEvent& event);
    
    protected:
    //Sizers must be public, otherwise they don't work
    wxBoxSizer* sizer;
    wxGridSizer* gs;
    wxTextCtrl* display;

    //Array of buttons, vectors don't work (duuuuh)
    std::array<wxButton*, 9> buttons;
    wxButton *add, *sub, *mult, *div, *equal, *decim, *clear, *back, *close;



    
   
};




#endif