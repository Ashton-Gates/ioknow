#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);

    void OnSubmitButtonClick(wxCommandEvent& event);

    wxTextCtrl* m_textCtrl;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("wxWidgets Window");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    m_textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(10, 10), wxSize(200, 25));
    wxButton* button = new wxButton(panel, wxID_ANY, "Submit", wxPoint(10, 40), wxSize(80, 25));

    button->Bind(wxEVT_BUTTON, &MyFrame::OnSubmitButtonClick, this);
}

void MyFrame::OnSubmitButtonClick(wxCommandEvent& event)
{
    wxString text = m_textCtrl->GetValue();

    // TODO: Implement your code to send data to the AWS API and store it in the SQLite database
    // For this example, we'll just print the text to the console
    wxLogMessage("Submitted text: %s", text);
}