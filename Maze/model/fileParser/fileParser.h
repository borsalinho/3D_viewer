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
        std::cout << "Я парсер" << std::endl;
        if(file->GetFile()->is_open()){
            file->GetFile()->seekg(0, std::ios::beg);

            std::getline(*file->GetFile(),line);
            std::cout << "я getline " << line << std::endl;
            // while(std::getline(*file->GetFile(),line)){
            //     std::cout << line << std::endl;
            // }
        }
        return file;
    };
private:

};



#endif // MODEL_FILE_PARSER_H