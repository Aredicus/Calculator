#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

extern "C" {
#include "c/Polish_notation/s21_calculation.h"
#include "c/Polish_notation/s21_parser.h"
#include "c/Stacks/s21_stack_char.h"
#include "c/Stacks/s21_stack_double.h"
#include <ctype.h>
#include <math.h>
#include <string.h>
}

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = nullptr);
  ~Dialog();

private:
  Ui::Dialog *ui;

  s21_stack_char result;

public slots:
  void get_polish(s21_stack_char *result);

private slots:
  void on_draw_clicked();
};

#endif // DIALOG_H
