#ifndef CALC_H
#define CALC_H



#include<wx-3.2/wx/wx.h>
#include<array>
#include<cstring>

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


    //Functions for buttons
    void OnOne(wxCommandEvent &event);
    void OnTwo(wxCommandEvent &event);
    void OnThree(wxCommandEvent &event);
    void OnFour(wxCommandEvent &event);
    void OnFive(wxCommandEvent &event);
    void OnSix(wxCommandEvent &event);
    void OnSeven(wxCommandEvent &event);
    void OnEight(wxCommandEvent &event);
    void OnNine(wxCommandEvent &event);
    void OnZero(wxCommandEvent &event);
   
    void OnAdd(wxCommandEvent &event);
    void OnSub(wxCommandEvent &event);
    void OnMult(wxCommandEvent &event);
    void OnDiv(wxCommandEvent &event);
    void OnClear(wxCommandEvent &event);
    void OnEqual(wxCommandEvent &event);
    void OnDecim(wxCommandEvent &event);
    void OnBack(wxCommandEvent &event);

    

    void UpdateRes();

    double result = 0;

    std::string leftOp = "";
    std::string rightOp = "";

    enum Operand {LEFT_OPPERAND, RIGHT_OPPERAND};
    enum Operation {ADD, SUB, MULT, DIV};
    Operand currentOperand = LEFT_OPPERAND;
    Operation currentOperation;




    
   
};




#endif