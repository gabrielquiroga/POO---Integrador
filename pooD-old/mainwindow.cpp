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
   string informe=base.iniciar_movimiento(0,position,base.get_vel(0));
   ui->plainTextEdit->ensureCursorVisible();
   ui->plainTextEdit->appendPlainText(QString::fromStdString(informe));
   ui->plainTextEdit->moveCursor(QTextCursor::End);
}


void MainWindow::on_dial_sliderMoved(int vel)
{
 ui->lcdNumber_2->display(vel);

    base.set_vel(0,vel);
}
//------------------------Art2-----------------------------
void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    ui->lcdNumber_4->display(position);
   string informe=base.iniciar_movimiento(1,position,base.get_vel(1));
   ui->plainTextEdit_2->ensureCursorVisible();
   ui->plainTextEdit_2->appendPlainText(QString::fromStdString(informe));
   ui->plainTextEdit_2->moveCursor(QTextCursor::End);
}


void MainWindow::on_dial_2_sliderMoved(int vel)
{
    ui->lcdNumber_3->display(vel);

       base.set_vel(1,vel);
}
//------------------------Art3-----------------------------


void MainWindow::on_horizontalSlider_3_sliderMoved(int position)
{
    ui->lcdNumber_6->display(position);
    string informe=base.iniciar_movimiento(2,position,base.get_vel(2));
    ui->plainTextEdit_3->ensureCursorVisible();
    ui->plainTextEdit_3->appendPlainText(QString::fromStdString(informe));
    ui->plainTextEdit_3->moveCursor(QTextCursor::End);
}

void MainWindow::on_dial_3_valueChanged(int value)
{
    ui->lcdNumber_5->display(value);

    base.set_vel(2,value);
}

//----------------------radioButton----------------------------

void MainWindow::on_radioButton_toggled(bool checked)
{
    int posicion=0, velocidad=0;
    if (checked == 1) {
        base.set_estado("Activo");
        this->on_dial_sliderMoved(velocidad);
        ui->dial->setSliderPosition(velocidad);
        this->on_horizontalSlider_sliderMoved(posicion);
        ui->horizontalSlider->setSliderPosition(posicion);
        this->on_dial_2_sliderMoved(velocidad);
        ui->dial_2->setSliderPosition(velocidad);
        this->on_horizontalSlider_2_sliderMoved(posicion);
        ui->horizontalSlider_2->setSliderPosition(posicion);
        this->on_dial_3_valueChanged(velocidad);
        ui->dial_3->setSliderPosition(velocidad);
        this->on_horizontalSlider_3_sliderMoved(posicion);
        ui->horizontalSlider_3->setSliderPosition(posicion);
    }
    else
    {
        base.set_estado("Inactivo");
        ui->plainTextEdit->clear();
        ui->plainTextEdit_2->clear();
        ui->plainTextEdit_3->clear();
    }
}

//------------------pushButton-----------------------

void MainWindow::on_pushButton_clicked()
{
    int **datos;
    int tam, i;
    tam = base.get_tam_archivo();
    datos = base.leer_comando(tam);
    for (i=0;i<tam;i++) {
        if (datos[i][0] == 0) {
            this->on_dial_sliderMoved(datos[i][2]);
            ui->dial->setSliderPosition(datos[i][2]);
            this->on_horizontalSlider_sliderMoved(datos[i][1]);
            ui->horizontalSlider->setSliderPosition(datos[i][1]);
        }
        else if (datos[i][0] == 1) {
            this->on_dial_2_sliderMoved(datos[i][2]);
            ui->dial_2->setSliderPosition(datos[i][2]);
            this->on_horizontalSlider_2_sliderMoved(datos[i][1]);
            ui->horizontalSlider_2->setSliderPosition(datos[i][1]);
        }
        else if (datos[i][0] == 2) {
            this->on_dial_3_valueChanged(datos[i][2]);
            ui->dial_3->setSliderPosition(datos[i][2]);
            this->on_horizontalSlider_3_sliderMoved(datos[i][1]);
            ui->horizontalSlider_3->setSliderPosition(datos[i][1]);
        }
    }

    for (int i=0;i<tam;i++) {
        delete datos[i];
    }
    delete datos;
}
