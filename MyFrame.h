#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    wxTextCtrl* textCtrl1;
    wxTextCtrl* textCtrl2;
    wxTextCtrl* textCtrl3;

    void OnSortButtonClick(wxCommandEvent& event);

    // Add declaration for the bubbleSort function
    void bubbleSort(std::vector<std::string>& vec);

    wxDECLARE_EVENT_TABLE();
};

#endif // MYFRAME_H
