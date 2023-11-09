#ifndef MODEL_H
#define MODEL_H

#include "file/file.h"
#include "fileValidator/fileValidator.h"
#include "fileParser/fileParser.h"

#include <iostream>
#include <string>



class Model { // Facade для Facade'ов
public:
    Model() {};

    ~Model() {
        if (file_) delete file_;
        // if (file_validator_) delete file_validator_;
    }

    File* FileProcessing(const std::string& path){
        file_ = new File(path);
        FileValidator file_validator;
        FileParser file_parser;

        file_->OpenFile();

        if(file_validator.IsValid(file_)){
            file_parser.Parsing(file_);
        } 
        
        file_->CloseFile();
        
        return file_;
    }



    
    
private:
    File* file_;
    // FileValidator* file_validator_;
};

#endif // MODEL_H
