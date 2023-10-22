#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDate>
#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QString>
#include <QVector>
#include <QtWidgets>
#include <iomanip>
#include <limits>
#include <sstream>

// Including qcustomplot as a library
#include <qcustomplot.h>

#include "./ui_mainwindow.h"

typedef struct g_struct {
  const char *func;
  int x_Min;
  int x_Max;
  int y_Min;
  int y_Max;
} s_graph;

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow {
  Q_OBJECT

 public:
  explicit Calculator(QWidget *parent = nullptr);
  ~Calculator();

 private slots:
  void Connect_Buttons();

  void Calculate_Result();

  void Calc_Pressed();

  void Graph_Pressed();

  void Backspace_Pressed();

  void Clean_Pressed();

  void Equal_Pressed();

  bool Is_Operation(QPushButton *button);

  void Symbol_Pressed();

  void Check_Graph();

  int Draw_Graph(s_graph g_val);

 private:
  Ui::Calculator *ui;
};

#endif  // MAINWINDOW_H
