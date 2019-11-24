#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExpValidator>
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

    void on_obj_add_pushButton_clicked();

    void on_object_remove_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QRegExpValidator double_valid;
    QRegExpValidator zero_one_valid;
    World *world;
    MyPaintWidget *canvas;
    int lights_count;
    int objects_count[OBJECTS_TOTAL] = {0};
    int zoom;


    Material glass;
    Material metal;
    Material mirror;
    Material ivory;
    Material plastic;
    Material rubber;
};

#endif // MAINWINDOW_H
