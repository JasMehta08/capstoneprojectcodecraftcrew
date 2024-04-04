#ifndef ACCESS_CLUBS_H
#define ACCESS_CLUBS_H

#include <QDialog>

namespace Ui {
class access_clubs;
}

class access_clubs : public QDialog
{
    Q_OBJECT

public:
    explicit access_clubs(QWidget *parent = nullptr);
    ~access_clubs();

private slots:
    

private:
    Ui::access_clubs *ui;
};

#endif // ACCESS_CLUBS_H
