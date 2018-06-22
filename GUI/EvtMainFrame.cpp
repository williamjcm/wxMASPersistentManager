#include "EvtMainFrame.h"

EvtMainFrame::EvtMainFrame( wxWindow* parent )
:
MainFrame( parent )
{
    SetIcon(snugnika);
    if(!m_PersistentManager.IsFolderOpen())
    {
        ErrorMessage("MAS's persistent folder couldn't be opened.\nTry restarting the application.");
        Close();
    }
    else
    {
        RefreshPersistentList();
    }
}

void EvtMainFrame::OnBackupMainPersistentButtonClick( wxCommandEvent& event )
{
    wxDateTime DateTime(wxGetUTCTimeMillis()); // Windows 10, Linux and macOS should use UTC time by default.
    wxString CurrentDateTime = DateTime.Format("%Y-%m-%d_%H-%M-%S");
    wxTextEntryDialog BackupNameDialog(this,
                                       "Please enter a name for the backup if you don't like the default.\n"
                                       "The chosen name will be prepended with \"persistent_\".\n"
                                       "Note: if a file with the same name exists, it WILL be overwritten.",
                                       "Enter backup name",
                                       "backup_" + CurrentDateTime);
    int Result = BackupNameDialog.ShowModal();
    if(Result == wxID_OK)
    {
        wxString BackupName = BackupNameDialog.GetValue();
        m_PersistentManager.BackupMainPersistent("persistent_" + BackupName);
        RefreshPersistentList();
    }
}

void EvtMainFrame::OnRenameSelectedBackupButtonClick( wxCommandEvent& event )
{
    int Selection = m_listBoxPersistents->GetSelection();
    if(Selection == wxNOT_FOUND)
    {
        ErrorMessage("No persistent file is selected. Please select one.");
    }
    else
    {
        wxString OldName = m_listBoxPersistents->GetString(Selection);
        if(OldName == "persistent")
        {
            WarningMessage("The main persistent is selected. A backup will be created,\nas if you had clicked \"Backup main persistent\".");
            OnBackupMainPersistentButtonClick(event);
        }
        else
        {
            wxTextEntryDialog BackupNameDialog(this,
                                               "Please enter a new name for the backup.\n"
                                               "The chosen name will be prepended with \"persistent_\".\n"
                                               "Note: if a file with the same name exists, it WON'T be overwritten.",
                                               "Enter new backup name",
                                               OldName.AfterFirst('_'));
            int Result = BackupNameDialog.ShowModal();
            if(Result == wxID_OK)
            {
                wxString NewName = "persistent_" + BackupNameDialog.GetValue();
                if(OldName == NewName)
                {
                    ErrorMessage("The two names are identical. Aborting.");
                }
                else
                {
                    m_PersistentManager.RenameBackup(OldName, NewName);
                    RefreshPersistentList();
                }
            }
        }
    }
}

void EvtMainFrame::OnRestoreSelectedBackupButtonClick( wxCommandEvent& event )
{
    wxString BackupName = m_listBoxPersistents->GetString(m_listBoxPersistents->GetSelection());
    if(BackupName == "persistent")
    {
        ErrorMessage("You can't restore the main persistent.");
    }
    else
    {
        wxMessageDialog DangerWarningDialog(this,
                                            "This operation is potentially destructive and can cause loss of data.\n"
                                            "Are you ABSOLUTELY sure you want to continue ?",
                                            "Warning",
                                            wxICON_EXCLAMATION|wxCENTRE|wxYES_NO);
        int Result = DangerWarningDialog.ShowModal();
        if(Result == wxID_YES)
        {
            m_PersistentManager.RestoreBackup(BackupName);
            RefreshPersistentList();
        }
    }
}

void EvtMainFrame::OnDeleteSelectedBackupButtonClick( wxCommandEvent& event )
{
    wxMessageDialog DangerWarningDialog(this,
                                        "This operation is potentially destructive and can cause loss of data.\n"
                                        "Are you ABSOLUTELY sure you want to continue ?",
                                        "Warning",
                                        wxICON_EXCLAMATION|wxCENTRE|wxYES_NO);
    int Result = DangerWarningDialog.ShowModal();
    if(Result == wxID_YES)
    {
        wxString BackupName = m_listBoxPersistents->GetString(m_listBoxPersistents->GetSelection());
        if(BackupName == "persistent")
        {
            wxMessageDialog PersistentDeletionWarning(this,
                                                      "You have selected the main persistent file.\n"
                                                      "Are you ABSOLUTELY sure you want to delete your current progress ?",
                                                      "Warning",
                                                      wxICON_EXCLAMATION|wxCENTRE|wxYES_NO|wxNO_DEFAULT);
            int PersistentDeletionConfirmation = PersistentDeletionWarning.ShowModal();
            if(PersistentDeletionConfirmation == wxID_YES)
            {
                m_PersistentManager.DeleteBackup(BackupName);
                RefreshPersistentList();
            }
        }
        else
        {
            m_PersistentManager.DeleteBackup(BackupName);
            RefreshPersistentList();
        }
    }
}

void EvtMainFrame::OnOpenSaveFolderButtonClick( wxCommandEvent& event )
{
    m_PersistentManager.OpenFileManager();
}

void EvtMainFrame::OnCreateZipButtonClick( wxCommandEvent& event )
{
    wxDateTime DateTime(wxGetUTCTimeMillis()); // Windows 10, Linux and macOS should use UTC time by default.
    wxString CurrentDateTime = DateTime.Format("%Y-%m-%d_%H-%M-%S");

    wxFileDialog ArchiveSaveDialog(this,
                                   "Select where to save the archive",
                                   wxGetCwd(),
                                   "Persistents_" + CurrentDateTime + ".zip",
                                   "Zip archives (*.zip)|*.zip",
                                   wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    int Result = ArchiveSaveDialog.ShowModal();
    if(Result == wxID_OK)
    {
        m_PersistentManager.CreateBackupZip(ArchiveSaveDialog.GetPath());
    }
}

void EvtMainFrame::RefreshPersistentList()
{
    m_listBoxPersistents->Clear();
    wxArrayString PersistentList = m_PersistentManager.GetPersistentList();
    for(auto it = PersistentList.begin(); it != PersistentList.end(); ++it) // wxArrayStrings has std::vector-like iterators.
    {
        m_listBoxPersistents->Append(*it);
    }
}

void EvtMainFrame::InfoMessage(wxString Message)
{
    wxMessageDialog InfoMessageDialog(this, Message, "Information", wxICON_INFORMATION|wxCENTRE|wxOK);
    InfoMessageDialog.ShowModal();
}

void EvtMainFrame::WarningMessage(wxString Message)
{
    wxMessageDialog WarningMessageDialog(this, Message, "Warning", wxICON_EXCLAMATION|wxCENTRE|wxOK);
    WarningMessageDialog.ShowModal();
}

void EvtMainFrame::ErrorMessage(wxString Message)
{
    wxMessageDialog ErrorMessageDialog(this, Message, "Error", wxICON_ERROR|wxCENTRE|wxOK);
    ErrorMessageDialog.ShowModal();
}
