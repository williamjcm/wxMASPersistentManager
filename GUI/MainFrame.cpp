///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );

	m_listBoxPersistents = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB|wxLB_SORT );
	bMainSizer->Add( m_listBoxPersistents, 1, wxALL|wxEXPAND, 5 );

	wxGridSizer* gSizerButtons;
	gSizerButtons = new wxGridSizer( 0, 2, 0, 0 );

	m_buttonCreateMainPersistentBackup = new wxButton( this, wxID_ANY, wxT("Backup main persistent"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizerButtons->Add( m_buttonCreateMainPersistentBackup, 0, wxALL|wxEXPAND, 5 );

	m_buttonRenameSelectedBackup = new wxButton( this, wxID_ANY, wxT("Rename selected persistent"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizerButtons->Add( m_buttonRenameSelectedBackup, 0, wxALL|wxEXPAND, 5 );

	m_buttonRestoreSelectedBackup = new wxButton( this, wxID_ANY, wxT("Restore selected persistent"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizerButtons->Add( m_buttonRestoreSelectedBackup, 0, wxALL|wxEXPAND, 5 );

	m_buttonDeleteSelectedBackup = new wxButton( this, wxID_ANY, wxT("Delete selected persistent"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizerButtons->Add( m_buttonDeleteSelectedBackup, 0, wxALL|wxEXPAND, 5 );

	m_buttonOpenSaveFolder = new wxButton( this, wxID_ANY, wxT("Open save folder in a file manager"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizerButtons->Add( m_buttonOpenSaveFolder, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_buttonCreateBackupZip = new wxButton( this, wxID_ANY, wxT("Archive persistents"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizerButtons->Add( m_buttonCreateBackupZip, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bMainSizer->Add( gSizerButtons, 0, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bMainSizer->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_staticTextAbout = new wxStaticText( this, wxID_ANY, wxT("This program was made by Guillaume Jacquemin (William JCM)\nfor the Monika After Story community."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticTextAbout->Wrap( -1 );
	m_staticTextAbout->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	bMainSizer->Add( m_staticTextAbout, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bMainSizer );
	this->Layout();
	m_timerRefresh.SetOwner( this, wxID_ANY );


	this->Centre( wxBOTH );

	// Connect Events
	m_buttonCreateMainPersistentBackup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnBackupMainPersistentButtonClick ), NULL, this );
	m_buttonRenameSelectedBackup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnRenameSelectedBackupButtonClick ), NULL, this );
	m_buttonRestoreSelectedBackup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnRestoreSelectedBackupButtonClick ), NULL, this );
	m_buttonDeleteSelectedBackup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDeleteSelectedBackupButtonClick ), NULL, this );
	m_buttonOpenSaveFolder->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnOpenSaveFolderButtonClick ), NULL, this );
	m_buttonCreateBackupZip->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnCreateZipButtonClick ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MainFrame::OnAutoRefreshTimer ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_buttonCreateMainPersistentBackup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnBackupMainPersistentButtonClick ), NULL, this );
	m_buttonRenameSelectedBackup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnRenameSelectedBackupButtonClick ), NULL, this );
	m_buttonRestoreSelectedBackup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnRestoreSelectedBackupButtonClick ), NULL, this );
	m_buttonDeleteSelectedBackup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnDeleteSelectedBackupButtonClick ), NULL, this );
	m_buttonOpenSaveFolder->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnOpenSaveFolderButtonClick ), NULL, this );
	m_buttonCreateBackupZip->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnCreateZipButtonClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MainFrame::OnAutoRefreshTimer ) );

}
