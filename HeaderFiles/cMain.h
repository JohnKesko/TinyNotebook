#pragma once
#include "wx/wx.h"

/*cMain.h - This is where we configure our application. Events, how the app should behave etc.*/

class cMain : public wxFrame
{
public:
    cMain();
    ~cMain() override;

public:
    enum { wxID_HELLO = 1};
    wxTextCtrl *tc;
    void OnOpen(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:

};
