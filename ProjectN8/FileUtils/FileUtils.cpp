//
//  FileUtils.cpp
//  ProjectN6
//
//  Created by pc-laptop on 10/29/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "FileUtils.h"

const char *FileSystemUtils::GetFileNameType(int fileType)
{
    switch (fileType)
    {
        case FileSystem::FileTypeWrite:
            return "w";
            break;
            
        case FileSystem::FileTypeRead:
            return "r";
            break;
    }
    return "";
}

FILE *FileSystemUtils::GetFileObject(void *fileID)
{
    return static_cast<FILE *>(fileID);
}

void FileSystemUtils::FileOperationRead(const char fileName [], char *pBufferToRead, int bufferSize)
{
    FileSystem::FileObject fileID = FileSystem::OpenFile(fileName, FileSystem::FileTypeRead);
    
    if (fileID == nullptr)
    {
        printf("File is null\n");
        throw FileSystemUtils::FileSystemExceptionOpenFile;
        return;
    }
    
    int maxBuffer = bufferSize == 0 ? MaxBufferCharacter : bufferSize;
    
    unsigned int rFile = FileSystem::ReadFile(fileID, pBufferToRead, maxBuffer);
    if (rFile > 0)
    {
        printf("File was read success!\n");
        printf("Read: %s\n", pBufferToRead);
        
    }
    else
    {
        printf("There was an error trying to read the file");
        throw FileSystemUtils::FileSystemExceptionReadFile;
    }
    FileSystemUtils::FileOperationClose(fileID);
}

void FileSystemUtils::FileOperationWrite(const char fileName [], int maxCharacterToWrite, char *pBufferToWrite)
{
    FileSystem::FileObject fileID = FileSystem::OpenFile(fileName, FileSystem::FileTypeWrite);
    
    if (fileID == nullptr)
    {
        printf("File is null\n");
        throw FileSystemUtils::FileSystemExceptionOpenFile;
        return;
    }
    
    unsigned int wFile = FileSystem::WriteFile(fileID, pBufferToWrite, maxCharacterToWrite);
    if (wFile > 0)
    {
        printf("File was write success!\n");
        printf("Write : \n");
        printf("%s\n", pBufferToWrite);
    }
    else
    {
        printf("There was an error trying to write the file");
        throw FileSystemUtils::FileSystemExceptionWriteFile;
    }
    
    FileSystemUtils::FileOperationClose(fileID);
}

void FileSystemUtils::FileOperationClose(FileSystem::FileObject fileID)
{
    FileSystem::CloseFile(fileID);
}

FileSystem::FileObject FileSystemUtils::FileOperationOpen(const char fileName[], FileSystem::FileType fileType)
{
    return FileSystem::OpenFile(fileName, fileType);
}

