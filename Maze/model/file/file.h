#ifndef MODEL_FILE_H
#define MODEL_FILE_H

#include <iostream>
#include <fstream>
#include <vector>


class File {
public:
    File(const std::string& path) : path_(path){};

    void OpenFile(){
        in_ = new std::ifstream(path_);
    }

    void CloseFile(){
        in_->close();
    }

    std::ifstream* GetFile(){
        return in_;
    }

private:
    const std::string path_;
    bool is_valid_;
    unsigned int cols_;
    unsigned int rows_;
    std::vector<unsigned int>* wall_right_;
    std::vector<unsigned int>* wall_down_;
    std::ifstream* in_;
};



#endif // MODEL_FILE_H