#include "credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QDialog(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
  ui->tableWidget_result->hide();
  ui->tableWidget_result->setColumnCount(5);
  ui->tableWidget_result->setHorizontalHeaderLabels(
      QStringList() << "Дата"
                    << "Сумма платежа"
                    << "Платеж по основному долгу"
                    << "Платеж по процентам"
                    << "Остаток долга");
  ui->radioButton_annuity->setChecked(true);
  this->adjustSize();
}

Credit::~Credit() { delete ui; }

void Credit::on_mainButton_clicked() {
  if (ui->radioButton_annuity->isChecked())
    credit_type = 0;
  else if (ui->radioButton_differ->isChecked())
    credit_type = 1;
  sum = ui->doubleSpinBox_sum->value();
  term = ui->spinBox_period->value();
  rate = ui->doubleSpinBox_rate->value();
  if (ui->comboBox_period->currentText() == "Лет") term *= 12;
  rate /= 100;
  std::vector<std::string> *result_vector =
      ctrl.calculate_credit(sum, term, rate, credit_type);
  if (ui->tableWidget_result->isHidden()) ui->tableWidget_result->show();
  fill_the_table(result_vector);
  int last_element = result_vector->size();
  ui->label_monthly_result->setText(
      QString::fromStdString(result_vector->at(last_element - 3)));
  ui->label_overpay_result->setText(
      QString::fromStdString(result_vector->at(last_element - 2)));
  ui->label_total_result->setText(
      QString::fromStdString(result_vector->at(last_element - 1)));
}

void Credit::fill_the_table(std::vector<std::string> *result_vector) {
  ui->tableWidget_result->setRowCount(term);
  ui->tableWidget_result->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  QDate this_day = QDate::currentDate();
  for (int i = 0; i < ui->tableWidget_result->rowCount(); i++) {
    std::istringstream f(result_vector->at(i));
    std::string s;
    for (int j = 0; j < ui->tableWidget_result->columnCount(); j++) {
      if (j == 0) {
        QTableWidgetItem *itm =
            new QTableWidgetItem(months.at((this_day.month()) % 12) + " " +
                                 QString::number(this_day.year()));
        itm->setBackground(QColor(65, 125, 200, 200));
        ui->tableWidget_result->setItem(i, j, itm);
        this_day = this_day.addMonths(1);
      } else if (j == 1) {
        getline(f, s, ';');
        QTableWidgetItem *itm = new QTableWidgetItem(QString::fromStdString(s));
        itm->setBackground(QColor(65, 125, 200, 100));
        ui->tableWidget_result->setItem(i, j, itm);
      } else if (j == 2) {
        getline(f, s, ';');
        QTableWidgetItem *itm = new QTableWidgetItem(QString::fromStdString(s));
        itm->setBackground(QColor(65, 125, 200, 50));
        ui->tableWidget_result->setItem(i, j, itm);
      } else if (j == 3) {
        getline(f, s, ';');
        QTableWidgetItem *itm = new QTableWidgetItem(QString::fromStdString(s));
        itm->setBackground(QColor(65, 125, 200, 25));
        ui->tableWidget_result->setItem(i, j, itm);
      } else {
        getline(f, s, ';');
        QTableWidgetItem *itm = new QTableWidgetItem(QString::fromStdString(s));
        itm->setBackground(QColor(65, 125, 200, 12));
        ui->tableWidget_result->setItem(i, j, itm);
      }
    }
  }
}
