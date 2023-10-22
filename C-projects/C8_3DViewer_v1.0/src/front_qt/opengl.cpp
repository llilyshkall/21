#include "opengl.h"

#define RGB_MIN 1.
#define RGB_MAX 255.

OpenGL::OpenGL(QWidget *parent) : QOpenGLWidget{parent} {
  shape = static_cast<Shape *>(calloc(1, sizeof(Shape)));
  zeroingShape(shape);
  initSettingsGL();
}

void OpenGL::initSettingsGL() {
  xRot = 0, yRot = 0, zRot = 0;
  settings.backgroundColor = QColorConstants::Black;
  settings.edgesColor = QColorConstants::White;
  settings.verticesColor = QColorConstants::White;
  settings.thickness = 1.;
  settings.scale = 1.;
  settings.edgesType = 0;
  settings.verticesType = 0;
  settings.verticesSize = 5.;
  settings.xCoord = 0, settings.yCoord = 0, settings.zCoord = 0;
  settings.xCurrentRot = 0, settings.yCurrentRot = 0, settings.zCurrentRot = 0;
  settings.projectionType = 0;
  settings.size = 10;
}

void OpenGL::initializeGL() {
  initializeOpenGLFunctions();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glEnable(GL_CULL_FACE);
}

void OpenGL::paintGL() {
  float r, g, b, a = normalize(255.0f, RGB_MIN, RGB_MAX);
  qColorToRGB(settings.backgroundColor, r, g, b);
  glClearColor(r, g, b, a);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (settings.projectionType == 0)
    glOrtho(-1, 1, -1, 1, 1, 3);
  else
    glFrustum(-1, 1, -1, 1, 1, 3);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, shape->vertexes);
  if (settings.verticesType != 0) {
    if (settings.verticesType == 1)
      glEnable(GL_POINT_SMOOTH);
    else
      glDisable(GL_POINT_SMOOTH);

    glPointSize(settings.verticesSize);
    qColorToRGB(settings.verticesColor, r, g, b);
    glColor4d(r, g, b, a);
    glDrawArrays(GL_POINTS, 0, shape->countVertexes);
  }

  glLineWidth(settings.thickness);
  if (settings.edgesType == 0) {
    glDisable(GL_LINE_STIPPLE);
    glEnable(GL_LINE_SMOOTH);
  } else {
    glDisable(GL_LINE_SMOOTH);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x1111);
  }
  qColorToRGB(settings.edgesColor, r, g, b);
  glColor4d(r, g, b, a);

  glDrawElements(GL_LINES, shape->countLines, GL_UNSIGNED_INT, shape->lines);
  glFlush();
  glDisableClientState(GL_VERTEX_ARRAY);
}

void OpenGL::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void OpenGL::mouseMoveEvent(QMouseEvent *mo) {
  double dAngles[3];
  dAngles[0] = speed * (mo->pos().y() - mPos.y());
  dAngles[1] = speed * (mo->pos().x() - mPos.x());
  dAngles[2] = 0;
  rotation(shape, dAngles);
  xRot = shape->angles[0];
  yRot = shape->angles[1];
  zRot = shape->angles[2];

  mPos = mo->pos();
  update();
  emit valueChange();
}

void OpenGL::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void OpenGL::qColorToRGB(const QColor &C, float &r, float &g, float &b) const {
  r = normalize(C.red(), RGB_MIN, RGB_MAX);
  g = normalize(C.green(), RGB_MIN, RGB_MAX);
  b = normalize(C.blue(), RGB_MIN, RGB_MAX);
}

float OpenGL::normalize(float val, float min, float max) const {
  return (val - min) / (max - min);
}

OpenGL::~OpenGL() {
  if (shape) {
    clearShape(shape);
  }
}
