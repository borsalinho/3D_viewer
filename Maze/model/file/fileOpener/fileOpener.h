#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <fstream>
#include <iostream>

class FileOpener {
public:
    void OpenFile(const std::string path){
        std::string line;
        std::ifstream in(path); // окрываем файл для чтения
        if (in.is_open())
        {
            while (std::getline(in, line))
            {
                std::cout << line << std::endl;
            }
        }
        in.close();  
    }

};

#endif // FILE_OPENER_H