#pragma once
#include "wx/wx.h"
#include "cMain.h"

/*cApp.h - This is the container if you will for holding the application together all together.*/

class cApp : public wxApp
{
public:
    cApp();

    //Destructor
    ~cApp() override;


/*Methods*/
public:
    bool OnInit() override;

private:
    cMain* m_frame1 = nullptr;
};