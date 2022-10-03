#include <string>

#include "SmartCalc2_0/calc_model.h"
#include "gtest/gtest.h"

TEST(calc1, start_calculations) {
  std::string test_expression = "(2+3)*6";
  s21::CalcModel model(test_expression);
  std::string result = model.calculate().first;
  ASSERT_EQ(result, "30");
}

TEST(calc2, start_calculations) {
  std::string test_expression = "acos(5)";
  s21::CalcModel model(test_expression);
  EXPECT_ANY_THROW(model.calculate());
}

TEST(calc3, start_calculations) {
  std::string test_expression = "asin(5)";
  s21::CalcModel model(test_expression);
  EXPECT_ANY_THROW(model.calculate());
}

TEST(calc4, start_calculations) {
  std::string test_expression = "ln(-6)";
  s21::CalcModel model(test_expression);
  std::string result = model.calculate().first;
  ASSERT_EQ(result, "nan");
}

TEST(calc5, start_calculations) {
  std::string test_expression = "sqrt(-5)";
  s21::CalcModel model(test_expression);
  EXPECT_ANY_THROW(model.calculate());
}

TEST(calc6, start_calculations) {
  std::string test_expression = "5^2";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
}

TEST(calc7, start_calculations) {
  std::string test_expression = "5sin(4)";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "-3.78401");
  ASSERT_NEAR(result.second, -3.78401, 7);
}

TEST(calc8, start_calculations) {
  std::string test_expression = "sin(6)cos(4)";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "0.182638");
  ASSERT_NEAR(result.second, 0.182638, 7);
}

TEST(calc9, start_calculations) {
  std::string test_expression = "sin(44)";
  s21::CalcModel model(test_expression);
  std::string result = model.calculate().first;
  ASSERT_EQ(result, "0.0177019");
}

TEST(calc10, start_calculations) {
  std::string test_expression =
      "(3 + (2 - (7 - (7 + (2 +(3 -(8 + (8 - (9 - (3 + (1 + 4) - 1) - 3) + 5) "
      "+ 6) + 7) - 7) - 6) - 5) - 4) - 2)";
  s21::CalcModel model(test_expression);
  std::string result = model.calculate().first;
  ASSERT_EQ(result, "-25");
}

TEST(calc11, start_calculations) {
  std::string test_expression =
      "5 + 1 - (2 + 1 - 3 + 1 + 1 + 1 + 2 - 4 - 2 + 5 + 7 - 3 + 1 - 2 + 1 - 3 "
      "+ 1 + 1 + 1 + 2 - 4 - 2 + 5 + 7 -3 + 1 - 2 + 1 - 3 + 1 + 1 + 1 + 2 - 4 "
      "- 2 + 5) + 7 - 3 - 1 - 1";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "-6");
  ASSERT_EQ(result.second, -6);
}

TEST(calc12, start_calculations) {
  std::string test_expression = "(2 ^ 2 ^ 2) / 2";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "8");
  ASSERT_EQ(result.second, 8);
}

TEST(calc13, start_calculations) {
  std::string test_expression = "cos(x)";
  std::string x_pression = "1";
  s21::CalcModel model(test_expression, x_pression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "0.540302");
  ASSERT_NEAR(result.second, 0.540302, 7);
}

TEST(calc14, start_calculations) {
  std::string test_expression = "5 mod 2";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "1");
  ASSERT_NEAR(result.second, 1, 7);
}

TEST(calc15, start_calculations) {
  std::string test_expression = "5 mod 2";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "1");
  ASSERT_NEAR(result.second, 1, 7);
}

TEST(calc16, start_calculations) {
  std::string test_expression = "5 mod 2";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "1");
  ASSERT_NEAR(result.second, 1, 7);
}

TEST(calc17, start_calculations) {
  std::string test_expression = "5 mod 2";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "1");
  ASSERT_NEAR(result.second, 1, 7);
}

TEST(calc18, start_calculations) {
  std::string test_expression = "5 mod 2";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "1");
  ASSERT_NEAR(result.second, 1, 7);
}

TEST(calc19, start_calculations) {
  std::string test_expression = "5 mod 2";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "1");
  ASSERT_NEAR(result.second, 1, 7);
}

TEST(calc20, graph_points) {
  std::vector<double> vec;
  for (int i = 0; i < 600; ++i) {
    vec.push_back(0);
  }
  std::string test_expression = "0";
  s21::CalcModel model(test_expression);
  std::vector<double> vec2;
  std::pair<double, double> range = {-10, 10};
  model.calc_graph_points(vec2, range, 600);
  for (int i = 0; i < 600; ++i) {
    ASSERT_EQ(vec[i], vec2[i]);
  }
}

TEST(calc21, calculations) {
  std::string test_expression = "1/0";
  s21::CalcModel model(test_expression);
  EXPECT_ANY_THROW(model.calculate());
}

TEST(calc22, calculations) {
  std::string test_expression = "log(-8)";
  s21::CalcModel model(test_expression);
  std::string result = model.calculate().first;
  ASSERT_EQ(result, "nan");
}

TEST(calc23, calculations) {
  std::string test_expression = "tan(0)";
  s21::CalcModel model(test_expression);
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "0");
  ASSERT_NEAR(result.second, 0, 7);
}

TEST(calc24, calculations) {
  std::string test_expression = "1x(45)";
  s21::CalcModel model(test_expression, "1");
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "45");
  ASSERT_NEAR(result.second, 45, 7);
}

TEST(calc25, calculations) {
  std::string test_expression = "x + 3 * x + x^x";
  s21::CalcModel model(test_expression, "1");
  std::pair<std::string, double> result = model.calculate();
  ASSERT_EQ(result.first, "5");
  ASSERT_NEAR(result.second, 5, 7);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
