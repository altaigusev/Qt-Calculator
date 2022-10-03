#ifndef SRC_SMARTCALC2_0_CREDIT_MODEL_H_
#define SRC_SMARTCALC2_0_CREDIT_MODEL_H_

#include <QDate>
#include <cmath>
#include <iostream>
#include <istream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "calc_model.h"

namespace s21 {
class CreditModel : public CalcModel {
 private:
  double sum_;
  unsigned int term_;
  double rate_;
  int credit_type_;
  std::vector<std::string> *calculate_annuity();
  std::vector<std::string> *calculate_differ();
  std::vector<std::string> *vec;

 public:
  CreditModel(double sum, unsigned int term, double rate, int credit_type)
      : CalcModel(),
        sum_(sum),
        term_(term),
        rate_(rate),
        credit_type_(credit_type),
        vec(nullptr) {
  }

  std::vector<std::string> *credit_calculate();
};
}  // namespace s21
#endif  // SRC_SMARTCALC2_0_CREDIT_MODEL_H_
