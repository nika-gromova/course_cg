#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QToolTip>
#include <QKeyEvent>

#include "vector3d.h"
#include "maths.h"
#include "sphere.h"

const int key_enter = 16777220;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->object_comboBox->addItem(tr("сфера"));
    ui->object_comboBox->addItem(tr("параллелепипед"));
    ui->object_comboBox->addItem(tr("правильная четырехугольная пирамида"));
    ui->object_comboBox->addItem(tr("конус"));
    ui->object_comboBox->addItem(tr("цилиндр"));
    ui->object_comboBox->addItem(tr("тор"));

    ui->sphere_pos_pushButton->setToolTip("положение: <b>центр</b> сферы.\n");

    ui->horizontalSlider->setRange(-100, 100);
    ui->doubleSpinBox->setRange(-100, 100);
    ui->doubleSpinBox->setDecimals(0);

    canvas = new MyPaintWidget(ui->draw_widget);
    canvas->setMinimumSize(ui->draw_widget->width(), ui->draw_widget->height());
    canvas->set_Qimage(ui->draw_widget->width(), ui->draw_widget->height());

    world = new World(ui->draw_widget->width(), ui->draw_widget->height(), 1);
    world->set_my_paint_widget(canvas);

    zoom = -10;

    GeometricObject *first_sphere = new Sphere(Point3D(0.0, 0.0, 5.0), 2);
    Material *m = new Material();
    m->color = RED;
    first_sphere->set_material(m);
    GeometricObject *second_sphere = new Sphere(Point3D(0.0, -5.0, 3.0), 1);
    Material *m2 = new Material();
    m2->color = WHITE;
    second_sphere->set_material(m2);

    world->add_object(first_sphere);
    world->add_object(second_sphere);

    lights_count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_object_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        ui->stackedWidget->setCurrentWidget(ui->sphere);
        break;
    case 1:
        ui->stackedWidget->setCurrentWidget(ui->box);
        break;
    case 2:
        ui->stackedWidget->setCurrentWidget(ui->pyramid);
        break;
    case 3:
        ui->stackedWidget->setCurrentWidget(ui->cone);
        break;
    case 4:
        ui->stackedWidget->setCurrentWidget(ui->cylinder);
        break;
    case 5:
        ui->stackedWidget->setCurrentWidget(ui->tori);
        break;
    default:
        break;
    }
}

void MainWindow::on_light_add_pushButton_clicked()
{
    lights_count++;
    ui->listWidget->addItem(ui->ligth_name->text());
}

void MainWindow::on_light_remove_pushButton_clicked()
{
    lights_count--;
    qDeleteAll(ui->listWidget->selectedItems());
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->doubleSpinBox->setValue(value);
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == key_enter)
    {
        int tmp = ui->horizontalSlider->value();
        if (tmp != zoom)
        {
            world->render(tmp);
            zoom = tmp;
        }
    }
}


