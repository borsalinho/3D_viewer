#ifndef FILE_H
#define FILE_H

#include "fileOpener/fileOpener.h"
#include "fileValidator/fileValidator.h"
#include "fileChecker/fileChecker.h"

class File {
public:
    File(){
        f_validator_ = new FileValidator();
        f_opener_ = new FileOpener();
    }
    ~File() {
        if (f_validator_) delete f_validator_;
        if (f_opener_) delete f_opener_;
    }

    bool CheckFile(const std::string path){
        return f_checker_->CheckFile(path);
    }

    bool ValidFile(const std::string path){
        return f_validator_->ValidationFile(path);
    }

    void OpenFile(const std::string path){
        f_opener_->OpenFile(path);
    }
    
    
    
private:
    FileValidator* f_validator_;
    FileOpener* f_opener_;
    FileChecker* f_checker_;
    std::vector<std::string>* data_;
};

#endif // FILE_H