#include "credit_model.h"

#include "calc_model.h"

namespace s21 {

std::vector<std::string> *CreditModel::credit_calculate() {
  vec = new std::vector<std::string>;
  if (this->credit_type_ == 0) return calculate_annuity();
  return calculate_differ();
}

std::vector<std::string> *CreditModel::calculate_annuity() {
  char buf[BUF_SIZE] = {0};
  snprintf(buf, BUF_SIZE, "%f * ((%.2f/12)/(1 - ((1+(%.2f/12)) ^ (-%u))))",
           sum_, rate_, rate_, term_);
  my_expression = buf;
  std::pair<std::string, double> mypair = calculate();
  int start_term = term_;
  double start_sum = sum_;
  while (term_-- > 0) {
    double percents = sum_ * rate_ / 12;
    sum_ = sum_ + percents - mypair.second;
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "%.2f;%.2f;%.2f;%.2f", mypair.second,
             mypair.second - percents, percents, sum_);
    vec->push_back(buf);
  }
  memset(buf, 0, BUF_SIZE);
  snprintf(buf, BUF_SIZE, "%.2f", mypair.second);
  std::string regular = buf;
  vec->push_back(regular + " рублей");
  memset(buf, 0, BUF_SIZE);
  snprintf(buf, BUF_SIZE, "%.2f", mypair.second * start_term - start_sum);
  std::string overpayment = buf;
  vec->push_back(overpayment + " рублей");
  memset(buf, 0, BUF_SIZE);
  snprintf(buf, BUF_SIZE, "%.2f", mypair.second * start_term);
  std::string total_loan = buf;
  vec->push_back(total_loan + " рублей");
  return vec;
}

std::vector<std::string> *CreditModel::calculate_differ() {
  char buf[BUF_SIZE] = {};
  snprintf(buf, BUF_SIZE, "%.2f / %u", sum_, term_);
  my_expression = buf;
  double first_month{}, last_month{}, total_loan{};
  double start_sum = sum_;
  std::pair<std::string, double> mypair = calculate();
  double regular_base_dbl = mypair.second;
  int count = 0;
  while (term_-- > 0 && sum_ > 0) {
    double percents = sum_ * rate_ / 12;
    double total_payment = regular_base_dbl + percents;
    if (count++ == 0) first_month = total_payment;
    if (term_ == 0) last_month = total_payment;
    total_loan += percents;
    sum_ = sum_ - regular_base_dbl;
    if (abs(sum_) <= 0.01) sum_ = 0;
    memset(buf, 0, BUF_SIZE);
    snprintf(buf, BUF_SIZE, "%.2f;%.2f;%.2f;%.2f", total_payment,
             regular_base_dbl, percents, sum_);
    vec->push_back(buf);
  }
  memset(buf, 0, BUF_SIZE);
  snprintf(buf, BUF_SIZE, "%.2f..%.2f рублей", first_month, last_month);
  vec->push_back(buf);
  memset(buf, 0, BUF_SIZE);
  snprintf(buf, BUF_SIZE, "%.2f рублей", total_loan);
  vec->push_back(buf);
  memset(buf, 0, BUF_SIZE);
  snprintf(buf, BUF_SIZE, "%.2f рублей", total_loan + start_sum);
  vec->push_back(buf);
  return vec;
}
}  // namespace s21
