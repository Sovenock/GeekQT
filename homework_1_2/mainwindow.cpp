#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->DegreesradioButton->clicked(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_commandLinkButton_clicked()
{
    qint32 a,b,Degree,result;
    a = ui->AlineEdit->text().toInt();
    b = ui->BlineEdit->text().toInt();
    if(ui->DegreesradioButton->isChecked()) Degree = ui->AnglelineEdit->text().toInt();
    else if(ui->RadiansradioButton->isChecked()) Degree = (ui->AnglelineEdit->text().toInt()) / (180/M_PI);
    else Degree = ui->AnglelineEdit->text().toInt();
    result = qSqrt((a*a + b*b - (2*a*b)*qCos(Degree)));
    ui->ResultLabel->setText(QString::number(result));
}

