//
// Created by Ashton.kinnell on 7/31/2023.
//

//#include "MyAppFrame.h"

MyAppFrame::MyAppFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) {

    m_button = new wxButton(this, wxID_ANY, "Click Me!", wxPoint(10, 10), wxSize(100, 30));
    // Bind the button click event to the event handler
    m_button->Bind(wxEVT_BUTTON, &MyAppFrame::OnButtonClick, this);
}

void MyAppFrame::OnButtonClick(wxCommandEvent& event) {
    // Handle button click event
    wxMessageBox("Button Clicked!", "Information", wxOK | wxICON_INFORMATION);
}
