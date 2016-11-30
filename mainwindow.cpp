#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlabel.h>
#include "qaction.h"
#include "qmenubar.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveActionClick()
{
    qApp->quit();
}
