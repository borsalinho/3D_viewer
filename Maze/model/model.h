#ifndef MODEL_H
#define MODEL_H

// #include "file/file.h"


#include <iostream>
#include <string>



class Model { // Facade
public:
    Model() {}

    ~Model() {
        // if (file_) delete  file_;
        // if (file_validator_) delete file_validator_;
    }

    // File& CreateFile(const std::string& path){
    //     return file_ = new File(path);
    // }

    
    
private:
    // File* file_;
};

#endif // MODEL_H
