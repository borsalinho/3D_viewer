#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>

// #include "fileParser/fileParser.h"
// #include "fileValidator/fileValidator.h"
// #include "fileChecker/fileChecker.h"

class File {
public:
    File(const std::string& path) : path_(path){}
    ~File() {}

private:
    std::string path_;
    std::ifstream in_;
};

#endif // FILE_H