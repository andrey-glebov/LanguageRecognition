/***************************************************************
 * Name:      LanguageRecognitionMain.h
 * Purpose:   Defines Application Frame
 * Author:    Angrey Glebov (andrey.gle@gmail.com)
 * Created:   2013-02-08
 * Copyright: Angrey Glebov ()
 * License:
 **************************************************************/

#ifndef LANGUAGERECOGNITIONMAIN_H
#define LANGUAGERECOGNITIONMAIN_H

//(*Headers(LanguageRecognitionFrame)
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
//*)

class LanguageRecognitionFrame: public wxFrame
{
    public:

        LanguageRecognitionFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~LanguageRecognitionFrame();

    private:

        //(*Handlers(LanguageRecognitionFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnAnalyzeButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(LanguageRecognitionFrame)
        static const long ID_BUTTON2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON3;
        static const long ID_GRID1;
        static const long ID_STATICBITMAP1;
        static const long ID_GRID2;
        static const long idMenuQuit;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(LanguageRecognitionFrame)
        wxButton* RecBtn;
        wxButton* PlayBtn;
        wxStatusBar* StatusBar1;
        wxGrid* Grid1;
        wxGrid* Grid2;
        wxStaticBitmap* StaticBitmap1;
        wxButton* AnalyzeButton;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // LANGUAGERECOGNITIONMAIN_H
