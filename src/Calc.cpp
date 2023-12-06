#include "Calc.h"
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
   buttons[0] = new wxButton(this, -1, wxT("0"));
   buttons[1] = new wxButton(this, -1, wxT("1"));
   buttons[2] = new wxButton(this, -1, wxT("2"));
   buttons[3] = new wxButton(this, -1, wxT("3"));
   buttons[4] = new wxButton(this, -1, wxT("4"));
   buttons[5] = new wxButton(this, -1, wxT("5"));
   buttons[6] = new wxButton(this, -1, wxT("6"));
   buttons[7] = new wxButton(this, -1, wxT("7"));
   buttons[8] = new wxButton(this, -1, wxT("8"));
   buttons[9] = new wxButton(this, -1, wxT("9"));

   //declaring and initilizing operation buttons
   wxButton *plus = new wxButton(this, -1, wxT("+"));
   wxButton *minus = new wxButton(this, -1, wxT("-"));
   wxButton *multi = new wxButton(this, -1, wxT("*"));
   wxButton *div = new wxButton(this, -1, wxT("/"));

   wxButton *clear = new wxButton(this, -1, wxT("C"));
   wxButton *back = new wxButton(this, -1, wxT("Back"));
   wxButton *dot = new wxButton(this, -1, wxT("."));
   wxButton *equal = new wxButton(this, -1, wxT("="));
   wxButton *close = new wxButton(this, wxID_EXIT, wxT("Close"));

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
   gs->Add(multi, 0, wxEXPAND);
   gs->Add(buttons[1], 0, wxEXPAND);
   gs->Add(buttons[2], 0, wxEXPAND);
   gs->Add(buttons[3], 0, wxEXPAND);
   gs->Add(minus, 0, wxEXPAND);
   gs->Add(dot, 0, wxEXPAND);
   gs->Add(buttons[0], 0, wxEXPAND);
   gs->Add(equal, 0, wxEXPAND);
   gs->Add(plus, 0, wxEXPAND);


  
   //adding grid to the sizer
   sizer->Add(gs, 1, wxEXPAND);
   SetSizer(sizer);
   SetMinSize(wxSize(270, 220));

   Centre();
}

void Calc::OnQuit(wxCommandEvent& WXUNUSED(event))
{
   Close(true);
}