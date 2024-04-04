#ifndef ON_SEARCH_H
#define ON_SEARCH_H

#include <QDialog>

namespace Ui {
class on_search;
}

class on_search : public QDialog
{
    Q_OBJECT

public:
    explicit on_search(QWidget *parent = nullptr);
    ~on_search();

private:
    Ui::on_search *ui;
};

#endif // ON_SEARCH_H
