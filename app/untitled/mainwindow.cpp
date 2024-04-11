// #006466 main
// #212F45 accent color
// #4D194D second accent color

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QObject>
#include <QMovie>
#include <QDebug>
#include "Image_Class.h"
#include <QIntValidator>
#include <QPropertyAnimation>
using namespace std;

Image my_image;
Image to_image;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    disableObtions();
    ui->pushButton->setCursor(Qt::PointingHandCursor);
    ui->BWBtn->setCursor(Qt::PointingHandCursor);
    ui->ResizeBtn->setCursor(Qt::PointingHandCursor);
    ui->CropBtn->setCursor(Qt::PointingHandCursor);
    ui->FlipBtn->setCursor(Qt::PointingHandCursor);
    ui->clearBtn->setCursor(Qt::PointingHandCursor);
    ui->saveBtn->setCursor(Qt::PointingHandCursor);
    ui->applyBtn->setCursor(Qt::PointingHandCursor);

    Drop_Shadow_Effect = new QGraphicsDropShadowEffect();
    Drop_Shadow_Effect->setBlurRadius(30);
    Drop_Shadow_Effect->setColor(QColor(15,15,15,255));
    Drop_Shadow_Effect->setOffset(0,0);

    connect(this,&MainWindow::filterFinished,this,&MainWindow::updateToImage);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::disableObtions(){
    ui->resize_width->setVisible(false);
    ui->resize_height->setVisible(false);
    ui->radioButton->setVisible(false);
    ui->radioButton_2->setVisible(false);
    ui->lineEdit_1->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
    ui->options_label->setVisible(false);
    ui->applyBtn->setVisible(false);
}
void MainWindow::loadingFilter(){
    bool val = !ui->BWBtn->isEnabled();
    ui->BWBtn->setEnabled(val);
    ui->CropBtn->setEnabled(val);
    ui->FlipBtn->setEnabled(val);
    ui->ResizeBtn->setEnabled(val);
    if(!val){
        ui->BWBtn->setStyleSheet("QPushButton{background-color:  rgba(255, 255, 255,200);color:rgba(77, 25, 77,200);}");
        ui->CropBtn->setStyleSheet("background-color:  rgba(255, 255, 255,200);color:rgba(77, 25, 77,200);");
        ui->FlipBtn->setStyleSheet("background-color:  rgba(255, 255, 255,200);color:rgba(77, 25, 77,200);");
        ui->ResizeBtn->setStyleSheet("background-color:  rgba(255, 255, 255,200);color:rgba(77, 25, 77,200);");
    }else{
        ui->BWBtn->setStyleSheet("QPushButton{background-color:  rgba(255, 255, 255,255);color:rgba(77, 25, 77,255);}"
            "QPushButton:hover{background-color:  rgb(156, 92, 156);}");
        ui->CropBtn->setStyleSheet("QPushButton{background-color:  rgba(255, 255, 255,255);color:rgba(77, 25, 77,255);}"
            "QPushButton:hover{background-color:  rgb(156, 92, 156);}");
        ui->FlipBtn->setStyleSheet("QPushButton{background-color:  rgba(255, 255, 255,255);color:rgba(77, 25, 77,255);}"
            "QPushButton:hover{background-color:  rgb(156, 92, 156);}");
        ui->ResizeBtn->setStyleSheet("QPushButton{background-color:  rgba(255, 255, 255,255);color:rgba(77, 25, 77,255);}"
            "QPushButton:hover{background-color:  rgb(156, 92, 156);}");
    }
}

void MainWindow::assigningBtnsText(){
    ui->BWBtn->setText("Black and white filter");
    ui->ResizeBtn->setText("Resize");
    ui->FlipBtn->setText("Flip");
    ui->CropBtn->setText("Crop");
}

void MainWindow::clearFilterBtn(QPushButton* btn){
    QLayout *layout = btn->layout();
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            layout->removeWidget(widget);
            delete widget;
        }
        delete item;
    }
}

void loadingImage(QString path,QThread *secT,MainWindow *mainwindow){
    my_image.loadNewImage(path.toStdString());
    my_image.saveImage("test.jpg");
    to_image.loadNewImage("test.jpg");
    emit mainwindow->imageLoaded();
}

void MainWindow::updateGui(){
    ui->label->setText(file_name);
    QString h = QString::fromStdString(to_string(my_image.height)), w =QString::fromStdString(to_string(my_image.width));
    ui->FromImageSize->setText(w + "X" + h);
    ui->ToImageSize->setText(w + "X" + h);
    ui->FromImage->setStyleSheet("border-image: url(\""+path+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
    ui->ToImage->setStyleSheet("border-image: url(\""+path+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
    ui->lineEdit_1->setValidator( new QIntValidator(1, my_image.width, this) );
    ui->lineEdit_2->setValidator( new QIntValidator(1, my_image.height, this) );
    ui->lineEdit_3->setValidator( new QIntValidator(1, my_image.width, this) );
    ui->lineEdit_4->setValidator( new QIntValidator(1, my_image.height, this) );
};

void MainWindow::on_pushButton_clicked()
{
    QString filter = "JPG image (*.jpg) ;; PNG image (*.png)";
    path = QFileDialog::getOpenFileName(this,"Chose an image file",QDir::homePath(),filter);
    if(path.size() != 0){
        file_name = "";
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
        connect(this,&MainWindow::imageLoaded,this,&MainWindow::updateGui);
        secT = QThread::create(loadingImage,path,secT,this);
        secT->start();
    }
}
void MainWindow::on_saveBtn_clicked()
{
    QString save_path = QFileDialog::getExistingDirectory(this,"Chose a folder",QDir::homePath());
    qDebug() << save_path.toStdString() + '/' + file_name.toStdString();
    if(to_image.imageData != 0x0)
        to_image.saveImage(save_path.toStdString() + '/' +  file_name.toStdString() + ".jpg");
}

void MainWindow::updateToImage(QPushButton* btn){
    QString testPath = QDir::currentPath() + "/test.jpg";
    ui->ToImage->setStyleSheet("border-image: url(\""+testPath+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
    ui->ToImageSize->setText(QString::fromStdString(to_string(to_image.width)) + "X" + QString::fromStdString(to_string(to_image.height)));
    clearFilterBtn(btn);
    assigningBtnsText();
    loadingFilter();
}

void BWFilter(QThread *secT,QString path,MainWindow* mainwindow,QPushButton* btn){
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
    emit mainwindow->filterFinished(btn);
}
void MainWindow::on_BWBtn_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(BWFilter,secT,path,this,ui->BWBtn);
        secT->start();

        ui->BWBtn->setText("");
        QLabel* spinnerLabel = new QLabel(this);

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinnerLabel->setStyleSheet("background-color:transparent;");
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);

        delete ui->BWBtn->layout();
        ui->BWBtn->setLayout(layout);

    }
}
void flip(bool choice,QThread *secT,QString path,MainWindow* mainwindow,QPushButton* btn){
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
    emit mainwindow->filterFinished(btn);
}
void MainWindow::on_FlipBtn_clicked()
{
    if(!ui->radioButton->isVisible()){
        disableObtions();
        ui->applyBtn->setVisible(true);
        ui->options_label->setVisible(true);
        ui->radioButton->setVisible(true);
        ui->radioButton_2->setVisible(true);
        optionsFor = ui->FlipBtn;
    }else if(path.size() != 0){
        loadingFilter();
        secT = QThread::create(flip,ui->radioButton->isChecked(),secT,path,this,ui->FlipBtn);
        secT->start();
        ui->FlipBtn->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->FlipBtn->layout();
        ui->FlipBtn->setLayout(layout);
    }
}
void cropFilter(int fromX,int fromY,int toX,int toY,QThread *secT,MainWindow* mainwindow,QPushButton* btn,QString path){
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
    emit mainwindow->filterFinished(btn);
}
void MainWindow::on_CropBtn_clicked()
{
    string firstFrom = ui->lineEdit_1->displayText().toStdString(),
        secondFrom = ui->lineEdit_2->displayText().toStdString(),
        firstTo = ui->lineEdit_3->displayText().toStdString(),
        secondTo = ui->lineEdit_4->displayText().toStdString();
    qDebug() << firstFrom << ' ' << secondFrom << ' ' << firstTo << ' ' << secondTo;
    if(!ui->lineEdit_1->isVisible()){
        disableObtions();
        ui->applyBtn->setVisible(true);
        ui->options_label->setVisible(true);
        ui->lineEdit_1->setVisible(true);
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->lineEdit_4->setVisible(true);
        optionsFor = ui->CropBtn;
    }else if(firstFrom.empty() || secondFrom.empty() || firstTo.empty() || secondTo.empty()){}
    else if(!(stoi(firstFrom) <= 0 || stoi(firstFrom) > my_image.width - 1) &&
               !(stoi(firstTo) <= 0 || stoi(firstTo) > my_image.width - 1) &&
               !(stoi(secondFrom) <= 0 || stoi(secondFrom) > my_image.height - 1) &&
               !(stoi(secondTo) <= 0 || stoi(secondTo) > my_image.height - 1)){
        if(path.size() != 0){
            loadingFilter();
            secT = QThread::create(cropFilter,stoi(firstFrom),stoi(secondFrom),stoi(firstTo),stoi(secondTo),secT,this,ui->CropBtn,path);
            secT->start();
            ui->CropBtn->setText("");
            QLabel* spinnerLabel = new QLabel(this);
            spinnerLabel->setStyleSheet("background-color:transparent;");
            QMovie* spinner = new QMovie("spinner.gif");

            spinnerLabel->setMovie(spinner);
            spinner->start();

            QGridLayout* layout = new QGridLayout();
            layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
            delete ui->CropBtn->layout();
            ui->CropBtn->setLayout(layout);
        }
    }else{
        ui->errorLabel->setText("invalid crop values");
    }
}

void resizeFilter(int newWidth,int newHeight,QThread *secT,MainWindow* mainwindow,QPushButton* btn,QString path){
    // creating a new image with the desired width and height
    Image newImage(newWidth,newHeight);
    int oldWidth = my_image.width,oldHeight = my_image.height;
    // getting the relative width and height
    float relativeWidth = (float)newWidth/my_image.width,relativeHeight = (float)newHeight/my_image.height;

    for(int i = 0;i < newImage.width;i++){
        for(int j = 0;j < newImage.height;j++){
            int x = floor((float)i/relativeWidth),y = floor((float)j/relativeHeight);
            // checking the x-axis if it is in inside the old image
            if(x > oldWidth - 1){
                x = oldWidth - 1;
            }else if(x < 0){
                x = 0;
            }
            // checking the y-axis if it is in inside the old image
            if(y > oldHeight - 1){
                y = oldHeight - 1;
            }else if(y < 0){
                y = 0;
            }
            // setting the new image pixel
            newImage(i,j,0) = my_image(x,y,0);
            newImage(i,j,1) = my_image(x,y,1);
            newImage(i,j,2) = my_image(x,y,2);
        }
    }
    // Save the processed image
    newImage.saveImage("test.jpg");
    to_image = newImage;
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_ResizeBtn_clicked()
{
    int width = ui->resize_width->text().toInt(),height = ui->resize_height->text().toInt();
    if(!ui->resize_width->isVisible()){
        disableObtions();
        ui->applyBtn->setVisible(true);
        ui->options_label->setVisible(true);
        ui->resize_width->setVisible(true);
        ui->resize_height->setVisible(true);
        optionsFor = ui->ResizeBtn;
    }else if(!(width <= 0) &&
               !(height <= 0)){
        if(path.size() != 0){
            loadingFilter();
            secT = QThread::create(resizeFilter,width,height,secT,this,ui->ResizeBtn,path);
            secT->start();
            ui->ResizeBtn->setText("");
            QLabel* spinnerLabel = new QLabel(this);
            spinnerLabel->setStyleSheet("background-color:transparent;");
            QMovie* spinner = new QMovie("spinner.gif");

            spinnerLabel->setMovie(spinner);
            spinner->start();

            QGridLayout* layout = new QGridLayout();
            layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
            delete ui->ResizeBtn->layout();
            ui->ResizeBtn->setLayout(layout);
        }
    }else{
        ui->errorLabel->setText("invalid width or height value");
    }
}

void MainWindow::on_clearBtn_clicked()
{

}


void MainWindow::on_applyBtn_toggled(bool checked)
{
    qDebug() << "toggaled";
}


void MainWindow::on_applyBtn_clicked()
{
    optionsFor->click();
}

