#ifndef FILE_H
#define FILE_H

#include "fileOpener/fileOpener.h"
#include "fileValidator/fileValidator.h"

class File{
public:
    File(){
        f_validator_ = new FileValidator();
        f_opener_ = new FileOpener();
    }
    ~File() {
        if (f_validator_) delete f_validator_;
        if (f_opener_) delete f_opener_;
    }
    void OpenFile(std::string path){
        f_opener_->OpenFile(path);
    }
    void OpenFile2(File file){
        f_opener_->OpenFile2(file);
    }
    bool ValidFile(std::string path){
        f_validator_->ValidationFile(path);
    }
    
private:
    FileValidator* f_validator_;
    FileOpener* f_opener_;
    std::string path_;
};

#endif // FILE_H