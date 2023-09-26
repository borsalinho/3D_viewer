#ifndef MODEL_H
#define MODEL_H

#include "file/file.h"

#include <iostream>
#include <string>



class Model { // Facade
public:
    Model() {
        file_ = new File();
    }

    ~Model() {
        if (file_) delete  file_;
    }

    bool CheckFile(const std::string path){
        return file_->CheckFile(path);
    }
    
    bool IsValidFile(const std::string path){
        return file_->ValidFile(path);
    }

    void ParserFile(const std::string path){
        file_->ParserFile(path);
    }

    void 
    
private:
    File* file_;
    Painter* painter_;
};

#endif // MODEL_H
