//
//  main.cpp
//  ProjectN51
//
//  Created by pc-laptop on 10/24/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>
#include "IFileManager.h"

const char fileName[] = "file.txt";

void FileOperationRead(int maxCharacterToRead = 10)
{
    FileSystem::FileObject fileID = FileSystem::OpenFile(fileName, FileSystem::FileTypeRead);
    
    if (fileID == NULL)
    {
        printf("File is null");
        return;
    }
    
    char * pBufferToRead = new char[maxCharacterToRead];
    unsigned int rFile = FileSystem::ReadFile(fileID, pBufferToRead, maxCharacterToRead);
    if (rFile > 0)
    {
        printf("File was read success!\n");
        printf("Read : \n");
        printf("%s", pBufferToRead);
    } else
    {
        printf("There was an error trying to read the file");
    }
    
    delete[] pBufferToRead;
    FileSystem::CloseFile(fileID);
}

void FileOperationWrite(int maxCharacterToWrite, char *pBufferToWrite)
{
    FileSystem::FileObject fileID = FileSystem::OpenFile(fileName, FileSystem::FileTypeRead);
    
    if (fileID == NULL)
    {
        printf("File is null");
        return;
    }
    
    unsigned int wFile = FileSystem::WriteFile(fileID, pBufferToWrite, maxCharacterToWrite);
    if (wFile > 0)
    {
        printf("File was read success!\n");
        printf("Write : \n");
        printf("%s", pBufferToWrite);
    } else
    {
        printf("There was an error trying to write the file");
    }
    
    delete[] pBufferToWrite;
    FileSystem::CloseFile(fileID);
}

int main(int argc, const char * argv[])
{
    FileOperationRead();
    
    char *pWrite = new char;
    std::cin >> pWrite;

    unsigned const int uNumberOfCharacter = static_cast<int>(strlen(pWrite));
    
    FileOperationWrite(uNumberOfCharacter, pWrite);
    
    return 0;
}
