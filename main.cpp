#include <QApplication>

#include "view/view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Model m;
  Controller c(&m);
  view w(&c);
  w.show();
  return a.exec();
}
