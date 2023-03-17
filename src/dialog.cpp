#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
}

Dialog::~Dialog() { delete ui; }

void Dialog::get_polish(s21_stack_char *res) { s21_copy_stack(*res, &result); }

void Dialog::on_draw_clicked() {
  QVector<double> x(1000), y(1000);
  double x_min = ui->x_min->value();
  double x_max = ui->x_max->value();
  double y_min = ui->y_min->value();
  double y_max = ui->y_max->value();
  s21_stack_char TMP1;
  s21_init_stack_char(&TMP1);
  int normal = 1;
  if(x_min <= x_max && y_min <= y_max) {
      if (result.is_x > 0) {
          double del = (fabs(x_max - x_min)) / 1000.0;
          int j = 0;
          for (double i = x_min; j < 1000; i += del, j++) {
              s21_remove_stack_char(&TMP1);
              s21_copy_stack(result, &TMP1);
              x[j] = i;
              y[j] = s21_calculation(&TMP1, &i);
              if (isinf(y[j]) && TMP1.is_correct == -1) {
                  y[j] = nan("");
                  TMP1.is_correct = 1;
              }
              normal &= TMP1.is_correct;
          }
      } else {
          s21_remove_stack_char(&TMP1);
          s21_copy_stack(result, &TMP1);
          double tmp_y = s21_calculation(&TMP1, NULL);
          double del = (fabs(x_max) + fabs(x_min)) / 1000.0;
          int j = 0;
          for (double i = x_min; j < 1000; i += del, j++) {
              x[j] = i;
              y[j] = tmp_y;
          }
          normal &= TMP1.is_correct;
      }
      if (normal == 1) {
          ui->plot->addGraph();
          ui->plot->graph(0)->setData(x, y);
          ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
          ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
          ui->plot->axisRect()->setAutoMargins(QCP::msNone);
          ui->plot->xAxis->setRange(x_min, x_max);
          ui->plot->yAxis->setRange(y_min, y_max);
          ui->plot->replot();
      } else {
          QMessageBox::warning(this, "Ошибка: некорректные значения",
                               "Обнаружены некорректные значения оси ординат. "
                               "Отредактируйте значения!");
      }
  } else {
      QMessageBox::warning(this, "Ошибка: некоректный диапозон",
                           "Обнаружены некорректные значения в диапазоне. "
                           "Отредактируйте значения!");
  }
  s21_remove_stack_char(&TMP1);
}
