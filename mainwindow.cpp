#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlabel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *label=new QLabel(this);
    label->setText("你好");
    label->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
