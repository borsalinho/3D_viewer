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
    QString str = QFileDialog::getOpenFileName(this,
                                               "Выберите файл",
                                               QDir::homePath() + "/Downloads",
                                               "All Files (*)");
    ui_->file_name->setText(str);

    c_->OpenFile(str.toStdString());

}

