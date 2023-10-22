#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  setenv("LC_NUMERIC", "C", 1);
  QApplication a(argc, argv);
  Calculator w;
  w.show();
  return a.exec();
}
