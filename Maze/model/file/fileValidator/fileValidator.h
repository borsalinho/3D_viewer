#ifndef FILE_VALIDATOR_H
#define FILE_VALIDATOR_H

#include <fstream>
#include <iostream>

class FileValidator {
public:
    bool ValidationFile(const std::string& path){
        std::string line;
        std::ifstream in(path); // окрываем файл для чтения
        if (in.is_open())
        {
            while (std::getline(in, line))
            {
                std::cout << line << std::endl;
            }
        } 
        in.close();  
        return true;
    }
};

#endif // FILE_VALIDATOR_H