#ifndef FILE_CHECKER_H
#define FILE_CHECKER_H

#include <fstream>

class FileChecker {
public:
    bool CheckFile(const std::string path){
        std::ifstream in(path); 
        if (in.is_open())
        {   
            in.close(); 
            return true;
        }
        return false;
    }
};


#endif // FILE_CHECKER_H