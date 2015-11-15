#include "showyout.h"
#include "ui_showyout.h"

ShowYout::ShowYout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowYout)
{
    ui->setupUi(this);

    QImage *imageObject = new QImage;
    int imageLabelWidth = ui->imageLabel->width();
    int imageLabelHeight = ui->imageLabel->height();
    for(int i = 0; i < 5; i++)
    {
        QString filename = "C:/Users/Woojung/Documents/User1/" + QString::number(i) + ".jpg";//경로 표시할 때 / 써야함
        imageObject->load(filename);
        images[i] = QPixmap::fromImage(*imageObject).scaled(imageLabelWidth, imageLabelHeight);
    }

}

void ShowYout::printyout(int a)
{
    ui->imageLabel->setPixmap(images[a]);
}

ShowYout::~ShowYout()
{
    delete ui;
}
