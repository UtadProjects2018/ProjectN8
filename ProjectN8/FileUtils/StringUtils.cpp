//
//  StringUtils.cpp
//  ProjectN6
//
//  Created by pc-laptop on 11/18/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "StringUtils.h"
#include "FileUtils.h"

#include <iostream>

int FileSystemStringUtils::GetNumberRepeatString(const char fileName[], const char searchChar[])
{
    int numberOfCharacterFound = 0;
    
    int length = FileSystemStringUtils::CharacterLength(fileName);
    char *pCharacter = new char[length];
    
    FileSystemUtils::FileOperationRead(fileName, pCharacter, length);

    if (pCharacter != nullptr)
    {
        const char *pFound = strstr(pCharacter, searchChar);
        while (pFound)
        {
            numberOfCharacterFound++;
            pFound++;
            pFound = strstr(pFound, searchChar);
        }
    }
    
    delete [] pCharacter;
    
    return numberOfCharacterFound;
}

int FileSystemStringUtils::CharacterLength(const char fileName[])
{
    int length = 0;
    FileSystem::FileObject fileID = FileSystem::OpenFile(fileName, FileSystem::FileTypeRead);
    char character = '\0';
    while (character != EOF)
    {
        character = (char)fgetc(FileSystemUtils::GetFileObject(fileID));
        length++;
    }
    FileSystem::CloseFile(fileID);
    return length;
}

int FileSystemStringUtils::SumNumberFromFile(const char fileName[])
{
    int result = 0;
    int length = FileSystemStringUtils::CharacterLength(fileName);
    char *pCharacter = new char[length + 1];
    
    FileSystemUtils::FileOperationRead(fileName, pCharacter, length);
    
    pCharacter[length + 1] = '\0';
    
    const char *pIni = pCharacter;
    char *pFound = strstr(pCharacter, ",");
    while (pFound)
    {
        *pFound = '\0';
        result += atoi(pIni);
        pFound++;
        pIni = pFound;
        pFound = strstr(pFound, ",");
    }
    
    //Sum the last character
    result += atoi(pIni);
    
    return result;
}
