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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
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
    QPushButton *Invert;
    QPushButton *TVEffect;
    QPushButton *GrayscaleBtn;
    QPushButton *EdgeDetection;
    QPushButton *BWBtn;
    QPushButton *brightnessBtn;
    QPushButton *RotateBtn;
    QPushButton *FlipBtn;
    QPushButton *nightMoodBtn;
    QPushButton *mergeBtn;
    QPushButton *CropBtn;
    QPushButton *Sepia;
    QPushButton *BlurBtn;
    QPushButton *sunLightBtn;
    QPushButton *Purple;
    QPushButton *Infrared;
    QPushButton *SkewBtn;
    QPushButton *ResizeBtn;
    QPushButton *OilPaint;
    QPushButton *FrameBtn;
    QLabel *options_label;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *loadNewImage;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QRadioButton *CommonArea;
    QRadioButton *ResizeMerge;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_3;
    QSlider *Brightness;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_13;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_19;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_14;
    QLabel *label_15;
    QSlider *horizontalSlider_4;
    QSpacerItem *horizontalSpacer_8;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_21;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_16;
    QLabel *label_17;
    QSlider *horizontalSlider_5;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *resize_width;
    QLineEdit *resize_height;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_11;
    QLabel *label_12;
    QSlider *horizontalSlider_3;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLabel *label_7;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_9;
    QLabel *label_8;
    QSlider *horizontalSlider_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *applyBtn;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_10;
    QFrame *frame_2;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_5;
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
        MainWindow->resize(867, 1129);
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
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 204, 1132));
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
        Invert = new QPushButton(scrollAreaWidgetContents);
        Invert->setObjectName("Invert");
        sizePolicy2.setHeightForWidth(Invert->sizePolicy().hasHeightForWidth());
        Invert->setSizePolicy(sizePolicy2);
        Invert->setMinimumSize(QSize(150, 50));
        QFont font1;
        font1.setWeight(QFont::DemiBold);
        Invert->setFont(font1);
        Invert->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Invert, 2, 0, 1, 1);

        TVEffect = new QPushButton(scrollAreaWidgetContents);
        TVEffect->setObjectName("TVEffect");
        sizePolicy2.setHeightForWidth(TVEffect->sizePolicy().hasHeightForWidth());
        TVEffect->setSizePolicy(sizePolicy2);
        TVEffect->setMinimumSize(QSize(150, 50));
        TVEffect->setFont(font1);
        TVEffect->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(TVEffect, 25, 0, 1, 1);

        GrayscaleBtn = new QPushButton(scrollAreaWidgetContents);
        GrayscaleBtn->setObjectName("GrayscaleBtn");
        sizePolicy2.setHeightForWidth(GrayscaleBtn->sizePolicy().hasHeightForWidth());
        GrayscaleBtn->setSizePolicy(sizePolicy2);
        GrayscaleBtn->setMinimumSize(QSize(150, 50));
        GrayscaleBtn->setFont(font1);
        GrayscaleBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(GrayscaleBtn, 0, 0, 1, 1);

        EdgeDetection = new QPushButton(scrollAreaWidgetContents);
        EdgeDetection->setObjectName("EdgeDetection");
        sizePolicy2.setHeightForWidth(EdgeDetection->sizePolicy().hasHeightForWidth());
        EdgeDetection->setSizePolicy(sizePolicy2);
        EdgeDetection->setMinimumSize(QSize(150, 50));
        EdgeDetection->setFont(font1);
        EdgeDetection->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(EdgeDetection, 24, 0, 1, 1);

        BWBtn = new QPushButton(scrollAreaWidgetContents);
        BWBtn->setObjectName("BWBtn");
        sizePolicy2.setHeightForWidth(BWBtn->sizePolicy().hasHeightForWidth());
        BWBtn->setSizePolicy(sizePolicy2);
        BWBtn->setMinimumSize(QSize(150, 50));
        BWBtn->setFont(font1);
        BWBtn->setLayoutDirection(Qt::LeftToRight);
        BWBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(BWBtn, 1, 0, 1, 1);

        brightnessBtn = new QPushButton(scrollAreaWidgetContents);
        brightnessBtn->setObjectName("brightnessBtn");
        sizePolicy2.setHeightForWidth(brightnessBtn->sizePolicy().hasHeightForWidth());
        brightnessBtn->setSizePolicy(sizePolicy2);
        brightnessBtn->setMinimumSize(QSize(150, 50));
        brightnessBtn->setFont(font1);
        brightnessBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(brightnessBtn, 21, 0, 1, 1);

        RotateBtn = new QPushButton(scrollAreaWidgetContents);
        RotateBtn->setObjectName("RotateBtn");
        sizePolicy2.setHeightForWidth(RotateBtn->sizePolicy().hasHeightForWidth());
        RotateBtn->setSizePolicy(sizePolicy2);
        RotateBtn->setMinimumSize(QSize(150, 50));
        RotateBtn->setFont(font1);
        RotateBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(RotateBtn, 4, 0, 1, 1);

        FlipBtn = new QPushButton(scrollAreaWidgetContents);
        FlipBtn->setObjectName("FlipBtn");
        sizePolicy2.setHeightForWidth(FlipBtn->sizePolicy().hasHeightForWidth());
        FlipBtn->setSizePolicy(sizePolicy2);
        FlipBtn->setMinimumSize(QSize(150, 50));
        FlipBtn->setFont(font1);
        FlipBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(FlipBtn, 3, 0, 1, 1);

        nightMoodBtn = new QPushButton(scrollAreaWidgetContents);
        nightMoodBtn->setObjectName("nightMoodBtn");
        sizePolicy2.setHeightForWidth(nightMoodBtn->sizePolicy().hasHeightForWidth());
        nightMoodBtn->setSizePolicy(sizePolicy2);
        nightMoodBtn->setMinimumSize(QSize(150, 50));
        nightMoodBtn->setFont(font1);
        nightMoodBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(nightMoodBtn, 32, 0, 1, 1);

        mergeBtn = new QPushButton(scrollAreaWidgetContents);
        mergeBtn->setObjectName("mergeBtn");
        sizePolicy2.setHeightForWidth(mergeBtn->sizePolicy().hasHeightForWidth());
        mergeBtn->setSizePolicy(sizePolicy2);
        mergeBtn->setMinimumSize(QSize(150, 50));
        mergeBtn->setFont(font1);
        mergeBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(mergeBtn, 9, 0, 1, 1);

        CropBtn = new QPushButton(scrollAreaWidgetContents);
        CropBtn->setObjectName("CropBtn");
        sizePolicy2.setHeightForWidth(CropBtn->sizePolicy().hasHeightForWidth());
        CropBtn->setSizePolicy(sizePolicy2);
        CropBtn->setMinimumSize(QSize(150, 50));
        CropBtn->setFont(font1);
        CropBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(CropBtn, 7, 0, 1, 1);

        Sepia = new QPushButton(scrollAreaWidgetContents);
        Sepia->setObjectName("Sepia");
        sizePolicy2.setHeightForWidth(Sepia->sizePolicy().hasHeightForWidth());
        Sepia->setSizePolicy(sizePolicy2);
        Sepia->setMinimumSize(QSize(150, 50));
        Sepia->setFont(font1);
        Sepia->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Sepia, 31, 0, 1, 1);

        BlurBtn = new QPushButton(scrollAreaWidgetContents);
        BlurBtn->setObjectName("BlurBtn");
        sizePolicy2.setHeightForWidth(BlurBtn->sizePolicy().hasHeightForWidth());
        BlurBtn->setSizePolicy(sizePolicy2);
        BlurBtn->setMinimumSize(QSize(150, 50));
        BlurBtn->setFont(font1);
        BlurBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(BlurBtn, 6, 0, 1, 1);

        sunLightBtn = new QPushButton(scrollAreaWidgetContents);
        sunLightBtn->setObjectName("sunLightBtn");
        sizePolicy2.setHeightForWidth(sunLightBtn->sizePolicy().hasHeightForWidth());
        sunLightBtn->setSizePolicy(sizePolicy2);
        sunLightBtn->setMinimumSize(QSize(150, 50));
        sunLightBtn->setFont(font1);
        sunLightBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(sunLightBtn, 28, 0, 1, 1);

        Purple = new QPushButton(scrollAreaWidgetContents);
        Purple->setObjectName("Purple");
        sizePolicy2.setHeightForWidth(Purple->sizePolicy().hasHeightForWidth());
        Purple->setSizePolicy(sizePolicy2);
        Purple->setMinimumSize(QSize(150, 50));
        Purple->setFont(font1);
        Purple->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Purple, 30, 0, 1, 1);

        Infrared = new QPushButton(scrollAreaWidgetContents);
        Infrared->setObjectName("Infrared");
        sizePolicy2.setHeightForWidth(Infrared->sizePolicy().hasHeightForWidth());
        Infrared->setSizePolicy(sizePolicy2);
        Infrared->setMinimumSize(QSize(150, 50));
        Infrared->setFont(font1);
        Infrared->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(Infrared, 29, 0, 1, 1);

        SkewBtn = new QPushButton(scrollAreaWidgetContents);
        SkewBtn->setObjectName("SkewBtn");
        sizePolicy2.setHeightForWidth(SkewBtn->sizePolicy().hasHeightForWidth());
        SkewBtn->setSizePolicy(sizePolicy2);
        SkewBtn->setMinimumSize(QSize(150, 50));
        SkewBtn->setFont(font1);
        SkewBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(SkewBtn, 26, 0, 1, 1);

        ResizeBtn = new QPushButton(scrollAreaWidgetContents);
        ResizeBtn->setObjectName("ResizeBtn");
        sizePolicy2.setHeightForWidth(ResizeBtn->sizePolicy().hasHeightForWidth());
        ResizeBtn->setSizePolicy(sizePolicy2);
        ResizeBtn->setMinimumSize(QSize(150, 50));
        ResizeBtn->setFont(font1);
        ResizeBtn->setAutoFillBackground(false);
        ResizeBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ResizeBtn, 10, 0, 1, 1);

        OilPaint = new QPushButton(scrollAreaWidgetContents);
        OilPaint->setObjectName("OilPaint");
        sizePolicy2.setHeightForWidth(OilPaint->sizePolicy().hasHeightForWidth());
        OilPaint->setSizePolicy(sizePolicy2);
        OilPaint->setMinimumSize(QSize(150, 50));
        OilPaint->setFont(font1);
        OilPaint->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(OilPaint, 27, 0, 1, 1);

        FrameBtn = new QPushButton(scrollAreaWidgetContents);
        FrameBtn->setObjectName("FrameBtn");
        sizePolicy2.setHeightForWidth(FrameBtn->sizePolicy().hasHeightForWidth());
        FrameBtn->setSizePolicy(sizePolicy2);
        FrameBtn->setMinimumSize(QSize(150, 50));
        FrameBtn->setFont(font1);
        FrameBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(FrameBtn, 5, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_5->addWidget(scrollArea);


        verticalLayout_4->addLayout(horizontalLayout_5);

        options_label = new QLabel(centralwidget);
        options_label->setObjectName("options_label");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        options_label->setFont(font2);
        options_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	opacity:0.4;\n"
"font: 700 16pt \"Segoe UI\";\n"
"}\n"
""));

        verticalLayout_4->addWidget(options_label);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        horizontalLayout_29->setContentsMargins(-1, 10, -1, 10);
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
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);
        label_2->setMinimumSize(QSize(150, 0));
        QFont font3;
        font3.setPointSize(18);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_29->addWidget(label_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	font: 700 14pt \"Segoe UI\";\n"
"}"));

        horizontalLayout_9->addWidget(label_6);

        CommonArea = new QRadioButton(centralwidget);
        CommonArea->setObjectName("CommonArea");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(CommonArea->sizePolicy().hasHeightForWidth());
        CommonArea->setSizePolicy(sizePolicy5);
        CommonArea->setChecked(true);

        horizontalLayout_9->addWidget(CommonArea);

        ResizeMerge = new QRadioButton(centralwidget);
        ResizeMerge->setObjectName("ResizeMerge");
        sizePolicy5.setHeightForWidth(ResizeMerge->sizePolicy().hasHeightForWidth());
        ResizeMerge->setSizePolicy(sizePolicy5);

        horizontalLayout_9->addWidget(ResizeMerge);


        horizontalLayout_29->addLayout(horizontalLayout_9);


        verticalLayout_4->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(0);
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy6);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_30->addWidget(label_3);

        Brightness = new QSlider(centralwidget);
        Brightness->setObjectName("Brightness");
        Brightness->setMaximumSize(QSize(400, 16777215));
        Brightness->setValue(50);
        Brightness->setOrientation(Qt::Horizontal);

        horizontalLayout_30->addWidget(Brightness);


        verticalLayout_4->addLayout(horizontalLayout_30);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_1 = new QLineEdit(centralwidget);
        lineEdit_1->setObjectName("lineEdit_1");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(lineEdit_1->sizePolicy().hasHeightForWidth());
        lineEdit_1->setSizePolicy(sizePolicy7);

        horizontalLayout_4->addWidget(lineEdit_1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy7.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy7);

        horizontalLayout_4->addWidget(lineEdit_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        frame_7 = new QFrame(centralwidget);
        frame_7->setObjectName("frame_7");
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy8);
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_7);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);

        radioButton_3 = new QRadioButton(frame_7);
        radioButton_3->setObjectName("radioButton_3");

        horizontalLayout_18->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(frame_7);
        radioButton_4->setObjectName("radioButton_4");

        horizontalLayout_18->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(frame_7);
        radioButton_5->setObjectName("radioButton_5");

        horizontalLayout_18->addWidget(radioButton_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_18);

        frame_8 = new QFrame(frame_7);
        frame_8->setObjectName("frame_8");
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_17 = new QHBoxLayout(frame_8);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);

        label_13 = new QLabel(frame_8);
        label_13->setObjectName("label_13");
        QSizePolicy sizePolicy9(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy9);

        horizontalLayout_17->addWidget(label_13);

        pushButton_2 = new QPushButton(frame_8);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 10px;\n"
"	padding: 5px 15px;\n"
"}"));

        horizontalLayout_17->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(frame_8);

        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName("frame_9");
        sizePolicy1.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy1);
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_9);
        verticalLayout_6->setObjectName("verticalLayout_6");
        frame_10 = new QFrame(frame_9);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_19 = new QHBoxLayout(frame_10);
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        horizontalLayout_19->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_14 = new QLabel(frame_10);
        label_14->setObjectName("label_14");
        label_14->setMinimumSize(QSize(80, 0));

        horizontalLayout_20->addWidget(label_14);

        label_15 = new QLabel(frame_10);
        label_15->setObjectName("label_15");
        QSizePolicy sizePolicy10(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy10);
        label_15->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"}"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_20->addWidget(label_15);

        horizontalSlider_4 = new QSlider(frame_10);
        horizontalSlider_4->setObjectName("horizontalSlider_4");
        horizontalSlider_4->setEnabled(true);
        QSizePolicy sizePolicy11(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(horizontalSlider_4->sizePolicy().hasHeightForWidth());
        horizontalSlider_4->setSizePolicy(sizePolicy11);
        horizontalSlider_4->setMinimumSize(QSize(300, 0));
        horizontalSlider_4->setStyleSheet(QString::fromUtf8("QSlider{\n"
"	margin-right:100px;\n"
"}"));
        horizontalSlider_4->setMinimum(0);
        horizontalSlider_4->setMaximum(255);
        horizontalSlider_4->setSingleStep(1);
        horizontalSlider_4->setPageStep(10);
        horizontalSlider_4->setValue(255);
        horizontalSlider_4->setSliderPosition(255);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_4->setTickInterval(0);

        horizontalLayout_20->addWidget(horizontalSlider_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_8);


        horizontalLayout_19->addLayout(horizontalLayout_20);


        verticalLayout_6->addWidget(frame_10);

        frame_11 = new QFrame(frame_9);
        frame_11->setObjectName("frame_11");
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_21 = new QHBoxLayout(frame_11);
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        horizontalLayout_21->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        label_16 = new QLabel(frame_11);
        label_16->setObjectName("label_16");
        label_16->setMinimumSize(QSize(80, 0));

        horizontalLayout_22->addWidget(label_16);

        label_17 = new QLabel(frame_11);
        label_17->setObjectName("label_17");
        sizePolicy10.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy10);
        label_17->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"}"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_22->addWidget(label_17);

        horizontalSlider_5 = new QSlider(frame_11);
        horizontalSlider_5->setObjectName("horizontalSlider_5");
        horizontalSlider_5->setEnabled(true);
        sizePolicy11.setHeightForWidth(horizontalSlider_5->sizePolicy().hasHeightForWidth());
        horizontalSlider_5->setSizePolicy(sizePolicy11);
        horizontalSlider_5->setMinimumSize(QSize(300, 0));
        horizontalSlider_5->setStyleSheet(QString::fromUtf8("QSlider{\n"
"	margin-right:100px;\n"
"}"));
        horizontalSlider_5->setMinimum(0);
        horizontalSlider_5->setMaximum(255);
        horizontalSlider_5->setSingleStep(1);
        horizontalSlider_5->setPageStep(10);
        horizontalSlider_5->setValue(255);
        horizontalSlider_5->setSliderPosition(255);
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        horizontalSlider_5->setTickInterval(0);

        horizontalLayout_22->addWidget(horizontalSlider_5);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_9);


        horizontalLayout_21->addLayout(horizontalLayout_22);


        verticalLayout_6->addWidget(frame_11);


        verticalLayout->addWidget(frame_9);


        verticalLayout_4->addWidget(frame_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        resize_width = new QLineEdit(centralwidget);
        resize_width->setObjectName("resize_width");
        sizePolicy7.setHeightForWidth(resize_width->sizePolicy().hasHeightForWidth());
        resize_width->setSizePolicy(sizePolicy7);

        horizontalLayout_8->addWidget(resize_width);

        resize_height = new QLineEdit(centralwidget);
        resize_height->setObjectName("resize_height");
        sizePolicy7.setHeightForWidth(resize_height->sizePolicy().hasHeightForWidth());
        resize_height->setSizePolicy(sizePolicy7);

        horizontalLayout_8->addWidget(resize_height);


        verticalLayout_4->addLayout(horizontalLayout_8);

        frame_6 = new QFrame(centralwidget);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_15 = new QHBoxLayout(frame_6);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_11 = new QLabel(frame_6);
        label_11->setObjectName("label_11");
        label_11->setMinimumSize(QSize(90, 0));

        horizontalLayout_16->addWidget(label_11);

        label_12 = new QLabel(frame_6);
        label_12->setObjectName("label_12");
        sizePolicy10.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy10);
        label_12->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"}"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_16->addWidget(label_12);

        horizontalSlider_3 = new QSlider(frame_6);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setEnabled(true);
        sizePolicy11.setHeightForWidth(horizontalSlider_3->sizePolicy().hasHeightForWidth());
        horizontalSlider_3->setSizePolicy(sizePolicy11);
        horizontalSlider_3->setMinimumSize(QSize(300, 0));
        horizontalSlider_3->setStyleSheet(QString::fromUtf8("QSlider{\n"
"	margin-right:100px;\n"
"}"));
        horizontalSlider_3->setMinimum(0);
        horizontalSlider_3->setMaximum(70);
        horizontalSlider_3->setSingleStep(1);
        horizontalSlider_3->setPageStep(10);
        horizontalSlider_3->setSliderPosition(0);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickInterval(0);

        horizontalLayout_16->addWidget(horizontalSlider_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_3);


        horizontalLayout_15->addLayout(horizontalLayout_16);


        verticalLayout_4->addWidget(frame_6);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_4);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_10 = new QLabel(frame_4);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(80, 0));

        horizontalLayout_11->addWidget(label_10);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName("label_7");
        sizePolicy10.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy10);
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"}"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_7);

        horizontalSlider = new QSlider(frame_4);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setEnabled(true);
        sizePolicy11.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy11);
        horizontalSlider->setMinimumSize(QSize(300, 0));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider{\n"
"	margin-right:100px;\n"
"}"));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(3);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(10);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickInterval(0);

        horizontalLayout_11->addWidget(horizontalSlider);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_4->addWidget(frame_4);

        frame_5 = new QFrame(centralwidget);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_5);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_9 = new QLabel(frame_5);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(80, 0));

        horizontalLayout_14->addWidget(label_9);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName("label_8");
        sizePolicy10.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy10);
        label_8->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	font: 700 12pt \"Segoe UI\";\n"
"}"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(label_8);

        horizontalSlider_2 = new QSlider(frame_5);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setEnabled(true);
        sizePolicy11.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy11);
        horizontalSlider_2->setMinimumSize(QSize(300, 0));
        horizontalSlider_2->setStyleSheet(QString::fromUtf8("QSlider{\n"
"	margin-right:100px;\n"
"}"));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(10);
        horizontalSlider_2->setSingleStep(1);
        horizontalSlider_2->setPageStep(10);
        horizontalSlider_2->setValue(0);
        horizontalSlider_2->setSliderPosition(0);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickInterval(0);

        horizontalLayout_14->addWidget(horizontalSlider_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        horizontalLayout_13->addLayout(horizontalLayout_14);


        verticalLayout_4->addWidget(frame_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        sizePolicy7.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy7);

        horizontalLayout_6->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        sizePolicy7.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy7);

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setEnabled(true);
        sizePolicy11.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy11);
        radioButton->setStyleSheet(QString::fromUtf8(""));
        radioButton->setChecked(true);

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName("radioButton_2");
        sizePolicy11.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy11);

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        applyBtn = new QPushButton(centralwidget);
        applyBtn->setObjectName("applyBtn");
        sizePolicy2.setHeightForWidth(applyBtn->sizePolicy().hasHeightForWidth());
        applyBtn->setSizePolicy(sizePolicy2);
        applyBtn->setMinimumSize(QSize(150, 50));
        applyBtn->setMaximumSize(QSize(16777215, 16777215));
        applyBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 24px;\n"
"}"));
        applyBtn->setAutoDefault(false);
        applyBtn->setFlat(false);

        horizontalLayout_7->addWidget(applyBtn);


        verticalLayout_4->addLayout(horizontalLayout_7);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(150, 150));
        frame_2->setMaximumSize(QSize(150, 150));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	border-image: url(\"logo-color.png\") 0 0 0 0 stretch stretch;\n"
"	background-color:rgb(220, 220, 220);\n"
"	background-position: center;\n"
"	background-repeat: no-repeat;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_10->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName("pushButton");
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(150, 35));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        pushButton->setFlat(false);

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(frame_3);
        label->setObjectName("label");
        sizePolicy10.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy10);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);


        verticalLayout_5->addLayout(horizontalLayout);

        clearBtn = new QPushButton(frame_3);
        clearBtn->setObjectName("clearBtn");
        sizePolicy2.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy2);
        clearBtn->setMinimumSize(QSize(150, 35));
        clearBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        clearBtn->setFlat(false);

        verticalLayout_5->addWidget(clearBtn);

        saveBtn = new QPushButton(frame_3);
        saveBtn->setObjectName("saveBtn");
        sizePolicy2.setHeightForWidth(saveBtn->sizePolicy().hasHeightForWidth());
        saveBtn->setSizePolicy(sizePolicy2);
        saveBtn->setMinimumSize(QSize(150, 35));
        saveBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        saveBtn->setFlat(false);

        verticalLayout_5->addWidget(saveBtn);


        horizontalLayout_10->addWidget(frame_3);


        verticalLayout_4->addWidget(frame);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        sizePolicy6.setHeightForWidth(errorLabel->sizePolicy().hasHeightForWidth());
        errorLabel->setSizePolicy(sizePolicy6);
        QFont font4;
        font4.setPointSize(12);
        errorLabel->setFont(font4);
        errorLabel->setLayoutDirection(Qt::LeftToRight);
        errorLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: red;\n"
"}"));
        errorLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_4->addWidget(errorLabel);

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
        Invert->setText(QCoreApplication::translate("MainWindow", "Invert", nullptr));
        TVEffect->setText(QCoreApplication::translate("MainWindow", "TV Effect", nullptr));
        GrayscaleBtn->setText(QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        EdgeDetection->setText(QCoreApplication::translate("MainWindow", "Edge detection", nullptr));
        BWBtn->setText(QCoreApplication::translate("MainWindow", "Black and white filter", nullptr));
        brightnessBtn->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        RotateBtn->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        FlipBtn->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        nightMoodBtn->setText(QCoreApplication::translate("MainWindow", "Night Mood", nullptr));
        mergeBtn->setText(QCoreApplication::translate("MainWindow", "Merge", nullptr));
        CropBtn->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        Sepia->setText(QCoreApplication::translate("MainWindow", "Sepia", nullptr));
        BlurBtn->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        sunLightBtn->setText(QCoreApplication::translate("MainWindow", "Sun Light", nullptr));
        Purple->setText(QCoreApplication::translate("MainWindow", "Purple", nullptr));
        Infrared->setText(QCoreApplication::translate("MainWindow", "Infrared", nullptr));
        SkewBtn->setText(QCoreApplication::translate("MainWindow", "Skew", nullptr));
        ResizeBtn->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        OilPaint->setText(QCoreApplication::translate("MainWindow", "Oil Paint", nullptr));
        FrameBtn->setText(QCoreApplication::translate("MainWindow", "Frame", nullptr));
        options_label->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        loadNewImage->setText(QCoreApplication::translate("MainWindow", "Load second image", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Merge Options", nullptr));
        CommonArea->setText(QCoreApplication::translate("MainWindow", "Common Area", nullptr));
        ResizeMerge->setText(QCoreApplication::translate("MainWindow", "Resize Both", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Brightness level", nullptr));
        lineEdit_1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Start X", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Start Y", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Common Frame", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Fancy frame", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "Gradient Frame ", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "colors", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Pick a color", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "blue strength", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "yellow strength", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        resize_width->setPlaceholderText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        resize_height->setPlaceholderText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Degree of Skew", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Degree", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Blur strength", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "horizontally", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "verticlay", nullptr));
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
