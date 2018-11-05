#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "efectorfinal.h"
#include "Conjunto.h"
#include "baserobot.h"
#include <iostream>
#include <string>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//------------------------Art1-----------------------------

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->lcdNumber->display(position);
   string informe=base.iniciar_movimiento(1,position,base.get_vel(1));
   ui->plainTextEdit->ensureCursorVisible();
   ui->plainTextEdit->appendPlainText(QString::fromStdString(informe));
}

void MainWindow::on_dial_sliderMoved(int vel)
{
 ui->lcdNumber_2->display(vel);

    base.set_vel(1,vel);
}
//------------------------Art2-----------------------------
void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    ui->lcdNumber_4->display(position);
   string informe=base.iniciar_movimiento(2,position,base.get_vel(2));
   ui->plainTextEdit_2->ensureCursorVisible();
   ui->plainTextEdit_2->appendPlainText(QString::fromStdString(informe));
}


void MainWindow::on_dial_2_sliderMoved(int vel)
{
    ui->lcdNumber_3->display(vel);

       base.set_vel(2,vel);
}
//------------------------Art3-----------------------------


void MainWindow::on_dial_3_valueChanged(int value)
{
    ui->lcdNumber_5->display(value);

    base.set_vel(3,value);
}

void MainWindow::on_horizontalSlider_3_sliderMoved(int position)
{
    ui->lcdNumber_6->display(position);
    string informe=base.iniciar_movimiento(2,position,base.get_vel(3));
    ui->plainTextEdit_3->ensureCursorVisible();
    ui->plainTextEdit_3->appendPlainText(QString::fromStdString(informe));
}

