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

    void OpenFile(std::string path);

    
private:
    File* file_;

};

#endif // MODEL_H