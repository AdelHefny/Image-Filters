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
    QGridLayout *gridLayout;
    QPushButton *BWBtn;
    QPushButton *ResizeBtn;
    QPushButton *FlipBtn;
    QPushButton *CropBtn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLabel *errorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(962, 611);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color:  qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 100, 102, 255), stop:1 rgba(27, 58, 75, 255));\n"
"	color: #4D194D;\n"
"}\n"
"QPushButton{\n"
"	background-color:  #ffffff;\n"
"	color:#4D194D;\n"
"	border-radius: 16px;\n"
"	font-size: 14px;\n"
"	font-weight: 600;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:  #9C5C9C;\n"
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

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
        BWBtn = new QPushButton(centralwidget);
        BWBtn->setObjectName("BWBtn");
        sizePolicy1.setHeightForWidth(BWBtn->sizePolicy().hasHeightForWidth());
        BWBtn->setSizePolicy(sizePolicy1);
        BWBtn->setMinimumSize(QSize(300, 60));
        QFont font;
        font.setWeight(QFont::DemiBold);
        BWBtn->setFont(font);
        BWBtn->setLayoutDirection(Qt::LeftToRight);
        BWBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(BWBtn, 0, 0, 1, 1);

        ResizeBtn = new QPushButton(centralwidget);
        ResizeBtn->setObjectName("ResizeBtn");
        sizePolicy1.setHeightForWidth(ResizeBtn->sizePolicy().hasHeightForWidth());
        ResizeBtn->setSizePolicy(sizePolicy1);
        ResizeBtn->setMinimumSize(QSize(300, 60));
        ResizeBtn->setFont(font);
        ResizeBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ResizeBtn, 1, 0, 1, 1);

        FlipBtn = new QPushButton(centralwidget);
        FlipBtn->setObjectName("FlipBtn");
        sizePolicy1.setHeightForWidth(FlipBtn->sizePolicy().hasHeightForWidth());
        FlipBtn->setSizePolicy(sizePolicy1);
        FlipBtn->setMinimumSize(QSize(300, 60));
        FlipBtn->setFont(font);
        FlipBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(FlipBtn, 2, 0, 1, 1);

        CropBtn = new QPushButton(centralwidget);
        CropBtn->setObjectName("CropBtn");
        sizePolicy1.setHeightForWidth(CropBtn->sizePolicy().hasHeightForWidth());
        CropBtn->setSizePolicy(sizePolicy1);
        CropBtn->setMinimumSize(QSize(300, 60));
        CropBtn->setFont(font);
        CropBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(CropBtn, 3, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(150, 50));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setFlat(false);

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(150, 50));
        pushButton_6->setStyleSheet(QString::fromUtf8(""));
        pushButton_6->setFlat(false);

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(150, 50));
        pushButton_7->setStyleSheet(QString::fromUtf8(""));
        pushButton_7->setFlat(false);

        verticalLayout->addWidget(pushButton_7);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy3);
        radioButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName("radioButton_2");
        sizePolicy3.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(radioButton_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEdit_1 = new QLineEdit(centralwidget);
        lineEdit_1->setObjectName("lineEdit_1");

        horizontalLayout_4->addWidget(lineEdit_1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_4->addWidget(lineEdit_3);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_4->addWidget(lineEdit_2);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout_4->addLayout(horizontalLayout_4);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");

        verticalLayout_4->addWidget(errorLabel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 962, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton->setDefault(false);
        pushButton_6->setDefault(false);
        pushButton_7->setDefault(false);


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
        ResizeBtn->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        FlipBtn->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        CropBtn->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Load image", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "horizontally", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "verticlay", nullptr));
        lineEdit_1->setPlaceholderText(QCoreApplication::translate("MainWindow", "From X", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "To X", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "From Y", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "To Y", nullptr));
        errorLabel->setText(QCoreApplication::translate("MainWindow", "eror message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
