#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QObject>
#include <QDebug>
#include "Image_Class.h"
#include <QIntValidator>
using namespace std;

Image my_image;
QThread* secT;
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
    my_image = newImage;
    qDebug() << "finished proccess";
    QMetaObject::invokeMethod(secT, "finished", Qt::QueuedConnection);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    Drop_Shadow_Effect = new QGraphicsDropShadowEffect();

    ui->setupUi(this);
    ui->pushButton->setCursor(Qt::PointingHandCursor);
    ui->pushButton_2->setCursor(Qt::PointingHandCursor);
    ui->pushButton_3->setCursor(Qt::PointingHandCursor);
    ui->pushButton_4->setCursor(Qt::PointingHandCursor);

    Drop_Shadow_Effect->setBlurRadius(30);
    Drop_Shadow_Effect->setColor(QColor(15,15,15,255));
    Drop_Shadow_Effect->setOffset(0,0);
    ui->frame->setGraphicsEffect(Drop_Shadow_Effect);



}


MainWindow::~MainWindow()
{
    delete ui;
}
QString path;

void MainWindow::on_pushButton_clicked()
{
    QString filter = "JPG image (*.jpg) ;; PNG image (*.png)";
    path = QFileDialog::getOpenFileName(this,"Chose an image file",QDir::homePath(),filter);
    QString file_name;
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
        // this->glob_image.loadNewImage(path.toStdString());
        // emit imageChanged(this->glob_image);
        // for(int i = 0;i < ;)
        my_image.loadNewImage(path.toStdString());
        my_image.saveImage("test.jpg");
        my_image.loadNewImage("test.jpg");
        ui->label->setText(file_name);
        ui->frame_2->setStyleSheet("border-image: url(\""+path+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat;");
        ui->lineEdit_1->setValidator( new QIntValidator(0, my_image.width, this) );
        ui->lineEdit_2->setValidator( new QIntValidator(0, my_image.height, this) );
        ui->lineEdit_3->setValidator( new QIntValidator(0, my_image.width, this) );
        ui->lineEdit_4->setValidator( new QIntValidator(0, my_image.height, this) );
        qDebug() << "validating";
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(path.size() != 0){
        QString testPath = QDir::currentPath() + "/test.jpg";
        secT = QThread::create(BWFilter);
        connect(secT,&QThread::finished,[=](){
            qDebug() << "hello lambda";
            ui->frame_2->setStyleSheet("border-image: url(\""+testPath+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat;");
        });
        qDebug() << "inside a click";
        QThread* secT = QThread::create(BWFilter);
        secT->start();
        qDebug() << "outside a click";
    }
}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{
    if(path.size() != 0){
        qDebug() << "inside a click";
        string firstFrom = ui->lineEdit_1->displayText().toStdString(),
            secondFrom = ui->lineEdit_2->displayText().toStdString(),
            firstTo = ui->lineEdit_3->displayText().toStdString(),
            secondTo = ui->lineEdit_4->displayText().toStdString();
        secT = QThread::create(cropFilter,stoi(firstFrom),stoi(secondFrom),stoi(firstTo),stoi(secondTo));
        QString testPath = QDir::currentPath() + "/test.jpg";
        connect(secT,&QThread::finished,[=](){
            qDebug() << "hello lambda";
            ui->frame_2->setStyleSheet("border-image: url(\""+testPath+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat;");
        });
        secT->start();
        qDebug() << "outside a click";
    }
}

