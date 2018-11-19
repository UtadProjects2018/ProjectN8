//
//  IFileManager.h
//  ProjectN6
//
//  Created by pc-laptop on 10/24/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#pragma once

namespace FileSystem
{
    typedef void *FileObject;
    
    enum FileType
    {
        FileTypeRead,
        FileTypeWrite,
    };
    
    FileObject OpenFile (const char *fileName, FileType fileType);
    void CloseFile (FileObject fileID);
    unsigned int ReadFile (FileObject fileID, char *pReadCharacterBuffer, unsigned int uNumOfCharacters);
    unsigned int WriteFile (FileObject fileID,char *pWriteCharacterBuffer, unsigned int uNumOfCharacters);
}
