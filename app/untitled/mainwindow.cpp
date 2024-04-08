// #006466 main
// #212F45 accent color
// #4D194D second accent color

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QObject>
#include <QDebug>
#include "Image_Class.h"
#include <QIntValidator>
#include <QPropertyAnimation>
using namespace std;

Image my_image;
Image to_image;

QThread* secT;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton->setVisible(false);
    ui->radioButton_2->setVisible(false);
    ui->lineEdit_1->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
    ui->pushButton->setCursor(Qt::PointingHandCursor);
    ui->BWBtn->setCursor(Qt::PointingHandCursor);
    ui->ResizeBtn->setCursor(Qt::PointingHandCursor);
    ui->CropBtn->setCursor(Qt::PointingHandCursor);
    ui->FlipBtn->setCursor(Qt::PointingHandCursor);

    Drop_Shadow_Effect = new QGraphicsDropShadowEffect();
    Drop_Shadow_Effect->setBlurRadius(30);
    Drop_Shadow_Effect->setColor(QColor(15,15,15,255));
    Drop_Shadow_Effect->setOffset(0,0);

    // QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    // animation->setDuration(300); // Adjust duration as needed (in milliseconds)
    // animation->setStartValue(QRect(widget->x(), widget->y(), widget->width(), widget->height()));
    // animation->setEndValue(QRect(newX, newY, newWidth, newHeight));
    // animation->start();
}


MainWindow::~MainWindow()
{
    delete ui;
}



QString path;
void MainWindow::disableObtions(){
    ui->radioButton->setVisible(false);
    ui->radioButton_2->setVisible(false);
    ui->lineEdit_1->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
}

void loadingImage(){
    qDebug() << "validating";
    my_image.loadNewImage(path.toStdString());
    my_image.saveImage("test.jpg");
    to_image.loadNewImage("test.jpg");
    qDebug() << "validating";
    QMetaObject::invokeMethod(secT,"finished",Qt::QueuedConnection);
}

void MainWindow::on_pushButton_clicked()
{
    QString filter = "JPG image (*.jpg) ;; PNG image (*.png)";
    path = QFileDialog::getOpenFileName(this,"Chose an image file",QDir::homePath(),filter);
    QString file_name;
    // C:\Me\college\structured programming\assignment3\app\build-untitled-Desktop.jpg
    for(int i = path.size() - 1;i >= 0;i--){
        if(path[i] == '/'){
            break;
        }
        file_name += path[i];
    }
    for(int i = file_name.size() - 1;i >= file_name.size()/2;i--){
        QChar c = file_name[i];
        file_name[i] = file_name[file_name.size() - i - 1];
        file_name[file_name.size() - i - 1] = c;
    }
    if(path.size() != 0){
        secT = QThread::create(loadingImage);
        connect(secT,&QThread::finished,[=](){
            ui->label->setText(file_name);
            ui->FromImage->setStyleSheet("border-image: url(\""+path+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
            ui->ToImage->setStyleSheet("border-image: url(\""+path+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
            ui->lineEdit_1->setValidator( new QIntValidator(0, my_image.width, this) );
            ui->lineEdit_2->setValidator( new QIntValidator(0, my_image.height, this) );
            ui->lineEdit_3->setValidator( new QIntValidator(0, my_image.width, this) );
            ui->lineEdit_4->setValidator( new QIntValidator(0, my_image.height, this) );
        });
        secT->start();
    }
}
void MainWindow::on_pushButton_7_clicked()
{
    path = QFileDialog::getExistingDirectory(this,"Chose a folder",QDir::homePath());
    qDebug() << to_image.imageData;
    qDebug() << path;
    if(to_image.imageData != 0x0)
        to_image.saveImage(path.toStdString());
}
void BWFilter(){
    qDebug() << "inside a filter";
    // Grayscale conversion using weighted average
    for (int i = 0; i < my_image.width; ++i) {
        for (int j = 0; j < my_image.height; ++j) {
            int avg = 0;
            for(int k = 0;k < 3;k++){
                avg += my_image(i,j,k);
            }
            avg /= 3;
            avg = (avg > 127 ? 255 : 0);
            my_image(i,j,0) = avg;
            my_image(i,j,1) = avg;
            my_image(i,j,2) = avg;
        }
    }
    // Save the processed image
    my_image.saveImage("test.jpg");
    to_image = my_image;
    my_image.loadNewImage(path.toStdString());
    qDebug() << "finished proccess";
    QMetaObject::invokeMethod(secT, "finished", Qt::QueuedConnection);
}

void cropFilter(int fromX,int fromY,int toX,int toY){
    qDebug() << "inside a Crop filter " << fromX << ' ' << fromY;
    qDebug() << toX << ' ' << toY;

    Image newImage(toX - fromX + 1,toY - fromY + 1);

    int counterX = 0,counterY = 0;

    for(int i = fromX - 1;i < toX;i++){
        for(int j = fromY - 1;j < toY;j++){
            for(int k = 0;k < 3;k++){
                newImage(counterX,counterY,k) = my_image(i,j,k);
            }
            counterY++;
        }
        counterX++;
        counterY = 0;
    }
    // Save the processed image
    newImage.saveImage("test.jpg");
    to_image = newImage;
    qDebug() << "finished proccess";
    QMetaObject::invokeMethod(secT, "finished", Qt::QueuedConnection);
}
void flip(bool choice){
    if(!choice){
        for(int i = 0;i < my_image.width;i++){
            for(int j = 0;j < my_image.height/2;j++){
                for(int k = 0;k < 3;k++){
                    int p = my_image(i,j,k);
                    my_image(i,j,k) = my_image(i,my_image.height - j - 1,k);
                    my_image(i,my_image.height - j - 1,k) = p;
                }
            }
        }
    }else{
        for(int i = 0;i < my_image.width/2;i++){
            for(int j = 0;j < my_image.height;j++){
                for(int k = 0;k < 3;k++){
                    int p = my_image(i,j,k);
                    my_image(i,j,k) = my_image(my_image.width - i - 1,j,k);
                    my_image(my_image.width - i - 1,j,k) = p;
                }
            }
        }
    }
    my_image.saveImage("test.jpg");
    to_image = my_image;
    my_image.loadNewImage(path.toStdString());
    QMetaObject::invokeMethod(secT,"finished",Qt::QueuedConnection);
}

void MainWindow::on_BWBtn_clicked()
{
    if(path.size() != 0){
        QString testPath = QDir::currentPath() + "/test.jpg";
        secT = QThread::create(BWFilter);
        connect(secT,&QThread::finished,[=](){
            qDebug() << "hello lambda";
            ui->ToImage->setStyleSheet("border-image: url(\""+testPath+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
        });
        secT->start();
    }
}

void MainWindow::on_FlipBtn_clicked()
{
    if(path.size() != 0){
        QString testPath = QDir::currentPath() + "/test.jpg";
        secT = QThread::create(flip,ui->radioButton->isChecked());
        connect(secT,&QThread::finished,[=](){
            qDebug() << "inside a lambda";
            ui->ToImage->setStyleSheet("border-image: url(\""+testPath+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
        });
        secT->start();
    }
}

void MainWindow::on_CropBtn_clicked()
{
    string firstFrom = ui->lineEdit_1->displayText().toStdString(),
        secondFrom = ui->lineEdit_2->displayText().toStdString(),
        firstTo = ui->lineEdit_3->displayText().toStdString(),
        secondTo = ui->lineEdit_4->displayText().toStdString();
    if(!ui->lineEdit_1->isVisible()){
        disableObtions();
        ui->lineEdit_1->setVisible(true);
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->lineEdit_4->setVisible(true);
    }else if(!(stoi(firstFrom) < 0 || stoi(firstFrom) > my_image.width - 1) &&
               !(stoi(secondFrom) < 0 || stoi(secondFrom) > my_image.width - 1) &&
               !(stoi(firstTo) < 0 || stoi(firstTo) > my_image.height - 1) &&
               !(stoi(secondTo) < 0 || stoi(secondTo) > my_image.height - 1)){
        if(path.size() != 0){
            qDebug() << "inside a click";
            secT = QThread::create(cropFilter,stoi(firstFrom),stoi(secondFrom),stoi(firstTo),stoi(secondTo));
            QString testPath = QDir::currentPath() + "/test.jpg";
            connect(secT,&QThread::finished,[=](){
                qDebug() << "hello lambda";
                ui->ToImage->setStyleSheet("border-image: url(\""+testPath+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
            });
            secT->start();
            qDebug() << "outside a click";
        }
    }
}


void MainWindow::on_ResizeBtn_clicked()
{

}



