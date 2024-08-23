#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  connects();
  on_pushButton_do_graph_clicked();
}

void MainWindow::connects() {
  ui->setupUi(this);
  // THERE ARE  NUMBERS
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  // THERE ARE OPERATIONS
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_divis, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  // THERE ARE BRACKETS
  connect(ui->pushButton_brack1, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_brack2, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  // THERE ARE FUNCTIONS
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  // THERE ARE OTHER
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ac, SIGNAL(clicked()), this,
          SLOT(on_pushButton_ac_clicked()));
}

void MainWindow::on_pushButton_do_graph_clicked() {
  ui->CustomPlot->clearGraphs();
  QVector<double> x;
  QVector<double> y;
  x.clear();
  y.clear();
  double result_Y = 0;

  QString strq = ui->label->text();
  //  strq += "=";
  QByteArray strbyteArray = strq.toUtf8();
  char *str = strbyteArray.data();

  double dbl_numb_X = ui->doubleSpinBox_X->value();
  double dbl_last_X = ui->doubleSpinBox_last_X->value();

  if (dbl_numb_X < dbl_last_X) {
    for (double i = dbl_numb_X; i <= dbl_last_X; i += 0.1) {
      int code = calculator_XY(str, &result_Y, i);
      if (code == 1) {
        x.push_back(i);
        y.push_back(result_Y);
      }
    }
    ui->CustomPlot->addGraph();
    ui->CustomPlot->xAxis->setLabel("X");
    ui->CustomPlot->yAxis->setLabel("Y");
    ui->CustomPlot->graph(0)->setData(x, y);
    ui->CustomPlot->replot();
    ui->CustomPlot->update();
    ui->CustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                                    QCP::iSelectPlottables);
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  ui->label->setText(ui->label->text() + button->text());
}

void MainWindow::on_pushButton_equal_clicked() {
  QString expression = ui->label->text();
  if (expression.isEmpty()) {
    return;
  }
  double result = 0;
  QString strq = ui->label->text();
  //  strq += "=";
  QByteArray strbyteArray = strq.toUtf8();
  char *str = strbyteArray.data();
  int code = calculator(str, &result); //*result
  if (code == 1) {
    QString resultQ = QString::number(result, 'g', 15);
    ui->label->setText(resultQ);
  } else {
    ui->label->setText("ERROR");
    return;
  }
}

void MainWindow::on_pushButton_clear_GR_clicked() {
  if (ui->CustomPlot && ui->CustomPlot->graphCount() > 0) {
    ui->CustomPlot->graph(0)->data()->clear();
    ui->CustomPlot->replot();
    ui->CustomPlot->update();
    ui->CustomPlot->clearGraphs();
  }
  if (ui->doubleSpinBox_X) {
    ui->doubleSpinBox_X->clear();
  }
  if (ui->doubleSpinBox_X) {
    ui->doubleSpinBox_last_X->clear();
  }
}

void MainWindow::on_pushButton_clean_clicked() {
  QString final = ui->label->text();
  final.chop(1);
  ui->label->setText(final);
}

void MainWindow::on_pushButton_ac_clicked() { ui->label->clear(); }

/*---------------------КРЕДИТНЫЙ АННУИТЕТНЫЙ---------------------*/
void MainWindow::on_calculate_credit_clicked() {
  //    аннуитентная схема
  double sum_cr = ui->QLineEdit_sum_cr->text().toDouble(); //сумма кредита

  double rate = ui->interest_rate->text().toDouble(); // процентная ставка
  rate = rate / 12 / 100;

  double term = ui->term->text().toDouble(); //срок
  double monthly_pay =
      sum_cr *
      (rate + (rate / (pow(1 + rate, term) - 1))); // ежемесячный платеж

  QString mon_pay_s = QString::number(monthly_pay, 'f', 3);
  ui->monthly_payment->setText(mon_pay_s);

  double total_payout = monthly_pay * term; // общая выплата
  QString total_payout_s = QString::number(total_payout, 'f', 3);
  ui->total_payout->setText(total_payout_s);

  double over_payment = monthly_pay * term - sum_cr; // переплата по кредиту
  QString over_payment_s = QString::number(over_payment, 'f', 3);
  ui->overpayment->setText(over_payment_s);
}

void MainWindow::on_calculate_credit_clear_clicked() {
  if (ui->QLineEdit_sum_cr) {
    ui->QLineEdit_sum_cr->clear();
  }
  if (ui->term) {
    ui->term->clear();
  }
  if (ui->interest_rate) {
    ui->interest_rate->clear();
  }
  if (ui->monthly_payment) {
    ui->monthly_payment->clear();
  }
  if (ui->overpayment) {
    ui->overpayment->clear();
  }
  if (ui->total_payout) {
    ui->total_payout->clear();
  }
}

/*---------------------КРЕДИТНЫЙ ДИФФЕРЕНЦИРОВАННЫЙ---------------------*/

void MainWindow::on_calculate_credit_d_clicked() {
  double sum_cr = ui->sum_cr_d->text().toDouble(); // сумма кредита
  double term_d_d = ui->term_d->text().toDouble(); // срок
  double rate = ui->interest_rate_d->text().toDouble(); // процентная ставка
  rate = rate / 12 / 100;

  ui->tableWidget->setRowCount(term_d_d);
  ui->tableWidget->setColumnCount(2);
  ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Номер платежа"
                                                           << "Сумма платежа");
  double rem_sum = sum_cr;
  double month_pay = 0;
  double share_res = 0;
  double full_mon_pay = 0;
  double total_pay = 0;
  double overpayment = 0;

  for (int i = 1; i <= term_d_d; i++) {
    month_pay = sum_cr / term_d_d;
    share_res = rem_sum * rate;
    full_mon_pay = month_pay + share_res; //ежемесячная плата с процентами

    QString full_mon_pay_s = QString::number(full_mon_pay, 'f', 2);
    QTableWidgetItem *tbl1 = new QTableWidgetItem(QString::number(i));
    QTableWidgetItem *tbl2 = new QTableWidgetItem(full_mon_pay_s);
    ui->tableWidget->setItem(i - 1, 0, tbl1);
    ui->tableWidget->setItem(i - 1, 1, tbl2);
    rem_sum -= month_pay;
    total_pay += full_mon_pay; //общая выплата НЕ ТРОГАЙ
    rate = ui->interest_rate_d->text().toDouble() / 12 / 100;
    overpayment = total_pay - sum_cr;
  }

  QString total_pay_s = QString::number(total_pay, 'f', 2);
  ui->total_payout_d->setText(total_pay_s);

  QString overpayment_s = QString::number(overpayment, 'f', 2);
  ui->overpayment_d->setText(overpayment_s);
}

void MainWindow::on_differ_clear_clicked() {
  //    if(ui->QLineEdit_sum_cr) {
  //        ui->QLineEdit_sum_cr->clear();

  //    }
  if (ui->sum_cr_d) {
    ui->sum_cr_d->clear();
  }
  if (ui->term_d) {
    ui->term_d->clear();
  }
  if (ui->interest_rate_d) {
    ui->interest_rate_d->clear();
  }
  if (ui->overpayment_d) {
    ui->overpayment_d->clear();
  }
  if (ui->total_payout_d) {
    ui->total_payout_d->clear();
  }
  if (ui->tableWidget) {
    ui->tableWidget->clear();
  }
}
