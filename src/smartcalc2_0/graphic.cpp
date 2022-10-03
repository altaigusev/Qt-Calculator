#include "graphic.h"

#include <QMessageBox>

#include "calccontroller.h"
#include "mainwindow.h"
#include "ui_graphic.h"

Graphic::Graphic(QWidget *parent)
    : QDialog(parent),
      g_ui(new Ui::Graphic),
      x_max(10),
      x_min(-10),
      y_max(5),
      y_min(-5),
      ppg(600) {
  g_ui->setupUi(this);
  chart = new QChart();
  chart->setBackgroundBrush(QBrush(QColor("salmon")));
  axisX = new QValueAxis;
  axisX->setRange(-10, 10);
  axisY = new QValueAxis;
  chart->addAxis(axisX, Qt::AlignBottom);
  series = new QScatterSeries();
  axisY->setRange(-5, 5);
  chart->addAxis(axisY, Qt::AlignLeft);
  chart->legend()->hide();
  chart->addSeries(series);
  series->attachAxis(axisX);
  series->attachAxis(axisY);
  series->setMarkerSize(g_ui->horizontalSlider->value() / 6.0);
  chart->setTitle("Graphic");
  g_ui->graphicsView->setChart(chart);
  g_ui->xmax_edit->setValidator(new QDoubleValidator(-100, 100, 2, this));
  g_ui->xmin_edit->setValidator(new QDoubleValidator(-100, 100, 2, this));
  g_ui->ymax_edit->setValidator(new QDoubleValidator(-100, 100, 2, this));
  g_ui->ymin_edit->setValidator(new QDoubleValidator(-100, 100, 2, this));
}

Graphic::~Graphic() {
  delete chart;
  delete g_ui;
}

void Graphic::on_autoButton_clicked() {
  g_ui->xmax_edit->setText("10.0");
  g_ui->xmin_edit->setText("-10.0");
  g_ui->ymax_edit->setText("5.0");
  g_ui->ymin_edit->setText("-5.0");
}

void Graphic::on_rebuildButton_clicked() {
  series->clear();
  series->setMarkerSize(g_ui->horizontalSlider->value() / 6.0);
  ppg = g_ui->ppg_slider->value();
  x_max = g_ui->xmax_edit->text().toDouble();
  setLimits(&x_max);
  x_min = g_ui->xmin_edit->text().toDouble();
  setLimits(&x_min);
  if (x_max == x_min) x_min = x_max - 1;
  y_max = g_ui->ymax_edit->text().toDouble();
  setLimits(&y_max);
  y_min = g_ui->ymin_edit->text().toDouble();
  setLimits(&y_min);
  axisX->setRange(x_min, x_max);
  QString str = g_ui->functionEdit->text();
  std::vector<double> points_vector;
  std::pair<double, double> range(x_min, x_max);
  s21::CalcController ctrl;
  try {
    ctrl.graphic_points(str.toStdString(), points_vector, range, ppg);
  } catch (const std::exception &e) {
    for (int i = 0; i < ppg; ++i) points_vector.push_back(0);
  }

  double x_value_of_tick = (x_max - x_min) / ppg;
  for (unsigned int i = 0; i < ppg; i++) {
    series->append(double(x_min + i * x_value_of_tick), points_vector.at(i));
  }
  axisY->setRange(y_min, y_max);
}

void Graphic::on_pushButton_clicked() {
  QPixmap pixmap = g_ui->graphicsView->grab();
  pixmap.toImage().save("../../../../graphics.jpg");
}

void Graphic::function_slot(QString a) { g_ui->functionEdit->setText(a); }

void Graphic::on_horizontalSlider_valueChanged(int value) {
  series->setMarkerSize(double(value) / 6.0);
}

void Graphic::setLimits(double *lim) {
  if (*lim > 1000000) *lim = 1000000;
  if (*lim < -1000000) *lim = -1000000;
}
