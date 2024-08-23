#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDoubleSpinBox>
#include <QInputDialog>
#include <QMainWindow>
#include <QVector>
#include <cstring>
#include <string>

extern "C" {
#include "../../calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

private slots:
  void connects();
  void digits_numbers();
  void on_pushButton_equal_clicked();
  void on_pushButton_clear_GR_clicked();
  void on_pushButton_clean_clicked();
  void on_pushButton_ac_clicked();
  void on_pushButton_do_graph_clicked();
  //    void on_pushButton_clicked();
  void on_calculate_credit_clicked();
  void on_calculate_credit_clear_clicked();
  void on_calculate_credit_d_clicked();
  void on_differ_clear_clicked();
};
#endif // MAINWINDOW_H
