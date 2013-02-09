/***************************************************************
 * Name:      LanguageRecognitionApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Angrey Glebov (andrey.gle@gmail.com)
 * Created:   2013-02-08
 * Copyright: Angrey Glebov ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "LanguageRecognitionApp.h"

//(*AppHeaders
#include "LanguageRecognitionMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LanguageRecognitionApp);

bool LanguageRecognitionApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LanguageRecognitionFrame* Frame = new LanguageRecognitionFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
