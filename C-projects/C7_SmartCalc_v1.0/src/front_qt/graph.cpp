#include "mainwindow.h"

extern "C" {
#include "../back/calculation.h"
}

void Calculator::Graph_Pressed() {
  ui->stackedWidget->setCurrentIndex(1);

  ui->graph_line->setFocus();
  ui->graph_img->addGraph();

  ui->graph_img->xAxis->setLabel("X");
  ui->graph_img->yAxis->setLabel("Y");

  ui->graph_img->xAxis->setRange(-10, 10);
  ui->graph_img->yAxis->setRange(-5, 5);

  ui->graph_img->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                                 QCP::iSelectPlottablesBeyondAxisRect);
  Check_Graph();
}

void Calculator::Check_Graph() {
  int error = 0;
  QString graph_str = ui->graph_line->text();
  std::string x_line = graph_str.toUtf8().constData();

  ui->graph_img->clearGraphs();
  ui->graph_img->addGraph();

  s_graph g_val;
  g_val.func = x_line.c_str();
  g_val.x_Min = ui->xMin->value();
  g_val.x_Max = ui->xMax->value();
  g_val.y_Min = ui->yMin->value();
  g_val.y_Max = ui->yMax->value();

  if (g_val.x_Min >= g_val.x_Max || g_val.y_Min >= g_val.y_Max) {
    error = 1;
  } else {
    ui->graph_img->xAxis->setRange(g_val.x_Min, g_val.x_Max);
    ui->graph_img->yAxis->setRange(g_val.y_Min, g_val.y_Max);

    error = Draw_Graph(g_val);
  }
  if (error) {
    ui->graph_line->setText("ERROR");
  }
  ui->graph_img->replot();
  ui->graph_img->update();
}

int Calculator::Draw_Graph(s_graph g_val) {
  int error = 0;

  double h = 0.01, last = 0;

  QVector<double> x, y;

  double i = g_val.x_Min;
  while (i < g_val.x_Max) {
    long double y_res = 0;
    calculation(const_cast<char*>(g_val.func), i, &y_res);
    if (error) break;
    if (qFabs(qFabs(y_res) - qFabs(last)) < 10) {
      if (y_res >= (g_val.y_Min - qFabs(g_val.y_Min)) &&
          y_res <= (g_val.y_Max + qFabs(g_val.y_Max))) {
        x.push_back(i);
        y.push_back(y_res);
      }
    } else {
      x.push_back(i);
      y.push_back(NAN);
    }
    last = y_res;
    i += h;
  }
  if (!error) {
    ui->graph_img->graph(0)->addData(x, y);
    ui->graph_img->addGraph();
  }
  return error;
}
