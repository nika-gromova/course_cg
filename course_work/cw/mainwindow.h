#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "world.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_object_comboBox_activated(int index);

    void on_light_add_pushButton_clicked();

    void on_light_remove_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_doubleSpinBox_valueChanged(double arg1);

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    World *world;
    MyPaintWidget *canvas;
    int lights_count;
    int zoom;
};

#endif // MAINWINDOW_H
