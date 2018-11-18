//
//  FileUtils.cpp
//  ProjectN51
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

void FileSystemUtils::FileOperationRead(FileSystem::FileObject fileID, char *pBufferToRead)
{
    if (fileID == nullptr)
    {
        printf("File is null\n");
        throw FileSystemUtils::FileSystemExceptionOpenFile;
        return;
    }
    
    unsigned int rFile = FileSystem::ReadFile(fileID, pBufferToRead, MaxBufferCharacter);
    if (rFile > 0)
    {
        printf("File was read success!\n");
        printf("Read %s:", pBufferToRead);
        
    }
    else
    {
        printf("There was an error trying to read the file");
        throw FileSystemUtils::FileSystemExceptionReadFile;
    }
}

void FileSystemUtils::FileOperationWrite(FileSystem::FileObject fileID, int maxCharacterToWrite, char *pBufferToWrite)
{
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
        printf("%s", pBufferToWrite);
    }
    else
    {
        printf("There was an error trying to write the file");
        throw FileSystemUtils::FileSystemExceptionWriteFile;
    }
}

void FileSystemUtils::FileOperationClose(FileSystem::FileObject fileID)
{
    FileSystem::CloseFile(fileID);
}

FileSystem::FileObject FileSystemUtils::FileOperationOpen(const char fileName[], FileSystem::FileType fileType)
{
    return FileSystem::OpenFile(fileName, fileType);
}

