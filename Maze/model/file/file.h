#ifndef MODEL_FILE_H
#define MODEL_FILE_H

#include <iostream>
#include <fstream>
#include <vector>


class File {
public:
    File(const std::string& path) : path_(path){};

private:
    const std::string path_;
    bool is_valid_;
    std::vector<std::vector<unsigned int>>* data_;
};



#endif // MODEL_FILE_H