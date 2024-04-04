#include "on_search.h"
#include "ui_on_search.h"

on_search::on_search(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::on_search)
{
    ui->setupUi(this);
    ui->comboBox->addItem("ID");
    ui->comboBox->addItem("Student Name");
    ui->comboBox->addItem("Club");
}

on_search::~on_search()
{
    delete ui;
}
