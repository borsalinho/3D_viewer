#ifndef MODEL_FILE_VALIDATOR_H
#define MODEL_FILE_VALIDATOR_H

#include <iostream>
#include <string>

#include "../file/file.h"


class FileValidator {
public:
    FileValidator(){};

    bool IsValid(File* file){
        std::string line;
        
        while(std::getline(*file->GetFile(),line)){
            for (char ch : line){
                if(!isdigit(ch) && ch != ' '){
                    return false;
                }
            }
        }
        
        return true;
    }

private:
    bool CheckSimbol(char ch){
        if (isdigit(ch) || ch == ' ') return true;
        return false;
    }
    
};



#endif // MODEL_FILE_VALIDATOR_H