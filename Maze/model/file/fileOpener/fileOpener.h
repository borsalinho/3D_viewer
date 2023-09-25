#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <fstream>
#include <iostream>

class FileOpener {
public:
    void OpenFile(std::string path){
        std::string line;
        std::ifstream in(path); // окрываем файл для чтения
        if (in.is_open())
        {
            while (std::getline(in, line))
            {
                std::cout << line << std::endl;
            }
        } else {
            std::cout << "file not found" << std::endl;
        }
        in.close();  
    }

    void OpenFile2(File file){
        std::string line;
        std::ifstream in(file.); // окрываем файл для чтения
        if (in.is_open())
        {
            while (std::getline(in, line))
            {
                std::cout << line << std::endl;
            }
        } else {
            std::cout << "file not found" << std::endl;
        }
        in.close();  
    }
};

#endif // FILE_OPENER_H