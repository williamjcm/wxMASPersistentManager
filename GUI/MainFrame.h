///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxListBox* m_listBoxPersistents;
		wxButton* m_buttonCreateMainPersistentBackup;
		wxButton* m_buttonRenameSelectedBackup;
		wxButton* m_buttonRestoreSelectedBackup;
		wxButton* m_buttonDeleteSelectedBackup;
		wxButton* m_buttonOpenSaveFolder;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticTextAbout;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnBackupMainPersistentButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRenameSelectedBackupButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRestoreSelectedBackupButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteSelectedBackupButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenSaveFolderButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MAS Persistent Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,500 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~MainFrame();
	
};

#endif //__MAINFRAME_H__
