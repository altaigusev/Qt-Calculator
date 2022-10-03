#ifndef SRC_SMARTCALC2_0_CALCCONTROLLER_H_
#define SRC_SMARTCALC2_0_CALCCONTROLLER_H_

#include <QString>
#include <algorithm>
#include <cctype>
#include <vector>

#include "calc_model.h"
#include "credit_model.h"


namespace s21 {
class CalcController {
 private:
  double sum;
  unsigned int term;
  double rate;
  int credit_type;
  std::string std_input, std_x_pression, std_output;
  std::pair<double, double> range;
  explicit CalcController(const CalcController &other)
      : sum(other.sum),
        term(other.term),
        rate(other.rate),
        credit_type(other.credit_type) {
    *this = other;
  }
  CalcController &operator=(const CalcController &other) {
    sum = other.sum;
    term = other.term;
    rate = other.rate;
    credit_type = other.credit_type;
    std_input = other.std_input;
    return *this;
  }

 public:
  CalcController() : sum(0), term(0), rate(0), credit_type(0) {}
  explicit CalcController(const std::string &str, const std::string &x_str)
      : sum(0),
        term(0),
        rate(0),
        credit_type(0),
        std_input(str),
        std_x_pression(x_str),
        std_output(" ") {}
  ~CalcController() {}
  QString input, output;
  void convert_qstring_to_std(QString *qt_str, std::string *std_str);
  std::string return_result();
  void graphic_points(std::string expression, std::vector<double> &,
                      std::pair<double, double>, unsigned int);
  std::vector<std::string> *calculate_credit(double sum, unsigned int term,
                                             double rate, int credit_type);
};
}  // namespace s21
#endif  // SRC_SMARTCALC2_0_CALCCONTROLLER_H_
