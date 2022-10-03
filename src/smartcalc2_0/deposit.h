#ifndef SRC_SMARTCALC2_0_DEPOSIT_H_
#define SRC_SMARTCALC2_0_DEPOSIT_H_

#include <QDialog>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog {
  Q_OBJECT

 public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();

 private:
  Ui::Deposit *ui;
};

#endif  // SRC_SMARTCALC2_0_DEPOSIT_H_
