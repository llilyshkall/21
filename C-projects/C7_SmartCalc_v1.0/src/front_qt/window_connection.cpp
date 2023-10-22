#include "mainwindow.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);

  Connect_Buttons();
}

void Calculator::Connect_Buttons() {
  connect(ui->calc, SIGNAL(released()), this, SLOT(Calc_Pressed()));
  connect(ui->graph, SIGNAL(released()), this, SLOT(Graph_Pressed()));

  QPushButton *numButtons[10];
  for (int i = 0; i < 10; i++) {
    QString butName = "num" + QString::number(i);
    numButtons[i] = Calculator::findChild<QPushButton *>(butName);
    connect(numButtons[i], SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  }

  connect(ui->add, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->sub, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->mul, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->div, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->dot, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->op_br, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->cl_br, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->pi, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->sqrt, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->pow, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->mod, SIGNAL(released()), this, SLOT(Symbol_Pressed()));

  connect(ui->sin, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->asin, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->cos, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->acos, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->tan, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->atan, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->ln, SIGNAL(released()), this, SLOT(Symbol_Pressed()));
  connect(ui->log, SIGNAL(released()), this, SLOT(Symbol_Pressed()));

  connect(ui->clear, SIGNAL(released()), this, SLOT(Clean_Pressed()));
  connect(ui->backspace, SIGNAL(released()), this, SLOT(Backspace_Pressed()));

  connect(ui->equal, SIGNAL(released()), this, SLOT(Equal_Pressed()));

  connect(ui->reload, SIGNAL(released()), this, SLOT(Check_Graph()));
}

Calculator::~Calculator() { delete ui; }
