#include "model.h"

void Model::OpenFile(std::string path) {
    file_->OpenFile(path);
}

void Model::OpenFile2(File file) {
    file_->OpenFile2(file);
}