#include <wx/wx.h>
#include "MainFrame.h"
#include <wx/spinctrl.h>
/*
enum IDs {
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4
};


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()
*/
MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
	
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));
	wxSlider* slider = new wxSlider(panel, wxID_ANY	, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);
	wxTextCtrl* textctrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", 
		wxPoint(500, 145), wxSize(200, -1));
	
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	textctrl->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);
	panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);
	button->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);

	panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);
	
	//button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", 
		wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Static Text - NOT editable", 
		wxPoint(0, 150), wxSize(400, -1), wxALIGN_CENTRE_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY);

	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(590, 205), wxSize(-1, 125), wxGA_VERTICAL);
	gauge->SetValue(50);

	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	choice->Select(0);

	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100,-1), wxSP_WRAP);

	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", 
		wxPoint(555, 450), wxDefaultSize, choices, 3, wxRA_SPECIFY_ROWS);

	CreateStatusBar();
}	

void MainFrame::OnButtonClicked(wxCommandEvent& evt){
	wxLogStatus("Button Clicked");
	wxLogMessage("Button Clicked!!!!");
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt){
	wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
	wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt){
	wxString str = wxString::Format("Text: %s", evt.GetString());
	wxLogStatus(str);
}

void MainFrame::OnClose(wxCloseEvent& evt){
	wxLogMessage("Frame Closed");
	evt.Skip();
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt){
	wxPoint mousePos = wxGetMousePosition();
	mousePos = this->ScreenToClient(mousePos);
	wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);	
	wxLogStatus(message);
}

void MainFrame::OnKeyEvent(wxKeyEvent& evt){
	/*
	if(evt.GetUnicodeKey() == 'A') {
		wxLogStatus("A was pressed!");
	}
	else {
		wxLogStatus("HOME was pressed!");
	}
	return;
	*/
	if (evt.GetKeyCode() == WXK_TAB) {
		wxWindow* window = (wxWindow*)evt.GetEventObject();
		window->Navigate();
	}

	wxChar keyChar = evt.GetUnicodeKey();

	if(keyChar == WXK_NONE) {
		int keyCode = evt.GetKeyCode();
		wxLogStatus("Key Event %d", keyCode);
	}
	else {
		wxLogStatus("Key Event %c", keyChar);
	}
	
	//wxLogStatus("Key Event", keyChar);
}