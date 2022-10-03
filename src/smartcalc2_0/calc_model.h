#ifndef SRC_SMARTCALC2_0_CALC_MODEL_H_
#define SRC_SMARTCALC2_0_CALC_MODEL_H_

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <istream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

static const int BUF_SIZE = 256;

namespace s21 {
class CalcModel {
 private:
  enum Token_value : char {
    name_,
    number_,
    end_,
    plus_ = '+',
    minus_ = '-',
    mul_ = '*',
    div_ = '/',
    lp_ = '(',
    rp_ = ')',
    mod_ = 'm',
    sin_ = 's',
    cos_ = 'c',
    tan_ = 't',
    asin_ = 'S',
    acos_ = 'C',
    atan_ = 'T',
    pow_ = '^',
    sqrt_ = 'Q',
    log_ = 'l',
    ln_ = 'L',
    print_ = ';'
  };

  enum Number_value : char {
    num0 = '0',
    num1 = '1',
    num2 = '2',
    num3 = '3',
    num4 = '4',
    num5 = '5',
    num6 = '6',
    num7 = '7',
    num8 = '8',
    num9 = '9',
    numP = '.',
  };
  const std::map<std::string, std::string> functions_map = {
      {"sin", "s"},  {"cos", "c"}, {"tan", "t"}, {"asin", "S"}, {"acos", "C"},
      {"atan", "T"}, {"log", "l"}, {"ln", "L"},  {"sqrt", "Q"}, {"mod", "m"}};

  bool get;
  double number_value;
  Token_value curr_tok;
  std::string string_value;
  Token_value get_token(std::istream* input);
  double prim(std::istream* input, bool get);
  double pow_next(std::istream* input, bool get);
  double term(std::istream* input, bool get);
  void x_replace(double x_val);
  void replace_all_x();
  void replace_all_trigonometric(std::string *not_replaced);
  bool validate_string() const;
  bool dots_check() const;
  bool parenthesis_count() const;
  void multiplication_insertion();
  bool is_trigonometric_full() const;
  void replace_mod(std::string *not_replaced);
  double expr(std::istream*, bool);

 protected:
  std::string my_expression;
  std::string my_x_pression;
  std::istream* input_;

 public:
  CalcModel() : get(true), number_value(0), curr_tok(name_) {
    input_ = nullptr;
  }
  explicit CalcModel(std::string const& expression,
                     std::string const& x_pression = "");

  virtual ~CalcModel() {}
  std::pair<std::string, double> calculate();
  bool calc_graph_points(std::vector<double>&, std::pair<double, double> range,
                         unsigned int ppg);
};
}  // namespace s21

#endif  // SRC_SMARTCALC2_0_CALC_MODEL_H_
