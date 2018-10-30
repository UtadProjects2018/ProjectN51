//
//  FileUtils.hpp
//  ProjectN51
//
//  Created by pc-laptop on 10/29/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <stdio.h>

namespace FileSystemUtils
{
    const char *GetFileNameType(int fileType);
    FILE *GetFileObject(void *fileID);
}
