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
    
    FileSystemUtils::FileOperationRead(fileName, pBufferToRead);
    
    char *pWrite = new char[FileSystemUtils::MaxBufferCharacter];
    
    std::cout << pBufferToRead << std::endl;
    std::cout << "Write something ... "<< std::endl;
    std::cin >> pWrite;
    
    unsigned const int uNumberOfCharacter = static_cast<int>(strlen(pWrite));
    
    FileSystemUtils::FileOperationWrite(fileName, uNumberOfCharacter, pWrite);
    FileSystemUtils::FileOperationRead(fileName, pWrite);
    
    delete [] pBufferToRead;
    delete [] pWrite;
    
    return 0;
}
