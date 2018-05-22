#include "MASPersistentManager.h"

MASPersistentManager::MASPersistentManager()
{
#if defined __WIN32__
    m_SaveFolderStr = wxStandardPaths::Get().GetUserConfigDir() + "\\RenPy\\Monika After Story\\"; // GetUserConfigDir() returns the path to the %APPDATA% folder on Windows.
#elif defined __linux__
    m_SaveFolderStr = wxStandardPaths::Get().GetUserConfigDir() + "/.renpy/Monika After Story/"; // GetUserConfigDir() returns the path to the user's home folder on Linux.
#elif defined __APPLE__
    m_SaveFolderStr = wxGetHomeDir() + "/Library/RenPy/Monika After Story/"; // wxStandardPaths has no method that returns the path to ~/Library.
#endif
    m_SaveFolder.Open(m_SaveFolderStr);
}

MASPersistentManager::~MASPersistentManager()
{
    m_SaveFolder.Close();
}

bool MASPersistentManager::IsFolderOpen()
{
    return m_SaveFolder.IsOpened();
}

wxArrayString MASPersistentManager::GetPersistentList()
{
    wxArrayString PersistentList;
    wxString PersistentName;
    wxString FileMask = "persistent*"; // We want to get all files that start with persistent
    bool cont = m_SaveFolder.GetFirst(&PersistentName, FileMask, wxDIR_FILES);
    while (cont)
    {
        PersistentList.Add(PersistentName);
        cont = m_SaveFolder.GetNext(&PersistentName);
    }
    return PersistentList;
}

void MASPersistentManager::BackupMainPersistent(wxString BackupName)
{
    try
    {
        wxCopyFile(m_SaveFolderStr + "persistent", m_SaveFolderStr + BackupName, true);
    }
    catch(...)
    {
        throw;
    }
}

void MASPersistentManager::RenameBackup(wxString OldName, wxString NewName)
{
    try
    {
        wxRenameFile(m_SaveFolderStr + OldName, m_SaveFolderStr + NewName, false);
    }
    catch(...)
    {
        throw;
    }
}

void MASPersistentManager::RestoreBackup(wxString BackupName)
{
    try
    {
        wxCopyFile(m_SaveFolderStr + BackupName, m_SaveFolderStr + "persistent", true);
    }
    catch(...)
    {
        throw;
    }
}

void MASPersistentManager::DeleteBackup(wxString BackupName)
{
    try
    {
        wxRemoveFile(m_SaveFolderStr + BackupName);
    }
    catch(...)
    {
        throw;
    }
}

void MASPersistentManager::OpenFileManager()
{
#ifdef __WIN32__
    wxExecute("explorer.exe " + m_SaveFolderStr, wxEXEC_ASYNC); // There's no way of getting the default file manager on Windows, so we assume explorer.exe by default
#elif defined __linux__
    wxExecute("xdg-open " + wxStandardPaths::Get().GetUserConfigDir() + "/.renpy/Monika\\ After\\ Story/", wxEXEC_ASYNC); // xdg-open is the best way of opening the default file manager on Linux.
#elif defined __APPLE__
    wxExecute("open " + m_SaveFolderStr, wxEXEC_ASYNC); // open is the macOS way of opening the Finder. NEEDS TESTING!
#endif
}
