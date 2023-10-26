#include "view.h"
#include "ui_view.h"

view::view(Controller *c, QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::view)
    , c_(c)
{
    ui_->setupUi(this);
}

view::~view()
{
    delete ui_;
}


void view::on_OpenFIle_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                               "Выберите файл",
                                               QDir::homePath() + "/Downloads",
                                               "All Files (*)");
    
    ui_->file_name->setText(path);

    c_->CreateFile(path.toStdString());

    // if (!c_->CheckFile(str.toStdString())) {
    //     std::cout << "file not found" << std::endl;
    //     return;
    // }
    // if (!c_->ValidFile(str.toStdString())) {
    //     std::cout << "file not valid" << std::endl;
    //     return;
    // }
    
    // c_->ParserFile(str.toStdString());

    // c_->PaintMaze(c_->ParserFile(str.toStdString()));

}

