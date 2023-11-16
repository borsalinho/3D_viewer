#ifndef MODEL_FILE_PARSER_H
#define MODEL_FILE_PARSER_H

#include <iostream>
#include <string>

#include "../file/file.h"


class FileParser {
public:
    FileParser(){};

    File* Parsing(File* file){
        std::string line;
        
        file->GetFile()->clear();
        file->GetFile()->seekg(0, file->GetFile()->beg);

        // std::getline(*file->GetFile(),line);
        // std::cout << "я getline " << line << std::endl;
        while(std::getline(*file->GetFile(),line)){
            std::cout << line << std::endl;
        }
        
        return file;
    };
private:
};



#endif // MODEL_FILE_PARSER_H