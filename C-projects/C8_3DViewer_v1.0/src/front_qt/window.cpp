#include "window.h"

#include "./ui_window.h"

Window::Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window) {
  ui->setupUi(this);
  QString setFile = QDir::homePath() + "/Desktop/settings.conf";
  fileNameStd = setFile.toStdString();
  connectButtons();
}

void Window::connectButtons() {
  connect(ui->openWidget, SIGNAL(valueChange()), this, SLOT(changeRSpinBox()));
  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));

  connect(ui->xDial, SIGNAL(actionTriggered(int)), this,
          SLOT(xDialSliderMoved()));
  connect(ui->yDial, SIGNAL(actionTriggered(int)), this,
          SLOT(yDialSliderMoved()));
  connect(ui->zDial, SIGNAL(actionTriggered(int)), this,
          SLOT(zDialSliderMoved()));

  connect(ui->xRSpinBox, SIGNAL(valueChanged(int)), this,
          SLOT(xRSpinBoxValueChanged()));
  connect(ui->yRSpinBox, SIGNAL(valueChanged(int)), this,
          SLOT(yRSpinBoxValueChanged()));
  connect(ui->zRSpinBox, SIGNAL(valueChanged(int)), this,
          SLOT(zRSpinBoxValueChanged()));

  connect(ui->BackgroundColor, SIGNAL(released()), this,
          SLOT(BackgroundColorReleased()));
  connect(ui->EdgesColor, SIGNAL(released()), this, SLOT(EdgesColorReleased()));
  connect(ui->VerticesColor, SIGNAL(released()), this,
          SLOT(VerticesColorReleased()));

  connect(ui->EdgesThickness, SIGNAL(valueChanged(double)), this,
          SLOT(EdgesThicknessValueChanged()));
  connect(ui->EdgesType, SIGNAL(currentIndexChanged(int)), this,
          SLOT(EdgesTypeIndexChanged()));
  connect(ui->VerticesType, SIGNAL(currentIndexChanged(int)), this,
          SLOT(VerticesTypeIndexChanged()));
  connect(ui->VerticesSize, SIGNAL(valueChanged(double)), this,
          SLOT(VerticesSizeValueChanged()));

  connect(ui->xSpinBox, SIGNAL(valueChanged(double)), this,
          SLOT(xSpinBoxValueChanged()));
  connect(ui->ySpinBox, SIGNAL(valueChanged(double)), this,
          SLOT(ySpinBoxValueChanged()));
  connect(ui->zSpinBox, SIGNAL(valueChanged(double)), this,
          SLOT(zSpinBoxValueChanged()));

  connect(ui->SizeSlider, SIGNAL(actionTriggered(int)), this,
          SLOT(SizeSliderActionTriggered()));
  connect(ui->SizeSpinBox, SIGNAL(valueChanged(int)), this,
          SLOT(SizeSpinBoxValueChanged()));
  connect(ui->ProjectionType, SIGNAL(currentIndexChanged(int)), this,
          SLOT(ProjectionTypeIndexChanged()));

  connect(ui->ScreenshotButton, SIGNAL(clicked()), this,
          SLOT(ScreenshotClicked()));
  connect(ui->GIFButton, SIGNAL(clicked()), this, SLOT(GIFButtonClicked()));
  connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
  connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadButtonClicked()));
  connect(ui->defaultButton, SIGNAL(clicked()), this,
          SLOT(setDefaultSettings()));
}

void Window::pushButtonClicked() {
  QString fileName = QFileDialog::getOpenFileName(
      this, "Choose File", QDir::homePath() + "/Desktop/", tr("*.obj"));
  // Helps on MacOS if you get "+[CATransaction synchronize] called within
  // transaction" error QString fileName = QFileDialog::getOpenFileName(this,
  // "Choose File", QDir::homePath() + "/Desktop/", tr("*.obj"), 0,
  // QFileDialog::DontUseNativeDialog);
  if (!fileName.isEmpty()) {
    setDefaultSettings();
    loadFromFile(fileName);
  }
}

void Window::loadFromFile(QString fileName) {
  std::string input_line = fileName.toStdString();
  const char *input_str = input_line.c_str();
  if (ui->openWidget->shape) clearShape(ui->openWidget->shape);
  if (!initShape(ui->openWidget->shape, const_cast<char *>(input_str))) return;
  ui->openWidget->update();

  ui->FileName->setText(fileName);
  ui->VerticesNumber->setText(
      QString::number(ui->openWidget->shape->countVertexes / 3));
  ui->EdgesNumber->setText(
      QString::number(ui->openWidget->shape->countLines / 2));
}

void Window::saveButtonClicked() {
  ui->openWidget->settings.xCurrentRot = ui->openWidget->xRot;
  ui->openWidget->settings.yCurrentRot = ui->openWidget->yRot;
  ui->openWidget->settings.zCurrentRot = ui->openWidget->zRot;
  FILE *settingFile = fopen(fileNameStd.c_str(), "wb");
  if (settingFile) {
    fwrite(&ui->openWidget->settings, sizeof(OpenGL::SettingsGL), 1,
           settingFile);
    fclose(settingFile);
  } else
    QMessageBox::information(this, "Error", "Cannot open settings file!");
}

void Window::loadButtonClicked() {
  FILE *settingFile = fopen(fileNameStd.c_str(), "rb");
  if (settingFile) {
    fread(&ui->openWidget->settings, sizeof(OpenGL::SettingsGL), 1,
          settingFile);
    fclose(settingFile);
    setSettings();
  } else
    QMessageBox::information(this, "Error", "No settings file!");
}

void Window::setSettings() {
  ui->xSpinBox->setValue(ui->openWidget->settings.xCoord);
  ui->ySpinBox->setValue(ui->openWidget->settings.yCoord);
  ui->zSpinBox->setValue(ui->openWidget->settings.zCoord);

  ui->xRSpinBox->setValue(ui->openWidget->settings.xCurrentRot);
  ui->yRSpinBox->setValue(ui->openWidget->settings.yCurrentRot);
  ui->zRSpinBox->setValue(ui->openWidget->settings.zCurrentRot);

  ui->SizeSpinBox->setValue(ui->openWidget->settings.size);
  ui->ProjectionType->setCurrentIndex(ui->openWidget->settings.projectionType);
  ui->VerticesType->setCurrentIndex(ui->openWidget->settings.verticesType);
  ui->VerticesSize->setValue(ui->openWidget->settings.verticesSize);
  ui->EdgesType->setCurrentIndex(ui->openWidget->settings.edgesType);
  ui->EdgesThickness->setValue(ui->openWidget->settings.thickness);
  ui->openWidget->update();
}

void Window::ScreenshotClicked() {
  QString fileName = QDir::homePath() + "/Desktop/3D_Viewer_";
  QTime date = QTime::currentTime();
  fileName.append(date.toString("hh_mm_ss"));
  fileName.append(ui->fileType->currentText());
  QImage img = ui->openWidget->grabFramebuffer();
  img.save(fileName);
}

void Window::GIFButtonClicked() {
  QString fileName = QDir::homePath() + "/Desktop/3D_Viewer_";
  QTime date = QTime::currentTime();
  fileName.append(date.toString("hh_mm_ss"));
  fileName.append(".gif");
  file = new QFile(fileName);
  if (file->open(QIODevice::WriteOnly)) {
    int width = ui->openWidget->width() * 2;
    int height = ui->openWidget->height() * 2;
    gif = new QGifImage(QSize(width, height));
    gif->setDefaultDelay(100);
    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(newGifImage()));
    timer->start(100);
    frames = 0;
  } else
    QMessageBox::information(
        this, "Error", "File " + fileName + " can not be opened to write");
}

void Window::newGifImage() {
  QImage img = ui->openWidget->grabFramebuffer();
  gif->addFrame(img);
  frames++;
  if (frames == 50) {
    gif->save(file);
    file->close();
    delete file;
    delete gif;
    timer->stop();
  }
}

void Window::setDefaultSettings() {
  ui->xSpinBox->setValue(0.);
  ui->ySpinBox->setValue(0.);
  ui->zSpinBox->setValue(0.);

  ui->SizeSpinBox->setValue(10);
  ui->SizeSlider->setValue(10);

  ui->xRSpinBox->setValue(0);
  ui->yRSpinBox->setValue(0);
  ui->zRSpinBox->setValue(0);

  ui->ProjectionType->setCurrentIndex(0);
  ui->EdgesType->setCurrentIndex(0);
  ui->EdgesThickness->setValue(1);

  ui->VerticesType->setCurrentIndex(0);
  ui->VerticesSize->setValue(5.);

  ui->openWidget->settings.backgroundColor = QColorConstants::Black;
  ui->openWidget->settings.edgesColor = QColorConstants::White;
  ui->openWidget->settings.verticesColor = QColorConstants::White;
}

void Window::changeRSpinBox() {
  ui->xRSpinBox->setValue(ui->openWidget->xRot);
  ui->yRSpinBox->setValue(ui->openWidget->yRot);
  ui->zRSpinBox->setValue(ui->openWidget->zRot);
}

void Window::xDialSliderMoved() { ui->xRSpinBox->setValue(ui->xDial->value()); }

void Window::yDialSliderMoved() { ui->yRSpinBox->setValue(ui->yDial->value()); }

void Window::zDialSliderMoved() { ui->zRSpinBox->setValue(ui->zDial->value()); }

void Window::xRSpinBoxValueChanged() {
  int position = ui->xRSpinBox->value();
  if ((int)position - ui->openWidget->xRot != 0) {
    double dAngles[3] = {position - ui->openWidget->xRot, 0, 0};
    ui->openWidget->xRot = position;
    rotation(ui->openWidget->shape, dAngles);
    ui->openWidget->update();
  }
  ui->xDial->setValue(position);
}

void Window::yRSpinBoxValueChanged() {
  int position = ui->yRSpinBox->value();
  if ((int)position - ui->openWidget->xRot != 0) {
    double dAngles[3] = {0, position - ui->openWidget->yRot, 0};
    ui->openWidget->yRot = position;
    rotation(ui->openWidget->shape, dAngles);
    ui->openWidget->update();
  }
  ui->yDial->setValue(position);
}

void Window::zRSpinBoxValueChanged() {
  int position = ui->zRSpinBox->value();
  if ((int)position - ui->openWidget->xRot != 0) {
    double dAngles[3] = {0, 0, position - ui->openWidget->zRot};
    ui->openWidget->zRot = position;
    rotation(ui->openWidget->shape, dAngles);
    ui->openWidget->update();
  }
  ui->zDial->setValue(position);
}

void Window::BackgroundColorReleased() {
  ui->openWidget->settings.backgroundColor =
      QColorDialog::getColor(Qt::white, this, "Choose color");
  ui->openWidget->update();
}

void Window::EdgesColorReleased() {
  ui->openWidget->settings.edgesColor =
      QColorDialog::getColor(Qt::white, this, "Choose color");
  ui->openWidget->update();
}

void Window::EdgesThicknessValueChanged() {
  ui->openWidget->settings.thickness = ui->EdgesThickness->value();
  ui->openWidget->update();
}

void Window::EdgesTypeIndexChanged() {
  ui->openWidget->settings.edgesType = ui->EdgesType->currentIndex();
  ui->openWidget->update();
}

void Window::VerticesTypeIndexChanged() {
  ui->openWidget->settings.verticesType = ui->VerticesType->currentIndex();
  ui->openWidget->update();
}

void Window::VerticesColorReleased() {
  ui->openWidget->settings.verticesColor =
      QColorDialog::getColor(Qt::white, this, "Choose color");
  if (ui->openWidget->settings.verticesType > 0) ui->openWidget->update();
}

void Window::VerticesSizeValueChanged() {
  ui->openWidget->settings.verticesSize = ui->VerticesSize->value();
  ui->openWidget->update();
}

void Window::xSpinBoxValueChanged() {
  double xCoord = ui->xSpinBox->value();
  ui->openWidget->settings.xCoord = xCoord;
  shifting(ui->openWidget->shape, xCoord, AXIS_X);
  ui->openWidget->update();
}

void Window::ySpinBoxValueChanged() {
  double yCoord = ui->ySpinBox->value();
  ui->openWidget->settings.yCoord = yCoord;
  shifting(ui->openWidget->shape, yCoord, AXIS_Y);
  ui->openWidget->update();
}

void Window::zSpinBoxValueChanged() {
  double zCoord = ui->zSpinBox->value();
  ui->openWidget->settings.zCoord = zCoord;
  shifting(ui->openWidget->shape, zCoord, AXIS_Z);
  ui->openWidget->update();
}

void Window::SizeSliderActionTriggered() {
  ui->SizeSpinBox->setValue(ui->SizeSlider->value());
}

void Window::SizeSpinBoxValueChanged() {
  int size = ui->SizeSpinBox->value();
  ui->openWidget->settings.size = size;
  ui->SizeSlider->setValue(size);
  setScale(ui->openWidget->shape, size / 10.);
  ui->openWidget->update();
}

void Window::ProjectionTypeIndexChanged() {
  ui->openWidget->settings.projectionType = ui->ProjectionType->currentIndex();
  ui->openWidget->update();
}

Window::~Window() { delete ui; }
