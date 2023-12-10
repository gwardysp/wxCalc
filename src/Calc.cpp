#include "Calc.h"


enum {
   BUTTON0 = 1000,
   BUTTON1 = 1001,
   BUTTON2 = 1002,
   BUTTON3 = 1003,
   BUTTON4 = 1004,
   BUTTON5 = 1005,
   BUTTON6 = 1006,
   BUTTON7 = 1007,
   BUTTON8 = 1008,
   BUTTON9 = 1009,

   BUTTON_ADD = 1010,
   BUTTON_SUB = 1011,
   BUTTON_MULT = 1012,
   BUTTON_DIV = 1013,

   BUTTON_CLEAR = 1014,
   BUTTON_BACK = 1015,
   BUTTON_DECIM = 1016,
   BUTTON_EQUAL = 1017,

   BUTTON_CLOSE = 1018



};


//Constructor
Calc::Calc(const wxString& title)
: wxFrame(nullptr, -1, title, wxPoint(-1,-1), wxSize(270,220))
{
   //Initilizeing sizers and display
   sizer = new wxBoxSizer(wxVERTICAL);

   display = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1),
                            wxSize(-1, -1), wxTE_RIGHT);

   sizer->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
   gs = new wxGridSizer(5, 4, 4, 4);

   //initilizing buttons
   buttons[0] = new wxButton(this, BUTTON0, wxT("0"));
   buttons[1] = new wxButton(this, BUTTON1, wxT("1"));
   buttons[2] = new wxButton(this, BUTTON2, wxT("2"));
   buttons[3] = new wxButton(this, BUTTON3, wxT("3"));
   buttons[4] = new wxButton(this, BUTTON4, wxT("4"));
   buttons[5] = new wxButton(this, BUTTON5, wxT("5"));
   buttons[6] = new wxButton(this, BUTTON6, wxT("6"));
   buttons[7] = new wxButton(this, BUTTON7, wxT("7"));
   buttons[8] = new wxButton(this, BUTTON8, wxT("8"));
   buttons[9] = new wxButton(this, BUTTON9, wxT("9"));

   add = new wxButton(this, BUTTON_ADD, wxT("="));
   sub = new wxButton(this, BUTTON_SUB, wxT("-"));
   mult = new wxButton(this, BUTTON_MULT, wxT("*"));
   div = new wxButton(this, BUTTON_DIV, wxT("/"));
   equal = new wxButton(this,BUTTON_EQUAL,wxT("="));
   decim = new wxButton(this,BUTTON_DECIM,wxT("."));
   clear = new wxButton(this,BUTTON_CLEAR,wxT("C"));

   close = new wxButton(this,BUTTON_CLOSE,wxT("Close"));

   

   //declaring and initilizing operation buttons
   
   

   Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Calc::OnQuit) );
   

   //adding buttons to the grid
   gs->Add(clear, 0, wxEXPAND);
   gs->Add(back, 0, wxEXPAND);
   gs->Add(close, 0, wxEXPAND);
   gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
   gs->Add(buttons[7], 0, wxEXPAND);
   gs->Add(buttons[8], 0, wxEXPAND);
   gs->Add(buttons[9], 0, wxEXPAND);
   gs->Add(div, 0, wxEXPAND);
   gs->Add(buttons[4], 0, wxEXPAND);
   gs->Add(buttons[5], 0, wxEXPAND);
   gs->Add(buttons[6], 0, wxEXPAND);
   gs->Add(mult, 0, wxEXPAND);
   gs->Add(buttons[1], 0, wxEXPAND);
   gs->Add(buttons[2], 0, wxEXPAND);
   gs->Add(buttons[3], 0, wxEXPAND);
   gs->Add(sub, 0, wxEXPAND);
   gs->Add(decim, 0, wxEXPAND);
   gs->Add(buttons[0], 0, wxEXPAND);
   gs->Add(equal, 0, wxEXPAND);
   gs->Add(add, 0, wxEXPAND);


  
   //adding grid to the sizer
   sizer->Add(gs, 1, wxEXPAND);
   SetSizer(sizer);
   SetMinSize(wxSize(270, 220));

   Centre();
}

