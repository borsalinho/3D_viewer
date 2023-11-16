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
        std::string num_str;

        std::cout << "Я валидатор" << std::endl;
        std::getline(*file->GetFile(),line);

        if(!line.empty()){
            
        }
        
        for (char ch : line) {
            if (ch != ' '){
                
            }
        }
        
        
        while(std::getline(*file->GetFile(),line)){
            for (char ch : line){
                if (ch != '1' && ch != '0' && ch != ' '){
                    std::cout << "Я провал 2" << std::endl;
                    return false;
                }
            }
        }
        
        return true;
    }

private:
    // bool CheckSimbol(char ch){
    //     if (isdigit(ch) || ch == ' ') return true;
    //     return false;
    // }

    void CheckColRow(std::string line){

    }
    
};



#endif // MODEL_FILE_VALIDATOR_H