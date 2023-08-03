//
// Created by Ashton.kinnell on 7/31/2023.
//

#ifndef IOKNOW_MYAPPFRAME_H
#define IOKNOW_MYAPPFRAME_H

#endif //IOKNOW_MYAPPFRAME_H

#pragma once

#include "wx/wx.h"

class MyAppFrame : public wxFrame {
public:
    MyAppFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    void OnButtonClick(wxCommandEvent& event); // Event handler
    // Declare other UI elements and event handlers as needed
    wxButton* m_button;
};
