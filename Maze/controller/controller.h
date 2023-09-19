#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

#include <iostream>
#include <string>

class Controller {
public:
    Controller(const Controller&) = delete;
    Controller& operator=(const Controller&) = delete;

    static Controller* Instance() {
        if (!instance_) {
            instance_ = new Controller();
        }
        return instance_;
    }
    void CheckController() { std::cout << "Controller has been created" << std::endl; }
private:
    Controller() { std::cout << "Controller" << std::endl; }
    static Controller* instance_;

};

#endif // CONTROLLER_H