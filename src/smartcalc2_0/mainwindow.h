#ifndef SRC_SMARTCALC2_0_MAINWINDOW_H_
#define SRC_SMARTCALC2_0_MAINWINDOW_H_

#include <QKeyEvent>
#include <QMainWindow>

#include "calccontroller.h"
#include "credit.h"
#include "deposit.h"
#include "graphic.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_numbutton_1_clicked();
  void on_numbutton_2_clicked();
  void on_numbutton_3_clicked();
  void on_numbutton_4_clicked();
  void on_numbutton_5_clicked();
  void on_numbutton_6_clicked();
  void on_numbutton_7_clicked();
  void on_numbutton_8_clicked();
  void on_numbutton_9_clicked();
  void on_numbutton_0_clicked();

  void on_dot_button_clicked();
  void on_operation_button_plus_clicked();
  void on_operation_button_minus_clicked();
  void on_operation_button_mul_clicked();
  void on_operation_button_div_clicked();
  void on_open_brace_button_clicked();
  void on_close_brace_button_clicked();
  void on_cos_button_clicked();
  void on_sin_button_clicked();
  void on_tan_button_clicked();
  void on_acos_button_clicked();
  void on_asin_button_clicked();
  void on_atan_button_clicked();
  void on_sqrt_button_clicked();
  void on_ln_button_clicked();
  void on_log_button_clicked();
  void on_x_button_clicked();
  void on_clear_button_clicked();
  void on_backspace_button_clicked();
  void on_credit_button_clicked();
  void on_deposit_button_clicked();
  void on_graphic_button_clicked();
  void on_main_button_clicked();
  void on_space_button_clicked();
  void on_operation_button_mod_clicked();
  void on_pow_button_clicked();
  void replace_all_trigonometric(std::string &);

  void on_numbutton_e_clicked();

 signals:
  void signal(QString);

 private:
  Ui::MainWindow *ui;
  Credit *credit_window;
  Deposit *deposit_window;
  Graphic *graphic_window;
  const std::map<std::string, std::string> functions_map = {
      {"sin", "s"},  {"cos", "c"}, {"tan", "t"}, {"asin", "S"}, {"acos", "C"},
      {"atan", "T"}, {"log", "l"}, {"ln", "L"},  {"sqrt", "Q"}, {"mod", "m"}};
  void keyPressEvent(QKeyEvent *event);
};
#endif  // SRC_SMARTCALC2_0_MAINWINDOW_H_
