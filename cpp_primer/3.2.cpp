#pragma once

#include "comm2/core/iString.h"
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <vector>

int main(int argc, char *argv[])
{
    std::string line;
    std::vector<std::string> words;
    std::string file_path = "/home/yangchen/data/myCode/dailyCode/cppPrimer/Manifesto.txt";
    std::ifstream file_stream;
    file_stream.open(file_path, std::ios::binary);
    if(file_stream.fail()){
        printf("error\n");
        return -1111;
    }
    
    while(std::getline(file_stream, line)){
        Comm::StrStripWhiteSpace(line);
        Comm::StrStripPunct(line);
        words.emplace_back(line); 
    }

    for(const auto & word : words){
        std::cout << word << std::endl;
    }

    return 0;
}