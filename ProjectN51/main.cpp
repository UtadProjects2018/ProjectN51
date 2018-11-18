//
//  main.cpp
//  ProjectN51
//
//  Created by pc-laptop on 10/24/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>
#include "FileUtils.h"

const char fileName[] = "Resources/txt/file.txt";

int main(int argc, const char * argv[])
{
    char *pBufferToRead = new char[FileSystemUtils::MaxBufferCharacter];
    FileSystem::FileObject fileObjectRead = FileSystemUtils::FileOperationOpen(fileName, FileSystem::FileTypeRead);
    
    FileSystemUtils::FileOperationRead(fileObjectRead, pBufferToRead);
    
    char *pWrite = new char;
    std::cout << pBufferToRead << std::endl;
    
    FileSystem::FileObject fileObjectWrite = FileSystemUtils::FileOperationOpen(fileName, FileSystem::FileTypeWrite);
    std::cout << "Write something ... "<< std::endl;
    std::cin >> pWrite;
    
    unsigned const int uNumberOfCharacter = static_cast<int>(strlen(pWrite));
    
    FileSystemUtils::FileOperationWrite(fileObjectWrite, uNumberOfCharacter, pWrite);
    
    FileSystemUtils::FileOperationRead(fileObjectWrite, pWrite);
    std::cout << pWrite << std::endl;
    
    return 0;
}
