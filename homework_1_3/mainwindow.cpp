#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsTextItem"

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


void MainWindow::on_ReplaceButton_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit_2->toPlainText());
}


void MainWindow::on_AddButton_clicked()
{
        ui->plainTextEdit_2->insertPlainText(ui->plainTextEdit->toPlainText());
}


void MainWindow::on_HTMLButton_clicked()
{
    QString text = "<fontcolor='red'>Hello</font>";
    //ui->plainTextEdit->setPlainText(QGraphicsTextItem::setHtml(text)); //как это заставить работать я так и не придумал.
}

