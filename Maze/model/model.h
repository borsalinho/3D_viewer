#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

class Model {
public:
    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;

    static Model* Instance() {
        if (!instance_) {
            instance_ = new Model();
        }
        return instance_;
    }
    void CheckModel() { std::cout << "Model has been created" << std::endl; }
private:
    Model() { std::cout << "Model" << std::endl; }
    static Model* instance_;

};

#endif // MODEL_H