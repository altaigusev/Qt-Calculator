#ifndef SRC_SMARTCALC2_0_CREDIT_H_
#define SRC_SMARTCALC2_0_CREDIT_H_

#include <QDialog>
#include <iostream>
#include <sstream>

#include "calccontroller.h"
#include "credit_model.h"

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();
  double sum;
  unsigned int term;
  double rate;
  int credit_type;

 private slots:
  void on_mainButton_clicked();

 private:
  Ui::Credit *ui;
  s21::CalcController ctrl;
  void fill_the_table(std::vector<std::string> *result_vector);
  std::vector<QString> months = {"Январь",   "Февраль", "Март",   "Апрель",
                                 "Май",      "Июнь",    "Июль",   "Август",
                                 "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
};

#endif  // SRC_SMARTCALC2_0_CREDIT_H_
