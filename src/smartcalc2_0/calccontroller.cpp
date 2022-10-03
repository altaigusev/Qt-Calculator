#include "calccontroller.h"
namespace s21 {
void CalcController::convert_qstring_to_std(QString *qt_str,
                                            std::string *std_str) {
  *std_str = qt_str->toStdString();
}

std::string CalcController::return_result() {
  try {
    s21::CalcModel calc_model(std_input, std_x_pression);
    std_output = calc_model.calculate().first;
  } catch (const std::exception &e) {
    std_output = e.what();
  }
  return std_output;
}

void CalcController::graphic_points(std::string std_input,
                                    std::vector<double> &vect,
                                    std::pair<double, double> range,
                                    unsigned int ppg) {
  try {
    s21::CalcModel calc_model(std_input);
    if (!calc_model.calc_graph_points(vect, range, ppg)) {
      for (int i = 0; i < 600; i++) vect.push_back(i);
      vect.shrink_to_fit();
    }
  } catch (const std::exception &e) {
    std_output = e.what();
    for (int i = 0; i < ppg; i++) vect.push_back(0);
  }
}

std::vector<std::string> *CalcController::calculate_credit(double sum,
                                                           unsigned int term,
                                                           double rate,
                                                           int credit_type) {
  s21::CreditModel credit_model(sum, term, rate, credit_type);
  return credit_model.credit_calculate();
}
}  // namespace s21
