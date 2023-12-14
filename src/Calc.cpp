#include "Calc.h"
#include<sstream>



template <typename T> 
wxString toString(T val)
{
   std::stringstream ss;
   ss<<val;
   return ss.str();
}


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

   BUTTON00 = 1018



};

wxBEGIN_EVENT_TABLE(Calc, wxFrame)
   EVT_BUTTON(BUTTON0, Calc::OnZero)
   EVT_BUTTON(BUTTON1, Calc::OnOne)
   EVT_BUTTON(BUTTON2, Calc::OnTwo)
   EVT_BUTTON(BUTTON3, Calc::OnThree)
   EVT_BUTTON(BUTTON4, Calc::OnFour)
   EVT_BUTTON(BUTTON5, Calc::OnFive)
   EVT_BUTTON(BUTTON6, Calc::OnSix)
   EVT_BUTTON(BUTTON7, Calc::OnSeven)
   EVT_BUTTON(BUTTON8, Calc::OnEight)
   EVT_BUTTON(BUTTON9, Calc::OnNine)
   EVT_BUTTON(BUTTON_ADD, Calc::OnAdd)
   EVT_BUTTON(BUTTON_SUB, Calc::OnSub)
   EVT_BUTTON(BUTTON_MULT, Calc::OnMult)
   EVT_BUTTON(BUTTON_DIV, Calc::OnDiv)
   EVT_BUTTON(BUTTON_CLEAR, Calc::OnClear)
   EVT_BUTTON(BUTTON_DECIM, Calc::OnDecim)
   EVT_BUTTON(BUTTON_EQUAL, Calc::OnEqual)
   EVT_BUTTON(BUTTON_BACK, Calc::OnBack)
   EVT_BUTTON(BUTTON00, Calc::OnBut00)
  
wxEND_EVENT_TABLE()


//Constructor
Calc::Calc(const wxString& title)
: wxFrame(nullptr, -1, title, wxPoint(-1,-1), wxSize(270,220))
{
   //Initilizeing sizers and display
   topBoxsizer = new wxBoxSizer(wxVERTICAL);
   topPanel = new wxPanel(this, wxID_ANY);

   

   topBoxsizer->Add(topPanel,1 , wxEXPAND | wxALL, 1);

   this->SetSizer(topBoxsizer);

   

   subBoxSizer = new wxBoxSizer(wxVERTICAL);

   topPanel->SetSizer(subBoxSizer);

   display = new wxTextCtrl(topPanel, wxID_ANY, wxT(""), wxPoint(-1,-1),
                            wxSize(-1,-1), wxTE_READONLY | wxTE_RIGHT);

  
   display->SetFocus();

   textSizer = new wxBoxSizer(wxHORIZONTAL);
   textSizer ->Add(display, 1, wxRIGHT | wxLEFT | wxTOP, 10);
   subBoxSizer->Add(textSizer, 0, wxEXPAND );

   

   //initilizing buttons
   buttons[0] = new wxButton(topPanel, BUTTON0, wxT("0"));
   buttons[1] = new wxButton(topPanel, BUTTON1, wxT("1"));
   buttons[2] = new wxButton(topPanel, BUTTON2, wxT("2"));
   buttons[3] = new wxButton(topPanel, BUTTON3, wxT("3"));
   buttons[4] = new wxButton(topPanel, BUTTON4, wxT("4"));
   buttons[5] = new wxButton(topPanel, BUTTON5, wxT("5"));
   buttons[6] = new wxButton(topPanel, BUTTON6, wxT("6"));
   buttons[7] = new wxButton(topPanel, BUTTON7, wxT("7"));
   buttons[8] = new wxButton(topPanel, BUTTON8, wxT("8"));
   buttons[9] = new wxButton(topPanel, BUTTON9, wxT("9"));

   add = new wxButton(topPanel, BUTTON_ADD, wxT("="));
   sub = new wxButton(topPanel, BUTTON_SUB, wxT("-"));
   mult = new wxButton(topPanel, BUTTON_MULT, wxT("*"));
   div = new wxButton(topPanel, BUTTON_DIV, wxT("/"));
   equal = new wxButton(topPanel,BUTTON_EQUAL,wxT("="));
   decim = new wxButton(topPanel,BUTTON_DECIM,wxT("."));
   clear = new wxButton(topPanel,BUTTON_CLEAR,wxT("C"));
   but00 = new wxButton(topPanel, BUTTON00, wxT("00"));


   leftKeypadSizer = new wxGridSizer(5,3,10,10);
   leftKeypadSizer->Add(clear);
   leftKeypadSizer->Add(div);
   leftKeypadSizer->Add(mult);
   leftKeypadSizer->Add(buttons[7]);
   leftKeypadSizer->Add(buttons[8]);
   leftKeypadSizer->Add(buttons[9]);
   leftKeypadSizer->Add(buttons[4]);
   leftKeypadSizer->Add(buttons[5]);
   leftKeypadSizer->Add(buttons[6]);
   leftKeypadSizer->Add(buttons[1]);
   leftKeypadSizer->Add(buttons[2]);
   leftKeypadSizer->Add(buttons[3]);
   leftKeypadSizer->Add(but00);
   leftKeypadSizer->Add(buttons[0]);
   leftKeypadSizer->Add(decim);

   rightKeypadSizer = new wxBoxSizer(wxVERTICAL);
   rightKeypadSizer->Add(add, 1, wxEXPAND | wxALL, 10);
   rightKeypadSizer->Add(sub, 2, wxEXPAND | wxALL, 10);
   rightKeypadSizer->Add(equal, 2, wxEXPAND | wxALL, 10);

   keypadSizer = new wxBoxSizer(wxHORIZONTAL);
   keypadSizer->Add(leftKeypadSizer, 0, wxEXPAND | wxTOP, 10);
   keypadSizer->Add(rightKeypadSizer,1, wxEXPAND );

   subBoxSizer->Add(keypadSizer, 1, wxEXPAND);
   this->SetMinSize(subBoxSizer->GetMinSize());
   this->SetSize(subBoxSizer->GetSize());

   Centre();
}

void Calc::OnAdd(wxCommandEvent &event)
{
   currentOperand = RIGHT_OPPERAND;
   currentOperation = ADD;
   display->SetFocus();
}

void Calc::OnSub(wxCommandEvent &event)
{
   currentOperand = RIGHT_OPPERAND;
   currentOperation = SUB;
   display->SetFocus();
}

void Calc::OnMult(wxCommandEvent &event)
{
   currentOperand = RIGHT_OPPERAND;
   currentOperation = MULT;
   display->SetFocus();
}

void Calc::OnDiv(wxCommandEvent &event)
{
   currentOperand = RIGHT_OPPERAND;
   currentOperation = DIV;
   display->SetFocus();
}

void Calc::OnZero(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('0');
   }
   else
   {
      rightOp.push_back('0');
   }

   UpdateRes();
}

void Calc::OnOne(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('1');
   }
   else
   {
      rightOp.push_back('1');
   }

   UpdateRes();
}

void Calc::OnTwo(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('2');
   }
   else
   {
      rightOp.push_back('2');
   }

   UpdateRes();
}

void Calc::OnThree(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('3');
   }
   else
   {
      rightOp.push_back('3');
   }

   UpdateRes();
}

void Calc::OnFour(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('4');
   }
   else
   {
      rightOp.push_back('4');
   }

   UpdateRes();
}

void Calc::OnFive(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('5');
   }
   else
   {
      rightOp.push_back('5');
   }

   UpdateRes();
}

void Calc::OnSix(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('6');
   }
   else
   {
      rightOp.push_back('6');
   }

   UpdateRes();
}

void Calc::OnSeven(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('7');
   }
   else
   {
      rightOp.push_back('7');
   }

   UpdateRes();
}

void Calc::OnEight(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('8');
   }
   else
   {
      rightOp.push_back('8');
   }

   UpdateRes();
}

void Calc::OnNine(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('9');
   }
   else
   {
      rightOp.push_back('9');
   }

   UpdateRes();
}

void Calc::OnDecim(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp += "."; 
   }
   else
   {
      rightOp += ".";
   }

   UpdateRes();
}

void Calc::OnEqual(wxCommandEvent &event)
{
   if(currentOperand == RIGHT_OPPERAND)
   {
      if(currentOperation == ADD)
      {
         result = stod(leftOp) + stod(rightOp);
      }
      else if(currentOperation == SUB)
      {
         result = stod(leftOp) - stod(rightOp);
      }
      else if (currentOperation == MULT)
      {
         result = stod(leftOp) * stod(rightOp);
      }
      else if(currentOperation == DIV)
      {
         result = stod(leftOp) / stod(rightOp);
      }

      display->Clear();
      display->AppendText(toString(result));

      currentOperand = LEFT_OPPERAND;
      leftOp = toString(result);
      rightOp.clear();

   }

   display->SetFocus();
}

void Calc::OnClear(wxCommandEvent &event)
{
   leftOp.clear();
   rightOp.clear();
   result = 0;
   display->Clear();
   display->SetFocus();
}


void Calc::UpdateRes()
{
   if(currentOperand == LEFT_OPPERAND)
   {
      display->Clear();
      display->AppendText(toString(leftOp));
   }
   else
   {
      display->Clear();
      display->AppendText(toString(rightOp));
   }

   display->SetFocus();

}



void Calc::OnBack(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.pop_back();
   }
   else
   {
      rightOp.pop_back();
   }

   UpdateRes();
}

void Calc::OnBut00(wxCommandEvent &event)
{
   if(currentOperand == LEFT_OPPERAND)
   {
      leftOp.push_back('0');
      leftOp.push_back('0');
   }
   else
   {
      rightOp.push_back('0');
      rightOp.push_back('0');
   }

   UpdateRes();
}