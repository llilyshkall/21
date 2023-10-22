#ifndef WINDOW_H
#define WINDOW_H

#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include "gif_lib.h"
#include "opengl.h"
#include "qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Window;
}
QT_END_NAMESPACE

class Window : public QMainWindow {
  Q_OBJECT

 public:
  explicit Window(QWidget *parent = nullptr);
  ~Window();

 private slots:
  void pushButtonClicked();
  void changeRSpinBox();
  void xDialSliderMoved();
  void yDialSliderMoved();
  void zDialSliderMoved();
  void xRSpinBoxValueChanged();
  void yRSpinBoxValueChanged();
  void zRSpinBoxValueChanged();
  void BackgroundColorReleased();
  void EdgesColorReleased();
  void EdgesThicknessValueChanged();
  void EdgesTypeIndexChanged();
  void VerticesTypeIndexChanged();
  void VerticesColorReleased();
  void VerticesSizeValueChanged();
  void xSpinBoxValueChanged();
  void ySpinBoxValueChanged();
  void zSpinBoxValueChanged();
  void SizeSliderActionTriggered();
  void SizeSpinBoxValueChanged();
  void ProjectionTypeIndexChanged();
  void ScreenshotClicked();
  void GIFButtonClicked();
  void newGifImage();
  void saveButtonClicked();
  void loadButtonClicked();
  void setDefaultSettings();

 private:
  Ui::Window *ui;
  QFile *file;
  QGifImage *gif;
  QTimer *timer;
  int frames;
  std::string fileNameStd;
  void loadFromFile(QString fileName);
  void connectButtons();
  void setSettings();
};
#endif  // WINDOW_H
