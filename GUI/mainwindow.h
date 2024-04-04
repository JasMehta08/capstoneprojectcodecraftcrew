#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "on_search.h"
#include "access_clubs.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    on_search  *search;
    access_clubs *access;

};
#endif // MAINWINDOW_H
