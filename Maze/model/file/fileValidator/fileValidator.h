#ifndef FILE_VALIDATOR_H
#define FILE_VALIDATOR_H


#include "../file.h"

class FileValidator : File {
public:
    bool ValidationFile(File file){
        
        std::string line;
        file.in_.open(file.path_);
        while (std::getline(in, line))
        {
            for (char c : line){
                if (с != '1' && c != '0' && c != ' '){
                    in.close();  
                    return false;
                }
            }
            
        }
        return true;
    }
};

#endif // FILE_VALIDATOR_H