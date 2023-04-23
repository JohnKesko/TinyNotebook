#include "../HeaderFiles/cMain.h"

/*cMain.cpp - This is where the implementations will be structured of how our application should behave.*/

/*Constructor*/
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Tiny Notebook", wxDefaultPosition, wxSize(400, 300))
{
    tc = new wxTextCtrl(this, -1, wxT(""), wxPoint(0, 0), wxSize(400, 300), wxTE_MULTILINE);

    // Create a new font with desired properties
    int fontSize = 14; // Set the desired font size (in points)
    wxFontFamily fontFamily = wxFONTFAMILY_DEFAULT; // Set the desired font family
    wxFontStyle fontStyle = wxFONTSTYLE_NORMAL; // Set the desired font style
    wxFontWeight fontWeight = wxFONTWEIGHT_NORMAL; // Set the desired font weight
    wxFont customFont(fontSize, fontFamily, fontStyle, fontWeight);
    tc->SetFont(customFont);

    // Menu
    auto* menuBar = new wxMenuBar;
    auto* menuFile = new wxMenu;
    auto* menuHelp = new wxMenu;

    menuFile->Append(wxID_NEW, "&New");
    menuFile->Append(wxID_OPEN, "&Open");
    menuFile->Append(wxID_SAVE, "&Save");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    menuHelp->Append(wxID_ABOUT, "&About");
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Tiny Notebook");

    Bind(wxEVT_MENU, &cMain::OnOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &cMain::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &cMain::OnExit, this, wxID_EXIT);
}

/*Destructor*/
cMain::~cMain() = default;

/*Method Implementations*/
void cMain::OnOpen(wxCommandEvent &event)
{
    wxFileDialog* openFileDialog = new wxFileDialog(this);
    if (openFileDialog->ShowModal() == wxID_OK)
    {
        wxString fileName = openFileDialog->GetPath();
        tc->LoadFile(fileName);
    }
}

void cMain::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("The simple notebook.","Tiny Notebook", wxOK | wxICON_INFORMATION);
}

void cMain::OnExit(wxCommandEvent &event)
{
    Close(true);
}

