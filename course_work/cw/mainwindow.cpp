#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QToolTip>
#include <QtCore>
#include <QKeyEvent>
#include <QLocale>
#include <QRegExp>

#include "vector3d.h"
#include "maths.h"
#include "sphere.h"
#include "constants.h"

const int key_enter = 16777220;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    double_valid(QRegExp("^[-]{0,1}\\d{0,}\\.\\d{0,}$")),
    zero_one_valid(QRegExp("^[-]{0,1}[0-1]\\.\\d{0,}$"))
{
    ui->setupUi(this);
    ui->object_comboBox->addItem(tr("сфера"));
    ui->object_comboBox->addItem(tr("параллелепипед"));
    ui->object_comboBox->addItem(tr("правильная четырехугольная пирамида"));
    ui->object_comboBox->addItem(tr("конус"));
    ui->object_comboBox->addItem(tr("цилиндр"));
    ui->object_comboBox->addItem(tr("тор"));
    ui->stackedWidget->setCurrentWidget(ui->sphere);

    ui->sphere_pos_pushButton->setToolTip("положение: <b>центр</b> сферы.\n");

    ui->horizontalSlider->setRange(-100, 100);
    ui->doubleSpinBox->setRange(-100, 100);
    ui->doubleSpinBox->setDecimals(-10);
    ui->horizontalSlider->setValue(-10);

    ui->x_pos->setValidator(&double_valid);
    ui->y_pos->setValidator(&double_valid);
    ui->z_pos->setValidator(&double_valid);
    ui->object_r->setValidator(&zero_one_valid);
    ui->object_g->setValidator(&zero_one_valid);
    ui->object_b->setValidator(&zero_one_valid);

    // sphere
    ui->sphere_radius->setValidator(&double_valid);

    // box
    ui->box_length->setValidator(&double_valid);
    ui->box_width->setValidator(&double_valid);
    ui->box_height->setValidator(&double_valid);

    // lights
    ui->light_x_pos->setValidator(&double_valid);
    ui->light_y_pos->setValidator(&double_valid);
    ui->light_z_pos->setValidator(&double_valid);
    ui->light_r->setValidator(&zero_one_valid);
    ui->light_g->setValidator(&zero_one_valid);
    ui->light_b->setValidator(&zero_one_valid);
    ui->light_intensity->setValidator(&zero_one_valid);

    canvas = new MyPaintWidget(ui->draw_widget);
    canvas->setMinimumSize(ui->draw_widget->width(), ui->draw_widget->height());
    canvas->set_Qimage(ui->draw_widget->width(), ui->draw_widget->height());

    world = new World(ui->draw_widget->width(), ui->draw_widget->height(), 1);
    world->set_my_paint_widget(canvas);

    zoom = -10;

    // testing
    /*
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
    */
    // end testing

    lights_count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_object_comboBox_activated(int index)
{
    switch (index) {
    case SPHERE:
        ui->stackedWidget->setCurrentWidget(ui->sphere);
        break;
    case BOX:
        ui->stackedWidget->setCurrentWidget(ui->box);
        break;
    case PYRAMID:
        ui->stackedWidget->setCurrentWidget(ui->pyramid);
        break;
    case CONE:
        ui->stackedWidget->setCurrentWidget(ui->cone);
        break;
    case CYLINDER:
        ui->stackedWidget->setCurrentWidget(ui->cylinder);
        break;
    case TORI:
        ui->stackedWidget->setCurrentWidget(ui->tori);
        break;
    default:
        break;
    }
}

void MainWindow::on_light_add_pushButton_clicked()
{
    bool ok = false;
    RGBColor cur_color(ui->light_r->text().toDouble(&ok), ui->light_g->text().toDouble(&ok), ui->light_b->text().toDouble(&ok));
    Point3D position(ui->light_x_pos->text().toDouble(&ok), ui->light_y_pos->text().toDouble(&ok), ui->light_z_pos->text().toDouble(&ok));
    Light *light = new Light(ui->light_intensity->text().toDouble(&ok), cur_color, position);
    world->add_light(light);
    QString name = "источник № " + QString("%1").arg(lights_count);
    ui->listWidget->addItem(name);
    lights_count++;
    world->render(zoom);
}

void MainWindow::on_object_remove_pushButton_clicked()
{
    bool changed = false;
    int obj_index = ui->listWidget_2->currentRow();
    if (obj_index != -1)
    {
        changed = true;
        world->remove_object(obj_index);
        qDeleteAll(ui->listWidget_2->selectedItems());
    }
    if (changed)
        world->render(zoom);
}


void MainWindow::on_light_remove_pushButton_clicked()
{
    bool changed = false;
    int light_index = ui->listWidget->currentRow();
    if (light_index != -1)
    {
        changed = true;
        world->remove_light(light_index);
        qDeleteAll(ui->listWidget->selectedItems());
    }
    if (changed)
        world->render(zoom);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->doubleSpinBox->setValue(value);
    zoom = value;
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->horizontalSlider->setValue(arg1);
    zoom = arg1;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return || event->key() == key_enter)
    {
        int tmp = ui->horizontalSlider->value();
        world->render(tmp);
    }
}



void MainWindow::on_obj_add_pushButton_clicked()
{
    bool ok;
    QString name;
    // сначала материал
    RGBColor cur_color(ui->object_r->text().toDouble(&ok), ui->object_g->text().toDouble(&ok), ui->object_b->text().toDouble(&ok));

    Material *m = new Material();
    m->color = cur_color;

    int index = ui->object_comboBox->currentIndex();
    switch(index) {
    case SPHERE:
        name = "сфера № " + QString("%1").arg(objects_count[SPHERE]);
        objects_count[SPHERE]++;
        ui->listWidget_2->addItem(name);
        GeometricObject *sphere = new Sphere(Point3D(ui->x_pos->text().toDouble(&ok), ui->y_pos->text().toDouble(&ok), ui->z_pos->text().toDouble(&ok)), ui->sphere_radius->text().toDouble(&ok));
        sphere->set_material(m);
        world->add_object(sphere);
        break;
    }

    world->render(zoom);
}
