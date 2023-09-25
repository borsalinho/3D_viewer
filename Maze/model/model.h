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
    void OpenFile2(File file);
    // bool IsValidFile(File file);
private:
    File* file_;
    // Validation* validation_;
};

#endif // MODEL_H