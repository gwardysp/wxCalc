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
 

    wxPanel *topPanel;
    wxBoxSizer *topBoxsizer, *subBoxSizer, *textSizer, *keypadSizer, *rightKeypadSizer;
    wxGridSizer* leftKeypadSizer;
    wxTextCtrl* display;
    
   
    //Sizers must be public, otherwise they don't work

    

    //Array of buttons, vectors don't work (duuuuh)
    std::array<wxButton*, 10> buttons;
    wxButton *add, *sub, *mult, *div, *equal, *decim, *clear, *back, *but00;


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

    void OnBut00(wxCommandEvent &event);
   
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