#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "on_search.h"
#include "access_clubs.h"
#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    search = new on_search(this);
    search->show();
}





void MainWindow::on_pushButton_2_clicked()
{
    access = new access_clubs(this);
    access->show();
}

