#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

#include <iostream>
#include <string>

class Controller {
public:
    Controller(Model* m) :m_(m){};

    bool CheckFile(const std::string path){
        return m_->CheckFile(path);
    }

    bool ValidFile(const std::string path){
        return m_->IsValidFile(path);
    }
    void ParserFile(const std::string path){
        m_->ParserFile(path);
    }
private:
    Model* m_;
};

#endif // CONTROLLER_H
