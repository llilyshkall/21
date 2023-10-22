#ifndef OPENGL_H
#define OPENGL_H

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include <QColor>
#include <QMoveEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

extern "C" {
#include "../back/shape.h"
}

class OpenGL : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT
 public:
  explicit OpenGL(QWidget *parent = nullptr);
  ~OpenGL();

  typedef struct SettingsGL_ {
    QColor backgroundColor;
    QColor edgesColor;
    QColor verticesColor;
    float thickness;
    float scale;
    int edgesType;
    int verticesType;
    float verticesSize;
    double xCoord, yCoord, zCoord;
    double xCurrentRot, yCurrentRot, zCurrentRot;
    int projectionType;
    int size;
  } SettingsGL;

  Shape *shape;
  SettingsGL settings;
  double xRot = 0, yRot = 0, zRot = 0;
  void initSettingsGL();

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

 private:
  void qColorToRGB(const QColor &C, float &r, float &g, float &b) const;
  float normalize(float val, float min, float max) const;

  QPoint mPos;
  double speed = 0.1;
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;

 signals:
  void valueChange();
};

#endif  // OPENGL_H
