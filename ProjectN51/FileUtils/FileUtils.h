//
//  FileUtils.hpp
//  ProjectN51
//
//  Created by pc-laptop on 10/29/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <stdio.h>
#include "IFileManager.h"

namespace FileSystemUtils
{
    const int MaxBufferCharacter = 10;
    
    enum FileSystemException
    {
        FileSystemExceptionOpenFile,
        FileSystemExceptionReadFile,
        FileSystemExceptionWriteFile
    };
    
    const char *GetFileNameType(int fileType);
    FILE *GetFileObject(void *fileID);
    void FileOperationRead(FileSystem::FileObject fileID, char *pBufferToRead);
    void FileOperationWrite(FileSystem::FileObject fileID, int maxCharacterToWrite, char *pBufferToWrite);
    void FileOperationClose(FileSystem::FileObject fileID);
    FileSystem::FileObject FileOperationOpen(const char fileName[], FileSystem::FileType fileType);
}
