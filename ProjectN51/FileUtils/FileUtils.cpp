//
//  FileUtils.cpp
//  ProjectN51
//
//  Created by pc-laptop on 10/29/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "FileUtils.h"
#include "IFileManager.h"

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

