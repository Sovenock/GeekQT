#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"

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


void MainWindow::on_commandLinkButton_clicked()
{
    ui->X1Label->clear();
    ui->X2Label->clear();
    ui->ReustLabelX1->clear();
    ui->ReustLabelX2->clear();
    qint32 a = ui->AlineInput->text().toInt();
    qint32 b = ui->BlineInput->text().toInt();
    qint32 c = ui->CLineInput->text().toInt();
    qint32 D = qPow(b,2) - (4*a*c);
    if(a == 0) {
        qint32 x = -c/b;
        ui->X1Label->setText("x = ");
        ui->ReustLabelX1->setText(QString::number(x));
    }
    else if(D > 0) {
        qint32 x1,x2;
        x1 = (-b + qSqrt(D))/(2*a);
        x2 = (-b - qSqrt(D))/(2*a);
        ui->ReustLabelX1->setText(QString::number(x1));
        ui->ReustLabelX2->setText(QString::number(x2));
        ui->X1Label->setText("x1 = ");
        ui->X2Label->setText("x2 = ");
    }
    else if(D = 0) {
        qint32 x = -b / (2*a);
        ui->X1Label->setText("x = ");
        ui->ReustLabelX1->setText(QString::number(x)); // Пока искал решение по переводу в qstring наткнулся на обсуждение, что это решение чересчур ресурсоёмкое. Есть что нибудь по легче?
    }
    else {
        ui->ReustLabelX1->setText("Не имеет корней");
    }
}

