#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QToolTip>
#include <QtCore>
#include <QKeyEvent>
#include <QLocale>
#include <QRegExp>
#include <QMessageBox>
#include <chrono>
#include <string>
#include <fstream>

#include "vector3d.h"
#include "maths.h"
#include "sphere.h"
#include "box.h"
#include "pyramid.h"
#include "cylinder.h"
#include "cone.h"
#include "tori.h"
#include "constants.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    double_valid(QRegExp("^[-]{0,1}\\d{0,}\\.\\d{0,}$")),
    zero_one_valid(QRegExp("^[-]{0,1}[0-1]\\.\\d{0,}$"))
{
    ui->setupUi(this);

    ui->object_comboBox->addItem(tr("шар"));
    ui->object_comboBox->addItem(tr("параллелепипед"));
    ui->object_comboBox->addItem(tr("правильная четырехугольная пирамида"));
    ui->object_comboBox->addItem(tr("конус"));
    ui->object_comboBox->addItem(tr("цилиндр"));
    ui->object_comboBox->addItem(tr("тор"));
    ui->stackedWidget->setCurrentWidget(ui->sphere);

    ui->sphere_pos_pushButton->setToolTip("<img src=':/files/images/sphere.png'>");
    ui->box_pos_pushButton->setToolTip("<img src=':/files/images/box.jpg'>");
    ui->pyramid_pos_pushButton->setToolTip("<img src=':/files/images/pyramid.jpg'>");
    ui->cone_pos_pushButton->setToolTip("<img src=':/files/images/cone.jpg'>");
    ui->cylinder_pos_pushButton->setToolTip("<img src=':/files/images/cylinder.jpg'>");
    ui->tori_pos_pushButton->setToolTip("<img src=':/files/images/tori.jpg'>");

    ui->matherial_comboBox->addItem(tr("стекло"));
    ui->matherial_comboBox->addItem(tr("металл"));
    ui->matherial_comboBox->addItem(tr("зеркало"));
    ui->matherial_comboBox->addItem(tr("пластик"));
    ui->matherial_comboBox->addItem(tr("резина"));
    // ui->matherial_comboBox->addItem(tr("слоновая кость"));


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

    color_dialog = new QColorDialog(ui->choose_color_pushButton);

    // sphere
    ui->sphere_radius->setValidator(&double_valid);

    // box
    ui->box_length->setValidator(&double_valid);
    ui->box_width->setValidator(&double_valid);
    ui->box_height->setValidator(&double_valid);

    // pyramid
    ui->pyramid_a->setValidator(&double_valid);
    ui->pyramid_h->setValidator(&double_valid);

    // cone
    ui->cone_height->setValidator(&double_valid);
    ui->cone_radius->setValidator(&double_valid);

    // cylinder
    ui->cylinder_height->setValidator(&double_valid);
    ui->cylinder_radius->setValidator(&double_valid);

    // tori
    ui->tori_outer_radius->setValidator(&double_valid);
    ui->tori_inner_radius->setValidator(&double_valid);

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

    glass = Material(0.01, 0.20, 125, 0.79, 1.0 / 1.5);
    metal = Material(0.1, 0.7, 50, 0.0, 1.5);
    mirror = Material(0.0, 1.0, 50, 0.0, 1.5);
    ivory = Material(0.6, 0.4, 50, 0.0, 1.5);
    plastic = Material(0.8, 0.2, 100, 0.0, 1.5);
    rubber = Material(0.99, 0.01, 10, 0.0, 1.5);

    world->draw_widget->repaint();

    lights_count = 0;    
}

MainWindow::~MainWindow()
{
    delete world;
    delete canvas;
    delete ui;
}

double MainWindow::str_to_double(QString str, bool &r)
{
    r = true;
    double ret;
    bool ok = true;
    if (str.isEmpty())
        ret = 0;
    else
    {
        ret = str.toDouble(&ok);
        if (!ok)
        {
            r = false;
            QMessageBox::warning(this, "Ошибка ввода", "Неверно введено значение. Введите вещественное число");
        }
    }
    return ret;
}

void MainWindow::choose_material(Material *m, const int &index)
{
    switch (index) {
    case GLASS:
        (*m) = glass;
        break;
    case METAL:
        (*m) = metal;
        break;
    case MIRROR:
        (*m) = mirror;
        break;
    case IVORY:
        (*m) = ivory;
        break;
    case PLASTIC:
        (*m) = plastic;
        break;
    case RUBBER:
        (*m) = rubber;
        break;
    default:
        break;
    }
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
    bool ok1, ok2, ok3;
    double r = str_to_double(ui->light_r->text(), ok1);
    double g = str_to_double(ui->light_g->text(), ok2);
    double b = str_to_double(ui->light_b->text(), ok3);
    if (!ok1 || !ok2 || !ok3)
        return;
    double x = str_to_double(ui->light_x_pos->text(), ok1);
    double y = str_to_double(ui->light_y_pos->text(), ok2);
    double z = str_to_double(ui->light_z_pos->text(), ok3);
    if (!ok1 || !ok2 || !ok3)
        return;

    RGBColor cur_color(r, g, b);
    Point3D position(x, y, z);

    double I = str_to_double(ui->light_intensity->text(), ok1);
    if (!ok1)
        return;

    add_light(position, cur_color, I);

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
    zoom = static_cast<int>(arg1);
    ui->horizontalSlider->setValue(zoom);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        int tmp = ui->horizontalSlider->value();
        world->render(tmp);
    }
    if (event->key() == Qt::Key_E)
        clear_all();
}

void write_res(const std::string &name, const int& num, const double &t)
{
    std::ofstream file;
    file.open(name, std::ios_base::app);
    file << num << ';' << t << '\n';
    file.close();
}

void MainWindow::on_obj_add_pushButton_clicked()
{
    bool ok1, ok2, ok3;
    double r = str_to_double(ui->object_r->text(), ok1);
    double g = str_to_double(ui->object_g->text(), ok2);
    double b = str_to_double(ui->object_b->text(), ok3);
    double x, y, z;

    if (!ok1 || !ok2 || !ok3)
        return;

    x = str_to_double(ui->x_pos->text(), ok1);
    y = str_to_double(ui->y_pos->text(), ok2);
    z = str_to_double(ui->z_pos->text(), ok3);

    if (!ok1 || !ok2 || !ok3)
        return;
    Point3D center = Point3D(x, y, z);

    QString name;

    Material *m = new Material();
    int material_index = ui->matherial_comboBox->currentIndex();
    choose_material(m, material_index);
    RGBColor cur_color(r, g, b);
    m->color = cur_color;

    int index = ui->object_comboBox->currentIndex();
    switch(index) {
    case SPHERE:
    {
        double r = str_to_double(ui->sphere_radius->text(), ok1);
        if (!ok1)
            return;
        add_sphere(center, r, m);
        break;
    }
    case BOX:
    {
        double a = str_to_double((ui->box_length->text()), ok1);
        double b = str_to_double((ui->box_width->text()), ok2);
        double c = str_to_double((ui->box_height->text()), ok3);
        if (!ok1 || !ok2 || !ok3)
            return;
        add_box(center, a, b, c, m);
        break;
    }
    case PYRAMID:
    {
        double a = str_to_double((ui->pyramid_a->text()), ok1);
        double h = str_to_double((ui->pyramid_h->text()), ok2);
        if (!ok1 || !ok2)
            return;
        add_pyramid(center, a, h, m);
        break;
    }
    case CYLINDER:
    {
        double r = str_to_double((ui->cylinder_radius->text()), ok1);
        double h = str_to_double((ui->cylinder_height->text()), ok2);
        if (!ok1 || !ok2)
            return;
        add_cylinder(center, r, h, m);
        break;
    }
    case CONE:
    {
        double r = str_to_double((ui->cone_radius->text()), ok1);
        double h = str_to_double((ui->cone_height->text()), ok2);
        if (!ok1 || !ok2)
            return;
        add_cone(center, r, h, m);
        break;
    }
    case TORI:
    {
        double a = str_to_double((ui->tori_outer_radius->text()), ok1);
        double b = str_to_double((ui->tori_inner_radius->text()), ok1);
        if (!ok1 || !ok2)
            return;
        add_tori(center, a, b, m);
        break;
    }
    }
    world->render(zoom);

    /* замеры времени
    auto t_start = std::chrono::high_resolution_clock::now();
    for (auto i = 0; i < 10; i++)
    {
        world->render(zoom);
    }
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(t_end - t_start).count();
    write_res("num_of_glass_4.txt", world->get_obj_size(), elapsed_seconds / 10.0);
    */

}

bool MainWindow::choose_color(double &r, double &g, double &b)
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Веберете цвет");
    if (!color.isValid())
        return false;

    int ri = 0, gi = 0, bi = 0;
    color.getRgb(&ri, &gi, &bi);
    r = ri / 255.0;
    g = gi / 255.0;
    b = bi / 255.0;
    return true;
}

void MainWindow::on_choose_color_pushButton_clicked()
{
    double r, g, b;
    if (choose_color(r, g, b))
    {
        ui->object_r->setText(QString().setNum(r, 'g', 2));
        ui->object_g->setText(QString().setNum(g, 'g', 2));
        ui->object_b->setText(QString().setNum(b, 'g', 2));
    }
}

void MainWindow::on_choose_color_pushButton_2_clicked()
{
    double r, g, b;
    if (choose_color(r, g, b))
    {
        ui->light_r->setText(QString().setNum(r, 'g', 2));
        ui->light_g->setText(QString().setNum(g, 'g', 2));
        ui->light_b->setText(QString().setNum(b, 'g', 2));
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (ui->mouse_obj_checkBox->isChecked() || ui->mouse_light_checkBox->isChecked())
    {
        QPoint p = canvas->mapFromGlobal(QCursor::pos());
        int canvas_width = ui->draw_widget->width();
        int canvas_height = ui->draw_widget->height();
        if (p.x() >= 0 && p.x() <= canvas_width && p.y() >= 0 && p.y() <= canvas_height)
        {
            double x = p.x() - (canvas_width - 1.0) * 0.5;
            double y = p.y() - (canvas_height - 1.0) * 0.5;
            x /= 100.0;
            y /= 100.0;
            if (ui->mouse_obj_checkBox->isChecked())
            {
                ui->x_pos->setText(QString().setNum(x, 'g', 3));
                ui->y_pos->setText(QString().setNum(y, 'g', 3));
            }
            if (ui->mouse_light_checkBox->isChecked())
            {
                ui->light_x_pos->setText(QString().setNum(x, 'g', 3));
                ui->light_y_pos->setText(QString().setNum(y, 'g', 3));
            }
        }
    }
}

void MainWindow::add_light(const Point3D &center, const RGBColor &color, const double &I)
{
    Light *light = new Light(I, color, center);
    world->add_light(light);

    QString name = "источник № " + QString("%1").arg(lights_count);
    ui->listWidget->addItem(name);
    lights_count++;
}

void MainWindow::add_sphere(const Point3D &center, const double &r, Material *m)
{
    QString name = "шар № " + QString("%1").arg(objects_count[SPHERE]);
    objects_count[SPHERE]++;
    ui->listWidget_2->addItem(name);
    GeometricObject *sphere = new Sphere(center, r);
    sphere->set_material(m);
    world->add_object(sphere);
}

void MainWindow::add_box(const Point3D &center, const double &a, const double &b, const double &c, Material *m)
{
    QString name = "параллелепипед № " + QString("%1").arg(objects_count[BOX]);
    objects_count[BOX]++;
    ui->listWidget_2->addItem(name);

    GeometricObject *box = new Box(center, a, b, c);
    box->set_material(m);
    world->add_object(box);
}

void MainWindow::add_pyramid(const Point3D &center, const double &a, const double &h, Material *m)
{
    QString name = "пирамида № " + QString("%1").arg(objects_count[PYRAMID]);
    objects_count[PYRAMID]++;
    ui->listWidget_2->addItem(name);

    GeometricObject *pyramid = new Pyramid(center, a, h);
    pyramid->set_material(m);
    world->add_object(pyramid);
}

void MainWindow::add_cone(const Point3D &center, const double &r, const double &h, Material *m)
{
    QString name = "конус № " + QString("%1").arg(objects_count[CONE]);
    objects_count[CONE]++;
    ui->listWidget_2->addItem(name);

    GeometricObject *cone = new Cone(center, r, h);
    cone->set_material(m);
    world->add_object(cone);
}

void MainWindow::add_cylinder(const Point3D &center, const double &r, const double &h, Material *m)
{
    QString name = "цилиндр № " + QString("%1").arg(objects_count[CYLINDER]);
    objects_count[CYLINDER]++;
    ui->listWidget_2->addItem(name);

    GeometricObject *cylinder = new Cylinder(center, h, r);
    cylinder->set_material(m);
    world->add_object(cylinder);
}

void MainWindow::add_tori(const Point3D &center, const double &a, const double &b, Material *m)
{
    QString name = "тор № " + QString("%1").arg(objects_count[TORI]);
    objects_count[TORI]++;
    ui->listWidget_2->addItem(name);

    GeometricObject *tori = new Tori(center, a, b);
    tori->set_material(m);
    world->add_object(tori);
}

void MainWindow::on_scene1_clicked()
{
    clear_all();
    Material *m1 = new Material();
    choose_material(m1, PLASTIC);
    m1->color = RGBColor(1, 1, 1);
    add_sphere(Point3D(0, 500, 0), 499, m1);

    Material *m2 = new Material();
    choose_material(m2, RUBBER);
    m2->color = RGBColor(1, 1, 0);
    add_box(Point3D(-3, 1, -5), 4, 2, 2, m2);

    Material *m3 = new Material();
    choose_material(m3, MIRROR);
    m3->color = RGBColor(1, 0.87, 0.64);
    add_sphere(Point3D(1, 0, -3), 1, m3);

    Material *m4 = new Material();
    choose_material(m4, METAL);
    m4->color = RGBColor(1, 0.18, 0.67);
    add_cylinder(Point3D(0, 0, -20), 3, 4, m4);

    Material *m5 = new Material();
    choose_material(m5, GLASS);
    m5->color = RGBColor(0.84, 0.92, 1);
    add_cone(Point3D(-1, 0, -4), 0.3, 0.5, m5);

    add_light(Point3D(0, -5, -2), RGBColor(1, 1, 1), 1);
    world->render(-10);
}



void MainWindow::on_scene2_clicked()
{
    clear_all();
    Material *m1 = new Material();
    choose_material(m1, METAL);
    m1->color = RGBColor(1, 1, 1);
    add_sphere(Point3D(0, 2, 0), 1, m1);

    Material *m2 = new Material();
    choose_material(m2, RUBBER);
    m2->color = RGBColor(1, 1, 1);
    add_tori(Point3D(0, 2, 0), 2, 0.3, m2);


    add_light(Point3D(0, 0, -2), RGBColor(1, 0, 1), 1);
    add_light(Point3D(0, 3, 2), RGBColor(0.89, 0.3, 0), 1);
    add_light(Point3D(-0.5, 2, -5), RGBColor(0, 0.7, 0.1), 1);
    world->render(-10);
}

void MainWindow::on_scene3_clicked()
{
    clear_all();
    Material *m1 = new Material();
    choose_material(m1, RUBBER);
    m1->color = RGBColor(1, 0, 0);
    add_pyramid(Point3D(0, 2, 0), 4, 4.5, m1);

    Material *m2 = new Material();
    choose_material(m2, GLASS);
    m2->color = RGBColor(1, 1, 1);
    add_sphere(Point3D(1, 1, -3), 1.3, m2);

    Material *m3 = new Material();
    choose_material(m3, GLASS);
    m3->color = RGBColor(0.84, 0.92, 0.94);
    add_box(Point3D(-1.5, 0, -5), 1, 2, 3, m3);

    world->render(-10);
}

void MainWindow::clear_all()
{
    int obj_index = world->get_obj_size();
    while (obj_index != 0)
    {
        world->remove_object(obj_index - 1);
        obj_index--;
    }
    ui->listWidget_2->clear();
    int light_index = world->get_light_size();
    while (light_index != 0)
    {
        world->remove_light(light_index - 1);
        light_index--;
    }
    ui->listWidget->clear();
    world->render(zoom);
}
