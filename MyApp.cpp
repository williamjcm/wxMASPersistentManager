#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "MyApp.h"
#include "GUI/EvtMainFrame.h"

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    SetAppName("MAS Persistent Manager");
    SetAppDisplayName("MAS Persistent Manager");

    EvtMainFrame* main_frame = new EvtMainFrame(nullptr);
    main_frame->Show();

    return true;
}
