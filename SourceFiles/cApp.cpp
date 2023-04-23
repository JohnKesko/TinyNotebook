#include "../HeaderFiles/cApp.h"

/*cApp.cpp - This is where the implementation overall of our application is -> holding it all together. */

cApp::cApp() = default;
cApp::~cApp() = default;

/*The default entry point for a wxWidget App.*/
wxIMPLEMENT_APP(cApp);

/*Method that we must initialize and override to get this app started.*/
bool cApp::OnInit()
{
    m_frame1 = new cMain();
    m_frame1->Show(true);
    return true;
}