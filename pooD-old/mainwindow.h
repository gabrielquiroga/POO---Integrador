#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "baserobot.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
 BaseRobot base;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_dial_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_dial_2_sliderMoved(int position);

    void on_dial_3_valueChanged(int value);

    void on_horizontalSlider_3_sliderMoved(int position);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
