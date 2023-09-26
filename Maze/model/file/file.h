#ifndef FILE_H
#define FILE_H

#include "fileParser/fileParser.h"
#include "fileValidator/fileValidator.h"
#include "fileChecker/fileChecker.h"

class File {
public:
    File(){
        f_validator_ = new FileValidator();
        f_parser_ = new FileParser();
        f_checker_ = new FileChecker();
    }
    ~File() {
        if (f_validator_) delete f_validator_;
        if (f_parser_) delete f_parser_;
        if (f_checker_) delete f_checker_;
    }

    bool CheckFile(const std::string path){
        return f_checker_->CheckFile(path);
    }

    bool ValidFile(const std::string path){
        return f_validator_->ValidationFile(path);
    }

    void ParserFile(const std::string path){
        data_ = f_parser_->ParserFile(path);
    }
    
private:
    FileValidator* f_validator_;
    FileParser* f_parser_;
    FileChecker* f_checker_;
    std::vector<std::string> data_;
};

#endif // FILE_H