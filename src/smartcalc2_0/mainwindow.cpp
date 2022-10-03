#include "mainwindow.h"
#include "calccontroller.h"
#include "credit.h"
#include "deposit.h"
#include "graphic.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui; }

void MainWindow::on_numbutton_1_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("1");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("1");
  }
}

void MainWindow::on_numbutton_2_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("2");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("2");
  }
}

void MainWindow::on_numbutton_3_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("3");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("3");
  }
}

void MainWindow::on_numbutton_4_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("4");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("4");
  }
}

void MainWindow::on_numbutton_5_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("5");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("5");
  }
}

void MainWindow::on_numbutton_6_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("6");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("6");
  }
}

void MainWindow::on_numbutton_7_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("7");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("7");
  }
}

void MainWindow::on_numbutton_8_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("8");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("8");
  }
}

void MainWindow::on_numbutton_9_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("9");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("9");
  }
}

void MainWindow::on_numbutton_0_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("0");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("0");
  }
}

void MainWindow::on_dot_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert(".");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert(".");
  }
}

void MainWindow::on_operation_button_plus_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("+");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("+");
  }
}

void MainWindow::on_operation_button_minus_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("-");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("-");
  }
}

void MainWindow::on_operation_button_mul_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("*");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("*");
  }
}

void MainWindow::on_operation_button_div_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("/");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("/");
  }
}

void MainWindow::on_operation_button_mod_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("mod");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("mod");
  }
}

void MainWindow::on_open_brace_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("(");
  }
}

void MainWindow::on_close_brace_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert(")");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert(")");
  }
}

void MainWindow::on_cos_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("cos(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("cos(");
  }
}

void MainWindow::on_sin_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("sin(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("sin(");
  }
}

void MainWindow::on_tan_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("tan(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("tan(");
  }
}

void MainWindow::on_acos_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("acos(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("acos(");
  }
}

void MainWindow::on_asin_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("asin(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("asin(");
  }
}

void MainWindow::on_atan_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("atan(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("atan(");
  }
}

void MainWindow::on_sqrt_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("sqrt(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("sqrt(");
  }
}

void MainWindow::on_ln_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("ln(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("ln(");
  }
}

void MainWindow::on_log_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("log(");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("log(");
  }
}

void MainWindow::on_pow_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("^");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("^");
  }
}

void MainWindow::replace_all_trigonometric(std::string &not_replaced) {
  auto function_chooser = functions_map.begin();
  for (; function_chooser != functions_map.end(); ++function_chooser) {
    auto place_of_function = not_replaced.find(function_chooser->first);
    while (place_of_function != std::string::npos) {
      not_replaced.replace(place_of_function, function_chooser->first.length(),
                           function_chooser->second);
      place_of_function = not_replaced.find(function_chooser->first);
    }
  }
}

void MainWindow::on_x_button_clicked() { ui->main_line->insert("x"); }

void MainWindow::on_clear_button_clicked() {
  if (ui->main_line->text().isEmpty()) ui->result_label->clear();
  if (ui->main_line->hasFocus()) {
    ui->main_line->clear();
  } else if (ui->x_value_edit->hasFocus()) {
    if (ui->x_value_edit->text().isEmpty()) {
      ui->main_line->clear();
      ui->result_label->clear();
      ui->main_line->setFocus();
    } else {
      ui->x_value_edit->clear();
    }
  }
}

void MainWindow::on_backspace_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->backspace();
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->backspace();
  }
}

void MainWindow::on_credit_button_clicked() {
  credit_window = new Credit();
  credit_window->setModal(true);
  credit_window->exec();
}

void MainWindow::on_deposit_button_clicked() {
  Deposit deposit_window;
  deposit_window.setModal(true);
  deposit_window.exec();
}

void MainWindow::on_graphic_button_clicked() {
  graphic_window = new Graphic(this);
  connect(this, &MainWindow::signal, graphic_window, &Graphic::function_slot);
  graphic_window->setModal(true);
  graphic_window->show();
  emit signal(ui->main_line->text());
}

void MainWindow::on_main_button_clicked() {
  std::string expression = ui->main_line->text().toStdString();
  std::string x_pression = ui->x_value_edit->text().toStdString();
  s21::CalcController ctrl(expression, x_pression);
  QString main_expression = QString::fromStdString(ctrl.return_result());
  ui->result_label->setText(main_expression);
}

void MainWindow::on_space_button_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert(" ");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert(" ");
  }
}

void MainWindow::on_numbutton_e_clicked() {
  if (ui->main_line->hasFocus()) {
    ui->main_line->insert("e");
  } else if (ui->x_value_edit->hasFocus()) {
    ui->x_value_edit->insert("e");
  }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Escape) {
    if (ui->x_value_edit->text().isEmpty() && ui->main_line->text().isEmpty()) {
      close();
    } else {
      on_clear_button_clicked();
      ui->result_label->clear();
    }
  } else if (event->key() == 16777220) {
    on_main_button_clicked();
  }
}
