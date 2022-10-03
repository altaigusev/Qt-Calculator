#include "calc_model.h"

namespace s21 {

CalcModel::CalcModel(std::string const& expression,
                     std::string const& x_pression)
    : get(true),
      number_value(0.0),
      curr_tok(print_),
      my_expression(expression),
      my_x_pression(x_pression),
      input_(nullptr) {}

typename CalcModel::Token_value CalcModel::get_token(std::istream* input) {
  char ch;
  do {
    if (!input->get(ch)) {
      return curr_tok = end_;
    }
  } while (ch != '\n' && isspace(ch));
  switch (ch) {
    case 0:
      return curr_tok = end_;
    case '\n':
      return curr_tok = print_;
    case mul_:
    case div_:
    case plus_:
    case minus_:
    case lp_:
    case rp_:
    case mod_:
    case sin_:
    case cos_:
    case tan_:
    case asin_:
    case acos_:
    case atan_:
    case pow_:
    case sqrt_:
    case log_:
    case ln_:
      return curr_tok = Token_value(ch);
    case num0:
    case num1:
    case num2:
    case num3:
    case num4:
    case num5:
    case num6:
    case num7:
    case num8:
    case num9:
    case numP:
      input->putback(ch);
      *input >> number_value;
      return curr_tok = number_;
    default:
      if (isalpha(ch)) {
        string_value = ch;
        while (input_->get(ch) && isalnum(ch)) {
          string_value.push_back(ch);
        }
        input_->putback(ch);
        return curr_tok = name_;
      }
      return curr_tok = print_;
  }
}

double CalcModel::prim(std::istream* input, bool get) {
  if (get) {
    get_token(input);
  }
  switch (curr_tok) {
    case number_: {
      double v = number_value;
      get_token(input);
      return v;
    }
      double inner_result;
    case minus_:
      return -prim(input, true);
    case sin_:
      return sin(prim(input, true));
    case cos_:
      return cos(prim(input, true));
    case tan_:
      return tan(prim(input, true));
    case asin_:
      inner_result = prim(input, true);
      if (inner_result >= -1 && inner_result <= 1)
        return asin(inner_result);
      else
        throw std::out_of_range("asin requires argument in (-1;1) range");
    case acos_:
      inner_result = prim(input, true);
      if (inner_result >= -1 && inner_result <= 1)
        return acos(prim(input, true));
      else
        throw std::out_of_range("acos requires argument in (-1;1) range");
    case atan_:
      return atan(prim(input, true));
    case sqrt_:
      inner_result = prim(input, true);
      if (inner_result >= 0)
        return sqrt(inner_result);
      else
        throw std::out_of_range("Cannot get square roots from negative values");
    case ln_:
      return log(prim(input, true));
    case log_:
      return log10(prim(input, true));
    case lp_: {
      double e = expr(input_, true);
      if (curr_tok != rp_) {
        throw std::invalid_argument("Not enough closed parenthesis");
      }
      get_token(input);
      return e;
    }
    default:
      throw std::invalid_argument("Expression error");
  }
}

double CalcModel::pow_next(std::istream* input, bool get) {
  double left = prim(input, get);
  for (;;) {
    switch (curr_tok) {
      case pow_:
        left = pow(left, prim(input, true));
        break;
      default:
        return left;
    }
  }
}

double CalcModel::term(std::istream* input, bool get) {
  double left = pow_next(input, get);
  for (;;) {
    switch (curr_tok) {
      case mul_:
        left *= pow_next(input, true);
        break;
      case div_:
        if (double d = pow_next(input, true)) {
          left /= d;
          break;
        }
        throw std::invalid_argument("Division by zero");
      case mod_:
        if (double d = pow_next(input, true)) {
          left = fmod(left, d);
          break;
        }
        throw std::invalid_argument("Division by zero");
      default:
        return left;
    }
  }
}

double CalcModel::expr(std::istream* input, bool get) {
  double left = term(input, get);
  for (;;) {
    switch (curr_tok) {
      case plus_:
        left += term(input, true);
        break;
      case minus_:
        left -= term(input, true);
        break;
      default:
        return left;
    }
  }
}

std::pair<std::string, double> CalcModel::calculate() {
  std::transform(my_expression.begin(), my_expression.end(),
                 my_expression.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  replace_mod(&my_expression);
  if (!validate_string()) throw std::invalid_argument("Bad expression");
  multiplication_insertion();
  replace_all_x();
  replace_all_trigonometric(&my_expression);
  input_ = new std::istringstream(my_expression);
  std::string result;
  char output_buf[BUF_SIZE] = {0};
  double var;
  while (*input_) {
    get_token(input_);
    if (curr_tok == end_) {
      break;
    }
    var = expr(input_, false);
    std::snprintf(output_buf, BUF_SIZE, "%g", var);
    result = output_buf;
  }
  std::pair<std::string, double> pair_result(result, var);
  delete input_;
  return pair_result;
}

void CalcModel::replace_all_x() {
  if (my_x_pression.length() != 0) {
    std::string tmp = my_expression;
    my_expression = my_x_pression;
    my_x_pression.clear();
    std::string x_val = calculate().first;
    auto x_place = tmp.find('x');
    while (x_place != std::string::npos) {
      tmp.replace(x_place, 1, x_val);
      x_place = tmp.find('x');
    }
    my_x_pression = my_expression;
    my_expression = tmp;
  }
}

bool CalcModel::calc_graph_points(std::vector<double>& vec,
                                  std::pair<double, double> range,
                                  unsigned int ppg) {
  char output_buf[BUF_SIZE] = {0};
  std::string expression_initial_state = my_expression;
  double x_value_of_tick = (range.second - range.first) / ppg;
  for (unsigned int i = 0; i < ppg; ++i) {
    std::snprintf(output_buf, BUF_SIZE, "%f",
                  range.first + i * x_value_of_tick);
    my_x_pression = output_buf;
    replace_all_x();
    double medium = 0;
    try {
      medium = calculate().second;
    } catch (const std::exception& e) {
      medium = 0;
    }
    vec.push_back(medium);
    my_expression = expression_initial_state;
  }
  vec.shrink_to_fit();
  return true;
}

void CalcModel::replace_all_trigonometric(std::string *not_replaced) {
  auto function_chooser = functions_map.begin();
  for (; function_chooser != functions_map.end(); ++function_chooser) {
    auto place_of_function = not_replaced->find(function_chooser->first);
    while (place_of_function != std::string::npos) {
      not_replaced->replace(place_of_function, function_chooser->first.length(),
                           function_chooser->second);
      place_of_function = not_replaced->find(function_chooser->first);
    }
  }
}

void CalcModel::replace_mod(std::string *not_replaced) {
  auto place_of_function = not_replaced->find("mod");
  while (place_of_function != std::string::npos) {
    not_replaced->replace(place_of_function, 3, "m");
    place_of_function = not_replaced->find("mod");
  }
}

bool CalcModel::validate_string() const {
  std::string etalons = "cosinatqrdlgmxe()1234567890-+*/^ .";
  if (dots_check()) throw std::invalid_argument("Only one dot per number");
  if (parenthesis_count())
    throw std::invalid_argument("Check parenthesis in expression");
  if (is_trigonometric_full())
    throw std::invalid_argument("Use full forms of functions");
  for (auto it = my_expression.begin(); it != my_expression.end(); ++it) {
    if (etalons.find(*it) == std::string::npos) return false;
  }
  return true;
}

bool CalcModel::dots_check() const {
  for (unsigned int i = 0; i < my_expression.length(); ++i) {
    int dots = 0;
    while (i < (my_expression.length() - 1) &&
           (isdigit(my_expression.at(i)) || my_expression.at(i) == '.')) {
      ++i;
      if (my_expression.at(i) == '.') ++dots;
    }
    if (dots > 1) return true;
  }
  return false;
}

bool CalcModel::parenthesis_count() const {
  size_t open_par = std::count(my_expression.begin(), my_expression.end(), '(');
  size_t closed_par =
      std::count(my_expression.begin(), my_expression.end(), ')');
  if (open_par - closed_par != 0) return true;
  return false;
}

void CalcModel::multiplication_insertion() {
  std::string etalons = "csnatdlx(";
  bool is_number = false;
  for (auto it = my_expression.begin(); it != my_expression.end(); ++it) {
    if (isnumber(*it)) {
      is_number = true;
      continue;
    }
    size_t it_place = etalons.find(*it);
    if (it_place != std::string::npos) {
      if (is_number) my_expression.insert(it, '*');
    }
    is_number = false;
  }
  bool is_x = false;
  for (auto it = my_expression.begin(); it != my_expression.end(); ++it) {
    if (*it == 'x') {
      is_x = true;
      continue;
    }
    size_t it_place = etalons.find(*it);
    if (it_place != std::string::npos && *it != 'x') {
      if (is_x) my_expression.insert(it, '*');
    }
    is_x = false;
  }
  auto x_place = my_expression.find(")");
  while (x_place != std::string::npos &&
         x_place < (my_expression.length() - 1)) {
    if (isdigit(my_expression.at(x_place + 1)) ||
        (etalons.find(my_expression.at(x_place + 1)) != std::string::npos ||
         my_expression.at(x_place + 1) == '(')) {
      my_expression.replace(x_place, 1, ")*");
    }
    x_place += 2;
    if (x_place < my_expression.length())
      x_place = my_expression.find(')', x_place);
    else
      break;
  }
}

bool CalcModel::is_trigonometric_full() const {
  std::string etalons = "cosinatqrlg";
  bool is_functions = false;
  std::string token;
  for (auto it = my_expression.begin(); it != my_expression.end(); ++it) {
    if (etalons.find(*it) != std::string::npos) {
      is_functions = true;
      while (*it != '(') {
        token.push_back(*it);
        ++it;
        if (it == my_expression.end()) break;
      }
      int good_functions_count = 0;
      for (auto tri_it = functions_map.begin(); tri_it != functions_map.end();
           ++tri_it) {
        if (tri_it->first == token) good_functions_count += 1;
      }
      token.clear();
      if (!good_functions_count)
        throw std::invalid_argument("Unexpected function");
    }
  }
  if (is_functions) {
    int good_functions_count = 0;
    int position = 0;
    for (auto tri_it = functions_map.begin(); tri_it != functions_map.end();
         ++tri_it) {
      auto function_place = my_expression.find(tri_it->first);
      if (function_place != std::string::npos) {
        good_functions_count++;
        if (my_expression.length() == tri_it->first.length())
          throw std::invalid_argument("Where is expression?");
        if (my_expression.at(function_place + tri_it->first.length()) != '(')
          throw std::invalid_argument("Invalid expression");
      }
      position++;
    }
    if (good_functions_count == 0) return true;
  } else {
    return false;
  }
  return false;
}
}  // namespace s21
