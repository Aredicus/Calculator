#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "dialog.h"
#include <QKeyEvent>
#include <QMainWindow>
#include <stdlib.h>

extern "C" {
#include "c/Main_logic/s21_calc.h"
#include "c/Polish_notation/s21_calculation.h"
#include "c/Polish_notation/s21_parser.h"
#include "c/Stacks/s21_stack_char.h"
#include "c/Stacks/s21_stack_double.h"
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
}

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow {
  Q_OBJECT

public:
  Calculator(QWidget *parent = nullptr);
  ~Calculator();

private slots:
  void on_pushButton_1_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_0_clicked();

  void on_pushButton_left_clicked();

  void on_pushButton_right_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_sqrt_clicked();

  void on_pushButton_Pi_clicked();

  void on_pushButton_e_clicked();

  void on_pushButton_point_clicked();

  void on_pushButton_div_clicked();

  void on_pushButton_add_clicked();

  void on_pushButton_sub_clicked();

  void on_pushButton_mul_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_pow_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_atan_clicked();

  void on_Result_clicked();

  void on_Clear_clicked();

  void keyPressEvent(QKeyEvent *e);

  void on_Graph_clicked();

  void on_pushButton_x_clicked();

  void on_pushButton_exit_clicked();

  void on_total_credit_clicked();

  void on_add_put_clicked();

  void on_add_get_clicked();

  void on_total_depos_clicked();

private:
  Ui::Calculator *ui;

  std::vector<std::pair<std::pair<long long, int>, QDate>> del;

signals:
  void send_polish(s21_stack_char *result);
};
#endif // CALCULATOR_H
