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
    QGridLayout *gridLayout;
    QPushButton *BWBtn;
    QPushButton *CropBtn;
    QPushButton *ResizeBtn;
    QPushButton *FlipBtn;
    QLabel *options_label;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *resize_width;
    QLineEdit *resize_height;
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
        MainWindow->resize(966, 786);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color:  qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 100, 102, 255), stop:1 rgba(27, 58, 75, 255));\n"
"	color: #4D194D;\n"
"}\n"
"QPushButton{\n"
"	background-color:  rgba(255, 255, 255,255);\n"
"	color:rgba(77, 25, 77,255);\n"
"	border-radius: 30%;\n"
"	font-size: 14px;\n"
"	font-weight: 600;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:  rgba(160, 160, 160,255);\n"
"}\n"
"QRadioButton{\n"
"	color:#9C5C9C ;\n"
"	font-weight: 500;\n"
"}\n"
"QLabel{\n"
"	color: #9C5C9C;\n"
"}\n"
"QLineEdit{\n"
"	border-radius: 18%;\n"
"	padding: 8px 4px;\n"
"	background-color:  transparent;\n"
"	color: #9C5C9C;\n"
"	 border: 1px solid #9C5C9C;\n"
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        FromImage = new QFrame(centralwidget);
        FromImage->setObjectName("FromImage");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(FromImage->sizePolicy().hasHeightForWidth());
        FromImage->setSizePolicy(sizePolicy1);
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
        sizePolicy.setHeightForWidth(FromImageSize->sizePolicy().hasHeightForWidth());
        FromImageSize->setSizePolicy(sizePolicy);
        FromImageSize->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(FromImageSize);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        ToImage = new QFrame(centralwidget);
        ToImage->setObjectName("ToImage");
        sizePolicy1.setHeightForWidth(ToImage->sizePolicy().hasHeightForWidth());
        ToImage->setSizePolicy(sizePolicy1);
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
        sizePolicy.setHeightForWidth(ToImageSize->sizePolicy().hasHeightForWidth());
        ToImageSize->setSizePolicy(sizePolicy);
        ToImageSize->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(ToImageSize);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(12);
        BWBtn = new QPushButton(centralwidget);
        BWBtn->setObjectName("BWBtn");
        sizePolicy1.setHeightForWidth(BWBtn->sizePolicy().hasHeightForWidth());
        BWBtn->setSizePolicy(sizePolicy1);
        BWBtn->setMinimumSize(QSize(300, 70));
        QFont font1;
        font1.setWeight(QFont::DemiBold);
        BWBtn->setFont(font1);
        BWBtn->setLayoutDirection(Qt::LeftToRight);
        BWBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(BWBtn, 1, 0, 1, 1);

        CropBtn = new QPushButton(centralwidget);
        CropBtn->setObjectName("CropBtn");
        sizePolicy1.setHeightForWidth(CropBtn->sizePolicy().hasHeightForWidth());
        CropBtn->setSizePolicy(sizePolicy1);
        CropBtn->setMinimumSize(QSize(300, 70));
        CropBtn->setFont(font1);
        CropBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(CropBtn, 4, 0, 1, 1);

        ResizeBtn = new QPushButton(centralwidget);
        ResizeBtn->setObjectName("ResizeBtn");
        sizePolicy1.setHeightForWidth(ResizeBtn->sizePolicy().hasHeightForWidth());
        ResizeBtn->setSizePolicy(sizePolicy1);
        ResizeBtn->setMinimumSize(QSize(300, 70));
        ResizeBtn->setFont(font1);
        ResizeBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ResizeBtn, 2, 0, 1, 1);

        FlipBtn = new QPushButton(centralwidget);
        FlipBtn->setObjectName("FlipBtn");
        sizePolicy1.setHeightForWidth(FlipBtn->sizePolicy().hasHeightForWidth());
        FlipBtn->setSizePolicy(sizePolicy1);
        FlipBtn->setMinimumSize(QSize(300, 70));
        FlipBtn->setFont(font1);
        FlipBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(FlipBtn, 3, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout);


        verticalLayout_5->addLayout(horizontalLayout_5);

        options_label = new QLabel(centralwidget);
        options_label->setObjectName("options_label");
        QFont font2;
        font2.setPointSize(20);
        options_label->setFont(font2);

        verticalLayout_5->addWidget(options_label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy2);
        radioButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName("radioButton_2");
        sizePolicy2.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_1 = new QLineEdit(centralwidget);
        lineEdit_1->setObjectName("lineEdit_1");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_1->sizePolicy().hasHeightForWidth());
        lineEdit_1->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(lineEdit_1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        sizePolicy3.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy3.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(lineEdit_2);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        sizePolicy3.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        resize_width = new QLineEdit(centralwidget);
        resize_width->setObjectName("resize_width");
        sizePolicy3.setHeightForWidth(resize_width->sizePolicy().hasHeightForWidth());
        resize_width->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(resize_width);

        resize_height = new QLineEdit(centralwidget);
        resize_height->setObjectName("resize_height");
        sizePolicy3.setHeightForWidth(resize_height->sizePolicy().hasHeightForWidth());
        resize_height->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(resize_height);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        applyBtn = new QPushButton(centralwidget);
        applyBtn->setObjectName("applyBtn");
        sizePolicy1.setHeightForWidth(applyBtn->sizePolicy().hasHeightForWidth());
        applyBtn->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(150, 35));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        pushButton->setFlat(false);

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        QFont font3;
        font3.setPointSize(18);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        sizePolicy1.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy1);
        clearBtn->setMinimumSize(QSize(150, 35));
        clearBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        clearBtn->setFlat(false);

        verticalLayout->addWidget(clearBtn);

        saveBtn = new QPushButton(centralwidget);
        saveBtn->setObjectName("saveBtn");
        sizePolicy1.setHeightForWidth(saveBtn->sizePolicy().hasHeightForWidth());
        saveBtn->setSizePolicy(sizePolicy1);
        saveBtn->setMinimumSize(QSize(150, 35));
        saveBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 15%;\n"
"}"));
        saveBtn->setFlat(false);

        verticalLayout->addWidget(saveBtn);


        verticalLayout_5->addLayout(verticalLayout);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(errorLabel->sizePolicy().hasHeightForWidth());
        errorLabel->setSizePolicy(sizePolicy5);
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
        menubar->setGeometry(QRect(0, 0, 966, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        applyBtn->setDefault(false);
        pushButton->setDefault(false);
        clearBtn->setDefault(false);
        saveBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        FromImageSize->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        ToImageSize->setText(QString());
        BWBtn->setText(QCoreApplication::translate("MainWindow", "Black and white filter", nullptr));
        CropBtn->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        ResizeBtn->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        FlipBtn->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        options_label->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "horizontally", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "verticlay", nullptr));
        lineEdit_1->setPlaceholderText(QCoreApplication::translate("MainWindow", "From X", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "To X", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "From Y", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "To Y", nullptr));
        resize_width->setPlaceholderText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        resize_height->setPlaceholderText(QCoreApplication::translate("MainWindow", "Height", nullptr));
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
