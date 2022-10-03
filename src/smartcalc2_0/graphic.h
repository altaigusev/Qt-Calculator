#ifndef SRC_SMARTCALC2_0_GRAPHIC_H_
#define SRC_SMARTCALC2_0_GRAPHIC_H_

#include <QBrush>
#include <QColor>
#include <QDialog>
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLogValueAxis>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QDoubleValidator>
#include <cmath>

namespace Ui {
class Graphic;
}

class Graphic : public QDialog {
  Q_OBJECT

 public:
  explicit Graphic(QWidget *parent = nullptr);
  ~Graphic();

 private slots:
  void on_autoButton_clicked();
  void on_rebuildButton_clicked();
  void on_pushButton_clicked();
  void on_horizontalSlider_valueChanged(int value);

 public slots:
  void function_slot(QString a);

 public:
  Ui::Graphic *g_ui;

 private:
  QChart *chart;
  QValueAxis *axisX;
  QValueAxis *axisY;
  QScatterSeries *series;
  double x_max;
  double x_min;
  double y_max;
  double y_min;
  unsigned int ppg;
  void setLimits(double *lim);
};

#endif  // SRC_SMARTCALC2_0_GRAPHIC_H_
