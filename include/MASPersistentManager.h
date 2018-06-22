#ifndef MASPERSISTENTMANAGER_H
#define MASPERSISTENTMANAGER_H

#include <wx/stdpaths.h>
#include <wx/utils.h>
#include <wx/dir.h>
#include <wx/filefn.h>
#include <wx/arrstr.h>
#include <wx/wfstream.h>
#include <wx/zipstrm.h>

class MASPersistentManager
{
    public:
        MASPersistentManager();
        ~MASPersistentManager();
        bool IsFolderOpen();
        wxArrayString GetPersistentList();
        void BackupMainPersistent(wxString BackupName);
        void RenameBackup(wxString OldName, wxString NewName);
        void RestoreBackup(wxString BackupName);
        void DeleteBackup(wxString BackupName);
        void OpenFileManager();
        void CreateBackupZip(wxString FilePath);

    protected:

    private:
        wxString m_SaveFolderStr; // wxDir has no way of getting the folder's full path, so it'll be stored here.
        wxDir m_SaveFolder;
        bool m_IsFolderOpen;
};

#endif // MASPERSISTENTMANAGER_H
