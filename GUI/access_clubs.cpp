#include "access_clubs.h"
#include "ui_access_clubs.h"

access_clubs::access_clubs(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::access_clubs)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Khelaiya Club");
    ui->comboBox->addItem("Press Club");
}

access_clubs::~access_clubs()
{
    delete ui;
}
