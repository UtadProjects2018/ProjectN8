//
//  main.cpp
//  ProjectN6
//
//  Created by pc-laptop on 10/24/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>
#include "FileUtils.h"
#include "StringUtils.h"

const char repeatStringfileName[] = "Resources/txt/repeat_strings.txt";
const char sumStringfileName[] = "Resources/txt/sum_numbers.txt";
const char searchString[] = "priest";

int main(int argc, const char * argv[])
{
    printf("The string: %s, appear %d times \n", searchString, FileSystemStringUtils::GetNumberRepeatString(repeatStringfileName, searchString));
    printf("sum numbers result: %d \n", FileSystemStringUtils::SumNumberFromFile(sumStringfileName));
    return 0;
}
