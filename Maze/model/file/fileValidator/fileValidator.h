#ifndef FILE_VALIDATOR_H
#define FILE_VALIDATOR_H

#include <fstream>
#include <iostream>

class FileValidator {
public:
    bool ValidationFile(const std::string& str){
        // for (auto c : str){
        //     if (isdigit(c) && c != ' ') return false;
        // }
        return true;
    }
};

#endif // FILE_VALIDATOR_H