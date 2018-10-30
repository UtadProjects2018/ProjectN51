//
//  FileManager.cpp
//  ProjectN51
//
//  Created by pc-laptop on 10/24/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <stdio.h>
#include "IFileManager.h"
#include "FileUtils.h"

FileSystem::FileObject FileSystem::OpenFile(const char *fileName, FileType fileType)
{
    return fopen(fileName, FileSystemUtils::GetFileNameType(fileType));
}

void FileSystem::CloseFile (FileObject fileID)
{
    fclose(FileSystemUtils::GetFileObject(fileID));
}

unsigned int FileSystem::ReadFile (FileObject fileID, char *pReadCharacterBuffer, unsigned int uNumOfCharacters)
{
    return static_cast<unsigned int>(fread(pReadCharacterBuffer,
                                           1,
                                           uNumOfCharacters,
                                           FileSystemUtils::GetFileObject(fileID)));
}

unsigned int FileSystem::WriteFile (FileObject fileID, char *pWriteCharacterBuffer, unsigned int uNumOfCharacters)
{
    return static_cast<unsigned int>(fwrite(pWriteCharacterBuffer,
                                            1,
                                            uNumOfCharacters,
                                            FileSystemUtils::GetFileObject(fileID)));
}
