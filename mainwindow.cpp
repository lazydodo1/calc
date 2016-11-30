#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlabel.h>
#include "qaction.h"
#include "qmenubar.h"
#include "qlabel.h"
#include "qtimer.h"
#include "qdialog.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *newaction=new QAction("Save",this);
    newaction->setShortcut(QKeySequence::Save);
    newaction->setToolTip("ToolTip:Save");
    newaction->setStatusTip("StatusTip:Save");
    QMenu *newMenu=menuBar()->addMenu("File");
    newMenu->addAction(newaction );

    connect(newaction,SIGNAL(triggered(bool)),this,SLOT(saveActionClick()));
    //状态栏显示一条消息，持续指定时间
    //statusBar()->showMessage("TestMsg",3000);
    //状态栏 分栏
    QLabel *bar1= new QLabel("aaaa");
    QLabel *bar2= new QLabel("定时5秒消失");
    statusBar()->addWidget(bar1);
    statusBar()->addWidget(bar2,1);
    bar1->show();
    bar2->show();
    //定时消失
    QTimer *timer = new QTimer;
    timer->singleShot(5000,bar2,SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveActionClick()
{
    //手工定义的对话框
//    QDialog dialog(this);
//    QLabel *label=new QLabel("测试放在对话框中的控件",&dialog);
    //qt预定义的对话框
    Dialog dialog;
    //显示对话框
    //dialog.exec();
    //显示并处理返回值
    if(dialog.exec()==QDialog::Accepted)
    {
        qApp->quit();
    }
}
