/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *draw_widget;
    QGroupBox *groupBox;
    QComboBox *object_comboBox;
    QStackedWidget *stackedWidget;
    QWidget *sphere;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *sphere_pos_pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *sphere_radius;
    QSpacerItem *horizontalSpacer;
    QWidget *box;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *box_pos_pushButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *box_length;
    QLineEdit *box_width;
    QLineEdit *box_height;
    QWidget *pyramid;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pyramid_pos_pushButton;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *pyramid_a;
    QLineEdit *pyramid_h;
    QWidget *cone;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *cone_pos_pushButton;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *cone_radius;
    QLineEdit *cone_height;
    QWidget *cylinder;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *cylinder_pos_pushButton;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *cylinder_radius;
    QLineEdit *cylinder_height;
    QWidget *tori;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QPushButton *tori_pos_pushButton;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *tori_inner_radius;
    QLineEdit *tori_outer_radius;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *x_pos;
    QLineEdit *y_pos;
    QLineEdit *z_pos;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QComboBox *matherial_comboBox;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_21;
    QLineEdit *object_r;
    QLineEdit *object_g;
    QLineEdit *object_b;
    QPushButton *obj_add_pushButton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_22;
    QSlider *horizontalSlider;
    QDoubleSpinBox *doubleSpinBox;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_15;
    QListWidget *listWidget;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_20;
    QLineEdit *ligth_name;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_17;
    QLineEdit *light_x_pos;
    QLineEdit *light_y_pos;
    QLineEdit *light_z_pos;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_18;
    QLineEdit *light_r;
    QLineEdit *light_g;
    QLineEdit *light_b;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_19;
    QLineEdit *light_intensity;
    QPushButton *light_add_pushButton;
    QPushButton *light_remove_pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1003, 629);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        draw_widget = new QWidget(centralWidget);
        draw_widget->setObjectName(QStringLiteral("draw_widget"));
        draw_widget->setGeometry(QRect(10, 10, 651, 611));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(670, 10, 321, 331));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        object_comboBox = new QComboBox(groupBox);
        object_comboBox->setObjectName(QStringLiteral("object_comboBox"));
        object_comboBox->setGeometry(QRect(10, 20, 301, 22));
        QFont font1;
        font1.setPointSize(10);
        object_comboBox->setFont(font1);
        stackedWidget = new QStackedWidget(groupBox);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 120, 301, 81));
        stackedWidget->setFont(font1);
        sphere = new QWidget();
        sphere->setObjectName(QStringLiteral("sphere"));
        verticalLayoutWidget_3 = new QWidget(sphere);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 0, 291, 71));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        sphere_pos_pushButton = new QPushButton(verticalLayoutWidget_3);
        sphere_pos_pushButton->setObjectName(QStringLiteral("sphere_pos_pushButton"));
        QFont font2;
        font2.setPointSize(11);
        sphere_pos_pushButton->setFont(font2);

        verticalLayout_3->addWidget(sphere_pos_pushButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        sphere_radius = new QLineEdit(verticalLayoutWidget_3);
        sphere_radius->setObjectName(QStringLiteral("sphere_radius"));
        sphere_radius->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(sphere_radius);

        horizontalSpacer = new QSpacerItem(118, 56, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(sphere);
        box = new QWidget();
        box->setObjectName(QStringLiteral("box"));
        verticalLayoutWidget = new QWidget(box);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 291, 81));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        box_pos_pushButton = new QPushButton(verticalLayoutWidget);
        box_pos_pushButton->setObjectName(QStringLiteral("box_pos_pushButton"));
        box_pos_pushButton->setFont(font2);

        verticalLayout->addWidget(box_pos_pushButton);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        box_length = new QLineEdit(verticalLayoutWidget);
        box_length->setObjectName(QStringLiteral("box_length"));
        box_length->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(box_length);

        box_width = new QLineEdit(verticalLayoutWidget);
        box_width->setObjectName(QStringLiteral("box_width"));
        box_width->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(box_width);

        box_height = new QLineEdit(verticalLayoutWidget);
        box_height->setObjectName(QStringLiteral("box_height"));
        box_height->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(box_height);


        verticalLayout->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(box);
        pyramid = new QWidget();
        pyramid->setObjectName(QStringLiteral("pyramid"));
        verticalLayoutWidget_2 = new QWidget(pyramid);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 0, 291, 81));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pyramid_pos_pushButton = new QPushButton(verticalLayoutWidget_2);
        pyramid_pos_pushButton->setObjectName(QStringLiteral("pyramid_pos_pushButton"));
        pyramid_pos_pushButton->setFont(font2);

        verticalLayout_2->addWidget(pyramid_pos_pushButton);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_9);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pyramid_a = new QLineEdit(verticalLayoutWidget_2);
        pyramid_a->setObjectName(QStringLiteral("pyramid_a"));
        pyramid_a->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(pyramid_a);

        pyramid_h = new QLineEdit(verticalLayoutWidget_2);
        pyramid_h->setObjectName(QStringLiteral("pyramid_h"));
        pyramid_h->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(pyramid_h);


        verticalLayout_2->addLayout(horizontalLayout_7);

        stackedWidget->addWidget(pyramid);
        cone = new QWidget();
        cone->setObjectName(QStringLiteral("cone"));
        verticalLayoutWidget_4 = new QWidget(cone);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 0, 291, 81));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        cone_pos_pushButton = new QPushButton(verticalLayoutWidget_4);
        cone_pos_pushButton->setObjectName(QStringLiteral("cone_pos_pushButton"));
        cone_pos_pushButton->setFont(font2);

        verticalLayout_4->addWidget(cone_pos_pushButton);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(verticalLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_3);

        label_7 = new QLabel(verticalLayoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_7);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cone_radius = new QLineEdit(verticalLayoutWidget_4);
        cone_radius->setObjectName(QStringLiteral("cone_radius"));
        cone_radius->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(cone_radius);

        cone_height = new QLineEdit(verticalLayoutWidget_4);
        cone_height->setObjectName(QStringLiteral("cone_height"));
        cone_height->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(cone_height);


        verticalLayout_4->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(cone);
        cylinder = new QWidget();
        cylinder->setObjectName(QStringLiteral("cylinder"));
        verticalLayoutWidget_5 = new QWidget(cylinder);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 0, 291, 81));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        cylinder_pos_pushButton = new QPushButton(verticalLayoutWidget_5);
        cylinder_pos_pushButton->setObjectName(QStringLiteral("cylinder_pos_pushButton"));
        cylinder_pos_pushButton->setFont(font2);

        verticalLayout_5->addWidget(cylinder_pos_pushButton);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(verticalLayoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font2);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_11);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        cylinder_radius = new QLineEdit(verticalLayoutWidget_5);
        cylinder_radius->setObjectName(QStringLiteral("cylinder_radius"));
        cylinder_radius->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(cylinder_radius);

        cylinder_height = new QLineEdit(verticalLayoutWidget_5);
        cylinder_height->setObjectName(QStringLiteral("cylinder_height"));
        cylinder_height->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(cylinder_height);


        verticalLayout_5->addLayout(horizontalLayout_10);

        stackedWidget->addWidget(cylinder);
        tori = new QWidget();
        tori->setObjectName(QStringLiteral("tori"));
        verticalLayoutWidget_6 = new QWidget(tori);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 0, 291, 81));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        tori_pos_pushButton = new QPushButton(verticalLayoutWidget_6);
        tori_pos_pushButton->setObjectName(QStringLiteral("tori_pos_pushButton"));
        tori_pos_pushButton->setFont(font2);

        verticalLayout_6->addWidget(tori_pos_pushButton);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_13 = new QLabel(verticalLayoutWidget_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_13);

        label_12 = new QLabel(verticalLayoutWidget_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_12);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        tori_inner_radius = new QLineEdit(verticalLayoutWidget_6);
        tori_inner_radius->setObjectName(QStringLiteral("tori_inner_radius"));
        tori_inner_radius->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(tori_inner_radius);

        tori_outer_radius = new QLineEdit(verticalLayoutWidget_6);
        tori_outer_radius->setObjectName(QStringLiteral("tori_outer_radius"));
        tori_outer_radius->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(tori_outer_radius);


        verticalLayout_6->addLayout(horizontalLayout_12);

        stackedWidget->addWidget(tori);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 50, 317, 21));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_2 = new QRadioButton(horizontalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        QFont font3;
        font3.setPointSize(8);
        radioButton_2->setFont(font3);
        radioButton_2->setChecked(true);

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(horizontalLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setFont(font3);

        horizontalLayout->addWidget(radioButton);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 291, 16));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 90, 291, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        x_pos = new QLineEdit(horizontalLayoutWidget_2);
        x_pos->setObjectName(QStringLiteral("x_pos"));
        x_pos->setEnabled(true);
        x_pos->setFont(font2);
        x_pos->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(x_pos);

        y_pos = new QLineEdit(horizontalLayoutWidget_2);
        y_pos->setObjectName(QStringLiteral("y_pos"));
        y_pos->setFont(font2);
        y_pos->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(y_pos);

        z_pos = new QLineEdit(horizontalLayoutWidget_2);
        z_pos->setObjectName(QStringLiteral("z_pos"));
        z_pos->setFont(font2);
        z_pos->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(z_pos);

        verticalLayoutWidget_9 = new QWidget(groupBox);
        verticalLayoutWidget_9->setObjectName(QStringLiteral("verticalLayoutWidget_9"));
        verticalLayoutWidget_9->setGeometry(QRect(20, 210, 291, 90));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_14 = new QLabel(verticalLayoutWidget_9);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font2);

        horizontalLayout_14->addWidget(label_14);

        matherial_comboBox = new QComboBox(verticalLayoutWidget_9);
        matherial_comboBox->setObjectName(QStringLiteral("matherial_comboBox"));
        matherial_comboBox->setFont(font2);

        horizontalLayout_14->addWidget(matherial_comboBox);


        verticalLayout_9->addLayout(horizontalLayout_14);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_21 = new QLabel(verticalLayoutWidget_9);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font2);
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_21);

        object_r = new QLineEdit(verticalLayoutWidget_9);
        object_r->setObjectName(QStringLiteral("object_r"));
        object_r->setEnabled(true);
        object_r->setFont(font1);
        object_r->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(object_r);

        object_g = new QLineEdit(verticalLayoutWidget_9);
        object_g->setObjectName(QStringLiteral("object_g"));
        object_g->setFont(font1);
        object_g->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(object_g);

        object_b = new QLineEdit(verticalLayoutWidget_9);
        object_b->setObjectName(QStringLiteral("object_b"));
        object_b->setFont(font1);
        object_b->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(object_b);


        verticalLayout_9->addLayout(horizontalLayout_19);

        obj_add_pushButton = new QPushButton(verticalLayoutWidget_9);
        obj_add_pushButton->setObjectName(QStringLiteral("obj_add_pushButton"));
        obj_add_pushButton->setFont(font2);

        verticalLayout_9->addWidget(obj_add_pushButton);

        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 300, 291, 27));
        horizontalLayout_20 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(horizontalLayoutWidget_3);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_20->addWidget(label_22);

        horizontalSlider = new QSlider(horizontalLayoutWidget_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_20->addWidget(horizontalSlider);

        doubleSpinBox = new QDoubleSpinBox(horizontalLayoutWidget_3);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        horizontalLayout_20->addWidget(doubleSpinBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(670, 340, 321, 281));
        groupBox_2->setFont(font);
        verticalLayoutWidget_7 = new QWidget(groupBox_2);
        verticalLayoutWidget_7->setObjectName(QStringLiteral("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(20, 170, 191, 101));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(verticalLayoutWidget_7);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font2);

        verticalLayout_7->addWidget(label_15);

        listWidget = new QListWidget(verticalLayoutWidget_7);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_7->addWidget(listWidget);

        verticalLayoutWidget_8 = new QWidget(groupBox_2);
        verticalLayoutWidget_8->setObjectName(QStringLiteral("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(20, 20, 291, 144));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(verticalLayoutWidget_8);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font2);

        verticalLayout_8->addWidget(label_16);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_20 = new QLabel(verticalLayoutWidget_8);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font2);

        horizontalLayout_18->addWidget(label_20);

        ligth_name = new QLineEdit(verticalLayoutWidget_8);
        ligth_name->setObjectName(QStringLiteral("ligth_name"));
        ligth_name->setFont(font1);

        horizontalLayout_18->addWidget(ligth_name);


        verticalLayout_8->addLayout(horizontalLayout_18);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_17 = new QLabel(verticalLayoutWidget_8);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_17);

        light_x_pos = new QLineEdit(verticalLayoutWidget_8);
        light_x_pos->setObjectName(QStringLiteral("light_x_pos"));
        light_x_pos->setEnabled(true);
        light_x_pos->setFont(font1);
        light_x_pos->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(light_x_pos);

        light_y_pos = new QLineEdit(verticalLayoutWidget_8);
        light_y_pos->setObjectName(QStringLiteral("light_y_pos"));
        light_y_pos->setFont(font1);
        light_y_pos->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(light_y_pos);

        light_z_pos = new QLineEdit(verticalLayoutWidget_8);
        light_z_pos->setObjectName(QStringLiteral("light_z_pos"));
        light_z_pos->setFont(font1);
        light_z_pos->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(light_z_pos);


        verticalLayout_8->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_18 = new QLabel(verticalLayoutWidget_8);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font2);
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(label_18);

        light_r = new QLineEdit(verticalLayoutWidget_8);
        light_r->setObjectName(QStringLiteral("light_r"));
        light_r->setEnabled(true);
        light_r->setFont(font1);
        light_r->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(light_r);

        light_g = new QLineEdit(verticalLayoutWidget_8);
        light_g->setObjectName(QStringLiteral("light_g"));
        light_g->setFont(font1);
        light_g->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(light_g);

        light_b = new QLineEdit(verticalLayoutWidget_8);
        light_b->setObjectName(QStringLiteral("light_b"));
        light_b->setFont(font1);
        light_b->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(light_b);


        verticalLayout_8->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_19 = new QLabel(verticalLayoutWidget_8);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font2);

        horizontalLayout_17->addWidget(label_19);

        light_intensity = new QLineEdit(verticalLayoutWidget_8);
        light_intensity->setObjectName(QStringLiteral("light_intensity"));
        light_intensity->setFont(font2);
        light_intensity->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(light_intensity);

        light_add_pushButton = new QPushButton(verticalLayoutWidget_8);
        light_add_pushButton->setObjectName(QStringLiteral("light_add_pushButton"));
        light_add_pushButton->setFont(font2);

        horizontalLayout_17->addWidget(light_add_pushButton);


        verticalLayout_8->addLayout(horizontalLayout_17);

        light_remove_pushButton = new QPushButton(groupBox_2);
        light_remove_pushButton->setObjectName(QStringLiteral("light_remove_pushButton"));
        light_remove_pushButton->setGeometry(QRect(220, 240, 81, 26));
        light_remove_pushButton->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        sphere_pos_pushButton->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\321\200\320\260\320\264\320\270\321\203\321\201", nullptr));
        sphere_radius->setPlaceholderText(QApplication::translate("MainWindow", "R", nullptr));
        box_pos_pushButton->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\264\320\273\320\270\320\275\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\321\210\320\270\321\200\320\270\320\275\320\260", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\262\321\213\321\201\320\276\321\202\320\260", nullptr));
        box_length->setPlaceholderText(QApplication::translate("MainWindow", "length", nullptr));
        box_width->setPlaceholderText(QApplication::translate("MainWindow", "width", nullptr));
        box_height->setPlaceholderText(QApplication::translate("MainWindow", "height", nullptr));
        pyramid_pos_pushButton->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\321\201\321\202\320\276\321\200\320\276\320\275\320\260 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\262\321\213\321\201\320\276\321\202\320\260", nullptr));
        pyramid_a->setPlaceholderText(QApplication::translate("MainWindow", "a", nullptr));
        pyramid_h->setPlaceholderText(QApplication::translate("MainWindow", "height", nullptr));
        cone_pos_pushButton->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\321\200\320\260\320\264\320\270\321\203\321\201", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\262\321\213\321\201\320\276\321\202\320\260", nullptr));
        cone_radius->setPlaceholderText(QApplication::translate("MainWindow", "R", nullptr));
        cone_height->setPlaceholderText(QApplication::translate("MainWindow", "height", nullptr));
        cylinder_pos_pushButton->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\321\200\320\260\320\264\320\270\321\203\321\201", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\262\321\213\321\201\320\276\321\202\320\260", nullptr));
        cylinder_radius->setPlaceholderText(QApplication::translate("MainWindow", "R", nullptr));
        cylinder_height->setPlaceholderText(QApplication::translate("MainWindow", "height", nullptr));
        tori_pos_pushButton->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\271 \321\200\320\260\320\264\320\270\321\203\321\201", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\262\320\275\320\265\321\210\320\275\320\270\320\271 \321\200\320\260\320\264\320\270\321\203\321\201", nullptr));
        tori_inner_radius->setPlaceholderText(QApplication::translate("MainWindow", "a", nullptr));
        tori_outer_radius->setPlaceholderText(QApplication::translate("MainWindow", "b", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\262\320\262\320\276\320\264 \321\201 \320\277\320\276\320\274\320\276\321\211\321\214\321\216 \320\274\321\213\321\210\320\270", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\320\262\320\262\320\276\320\264 \321\202\320\276\321\207\320\275\321\213\321\205 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        x_pos->setPlaceholderText(QApplication::translate("MainWindow", "x", nullptr));
        y_pos->setPlaceholderText(QApplication::translate("MainWindow", "y", nullptr));
        z_pos->setPlaceholderText(QApplication::translate("MainWindow", "z", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273:", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202:", nullptr));
        object_r->setText(QString());
        object_r->setPlaceholderText(QApplication::translate("MainWindow", "r", nullptr));
        object_g->setText(QString());
        object_g->setPlaceholderText(QApplication::translate("MainWindow", "g", nullptr));
        object_b->setText(QString());
        object_b->setPlaceholderText(QApplication::translate("MainWindow", "b", nullptr));
        obj_add_pushButton->setText(QApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\320\267\321\203\320\274:", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\270 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\321\201\320\277\320\270\321\201\320\276\320\272 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\276\320\262:", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260:", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265:", nullptr));
        light_x_pos->setPlaceholderText(QApplication::translate("MainWindow", "x", nullptr));
        light_y_pos->setPlaceholderText(QApplication::translate("MainWindow", "y", nullptr));
        light_z_pos->setPlaceholderText(QApplication::translate("MainWindow", "z", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\321\206\320\262\320\265\321\202:", nullptr));
        light_r->setText(QString());
        light_r->setPlaceholderText(QApplication::translate("MainWindow", "r", nullptr));
        light_g->setText(QString());
        light_g->setPlaceholderText(QApplication::translate("MainWindow", "g", nullptr));
        light_b->setText(QString());
        light_b->setPlaceholderText(QApplication::translate("MainWindow", "b", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\270\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214:", nullptr));
        light_intensity->setPlaceholderText(QApplication::translate("MainWindow", "I", nullptr));
        light_add_pushButton->setText(QApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        light_remove_pushButton->setText(QApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
