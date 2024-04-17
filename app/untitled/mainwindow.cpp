#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDir>
#include <QObject>
#include <QMovie>
#include <QDebug>
#include <random>
#include <QColorDialog>
#include "Image_Class.h"
#include <QIntValidator>
#include <QPropertyAnimation>
using namespace std;

Image my_image,my_image2,recoverImage;
Image to_image;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(867,600);
    disableObtions();

    Drop_Shadow_Effect = new QGraphicsDropShadowEffect();
    Drop_Shadow_Effect->setBlurRadius(30);
    Drop_Shadow_Effect->setColor(QColor(15,15,15,255));
    Drop_Shadow_Effect->setOffset(0,0);

    QObjectList children = ui->scrollAreaWidgetContents->children();
    for(QObject *child : children) {
        if(QWidget *widget = qobject_cast<QWidget*>(child)) {
            widget->setFocusPolicy(Qt::NoFocus);
            widget->setCursor(Qt::PointingHandCursor);
        }
    }
    ui->pushButton->setCursor(Qt::PointingHandCursor);
    ui->clearBtn->setCursor(Qt::PointingHandCursor);
    ui->saveBtn->setCursor(Qt::PointingHandCursor);
    ui->loadNewImage->setCursor(Qt::PointingHandCursor);
    ui->applyBtn->setCursor(Qt::PointingHandCursor);
    ui->pushButton_2->setCursor(Qt::PointingHandCursor);
    connect(this,&MainWindow::filterFinished,this,&MainWindow::updateToImage);

    ui->FromImage->setAcceptDrops(true);
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
    ui->label_2->setVisible(false);
    ui->loadNewImage->setVisible(false);
    ui->label_3->setVisible(false);
    ui->Brightness->setVisible(false);
    ui->options_label->setVisible(false);
    ui->applyBtn->setVisible(false);
    ui->ResizeMerge->setVisible(false);
    ui->CommonArea->setVisible(false);
    ui->label_6->setVisible(false);
    ui->frame_4->setVisible(false);
    ui->frame_5->setVisible(false);
    ui->frame_6->setVisible(false);
    ui->frame_7->setVisible(false);
}
void MainWindow::loadingFilter(){
    bool val = !ui->BWBtn->isEnabled();
    ui->applyBtn->setEnabled(val);
    ui->pushButton->setEnabled(val);
    ui->clearBtn->setEnabled(val);
    ui->saveBtn->setEnabled(val);
    QObjectList children = ui->scrollAreaWidgetContents->children();
    if(!val){
        for(QObject *child : children) {
            if(QWidget *widget = qobject_cast<QWidget*>(child)) {
                widget->setEnabled(val);
                widget->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,200);}");
            }
        }
        ui->applyBtn->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,200);border-radius:24px;}");
        ui->pushButton->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,200);border-radius: 15%;}");
        ui->clearBtn->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,200);border-radius: 15%;}");
        ui->saveBtn->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,200);border-radius: 15%;}");
    }else{
        for(QObject *child : children) {
            if(QWidget *widget = qobject_cast<QWidget*>(child)) {
                widget->setEnabled(val);
                widget->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,255);}"
                "QPushButton:hover{background-color:  #A7BEAE;}");
            }
        }
        ui->applyBtn->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,255);border-radius:24px;}"
                "QPushButton:hover{background-color:  #A7BEAE;}");
        ui->pushButton->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,255);border-radius: 15%;}"
                "QPushButton:hover{background-color:  #A7BEAE;}");
        ui->clearBtn->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,255);border-radius: 15%;}"
                "QPushButton:hover{background-color:  #A7BEAE;}");
        ui->saveBtn->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,255);border-radius: 15%;}"
                "QPushButton:hover{background-color:  #A7BEAE;}");
    }
}
void MainWindow::assigningBtnsText(){
    ui->applyBtn->setText("Apply");
    ui->BWBtn->setText("Black and white filter");
    ui->ResizeBtn->setText("Resize");
    ui->Invert->setText("Invert");
    ui->FlipBtn->setText("Flip");
    ui->CropBtn->setText("Crop");
    ui->RotateBtn->setText("Rotate");
    ui->BlurBtn->setText("Blur");
    ui->OilPaint->setText("Oil Paint");
    ui->Infrared->setText("Infrared");
    ui->GrayscaleBtn->setText("Grayscale");
    ui->mergeBtn->setText("Merge");
    ui->brightnessBtn->setText("Brightness");
    ui->EdgeDetection->setText("Edge detection");
    ui->Purple->setText("Purple");
    ui->sunLightBtn->setText("Sun Light");
    ui->Sepia->setText("Sepia");
    ui->nightMoodBtn->setText("Night Mood");
    ui->TVEffect->setText("TV Effect");
    ui->SkewBtn->setText("Skew");
    ui->FrameBtn->setText("Frame");
    ui->errorLabel->setText("");
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
    QLayout *layout2 = ui->applyBtn->layout();
    while (QLayoutItem* item = layout2->takeAt(0)) {
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

void loadingSecondImage(QString path,QThread *secT,MainWindow *mainwindow){
    my_image2.loadNewImage(path.toStdString());
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
void MainWindow::on_loadNewImage_clicked()
{
    QString filter = "JPG image (*.jpg) ;; PNG image (*.png)";
    path2 = QFileDialog::getOpenFileName(this,"Chose an image file",QDir::homePath(),filter);
    if(path2.size() != 0){
        file_name2 = "";
        for(int i = path2.size() - 1;i >= 0;i--){
            if(path2[i] == '/'){
                break;
            }
            file_name2 += path2[i];
        }
        for(int i = file_name2.size() - 1;i >= file_name2.size()/2;i--){
            QChar c = file_name2[i];
            file_name2[i] = file_name2[file_name2.size() - i - 1];
            file_name2[file_name2.size() - i - 1] = c;
        }
        secT = QThread::create(loadingSecondImage,path2,secT,this);
        secT->start();
        secT->wait();
        ui->label_2->setText(file_name2);
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

void putSpinner(QPushButton* &btn){
    btn->setText("");
    QLabel* spinnerLabel = new QLabel(btn);
    spinnerLabel->setStyleSheet("background-color:transparent;");

    QMovie* spinner = new QMovie("spinner.gif");

    spinnerLabel->setMovie(spinner);
    spinner->start();

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
    delete btn->layout();
    btn->setLayout(layout);
}

void BWFilter(MainWindow* mainwindow,QPushButton* btn){
    qDebug() << "inside a filter";
    // Grayscale conversion using weighted average
    for (int i = 0; i < to_image.width; ++i) {
        for (int j = 0; j < to_image.height; ++j) {
            int avg = 0;
            for(int k = 0;k < 3;k++){
                avg += to_image(i,j,k);
            }
            avg /= 3;
            avg = (avg > 127 ? 255 : 0);
            to_image(i,j,0) = avg;
            to_image(i,j,1) = avg;
            to_image(i,j,2) = avg;
        }
    }
    // Save the processed image
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}
void MainWindow::on_BWBtn_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(BWFilter,this,ui->BWBtn);
        secT->start();

        putSpinner(ui->BWBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}
void flip(bool choice,MainWindow* mainwindow,QPushButton* btn){
    if(!choice){
        for(int i = 0;i < to_image.width;i++){
            for(int j = 0;j < to_image.height/2;j++){
                for(int k = 0;k < 3;k++){
                    int p = to_image(i,j,k);
                    to_image(i,j,k) = to_image(i,to_image.height - j - 1,k);
                    to_image(i,to_image.height - j - 1,k) = p;
                }
            }
        }
    }else{
        for(int i = 0;i < to_image.width/2;i++){
            for(int j = 0;j < to_image.height;j++){
                for(int k = 0;k < 3;k++){
                    int p = to_image(i,j,k);
                    to_image(i,j,k) = to_image(to_image.width - i - 1,j,k);
                    to_image(to_image.width - i - 1,j,k) = p;
                }
            }
        }
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}
void setupFadeInAnimation(QWidget *widget, int duration) {
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(widget);
    widget->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(duration);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
void MainWindow::on_FlipBtn_clicked()
{
    if(!ui->radioButton->isVisible()){
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->lineEdit_1->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->label_2->setVisible(false);
        ui->loadNewImage->setVisible(false);
        ui->label_3->setVisible(false);
        ui->Brightness->setVisible(false);
        ui->ResizeMerge->setVisible(false);
        ui->CommonArea->setVisible(false);
        ui->label_6->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_5->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_7->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }

        if (!ui->applyBtn->isVisible()) {
            ui->applyBtn->setVisible(true);
            setupFadeInAnimation(ui->applyBtn, 500);
        }

        ui->radioButton->setVisible(true);
        ui->radioButton_2->setVisible(true);

        setupFadeInAnimation(ui->radioButton, 500);

        // Fade-in animation for radioButton_2
        setupFadeInAnimation(ui->radioButton_2, 500);

        optionsFor = ui->FlipBtn;
    }else if(path.size() != 0 && (ui->radioButton->isChecked() || ui->radioButton_2->isChecked())){
        loadingFilter();
        secT = QThread::create(flip,ui->radioButton->isChecked(),this,ui->FlipBtn);
        secT->start();
        putSpinner(ui->FlipBtn);
        putSpinner(ui->applyBtn);
    }else{
        if(path.size() == 0){
            ui->errorLabel->setText("please select an image");
        }else{
            ui->errorLabel->setText("please select an option");
        }
    }
}
void cropFilter(int fromX,int fromY,int width,int height,MainWindow* mainwindow,QPushButton* btn){
    Image newImage(width,height);
    int counterX = 0,counterY = 0;
    for(int i = fromX; i < fromX + width && i < to_image.width; i++){
        for(int j = fromY; j < fromY + height && j < to_image.height; j++){
            for(int k = 0; k < 3; k++){
                newImage(counterX,counterY,k) = to_image(i,j,k);
            }
            counterY++;
        }
        counterX++;
        counterY = 0; // Reset counterY for the next row
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
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->label_2->setVisible(false);
        ui->loadNewImage->setVisible(false);
        ui->label_3->setVisible(false);
        ui->Brightness->setVisible(false);
        ui->ResizeMerge->setVisible(false);
        ui->CommonArea->setVisible(false);
        ui->label_6->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_5->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_7->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }

        if (!ui->applyBtn->isVisible()) {
            ui->applyBtn->setVisible(true);
            setupFadeInAnimation(ui->applyBtn, 500);
        }
        QList<QLineEdit*> lineEdits = {ui->lineEdit_1, ui->lineEdit_2, ui->lineEdit_3, ui->lineEdit_4};
        for(QLineEdit *lineEdit : lineEdits) {
            if(!lineEdit->isVisible()) {
                lineEdit->setVisible(true);
                setupFadeInAnimation(lineEdit, 500);
            }
        }
        optionsFor = ui->CropBtn;
    }else if(firstFrom.empty() || secondFrom.empty() || firstTo.empty() || secondTo.empty()){}
    else if(!(stoi(firstFrom) < 0 || stoi(firstFrom) > to_image.width - 1) &&
               !(stoi(firstTo) <= 0 || stoi(firstTo) > to_image.width - stoi(firstFrom)) &&
               !(stoi(secondFrom) < 0 || stoi(secondFrom) > to_image.height - 1) &&
               !(stoi(secondTo) <= 0 || stoi(secondTo) > to_image.height - stoi(secondFrom))){
        if(path.size() != 0){
            loadingFilter();
            secT = QThread::create(cropFilter,stoi(firstFrom),stoi(secondFrom),stoi(firstTo),stoi(secondTo),this,ui->CropBtn);
            secT->start();
            putSpinner(ui->CropBtn);
            putSpinner(ui->applyBtn);
        }
    }else{
        if(path.size() == 0){
            ui->errorLabel->setText("please select an image");
        }else{
            ui->errorLabel->setText("please enter valid values");
        }
    }
}

void resizeFilter(int newWidth,int newHeight,MainWindow* mainwindow,QPushButton* btn){
    // creating a new image with the desired width and height
    Image newImage(newWidth,newHeight);
    int oldWidth = to_image.width,oldHeight = to_image.height;
    // getting the relative width and height
    float relativeWidth = (float)newWidth/to_image.width,relativeHeight = (float)newHeight/to_image.height;

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
            newImage(i,j,0) = to_image(x,y,0);
            newImage(i,j,1) = to_image(x,y,1);
            newImage(i,j,2) = to_image(x,y,2);
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
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->lineEdit_1->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->label_2->setVisible(false);
        ui->loadNewImage->setVisible(false);
        ui->label_3->setVisible(false);
        ui->Brightness->setVisible(false);
        ui->ResizeMerge->setVisible(false);
        ui->CommonArea->setVisible(false);
        ui->label_6->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_5->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_7->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }

        if (!ui->applyBtn->isVisible()) {
            ui->applyBtn->setVisible(true);
            setupFadeInAnimation(ui->applyBtn, 500);
        }
        // Fade-in animation for resize_width
        ui->resize_width->setVisible(true);
        setupFadeInAnimation(ui->resize_width, 500);

        // Fade-in animation for resize_height
        ui->resize_height->setVisible(true);
        setupFadeInAnimation(ui->resize_height, 500);
        optionsFor = ui->ResizeBtn;
    }else if(!(width <= 0) &&
               !(height <= 0)){
        if(path.size() != 0){
            loadingFilter();
            secT = QThread::create(resizeFilter,width,height,this,ui->ResizeBtn);
            secT->start();
            putSpinner(ui->ResizeBtn);
            putSpinner(ui->applyBtn);
        }else{
            ui->errorLabel->setText("please select an image");
        }
    }else{
        ui->errorLabel->setText("invalid width or height value");
    }
}

void MainWindow::on_clearBtn_clicked()
{
    QString testPath = QDir::currentPath() + "/test.jpg";
    my_image.saveImage("test.jpg");
    to_image = my_image;
    ui->ToImage->setStyleSheet("border-image: url(\""+testPath+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
}


void MainWindow::on_applyBtn_toggled(bool checked)
{
    qDebug() << "toggaled";
}


void MainWindow::on_applyBtn_clicked()
{
    optionsFor->click();
}

void infrared(MainWindow *mainwindow,QPushButton *btn){
    for(int i = 0;i < to_image.width;i++){
        for(int j = 0;j < to_image.height;j++){
            to_image(i,j,0) = 255;
            int intenisty = (to_image(i,j,1)+to_image(i,j,2))/2;
            to_image(i,j,1) = 255 - intenisty;
            to_image(i,j,2) = 255 - intenisty;
        }
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_Infrared_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(infrared,this,ui->Infrared);
        secT->start();
        putSpinner(ui->Infrared);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}
void oilPaint(MainWindow *mainwindow,QPushButton *btn){
    int radius = 5;
    Image new_image(to_image.width,to_image.height);
    for(int i = 0;i < to_image.width;i++){
        for(int j = 0;j < to_image.height;j++){
            vector<int> intenistyLevels(255),averageR(255),averageG(255),averageB(255);
            int maxIntenisty = 0;
            int beginRaw = max(0,i-radius),endRaw = min(i+radius,to_image.width-1);
            int beginCol = max(0,j-radius),endCol = min(j+radius,to_image.height-1);
            for(int k = beginRaw;k <= endRaw;k++){
                for(int l = beginCol;l <= endCol;l++){
                    int intenisty = (to_image(k,l,0)+to_image(k,l,1)+to_image(k,l,2))/3;
                    intenistyLevels[intenisty]++;
                    averageR[intenisty] += to_image(k,l,0);
                    averageG[intenisty] += to_image(k,l,1);
                    averageB[intenisty] += to_image(k,l,2);
                }
            }
            int maxIndex;
            for(int k = 0;k < 255;k++){
                if(maxIntenisty < intenistyLevels[k]){
                    maxIntenisty = intenistyLevels[k];
                    maxIndex = k;
                }
            }
            new_image(i,j,0) = averageR[maxIndex]/maxIntenisty;
            new_image(i,j,1) = averageG[maxIndex]/maxIntenisty;
            new_image(i,j,2) = averageB[maxIndex]/maxIntenisty;
        }
    }
    new_image.saveImage("test.jpg");
    to_image = new_image;
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_OilPaint_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(oilPaint,this,ui->OilPaint);
        secT->start();
        putSpinner(ui->OilPaint);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void BlackAndWhite(Image& image)
{
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            // Calculate average intensity value across RGB channels
            int avg = 0;
            for(int k = 0; k < 3; k++){
                avg += image(i, j, k);
            }
            avg /= 3;
            // Threshold to binary (black and white)
            avg = (avg > 127 ? 255 : 0);
            // Set RGB values to the same value to convert to grayscale
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}


void edgeDetection(MainWindow* mainwindow,QPushButton* btn){
    // Convert image to black and white
    BlackAndWhite(to_image);
    int width = to_image.width,height = to_image.height;
    // Perform edge detection
    for(int i = 0; i < width - 1; i++){
        for(int j = 0; j < height - 1; j++){
            for(int k = 0; k < 3; k++){
                // Compute differences in vertical and horizontal directions
                int diffV = abs(to_image(i, j, k) - to_image(i + 1, j, k)); // Vertical difference
                int diffH = abs(to_image(i, j, k) - to_image(i, j + 1, k)); // Horizontal difference
                // Compute gradient magnitude using Euclidean distance
                int res = sqrt(diffV * diffV + diffH * diffH);
                // Apply thresholding
                int constant = 100; // Threshold constant (adjust as needed)
                to_image(i, j, k) = res > constant ? 0 : 255; // Set pixel to black or white based on threshold
            }
        }
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_EdgeDetection_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(edgeDetection,this,ui->EdgeDetection);
        secT->start();

        putSpinner(ui->EdgeDetection);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void grayScale(QPushButton* btn,MainWindow* mainwindow){
    // Loop through each pixel in the image
    for (int i = 0; i < to_image.width; ++i) {
        for (int j = 0; j < to_image.height; ++j) {
            unsigned  int avg = 0; // Initialize an integer variable to store the average value

            // Calculate the average value of RGB channels for each pixel
            for (int k = 0; k < 3; ++k) {
                avg += to_image(i, j, k);
            }

            avg /= 3; // Calculate the final average value

            // Set the RGB values of the pixel to the calculated average
            for (int k = 0; k < 3; ++k) {
                to_image(i, j, k) = avg;
            }
        }
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_GrayscaleBtn_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(grayScale,ui->GrayscaleBtn,this);
        secT->start();
        putSpinner(ui->GrayscaleBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}
Image resize(int newWidth,int newHeight,Image &image){
    // creating a new image with the desired width and height
    Image newImage(newWidth,newHeight);
    int oldWidth = image.width,oldHeight = image.height;
    // getting the relative width and height
    float relativeWidth = (float)newWidth/image.width,relativeHeight = (float)newHeight/image.height;

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
            newImage(i,j,0) = image(x,y,0);
            newImage(i,j,1) = image(x,y,1);
            newImage(i,j,2) = image(x,y,2);
        }
    }
    return newImage;
}

void mergeFilter(QPushButton* btn,MainWindow* mainwindow){
    // Determine dimensions of the final image
    int NewHeight = max(to_image.height, my_image2.height), NewWidth = max(to_image.width, my_image2.width);
    Image final_image(NewWidth,NewHeight);

    // If dimensions of images are different, resize them
    if(to_image.width != my_image2.width || to_image.height != my_image2.height){
        qDebug() << "first";
        Image NewImage_1 = resize(NewWidth, NewHeight,to_image);
        Image NewImage_2 = resize(NewWidth, NewHeight,my_image2);
        int MidPoint = 0;
        for(int i = 0; i < NewWidth; i++){
            for(int j = 0; j < NewHeight; j++) {
                for (int k = 0; k < 3; k++) {
                    // Average RGB values of corresponding pixels
                    MidPoint = (NewImage_1(i, j, k) + NewImage_2(i, j, k)) / 2;
                    final_image(i, j, k) = MidPoint;
                }
            }
        }
    }
    // If dimensions are same, merge images directly
    else{
        qDebug() << "second";
        int MidPoint = 0;
        for(int i = 0; i < to_image.width; i++){
            for(int j = 0; j < to_image.height; j++){
                for(int k = 0; k < 3; k++){
                    // Average RGB values of corresponding pixels
                    MidPoint = (to_image(i,j,k) + my_image2(i,j,k))/2;
                    final_image(i,j,k) = MidPoint;
                }
            }
        }
    }
    final_image.saveImage("test.jpg");
    to_image = final_image;
    emit mainwindow->filterFinished(btn);
}

void mergeCommonAreaFilter(QPushButton* btn,MainWindow* mainwindow){
    int NewHeight = min(to_image.height, my_image2.height), NewWidth = min(to_image.width, my_image2.width),MidPoint;
    Image final_image(NewWidth,NewHeight);
    for(int i = 0; i < NewWidth; i++){
        for(int j = 0; j < NewHeight; j++){
            for(int k = 0; k < 3; k++){
                // Average RGB values of corresponding pixels
                MidPoint = (to_image(i,j,k) + my_image2(i,j,k))/2;
                final_image(i,j,k) = MidPoint;
            }
        }
    }
    final_image.saveImage("test.jpg");
    to_image = final_image;
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_mergeBtn_clicked()
{
    if(!ui->label_2->isVisible()){
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->lineEdit_1->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->Brightness->setVisible(false);
        ui->label_3->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_5->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_7->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }

        if (!ui->applyBtn->isVisible()) {
            ui->applyBtn->setVisible(true);
            setupFadeInAnimation(ui->applyBtn, 500);
        }
        // Fade-in animation for resize_width
        ui->label_2->setVisible(true);
        setupFadeInAnimation(ui->label_2, 500);

        ui->label_6->setVisible(true);
        setupFadeInAnimation(ui->label_6, 500);

        // Fade-in animation for resize_height
        ui->loadNewImage->setVisible(true);
        setupFadeInAnimation(ui->loadNewImage, 500);

        // Fade-in animation for resize_width
        ui->CommonArea->setVisible(true);
        setupFadeInAnimation(ui->CommonArea, 500);

        // Fade-in animation for resize_height
        ui->ResizeMerge->setVisible(true);
        setupFadeInAnimation(ui->ResizeMerge, 500);
        optionsFor = ui->mergeBtn;
    }else if(path.size() != 0 && path2.size() != 0){
        loadingFilter();
        if(ui->CommonArea->isChecked()){
            secT = QThread::create(mergeCommonAreaFilter,ui->mergeBtn,this);
        }else{
            secT = QThread::create(mergeFilter,ui->mergeBtn,this);
        }
        secT->start();
        putSpinner(ui->mergeBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void MainWindow::on_Brightness_valueChanged(int value)
{
    if(path.size() != 0){
        double val = value/50.f;
        putSpinner(ui->brightnessBtn);
        Image final_image(recoverImage.width, recoverImage.height);
        int increase_brightness;
        // Loop through each pixel in the image
        for (int i = 0; i < recoverImage.width; i++) {
            for (int j = 0; j < recoverImage.height; j++) {
                for (int k = 0; k < 3; k++) {
                    // Get the pixel value at (i, j) for channel k
                    int pixel_value = recoverImage(i, j, k);
                    // Increase the brightness by multiplying the pixel value by 1.5
                    increase_brightness = min(int(pixel_value*val), 255);
                    // Store the adjusted pixel value in the final image
                    final_image(i, j, k) = increase_brightness;
                }
            }
        }
        final_image.saveImage("test.jpg");
        to_image = final_image;
        QString testPath = QDir::currentPath() + "/test.jpg";
        ui->ToImage->setStyleSheet("border-image: url(\""+testPath+"\") 0 0 0 0 stretch stretch;" + "background-color:rgb(220, 220, 220);background-position: center;background-repeat: no-repeat");
        QLayout *layout1 = ui->brightnessBtn->layout();
        while (QLayoutItem* item = layout1->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                layout1->removeWidget(widget);
                delete widget;
            }
            delete item;
        }
        ui->brightnessBtn->setText("Brightness");
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void MainWindow::on_brightnessBtn_clicked()
{
    if(!ui->label_2->isVisible()){
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->lineEdit_1->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->label_2->setVisible(false);
        ui->loadNewImage->setVisible(false);
        ui->applyBtn->setVisible(false);
        ui->ResizeMerge->setVisible(false);
        ui->CommonArea->setVisible(false);
        ui->label_6->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_5->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_7->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }
        // Fade-in animation for resize_width
        ui->label_3->setVisible(true);
        setupFadeInAnimation(ui->label_3, 500);

        // Fade-in animation for resize_height
        ui->Brightness->setVisible(true);
        setupFadeInAnimation(ui->Brightness, 500);
        optionsFor = ui->brightnessBtn;
        recoverImage = to_image;
    }
}

void sunLight(MainWindow* mainwindow,QPushButton* btn){

    Image sunlight(to_image.width, to_image.height);
    Image final_image(to_image.width, to_image.height);

    // Apply sunlight effect to the image
    for (int i = 0; i < to_image.width; i++) {
        for (int j = 0; j < to_image.height; j++) {
            // Adjust pixel values for sunlight effect
            sunlight(i,j,0) = min(to_image(i,j,0) + 30, 255);
            sunlight(i,j,1) = min(to_image(i,j,1) + 30, 255);
            sunlight(i,j,2) = max(0, to_image(i,j,2) - 50);
        }
    }
    sunlight.saveImage("test.jpg");
    to_image = sunlight;
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_sunLightBtn_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(sunLight,this,ui->sunLightBtn);
        secT->start();

        putSpinner(ui->sunLightBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void Purple(MainWindow* mainwindow,QPushButton* btn){
    // Create a new image for the purple effect
    Image purple(to_image.width, to_image.height);

    // Apply the purple effect to the image
    for (int i = 0; i < to_image.width; i++) {
        for (int j = 0; j < to_image.height; j++) {
            // Adjust RGB values to create a purple effect
            purple(i, j, 0) = min(to_image(i, j, 0) + 20, 255);  // Increase red
            purple(i, j, 1) = max(to_image(i, j, 1) - 30, 0);   // Decrease green
            purple(i, j, 2) = min(to_image(i, j, 2) + 20, 255);  // Increase blue
        }
    }
    purple.saveImage("test.jpg");
    to_image = purple;
    emit mainwindow->filterFinished(btn);
}
void MainWindow::on_Purple_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(Purple,this,ui->Purple);
        secT->start();

        putSpinner(ui->Purple);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void Sepia(MainWindow* mainwindow,QPushButton* btn){
    int newR, newG, newB;
    int width = to_image.width,height = to_image.height;
    // Iterate over each pixel in the image
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // For each pixel, calculate new RGB values based on the sepia tone effect
            for (int k = 0; k < 3; k++) {
                int PixelValue = to_image(i, j, k);
                if (k == 0) {
                    // Calculate new Red value
                    newR = min(255, (int)(0.393 * PixelValue + 0.769 * to_image(i, j, 1) + 0.189 * to_image(i, j, 2)));
                }
                else if (k == 1) {
                    // Calculate new Green value
                    newG = min(255, (int)(0.349 * to_image(i, j, 0) + 0.686 * PixelValue + 0.168 * to_image(i, j, 2)));
                }
                else {
                    // Calculate new Blue value
                    newB = min(255, (int)(0.272 * to_image(i, j, 0) + 0.534 * to_image(i, j, 1) + 0.131 * PixelValue));
                }
            }

            // Update the pixel with the new RGB values
            to_image(i, j, 0) = newR;
            to_image(i, j, 1) = newG;
            to_image(i, j, 2) = newB;
        }
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}


void MainWindow::on_Sepia_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(Sepia,this,ui->Sepia);
        secT->start();

        putSpinner(ui->Sepia);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void nightMood(MainWindow* mainwindow,QPushButton* btn){
    int width = to_image.width,height = to_image.height;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++){
            // Iterate over each color channel (R, G, B) of the pixel
            for (int k = 0; k < 3; k++){

                // Retrieve the pixel value for the current channel
                int PixelValue = to_image(i,j,k);

                // Apply different multipliers to each channel to achieve the night mood effect
                if(k == 0) { // Red channel
                    PixelValue *= 0.5; // Reduce intensity by 50%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    to_image(i,j,0) = PixelValue; // Update the pixel value for the Red channel
                }
                else if (k == 1) { // Green channel
                    PixelValue *= 0.5; // Reduce intensity by 50%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    to_image(i,j,1) = PixelValue; // Update the pixel value for the Green channel
                }
                else {
                    // Blue channel
                    PixelValue *= 0.7; // Reduce intensity by 30%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    to_image(i,j,2) = PixelValue; // Update the pixel value for the Blue channel
                }
            }
        }
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_nightMoodBtn_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(nightMood,this,ui->nightMoodBtn);
        secT->start();

        putSpinner(ui->nightMoodBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void invert(MainWindow* mainwindow,QPushButton* btn){
    int r = to_image.width; // Get the width of the image
    int c = to_image.height; // Get the height of the image

    for (int i = 0; i < r; ++i){ // Loop through each row of the image
        for (int j = 0; j < c ; ++j){ // Loop through each column of the image
            for (int k = 0; k < 3; ++k){ // Loop through each color channel (RGB)
                to_image(i, j, k) = 255 - to_image(i, j, k) ; // Invert the pixel value for each color channel
            }
        }
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_Invert_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(invert,this,ui->Invert);
        secT->start();

        putSpinner(ui->Invert);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

// Function to rotate the image clockwise by 90 degrees
Image rotateImage90(Image& image) {
    int r = image.width;
    int c = image.height;
    Image rotated(c, r); // Create a new image with dimensions swapped

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotated(c - 1 - j, i, k) = image(i, j, k); // Correct indices for clockwise rotation
            }
        }
    }

    return rotated;
}

// Function to rotate the image clockwise by 180 degrees
Image rotateImage180(Image& image) {
    int r = image.width;
    int c = image.height;
    Image rotated(r, c); // Create a new image with the same dimensions

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotated(i, j, k) = image(r - 1 - i, c - 1 - j, k); // Correct indices for 180-degree rotation
            }
        }
    }

    return rotated;
}

// Function to rotate the image clockwise by 270 degrees
Image rotateImage270(Image& image) {
    int r = image.width;
    int c = image.height;
    Image rotated(c, r);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotated(j, r - 1 - i, k) = image(i, j, k); // Correct indices for clockwise rotation
            }
        }
    }

    return rotated;
}

void Rotate(MainWindow* mainwindow,QPushButton* btn,int choice){
    switch (choice) {
    case 1:
        to_image = rotateImage90(recoverImage);
        break;
    case 2:
        to_image = rotateImage180(recoverImage);
        break;
    case 3:
        to_image = rotateImage270(recoverImage);
        break;
    default:
        to_image = recoverImage;
        break;
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_RotateBtn_clicked()
{
    if(!ui->frame_4->isVisible()){
        recoverImage = to_image;
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->lineEdit_1->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->Brightness->setVisible(false);
        ui->label_3->setVisible(false);
        ui->frame_5->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_7->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }

        if (!ui->applyBtn->isVisible()) {
            ui->applyBtn->setVisible(true);
            setupFadeInAnimation(ui->applyBtn, 500);
        }
        // Fade-in animation for frame_4
        ui->frame_4->setVisible(true);
        setupFadeInAnimation(ui->frame_4, 500);
        optionsFor = ui->RotateBtn;
    }else if(path.size() != 0){
        int val = ui->horizontalSlider->value();
        loadingFilter();
        secT = QThread::create(Rotate,this,ui->RotateBtn,val);
        secT->start();

        putSpinner(ui->RotateBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(value == 1){
        ui->label_7->setText("90");
    }else if(value == 2){
        ui->label_7->setText("180");
    }else if(value == 3){
        ui->label_7->setText("270");
    }else{
        ui->label_7->setText("0");
    }
}

void applyBoxBlur(MainWindow* mainwindow,QPushButton* btn,int kernelSize) {
    int width = recoverImage.width;
    int height = recoverImage.height;
    int channels = recoverImage.channels;

    // Create a temporary image to store the blurred result
    Image blurredImage(width, height);

    // Apply box blur using the specified kernel size
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int c = 0; c < channels; ++c) {
                int sum = 0;
                int count = 0;
                for (int k = -kernelSize; k <= kernelSize; ++k) {
                    for (int l = -kernelSize; l <= kernelSize; ++l) {
                        int x = max(0, min(width - 1, i + k));
                        int y = max(0, min(height - 1, j + l));
                        sum += recoverImage(x, y, c);
                        count++;
                    }
                }
                blurredImage(i, j, c) = sum / count; // Average of the pixel values in the kernel
            }
        }
    }
    to_image = blurredImage;
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}
void MainWindow::on_BlurBtn_clicked()
{
    if(!ui->frame_5->isVisible()){
        recoverImage = to_image;
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->lineEdit_1->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->Brightness->setVisible(false);
        ui->label_3->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_7->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }

        if (!ui->applyBtn->isVisible()) {
            ui->applyBtn->setVisible(true);
            setupFadeInAnimation(ui->applyBtn, 500);
        }
        // Fade-in animation for frame_5
        ui->frame_5->setVisible(true);
        setupFadeInAnimation(ui->frame_5, 500);
        optionsFor = ui->BlurBtn;
    }else if(path.size() != 0){
        int val = ui->horizontalSlider_2->value();
        loadingFilter();
        secT = QThread::create(applyBoxBlur,this,ui->BlurBtn,val);
        secT->start();

        putSpinner(ui->BlurBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_8->setText(QString::fromStdString(to_string(value)));
}

void tvEffect(MainWindow* mainwindow,QPushButton* btn){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 30);
    int width = to_image.width;
    int height = to_image.height;

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int random = dis(gen); // Random value for each pixel

            for (int k = 0; k < to_image.channels; ++k) {
                if (i % 2 == 0) { // Even row
                    int newValue = to_image(i, j, k) - random;
                    to_image(i, j, k) = (newValue < 0) ? 0 : newValue;
                } else { // Odd row
                    int newValue = to_image(i, j, k) + random;
                    to_image(i, j, k) = (newValue > 255) ? 255 : newValue;
                }
            }
        }
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_TVEffect_clicked()
{
    if(path.size() != 0){
        disableObtions();
        loadingFilter();
        secT = QThread::create(tvEffect,this,ui->TVEffect);
        secT->start();

        putSpinner(ui->TVEffect);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}

// Function to apply vertical skew effects to an image
void applyVerticalSkew(MainWindow* mainwindow,QPushButton* btn,double angleOfSkew) {
    // Convert the angle from degrees to radians
    double angleRad = angleOfSkew * M_PI / 180.0;

    // Calculate the new width and height after skewing
    int newWidth = round(recoverImage.width + tan(angleRad) * recoverImage.height);
    int newHeight = recoverImage.height;

    // Create a new image with the skewed dimensions
    Image skewedImage(newWidth, newHeight);

    // Apply skew transformation to each pixel
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            // Calculate the corresponding position in the original image after skewing
            int origX = round(x - tan(angleRad) * (newHeight - y));

            // Check if the original position is within bounds
            if (origX >= 0 && origX < recoverImage.width && y >= 0 && y < recoverImage.height) {
                // Get the color values from the original position and set them in the skewed image
                for (int c = 0; c < recoverImage.channels; ++c) {
                    skewedImage(x, y, c) = recoverImage(origX, y, c);
                }
            }
        }
    }
    // Update the original image with the skewed version
    to_image = skewedImage;
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_SkewBtn_clicked()
{
    if(!ui->frame_6->isVisible()){
        recoverImage = to_image;
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->lineEdit_1->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->Brightness->setVisible(false);
        ui->label_3->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_5->setVisible(false);
        ui->frame_7->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }

        if (!ui->applyBtn->isVisible()) {
            ui->applyBtn->setVisible(true);
            setupFadeInAnimation(ui->applyBtn, 500);
        }
        // Fade-in animation for frame_5
        ui->frame_6->setVisible(true);
        setupFadeInAnimation(ui->frame_6, 500);
        optionsFor = ui->SkewBtn;
    }else if(path.size() != 0){
        int val = ui->horizontalSlider_3->value();
        loadingFilter();
        secT = QThread::create(applyVerticalSkew,this,ui->SkewBtn,val);
        secT->start();

        putSpinner(ui->SkewBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}


void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    ui->label_12->setText(QString::fromStdString(to_string(value)));
}


void setColorForFrame(Image& image, int startX, int startY, int endX, int endY, int r, int g, int b) {
    for (int i = startX; i < endX; ++i) {
        for (int j = startY; j < endY; ++j) {
            image(i, j, 0) = r;
            image(i, j, 1) = g;
            image(i, j, 2) = b;
        }
    }
}

// Function to create a simple frame with a specified color
void createSimpleFrame(QColor frameColor) {
    int rValue = frameColor.red(), gValue = frameColor.green(), bValue = frameColor.blue();

    setColorForFrame(to_image, 0, 0, 5, to_image.height, rValue, gValue, bValue);
    setColorForFrame(to_image, to_image.width - 5, 0, to_image.width, to_image.height, rValue, gValue, bValue);
    setColorForFrame(to_image, 0, 0, to_image.width, 5, rValue, gValue, bValue);
    setColorForFrame(to_image, 0, to_image.height - 5, to_image.width, to_image.height, rValue, gValue, bValue);
}

// Function to create a fancy frame with gradient colors
void createFancyFrame() {
    int startColorR = 255;  // Red
    int startColorG = 0;
    int startColorB = 0;
    int endColorR = 0;      // Blue
    int endColorG = 0;
    int endColorB = 255;

    int frameSize = 10;

    setColorForFrame(to_image, 0, 0, frameSize, to_image.height, startColorR, startColorG, startColorB);
    setColorForFrame(to_image, to_image.width - frameSize, 0, to_image.width, to_image.height, endColorR, endColorG, endColorB);
    setColorForFrame(to_image, 0, 0, to_image.width, frameSize, startColorR, startColorG, startColorB);
    setColorForFrame(to_image, 0, to_image.height - frameSize, to_image.width, to_image.height, endColorR, endColorG, endColorB);
}

void frame(MainWindow* mainwindow,QPushButton* btn,int choice,QColor frameColor){
    switch (choice) {
    case 1:
        createSimpleFrame(frameColor);
        break;
    case 2:
        createFancyFrame();
        break;
    default:
        break;
    }
    to_image.saveImage("test.jpg");
    emit mainwindow->filterFinished(btn);
}

void MainWindow::on_FrameBtn_clicked()
{
    if(!ui->frame_7->isVisible()){
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->lineEdit_1->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->Brightness->setVisible(false);
        ui->label_3->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->frame_5->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_8->setVisible(false);
        if (!ui->options_label->isVisible()) {
            ui->options_label->setVisible(true);
            setupFadeInAnimation(ui->options_label, 500);
        }

        if (!ui->applyBtn->isVisible()) {
            ui->applyBtn->setVisible(true);
            setupFadeInAnimation(ui->applyBtn, 500);
        }
        // Fade-in animation for frame_5
        ui->frame_7->setVisible(true);
        setupFadeInAnimation(ui->frame_7, 500);
        optionsFor = ui->FrameBtn;
    }else if(path.size() != 0){
        loadingFilter();
        int choice;
        if(ui->radioButton_3->isChecked()){
            choice = 1;
        }else{
            choice = 2;
        }
        secT = QThread::create(frame,this,ui->FrameBtn,choice,Framecolor);
        secT->start();

        putSpinner(ui->FrameBtn);
        putSpinner(ui->applyBtn);
    }else{
        ui->errorLabel->setText("please select an image");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QColorDialog *colorDialog = new QColorDialog();
    colorDialog->setOption(QColorDialog::DontUseNativeDialog); // optional: Use this line if you want to ensure that the QColorDialog always uses the Qt version
    QDialog* dialog = new QDialog(this); // Creating a QDialog to hold the QColorDialog
    dialog->resize(320, 400);

    QGridLayout* layout = new QGridLayout(dialog); // Setting the layout to the dialog
    layout->addWidget(colorDialog);

    connect(colorDialog, &QColorDialog::finished, dialog, &QDialog::accept);

    dialog->exec(); // Show the dialog as a modal dialog
    delete dialog; // Release the allocated memory when the dialog is closed
    Framecolor = colorDialog->currentColor();
}



void MainWindow::on_radioButton_3_clicked()
{
    ui->frame_8->setVisible(true);
}


void MainWindow::on_radioButton_4_clicked()
{
    ui->frame_8->setVisible(false);
}

