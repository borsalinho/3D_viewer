#include "view.h"
#include "ui_view.h"

view::view(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::view)
{
    ui_->setupUi(this);
}

view::~view()
{
    delete ui_;
}


void view::on_pushButton_clicked()
{
    QString str = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath() + "/Downloads", "All Files (*)");

    ui_->label->setText(str);

    std::string line;

    std::ifstream in(str.toStdString()); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();  

}

