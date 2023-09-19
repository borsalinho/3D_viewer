#include "view/view.h"
// #include "model/model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model *v = Model::Instance();
    v->CheckModel();
    Controller *c = Controller::Instance();
    c->CheckController();
    view w;
    w.show();
    return a.exec();
}
