#ifndef SHOWYOUT_H
#define SHOWYOUT_H

#include <QDialog>
#include <QPixmap>
#include <QImage>

namespace Ui {
class ShowYout;
}

class ShowYout : public QDialog
{
    Q_OBJECT

public:
    explicit ShowYout(QWidget *parent = 0);
    void printyout(int a);
    ~ShowYout();

private:
    Ui::ShowYout *ui;
    QPixmap images[5];
};

#endif // SHOWYOUT_H
