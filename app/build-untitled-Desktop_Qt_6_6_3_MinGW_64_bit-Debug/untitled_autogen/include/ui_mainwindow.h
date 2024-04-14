/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QFrame *FromImage;
    QLabel *FromImageSize;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QFrame *ToImage;
    QLabel *ToImageSize;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QPushButton *BWBtn;
    QPushButton *OilPaint;
    QPushButton *ResizeBtn;
    QPushButton *FlipBtn;
    QPushButton *Infrared;
    QPushButton *Sepia;
    QPushButton *CropBtn;
    QPushButton *Purple;
    QPushButton *mergeBtn;
    QPushButton *sunLightBtn;
    QPushButton *GrayscaleBtn;
    QPushButton *brightnessBtn;
    QPushButton *EdgeDetection;
    QPushButton *nightMoodBtn;
    QLabel *options_label;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_3;
    QSlider *Brightness;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *resize_width;
    QLineEdit *resize_height;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *loadNewImage;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *applyBtn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *clearBtn;
    QPushButton *saveBtn;
    QLabel *errorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(867, 828);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../../Users/ALRWAD LAPTOP/Downloads/icons8-filter-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color:  #E7E8D1;\n"
"	color: #B85042;\n"
"}\n"
"QPushButton{\n"
"	background-color:  #B85042;\n"
"	color:#E7E8D1;\n"
"	border-radius: 30%;\n"
"	font-size: 14px;\n"
"	font-weight: 600;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:  #A7BEAE;\n"
"}\n"
"QRadioButton{\n"
"	color: #B85042 ;\n"
"	font-weight: 500;\n"
"}\n"
"QLabel{\n"
"	color:  #B85042;\n"
"}\n"
"QLineEdit{\n"
"	border-radius: 18%;\n"
"	padding: 8px 4px;\n"
"	background-color:  transparent;\n"
"	color:  #B85042;\n"
"	 border: 1px solid  #B85042;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1px solid #A7BEAE;\n"
"}"));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(11);
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        FromImage = new QFrame(centralwidget);
        FromImage->setObjectName("FromImage");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(FromImage->sizePolicy().hasHeightForWidth());
        FromImage->setSizePolicy(sizePolicy2);
        FromImage->setMinimumSize(QSize(300, 200));
        FromImage->setAutoFillBackground(false);
        FromImage->setStyleSheet(QString::fromUtf8("QFrame#frame_2{\n"
"	background-color: transparent;\n"
"	background-position: center;\n"
"}"));
        FromImage->setFrameShape(QFrame::StyledPanel);
        FromImage->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(FromImage);

        FromImageSize = new QLabel(centralwidget);
        FromImageSize->setObjectName("FromImageSize");
        sizePolicy1.setHeightForWidth(FromImageSize->sizePolicy().hasHeightForWidth());
        FromImageSize->setSizePolicy(sizePolicy1);
        FromImageSize->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(FromImageSize);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        ToImage = new QFrame(centralwidget);
        ToImage->setObjectName("ToImage");
        sizePolicy2.setHeightForWidth(ToImage->sizePolicy().hasHeightForWidth());
        ToImage->setSizePolicy(sizePolicy2);
        ToImage->setMinimumSize(QSize(300, 200));
        ToImage->setAutoFillBackground(false);
        ToImage->setStyleSheet(QString::fromUtf8("QFrame#frame_2{\n"
"	background-color: transparent;\n"
"	background-position: center;\n"
"}"));
        ToImage->setFrameShape(QFrame::StyledPanel);
        ToImage->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(ToImage);

        ToImageSize = new QLabel(centralwidget);
        ToImageSize->setObjectName("ToImageSize");
        sizePolicy1.setHeightForWidth(ToImageSize->sizePolicy().hasHeightForWidth());
        ToImageSize->setSizePolicy(sizePolicy1);
        ToImageSize->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(ToImageSize);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy3);
        scrollArea->setMaximumSize(QSize(300, 300));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"	background-color: transparent;\n"
"	border radius: 22px;\n"
"	border: 1px solid #A7BEAE;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 204, 796));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: transparent;\n"
"}\n"
"QPushButton{\n"
"	background-color: #B85042;\n"
"	border-radius: 24px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #A7BEAE;\n"
"}"));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        BWBtn = new QPushButton(scrollAreaWidgetContents);
        BWBtn->setObjectName("BWBtn");
        sizePolicy2.setHeightForWidth(BWBtn->sizePolicy().hasHeightForWidth());
        BWBtn->setSizePolicy(sizePolicy2);
        BWBtn->setMinimumSize(QSize(150, 50));
        QFont font1;
        font1.setWeight(QFont::DemiBold);
        BWBtn->setFont(font1);
        BWBtn->setLayoutDirection(Qt::LeftToRight);
        BWBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(BWBtn, 0, 0, 1, 1);

        OilPaint = new QPushButton(scrollAreaWidgetContents);
        OilPaint->setObjectName("OilPaint");
        sizePolicy2.setHeightForWidth(OilPaint->sizePolicy().hasHeightForWidth());
        OilPaint->setSizePolicy(sizePolicy2);
        OilPaint->setMinimumSize(QSize(150, 50));
        OilPaint->setFont(font1);
        OilPaint->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(OilPaint, 10, 0, 1, 1);

        ResizeBtn = new QPushButton(scrollAreaWidgetContents);
        ResizeBtn->setObjectName("ResizeBtn");
        sizePolicy2.setHeightForWidth(ResizeBtn->sizePolicy().hasHeightForWidth());
        ResizeBtn->setSizePolicy(sizePolicy2);
        ResizeBtn->setMinimumSize(QSize(150, 50));
        ResizeBtn->setFont(font1);
        ResizeBtn->setAutoFillBackground(false);
        ResizeBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ResizeBtn, 5, 0, 1, 1);

        FlipBtn = new QPushButton(scrollAreaWidgetContents);
        FlipBtn->setObjectName("FlipBtn");
        sizePolicy2.setHeightForWidth(FlipBtn->sizePolicy().hasHeightForWidth());
        FlipBtn->setSizePolicy(sizePolicy2);
        FlipBtn->setMinimumSize(QSize(150, 50));
        FlipBtn->setFont(font1);
        FlipBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(FlipBtn, 1, 0, 1, 1);

        Infrared = new QPushButton(scrollAreaWidgetContents);
        Infrared->setObjectName("Infrared");
        sizePolicy2.setHeightForWidth(Infrared->sizePolicy().hasHeightForWidth());
        Infrared->setSizePolicy(sizePolicy2);
        Infrared->setMinimumSize(QSize(150, 50));
        Infrared->setFont(font1);
        Infrared->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Infrared, 6, 0, 1, 1);

        Sepia = new QPushButton(scrollAreaWidgetContents);
        Sepia->setObjectName("Sepia");
        sizePolicy2.setHeightForWidth(Sepia->sizePolicy().hasHeightForWidth());
        Sepia->setSizePolicy(sizePolicy2);
        Sepia->setMinimumSize(QSize(150, 50));
        Sepia->setFont(font1);
        Sepia->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Sepia, 17, 0, 1, 1);

        CropBtn = new QPushButton(scrollAreaWidgetContents);
        CropBtn->setObjectName("CropBtn");
        sizePolicy2.setHeightForWidth(CropBtn->sizePolicy().hasHeightForWidth());
        CropBtn->setSizePolicy(sizePolicy2);
        CropBtn->setMinimumSize(QSize(150, 50));
        CropBtn->setFont(font1);
        CropBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(CropBtn, 3, 0, 1, 1);

        Purple = new QPushButton(scrollAreaWidgetContents);
        Purple->setObjectName("Purple");
        sizePolicy2.setHeightForWidth(Purple->sizePolicy().hasHeightForWidth());
        Purple->setSizePolicy(sizePolicy2);
        Purple->setMinimumSize(QSize(150, 50));
        Purple->setFont(font1);
        Purple->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Purple, 16, 0, 1, 1);

        mergeBtn = new QPushButton(scrollAreaWidgetContents);
        mergeBtn->setObjectName("mergeBtn");
        sizePolicy2.setHeightForWidth(mergeBtn->sizePolicy().hasHeightForWidth());
        mergeBtn->setSizePolicy(sizePolicy2);
        mergeBtn->setMinimumSize(QSize(150, 50));
        mergeBtn->setFont(font1);
        mergeBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(mergeBtn, 12, 0, 1, 1);

        sunLightBtn = new QPushButton(scrollAreaWidgetContents);
        sunLightBtn->setObjectName("sunLightBtn");
        sizePolicy2.setHeightForWidth(sunLightBtn->sizePolicy().hasHeightForWidth());
        sunLightBtn->setSizePolicy(sizePolicy2);
        sunLightBtn->setMinimumSize(QSize(150, 50));
        sunLightBtn->setFont(font1);
        sunLightBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(sunLightBtn, 15, 0, 1, 1);

        GrayscaleBtn = new QPushButton(scrollAreaWidgetContents);
        GrayscaleBtn->setObjectName("GrayscaleBtn");
        sizePolicy2.setHeightForWidth(GrayscaleBtn->sizePolicy().hasHeightForWidth());
        GrayscaleBtn->setSizePolicy(sizePolicy2);
        GrayscaleBtn->setMinimumSize(QSize(150, 50));
        GrayscaleBtn->setFont(font1);
        GrayscaleBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(GrayscaleBtn, 11, 0, 1, 1);

        brightnessBtn = new QPushButton(scrollAreaWidgetContents);
        brightnessBtn->setObjectName("brightnessBtn");
        sizePolicy2.setHeightForWidth(brightnessBtn->sizePolicy().hasHeightForWidth());
        brightnessBtn->setSizePolicy(sizePolicy2);
        brightnessBtn->setMinimumSize(QSize(150, 50));
        brightnessBtn->setFont(font1);
        brightnessBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(brightnessBtn, 13, 0, 1, 1);

        EdgeDetection = new QPushButton(scrollAreaWidgetContents);
        EdgeDetection->setObjectName("EdgeDetection");
        sizePolicy2.setHeightForWidth(EdgeDetection->sizePolicy().hasHeightForWidth());
        EdgeDetection->setSizePolicy(sizePolicy2);
        EdgeDetection->setMinimumSize(QSize(150, 50));
        EdgeDetection->setFont(font1);
        EdgeDetection->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(EdgeDetection, 14, 0, 1, 1);

        nightMoodBtn = new QPushButton(scrollAreaWidgetContents);
        nightMoodBtn->setObjectName("nightMoodBtn");
        sizePolicy2.setHeightForWidth(nightMoodBtn->sizePolicy().hasHeightForWidth());
        nightMoodBtn->setSizePolicy(sizePolicy2);
        nightMoodBtn->setMinimumSize(QSize(150, 50));
        nightMoodBtn->setFont(font1);
        nightMoodBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(nightMoodBtn, 18, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_5->addWidget(scrollArea);


        verticalLayout_5->addLayout(horizontalLayout_5);

        options_label = new QLabel(centralwidget);
        options_label->setObjectName("options_label");
        QFont font2;
        font2.setPointSize(20);
        options_label->setFont(font2);
        options_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	opacity:0.4;\n"
"}"));

        verticalLayout_5->addWidget(options_label);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(0);
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_30->addWidget(label_3);

        Brightness = new QSlider(centralwidget);
        Brightness->setObjectName("Brightness");
        Brightness->setMaximumSize(QSize(400, 16777215));
        Brightness->setOrientation(Qt::Horizontal);

        horizontalLayout_30->addWidget(Brightness);


        verticalLayout_5->addLayout(horizontalLayout_30);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_1 = new QLineEdit(centralwidget);
        lineEdit_1->setObjectName("lineEdit_1");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit_1->sizePolicy().hasHeightForWidth());
        lineEdit_1->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(lineEdit_1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        sizePolicy5.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy5.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy5);

        horizontalLayout_6->addWidget(lineEdit_2);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        sizePolicy5.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy5);

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy6);
        radioButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName("radioButton_2");
        sizePolicy6.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy6);

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        resize_width = new QLineEdit(centralwidget);
        resize_width->setObjectName("resize_width");
        sizePolicy5.setHeightForWidth(resize_width->sizePolicy().hasHeightForWidth());
        resize_width->setSizePolicy(sizePolicy5);

        horizontalLayout_8->addWidget(resize_width);

        resize_height = new QLineEdit(centralwidget);
        resize_height->setObjectName("resize_height");
        sizePolicy5.setHeightForWidth(resize_height->sizePolicy().hasHeightForWidth());
        resize_height->setSizePolicy(sizePolicy5);

        horizontalLayout_8->addWidget(resize_height);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        loadNewImage = new QPushButton(centralwidget);
        loadNewImage->setObjectName("loadNewImage");
        sizePolicy2.setHeightForWidth(loadNewImage->sizePolicy().hasHeightForWidth());
        loadNewImage->setSizePolicy(sizePolicy2);
        loadNewImage->setMinimumSize(QSize(150, 35));
        loadNewImage->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        loadNewImage->setFlat(false);

        horizontalLayout_29->addWidget(loadNewImage);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy7);
        QFont font3;
        font3.setPointSize(18);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_29->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_29);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");

        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        applyBtn = new QPushButton(centralwidget);
        applyBtn->setObjectName("applyBtn");
        sizePolicy2.setHeightForWidth(applyBtn->sizePolicy().hasHeightForWidth());
        applyBtn->setSizePolicy(sizePolicy2);
        applyBtn->setMinimumSize(QSize(107, 30));
        applyBtn->setMaximumSize(QSize(16777215, 16777215));
        applyBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        applyBtn->setAutoDefault(false);
        applyBtn->setFlat(false);

        horizontalLayout_7->addWidget(applyBtn);


        verticalLayout_5->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(150, 35));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        pushButton->setFlat(false);

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        sizePolicy7.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy7);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        sizePolicy2.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy2);
        clearBtn->setMinimumSize(QSize(150, 35));
        clearBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        clearBtn->setFlat(false);

        verticalLayout->addWidget(clearBtn);

        saveBtn = new QPushButton(centralwidget);
        saveBtn->setObjectName("saveBtn");
        sizePolicy2.setHeightForWidth(saveBtn->sizePolicy().hasHeightForWidth());
        saveBtn->setSizePolicy(sizePolicy2);
        saveBtn->setMinimumSize(QSize(150, 35));
        saveBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        saveBtn->setFlat(false);

        verticalLayout->addWidget(saveBtn);


        verticalLayout_5->addLayout(verticalLayout);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        sizePolicy4.setHeightForWidth(errorLabel->sizePolicy().hasHeightForWidth());
        errorLabel->setSizePolicy(sizePolicy4);
        QFont font4;
        font4.setPointSize(12);
        errorLabel->setFont(font4);
        errorLabel->setLayoutDirection(Qt::LeftToRight);
        errorLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: red;\n"
"}"));
        errorLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(errorLabel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 867, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        loadNewImage->setDefault(false);
        applyBtn->setDefault(false);
        pushButton->setDefault(false);
        clearBtn->setDefault(false);
        saveBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "baby Filters", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        FromImageSize->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        ToImageSize->setText(QString());
        BWBtn->setText(QCoreApplication::translate("MainWindow", "Black and white filter", nullptr));
        OilPaint->setText(QCoreApplication::translate("MainWindow", "Oil Paint", nullptr));
        ResizeBtn->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        FlipBtn->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        Infrared->setText(QCoreApplication::translate("MainWindow", "Infrared", nullptr));
        Sepia->setText(QCoreApplication::translate("MainWindow", "Sepia", nullptr));
        CropBtn->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        Purple->setText(QCoreApplication::translate("MainWindow", "Purple", nullptr));
        mergeBtn->setText(QCoreApplication::translate("MainWindow", "Merge", nullptr));
        sunLightBtn->setText(QCoreApplication::translate("MainWindow", "Sun Light", nullptr));
        GrayscaleBtn->setText(QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        brightnessBtn->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        EdgeDetection->setText(QCoreApplication::translate("MainWindow", "Edge detection", nullptr));
        nightMoodBtn->setText(QCoreApplication::translate("MainWindow", "Night Mood", nullptr));
        options_label->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Brightness level", nullptr));
        lineEdit_1->setPlaceholderText(QCoreApplication::translate("MainWindow", "From X", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "To X", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "From Y", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "To Y", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "horizontally", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "verticlay", nullptr));
        resize_width->setPlaceholderText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        resize_height->setPlaceholderText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        loadNewImage->setText(QCoreApplication::translate("MainWindow", "Load second image", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        applyBtn->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Load image", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        saveBtn->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
