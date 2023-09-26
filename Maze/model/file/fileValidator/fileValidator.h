#ifndef FILE_VALIDATOR_H
#define FILE_VALIDATOR_H

#include <fstream>
#include <iostream>

class FileValidator {
public:
    bool ValidationFile(const std::string& path){
        std::string line;
        std::ifstream in; // окрываем файл для чтения
        in.open(path);
        while (std::getline(in, line))
        {
            for (char c : line){
                if (!isdigit(c) && c != ' '){
                    in.close();  
                    return false;
                }
            }
            
        }
        in.close();  
        return true;
    }
};

#endif // FILE_VALIDATOR_H