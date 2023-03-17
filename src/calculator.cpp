#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);
}

Calculator::~Calculator() { delete ui; }

void Calculator::on_pushButton_1_clicked() { ui->Input->insertPlainText("1"); }

void Calculator::on_pushButton_3_clicked() { ui->Input->insertPlainText("3"); }

void Calculator::on_pushButton_2_clicked() { ui->Input->insertPlainText("2"); }

void Calculator::on_pushButton_4_clicked() { ui->Input->insertPlainText("4"); }

void Calculator::on_pushButton_5_clicked() { ui->Input->insertPlainText("5"); }

void Calculator::on_pushButton_6_clicked() { ui->Input->insertPlainText("6"); }

void Calculator::on_pushButton_7_clicked() { ui->Input->insertPlainText("7"); }

void Calculator::on_pushButton_8_clicked() { ui->Input->insertPlainText("8"); }

void Calculator::on_pushButton_9_clicked() { ui->Input->insertPlainText("9"); }

void Calculator::on_pushButton_0_clicked() { ui->Input->insertPlainText("0"); }

void Calculator::on_pushButton_left_clicked() {
  ui->Input->insertPlainText("(");
}

void Calculator::on_pushButton_right_clicked() {
  ui->Input->insertPlainText(")");
}

void Calculator::on_pushButton_log_clicked() {
  ui->Input->insertPlainText("log()");
}

void Calculator::on_pushButton_ln_clicked() {
  ui->Input->insertPlainText("ln()");
}

void Calculator::on_pushButton_sqrt_clicked() {
  ui->Input->insertPlainText("sqrt()");
}

void Calculator::on_pushButton_Pi_clicked() {
  ui->Input->insertPlainText("Pi");
}

void Calculator::on_pushButton_e_clicked() { ui->Input->insertPlainText("e"); }

void Calculator::on_pushButton_point_clicked() {
  ui->Input->insertPlainText(".");
}

void Calculator::on_pushButton_div_clicked() {
  ui->Input->insertPlainText("/");
}

void Calculator::on_pushButton_add_clicked() {
  ui->Input->insertPlainText("+");
}

void Calculator::on_pushButton_sub_clicked() {
  ui->Input->insertPlainText("-");
}

void Calculator::on_pushButton_mul_clicked() {
  ui->Input->insertPlainText("*");
}

void Calculator::on_pushButton_cos_clicked() {
  ui->Input->insertPlainText("cos()");
}

void Calculator::on_pushButton_acos_clicked() {
  ui->Input->insertPlainText("acos()");
}

void Calculator::on_pushButton_pow_clicked() {
  ui->Input->insertPlainText("^");
}

void Calculator::on_pushButton_sin_clicked() {
  ui->Input->insertPlainText("sin()");
}

void Calculator::on_pushButton_asin_clicked() {
  ui->Input->insertPlainText("asin()");
}

void Calculator::on_pushButton_mod_clicked() {
  ui->Input->insertPlainText("mod()");
}

void Calculator::on_pushButton_tan_clicked() {
  ui->Input->insertPlainText("tan()");
}

void Calculator::on_pushButton_atan_clicked() {
  ui->Input->insertPlainText("atan()");
}

void Calculator::on_Result_clicked() {
  QString mainLine = ui->Input->toPlainText();
  char mainInput[512] = {'\0'};
  strncpy(mainInput, mainLine.toLocal8Bit().data(), 255);
  if (strcmp(mainInput, "") == 0) {
      ui->Output->setPlainText("Пустая строка");
  } else {
    char *res = s21_calc(mainInput, ui->set_x->value());
    ui->Output->setPlainText(res);
    free(res);
  }
}

void Calculator::keyPressEvent(QKeyEvent *e) {
  switch (e->key()) {
  case Qt::Key_Equal:
    on_Result_clicked();
    break;
  }
}

void Calculator::on_Clear_clicked() { ui->Input->setPlainText(""); }

void Calculator::on_Graph_clicked() {
  s21_stack_char TMP, RESULT;
  s21_init_stack_char(&TMP);
  s21_init_stack_char(&RESULT);
  QString mainLine = ui->Input->toPlainText();
  char mainInput[512] = {'\0'};
  strncpy(mainInput, mainLine.toLocal8Bit().data(), 255);
  s21_parse(&TMP, &RESULT, mainInput);
  if (RESULT.is_correct && TMP.is_correct) {
    Dialog *dialog = new Dialog;
    connect(this, &Calculator::send_polish, dialog, &Dialog::get_polish);
    s21_reverse_stack_char(&RESULT);
    send_polish(&RESULT);
    dialog->show();
  } else {
    ui->Output->setPlainText("Некорректный ввод");
  }
  s21_remove_stack_char(&TMP);
  s21_remove_stack_char(&RESULT);
}

void Calculator::on_pushButton_x_clicked() { ui->Input->insertPlainText("x"); }

void Calculator::on_pushButton_exit_clicked() { exit(0); }

void Calculator::on_total_credit_clicked() {
  long long sum = ui->sum_credit->value();
  long double result = 0;
  int period = ui->period_credit_long->value();
  int type_period = ui->period_credit->currentIndex();
  if (type_period == 1) {
    period *= 12;
  }
  double procent = ui->procent->value();
  procent = procent / 1200.0;
  int type = ui->type_credit->currentIndex();
  if (type == 0) {
    if (procent - 0.0 > 0.0000001) {
      result = sum * (procent / (1.0 - pow((1.0 + procent), -1 * period)));
      ui->mouth_payment->setPlainText(QString::number(result, 'f', 2));
      result = result * period - sum;
      ui->over_payment->setPlainText(QString::number(result, 'f', 2));
      result = result + sum;
      ui->total_payment->setPlainText(QString::number(result, 'f', 2));
    } else {
      ui->mouth_payment->setPlainText("0");
      ui->over_payment->setPlainText("0");
      ui->total_payment->setPlainText(QString::number(sum));
    }
  } else if (type == 1) {
    double tmp = sum / period;
    long double sum_tmp = sum;
    long double res = 0;
    double proc_tmp;
    ui->mouth_payment->setPlainText("");
      for (int i = 0; i < period; ++i) {
      proc_tmp = sum_tmp * procent;
      res += proc_tmp;
      ui->mouth_payment->append(QString::number(proc_tmp + tmp, 'f', 2));
      sum_tmp -= tmp;
    }
    ui->over_payment->setPlainText(QString::number(res, 'f', 2));
    res = res + sum;
    ui->total_payment->setPlainText(QString::number(res, 'f', 2));
  }
}

void Calculator::on_add_put_clicked() {
  std::pair<std::pair<long long, int>, QDate> tmp;
  std::pair<long long, int> tmp1;
  tmp1.first = ui->money_put->value();
  tmp1.second = ui->long_period_put->currentIndex();
  tmp.first = tmp1;
  tmp.second = ui->date_put->date();
  del.push_back(tmp);
}

void Calculator::on_add_get_clicked() {

  std::pair<std::pair<long long, int>, QDate> tmp;
  std::pair<long long, int> tmp1;
  tmp1.first = -1 * ui->money_get->value();
  tmp1.second = ui->long_period_get->currentIndex();
  tmp.first = tmp1;
  tmp.second = ui->date_get->date();
  del.push_back(tmp);
}

void Calculator::on_total_depos_clicked() {
  long double sum = ui->start_money->value();
  int lon = ui->period_depo_long->value();
  if (ui->period_depos->currentIndex() == 1) {
    lon *= 12;
  }
  long double prof = 0;
  long double tmp_prof = 0;
  int period = ui->period_get_money->currentIndex();
  switch (period) {
  case 0:
    period = 1;
    break;
  case 1:
    period = 3;
    break;
  case 2:
    period = 12;
    break;
  case 3:
    period = -1;
    break;
  }
  double procent = ui->procent_depos->value() / 36500;
  int size_del = del.size();
  QDate start_date = ui->start_date->date();
  QDate tmp_date = ui->start_date->date();
  QDate end_date = start_date.addMonths(lon);
  start_date  = start_date.addMonths(period);
  for (; tmp_date < end_date; tmp_date = tmp_date.addDays(1)) {
    prof += sum * procent;
    tmp_prof += sum * procent;
    if (ui->capitalization->isChecked() && start_date == tmp_date) {
      sum += tmp_prof;
      tmp_prof = 0;
      start_date = start_date.addMonths(period);
    }
    for (int i = 0; i < size_del; i++) {
      if (del[i].second == tmp_date) {
        sum += del[i].first.first;
        switch (del[i].first.second) {
        case 1:
          del[i].second = del[i].second.addMonths(1);
          break;
        case 2:
          del[i].second = del[i].second.addMonths(3);
          break;
        case 3:
          del[i].second = del[i].second.addMonths(6);
          break;
        case 4:
          del[i].second = del[i].second.addYears(1);
          break;
        }
      }
    }
  }
  if (ui->capitalization->isChecked()) {
    sum += tmp_prof;
  }
  ui->prof_depos->setPlainText(QString::number(prof, 'f', 2));
  double nal = prof * ui->procent_nalog->value() / 100;
  ui->nalog_sum->setPlainText(QString::number(nal, 'f', 2));
  ui->total_prof->setPlainText(QString::number(sum, 'f', 2));
  del.clear();
}
