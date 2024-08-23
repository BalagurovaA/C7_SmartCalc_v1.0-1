#include <check.h>

#include "calc.h"

/***********************************/
/************ VALIDATOR ************/
/***********************************/

/****************** dot *****************/
START_TEST(test_s21_validator1) {
  char exapmle[MAX_NUM] = "log(3.3)-3.3+1";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator2) {
  char exapmle[MAX_NUM] = "3.3-3.9+1";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator3) {
  char exapmle[MAX_NUM] = "3.3.3+1";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator4) {
  char exapmle[MAX_NUM] = "3...2-1";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator5) {
  char exapmle[MAX_NUM] = "3.0-0.3*2-1";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

/****************** number *****************/

START_TEST(test_s21_validator6) {
  char exapmle[MAX_NUM] = "33+2";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator7) {
  char exapmle[MAX_NUM] = "3.3+2";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator8) {
  char example[MAX_NUM] = "(33+2)";
  ck_assert_int_eq(validator(example), true);
}
END_TEST;

START_TEST(test_s21_validator9) {
  char exapmle[MAX_NUM] = "(33+2)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator10) {
  char exapmle[MAX_NUM] = "(56^2)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator11) {
  char exapmle[MAX_NUM] = "(56^2)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator12) {
  char exapmle[MAX_NUM] = "4mod6";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator13) {
  char exapmle[MAX_NUM] = "(2-7)4";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator14) {
  char exapmle[MAX_NUM] = "sin6";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator15) {
  char exapmle[MAX_NUM] = "x6";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator16) {
  char exapmle[MAX_NUM] = "6(8-9)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator17) {
  char exapmle[MAX_NUM] = "6sin(2)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator18) {
  char exapmle[MAX_NUM] = "6acos(8)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator19) {
  char exapmle[MAX_NUM] = "6ln(34)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator20) {
  char exapmle[MAX_NUM] = "66747475747564sin(4)-59393493.3.3.3.3.9";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

/****************** bracket1 ( *****************/
START_TEST(test_s21_validator21) {
  char exapmle[MAX_NUM] = "4+(7/9)";
  ck_assert_int_eq(validator(exapmle), true);
}

START_TEST(test_s21_validator22) {
  char exapmle[MAX_NUM] = "4mod(7/9)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator23) {
  char exapmle[MAX_NUM] = "sin((7/9))";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator24) {
  char exapmle[MAX_NUM] = "(7/9)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator25) {
  char exapmle[MAX_NUM] = "((67-4444+9)-7/9)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator26) {
  char exapmle[MAX_NUM] = "(.(67-4444+9)-7/9)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator27) {
  char exapmle[MAX_NUM] = "(-7/9)-9";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator28) {
  char exapmle[MAX_NUM] = "(sin(6)/5)-9";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator29) {
  char exapmle[MAX_NUM] = "4(8-10)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator30) {
  char exapmle[MAX_NUM] = ".(8-0)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator31) {
  char exapmle[MAX_NUM] = "(sin(6)/5)-9";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator32) {
  char exapmle[MAX_NUM] = "(4-0)(8-9)-9";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator33) {
  char exapmle[MAX_NUM] = "(.4-1)-9";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator34) {
  char exapmle[MAX_NUM] = "()-9";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator35) {
  char exapmle[MAX_NUM] = "(mod8)-9";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

/****************** bracket2 ) *****************/
START_TEST(test_s21_validator36) {
  char exapmle[MAX_NUM] = "(3-3)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator37) {
  char exapmle[MAX_NUM] = "(3-(4+58))";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator38) {
  char exapmle[MAX_NUM] = "(3-(4+58)/9)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator39) {
  char exapmle[MAX_NUM] = "(58-3)mod(34-22)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator40) {
  char exapmle[MAX_NUM] = "(56-5.)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator41) {
  char exapmle[MAX_NUM] = "(4mod)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator42) {
  char exapmle[MAX_NUM] = "(58-3)3";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator43) {
  char exapmle[MAX_NUM] = "(58-3)sin(6)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator44) {
  char exapmle[MAX_NUM] = "(58-3)atan(6)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator45) {
  char exapmle[MAX_NUM] = "(58-3)ln(6)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

/****************** operators *****************/

START_TEST(test_s21_validator46) {
  char exapmle[MAX_NUM] = "(8-9)^465";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator47) {
  char exapmle[MAX_NUM] = "78*(5-1)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator48) {
  char exapmle[MAX_NUM] = "5/sin(45.5)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;
START_TEST(test_s21_validator49) {
  char exapmle[MAX_NUM] = "5-ln(3)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator50) {
  char exapmle[MAX_NUM] = "7./4";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator51) {
  char exapmle[MAX_NUM] = "(*9)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator52) {
  char exapmle[MAX_NUM] = "(58-3)ln(6)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator53) {
  char exapmle[MAX_NUM] = "55**8";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator54) {
  char exapmle[MAX_NUM] = "6mod*";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator55) {
  char exapmle[MAX_NUM] = "cos*8";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator56) {
  char exapmle[MAX_NUM] = "*.4";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator57) {
  char exapmle[MAX_NUM] = "(*)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator58) {
  char exapmle[MAX_NUM] = "/mod7";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator59) {
  char exapmle[MAX_NUM] = "/=";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator60) {
  char exapmle[MAX_NUM] = "/46-6";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator61) {
  char exapmle[MAX_NUM] = "-46-6";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator62) {
  char exapmle[MAX_NUM] = "(-46-6)-9";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator63) {
  char exapmle[MAX_NUM] = "(+46-6)-9";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator64) {
  char exapmle[MAX_NUM] = "3+3";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

/****************** mod *****************/
START_TEST(test_s21_validator65) {
  char exapmle[MAX_NUM] = "3mod5";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator66) {
  char exapmle[MAX_NUM] = "(-2)mod5";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator67) {
  char exapmle[MAX_NUM] = "5mod(45-9)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator68) {
  char exapmle[MAX_NUM] = "4modlog(3)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator69) {
  char exapmle[MAX_NUM] = "(mod8)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator70) {
  char exapmle[MAX_NUM] = "/mod8";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator71) {
  char exapmle[MAX_NUM] = ".mod6.7";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator72) {
  char exapmle[MAX_NUM] = "4mod.9";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator73) {
  char exapmle[MAX_NUM] = "4mod/";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

/****************** unary operators *****************/
START_TEST(test_s21_validator731) {
  char exapmle[MAX_NUM] = "-5/6";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator74) {
  char exapmle[MAX_NUM] = "-9*6-(-12-34)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator75) {
  char exapmle[MAX_NUM] = "(-4-(-21+34)-9)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator76) {
  char exapmle[MAX_NUM] = "--5";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

/****************** trigonometry *****************/

START_TEST(test_s21_validator77) {
  char exapmle[MAX_NUM] = "(sin(8)-22)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator78) {
  char exapmle[MAX_NUM] = "55-cos(2)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator79) {
  char exapmle[MAX_NUM] = "tan(3)modasin(4)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator80) {
  char exapmle[MAX_NUM] = "acos(8)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;
START_TEST(test_s21_validator81) {
  char exapmle[MAX_NUM] = "atan((34-9)/9)";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator82) {
  char exapmle[MAX_NUM] = "3acos(445)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator83) {
  char exapmle[MAX_NUM] = "4.atan(45)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator84) {
  char exapmle[MAX_NUM] = "(4-5)acos(445)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator85) {
  char exapmle[MAX_NUM] = "sin(.)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator86) {
  char exapmle[MAX_NUM] = "cos(/4)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator88) {
  char exapmle[MAX_NUM] = "sqrt(mod9)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

START_TEST(test_s21_validator89) {
  char exapmle[MAX_NUM] = "x+4";
  ck_assert_int_eq(validator(exapmle), true);
}
END_TEST;

START_TEST(test_s21_validator90) {
  char exapmle[MAX_NUM] = "cas(4)";
  ck_assert_int_eq(validator(exapmle), false);
}
END_TEST;

Suite *validator_test() {
  Suite *result;
  TCase *tc_validator;

  result = suite_create("validator");
  tc_validator = tcase_create("validator");

  /****************** dot *****************/
  tcase_add_test(tc_validator, test_s21_validator1);
  tcase_add_test(tc_validator, test_s21_validator2);
  tcase_add_test(tc_validator, test_s21_validator3);
  tcase_add_test(tc_validator, test_s21_validator4);
  tcase_add_test(tc_validator, test_s21_validator5);

  /****************** number *****************/
  tcase_add_test(tc_validator, test_s21_validator6);
  tcase_add_test(tc_validator, test_s21_validator7);
  tcase_add_test(tc_validator, test_s21_validator8);
  tcase_add_test(tc_validator, test_s21_validator9);
  tcase_add_test(tc_validator, test_s21_validator10);
  tcase_add_test(tc_validator, test_s21_validator11);
  tcase_add_test(tc_validator, test_s21_validator12);
  tcase_add_test(tc_validator, test_s21_validator13);
  tcase_add_test(tc_validator, test_s21_validator14);
  tcase_add_test(tc_validator, test_s21_validator15);
  tcase_add_test(tc_validator, test_s21_validator16);
  tcase_add_test(tc_validator, test_s21_validator17);
  tcase_add_test(tc_validator, test_s21_validator18);
  tcase_add_test(tc_validator, test_s21_validator19);
  tcase_add_test(tc_validator, test_s21_validator20);

  /****************** bracket1 ( *****************/
  tcase_add_test(tc_validator, test_s21_validator21);
  tcase_add_test(tc_validator, test_s21_validator22);
  tcase_add_test(tc_validator, test_s21_validator23);
  tcase_add_test(tc_validator, test_s21_validator24);
  tcase_add_test(tc_validator, test_s21_validator25);
  tcase_add_test(tc_validator, test_s21_validator26);
  tcase_add_test(tc_validator, test_s21_validator27);
  tcase_add_test(tc_validator, test_s21_validator28);
  tcase_add_test(tc_validator, test_s21_validator29);
  tcase_add_test(tc_validator, test_s21_validator30);
  tcase_add_test(tc_validator, test_s21_validator31);
  tcase_add_test(tc_validator, test_s21_validator32);
  tcase_add_test(tc_validator, test_s21_validator33);
  tcase_add_test(tc_validator, test_s21_validator34);
  tcase_add_test(tc_validator, test_s21_validator35);

  /****************** bracket2 ) *****************/
  tcase_add_test(tc_validator, test_s21_validator36);
  tcase_add_test(tc_validator, test_s21_validator37);
  tcase_add_test(tc_validator, test_s21_validator38);
  tcase_add_test(tc_validator, test_s21_validator39);
  tcase_add_test(tc_validator, test_s21_validator40);
  tcase_add_test(tc_validator, test_s21_validator41);
  tcase_add_test(tc_validator, test_s21_validator42);
  tcase_add_test(tc_validator, test_s21_validator43);
  tcase_add_test(tc_validator, test_s21_validator44);
  tcase_add_test(tc_validator, test_s21_validator45);

  /****************** operators *****************/
  tcase_add_test(tc_validator, test_s21_validator46);
  tcase_add_test(tc_validator, test_s21_validator47);
  tcase_add_test(tc_validator, test_s21_validator48);
  tcase_add_test(tc_validator, test_s21_validator49);
  tcase_add_test(tc_validator, test_s21_validator50);
  tcase_add_test(tc_validator, test_s21_validator51);
  tcase_add_test(tc_validator, test_s21_validator52);
  tcase_add_test(tc_validator, test_s21_validator53);
  tcase_add_test(tc_validator, test_s21_validator54);
  tcase_add_test(tc_validator, test_s21_validator55);
  tcase_add_test(tc_validator, test_s21_validator56);
  tcase_add_test(tc_validator, test_s21_validator57);
  tcase_add_test(tc_validator, test_s21_validator58);
  tcase_add_test(tc_validator, test_s21_validator59);
  tcase_add_test(tc_validator, test_s21_validator60);
  tcase_add_test(tc_validator, test_s21_validator61);
  tcase_add_test(tc_validator, test_s21_validator62);
  tcase_add_test(tc_validator, test_s21_validator63);
  tcase_add_test(tc_validator, test_s21_validator64);

  /****************** mod *****************/

  tcase_add_test(tc_validator, test_s21_validator65);
  tcase_add_test(tc_validator, test_s21_validator66);
  tcase_add_test(tc_validator, test_s21_validator67);
  tcase_add_test(tc_validator, test_s21_validator68);
  tcase_add_test(tc_validator, test_s21_validator69);
  tcase_add_test(tc_validator, test_s21_validator70);
  tcase_add_test(tc_validator, test_s21_validator71);
  tcase_add_test(tc_validator, test_s21_validator72);
  tcase_add_test(tc_validator, test_s21_validator73);
  tcase_add_test(tc_validator, test_s21_validator731);
  tcase_add_test(tc_validator, test_s21_validator74);
  tcase_add_test(tc_validator, test_s21_validator75);
  tcase_add_test(tc_validator, test_s21_validator76);

  /****************** trigonometry *****************/

  tcase_add_test(tc_validator, test_s21_validator77);
  tcase_add_test(tc_validator, test_s21_validator78);
  tcase_add_test(tc_validator, test_s21_validator79);
  tcase_add_test(tc_validator, test_s21_validator80);
  tcase_add_test(tc_validator, test_s21_validator81);
  tcase_add_test(tc_validator, test_s21_validator82);
  tcase_add_test(tc_validator, test_s21_validator83);
  tcase_add_test(tc_validator, test_s21_validator83);
  tcase_add_test(tc_validator, test_s21_validator84);
  tcase_add_test(tc_validator, test_s21_validator85);
  tcase_add_test(tc_validator, test_s21_validator86);
  tcase_add_test(tc_validator, test_s21_validator88);
  tcase_add_test(tc_validator, test_s21_validator89);
  tcase_add_test(tc_validator, test_s21_validator90);
  suite_add_tcase(result, tc_validator);
  return result;
}

/***********************************/
/*************** RPN ***************/
/***********************************/

START_TEST(test_s21_RPN1) {
  char buffer[MAX_NUM] = "1/0";
  double result = 0;

  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, INFINITY);
}
END_TEST;

// 86+37*4/2

START_TEST(test_s21_RPN2) {
  char buffer[MAX_NUM] = "45-(56+9)*2-44";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, -129);
}
END_TEST;

START_TEST(test_s21_RPN3) {
  char buffer[MAX_NUM] = "((54-96)+44)*21-44+(31-6)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 23);
}
END_TEST;

START_TEST(test_s21_RPN4) {
  char buffer[MAX_NUM] = "47-64*(21/6)+56*7";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 215);
}
END_TEST;

START_TEST(test_s21_RPN5) {
  char buffer[MAX_NUM] = "47-64*(21/9)+56*7";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  int code = 0;
  if (fabs(result - 289.667) < 0.001) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

START_TEST(test_s21_RPN6) {
  char buffer[MAX_NUM] = "45+9*sin(0.5)-4";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  int code = 0;
  if (fabs(result - 45.3148) < 0.001) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

START_TEST(test_s21_RPN7) {
  char buffer[MAX_NUM] = "4*(78-6)-sqrt(49)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 281);
}
END_TEST;

START_TEST(test_s21_RPN8) {
  char buffer[MAX_NUM] = "9-9";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 0);
}
END_TEST;

START_TEST(test_s21_RPN9) {
  char buffer[MAX_NUM] = "45-(56+9)*(x)";
  double X = -4;
  double result = 0;
  validator(buffer);
  calculator_XY(buffer, &result, X);
  int code = 0;
  if (fabs(result - 305) < 0.001) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

START_TEST(test_s21_RPN10) {
  char buffer[MAX_NUM] = "9-9";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 0);
}
END_TEST;

START_TEST(test_s21_RPN11) {
  char buffer[MAX_NUM] = "9-9";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 0);
}
END_TEST;

START_TEST(test_s21_RPN12) {
  char buffer[MAX_NUM] = "3^2";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 9);
}
END_TEST;

START_TEST(test_s21_RPN13) {
  char buffer[MAX_NUM] = "log(10)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 1);
}
END_TEST;

START_TEST(test_s21_RPN14) {
  char buffer[MAX_NUM] = "ln(1)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 0);
}
END_TEST;

START_TEST(test_s21_RPN15) {
  char buffer[MAX_NUM] = "sin(0.50)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  int code = 0;
  if (fabs(result - 0.4794255386) < 0.001) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

START_TEST(test_s21_RPN16) {
  char buffer[MAX_NUM] = "cos(0.50)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  int code = 0;
  if (fabs(result - 0.87758256189) < 0.001) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

START_TEST(test_s21_RPN17) {
  char buffer[MAX_NUM] = "tan(0.1)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  int code = 0;
  if (fabs(result - 0.10033467208) < 0.001) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

START_TEST(test_s21_RPN18) {
  char buffer[MAX_NUM] = "123mod10";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  ck_assert_double_eq(result, 3);
}
END_TEST;

START_TEST(test_s21_RPN19) {
  char buffer[MAX_NUM] = "asin(0.1)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  int code = 0;
  double toler = 0.001;
  if (fabs(result - 0.10016742116156) < toler) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

START_TEST(test_s21_RPN20) {
  char buffer[MAX_NUM] = "acos(0.1)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  int code = 0;
  if (fabs(result - 1.47063) < 0.001) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

START_TEST(test_s21_RPN21) {
  char buffer[MAX_NUM] = "atan(0.1)";
  double result = 0;
  validator(buffer);
  calculator(buffer, &result);
  int code = 0;
  if (fabs(result - 0.099668652491162) < 0.001) {
    code = 1;
  }
  ck_assert_int_eq(code, 1);
}
END_TEST;

Suite *rpn_test() {
  Suite *result;
  TCase *tc_rpn;
  result = suite_create("RPN");
  tc_rpn = tcase_create("RPN");
  tcase_add_test(tc_rpn, test_s21_RPN1);
  tcase_add_test(tc_rpn, test_s21_RPN2);
  tcase_add_test(tc_rpn, test_s21_RPN3);
  tcase_add_test(tc_rpn, test_s21_RPN4);
  tcase_add_test(tc_rpn, test_s21_RPN5);
  tcase_add_test(tc_rpn, test_s21_RPN6);
  tcase_add_test(tc_rpn, test_s21_RPN7);
  tcase_add_test(tc_rpn, test_s21_RPN8);
  tcase_add_test(tc_rpn, test_s21_RPN9);
  tcase_add_test(tc_rpn, test_s21_RPN10);
  tcase_add_test(tc_rpn, test_s21_RPN11);
  tcase_add_test(tc_rpn, test_s21_RPN12);
  tcase_add_test(tc_rpn, test_s21_RPN13);
  tcase_add_test(tc_rpn, test_s21_RPN14);
  tcase_add_test(tc_rpn, test_s21_RPN15);
  tcase_add_test(tc_rpn, test_s21_RPN16);
  tcase_add_test(tc_rpn, test_s21_RPN17);
  tcase_add_test(tc_rpn, test_s21_RPN18);
  tcase_add_test(tc_rpn, test_s21_RPN19);
  tcase_add_test(tc_rpn, test_s21_RPN20);
  tcase_add_test(tc_rpn, test_s21_RPN21);
  suite_add_tcase(result, tc_rpn);
  return result;
}

int main() {
  Suite *result;
  int failed = 0;
  SRunner *runner;

  result = validator_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = rpn_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : CK_FAILURE;
}