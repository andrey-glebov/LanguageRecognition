/***************************************************************
 * Name:      LanguageRecognitionMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Angrey Glebov (andrey.gle@gmail.com)
 * Created:   2013-02-08
 * Copyright: Angrey Glebov ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "LanguageRecognitionMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(LanguageRecognitionFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <LanguageRecognizer.hpp>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(LanguageRecognitionFrame)
const long LanguageRecognitionFrame::ID_BUTTON2 = wxNewId();
const long LanguageRecognitionFrame::ID_BUTTON1 = wxNewId();
const long LanguageRecognitionFrame::ID_BUTTON3 = wxNewId();
const long LanguageRecognitionFrame::ID_GRID1 = wxNewId();
const long LanguageRecognitionFrame::ID_STATICBITMAP1 = wxNewId();
const long LanguageRecognitionFrame::ID_GRID2 = wxNewId();
const long LanguageRecognitionFrame::idMenuQuit = wxNewId();
const long LanguageRecognitionFrame::ID_STATUSBAR1 = wxNewId();
//*)

LanguageRecognizer *Recognize = new LanguageRecognizer();

BEGIN_EVENT_TABLE(LanguageRecognitionFrame,wxFrame)
    //(*EventTable(LanguageRecognitionFrame)
    //*)
END_EVENT_TABLE()

LanguageRecognitionFrame::LanguageRecognitionFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(LanguageRecognitionFrame)
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    RecBtn = new wxButton(this, ID_BUTTON2, _("Record"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(RecBtn, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PlayBtn = new wxButton(this, ID_BUTTON1, _("Play"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(PlayBtn, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AnalyzeButton = new wxButton(this, ID_BUTTON3, _("Analyze"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer1->Add(AnalyzeButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    FlexGridSizer1->Add(Grid1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    StaticBitmap1->SetMinSize(wxSize(400,300));
    FlexGridSizer1->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Grid2 = new wxGrid(this, ID_GRID2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID2"));
    FlexGridSizer1->Add(Grid2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LanguageRecognitionFrame::OnAnalyzeButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LanguageRecognitionFrame::OnQuit);
    //*)
}

LanguageRecognitionFrame::~LanguageRecognitionFrame()
{
    //(*Destroy(LanguageRecognitionFrame)
    //*)
}

void LanguageRecognitionFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void LanguageRecognitionFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void LanguageRecognitionFrame::OnAnalyzeButtonClick(wxCommandEvent& event)
{
    //Recognize->Analyze("word.wav");
    char file[80]="word.wav";
    printf("%d\n",Recognize->Analyze(file));
}
