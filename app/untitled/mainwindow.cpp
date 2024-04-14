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

Image my_image,my_image2;
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
}
void MainWindow::loadingFilter(){
    bool val = !ui->BWBtn->isEnabled();
    ui->applyBtn->setEnabled(val);
    QObjectList children = ui->scrollAreaWidgetContents->children();
    if(!val){
        for(QObject *child : children) {
            if(QWidget *widget = qobject_cast<QWidget*>(child)) {
                widget->setEnabled(val);
                widget->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,200);}");
            }
        }
        ui->applyBtn->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,200);}");
    }else{
        for(QObject *child : children) {
            if(QWidget *widget = qobject_cast<QWidget*>(child)) {
                widget->setEnabled(val);
                widget->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,255);}"
                "QPushButton:hover{background-color:  #A7BEAE;}");
            }
        }
        ui->applyBtn->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,255);}"
                "QPushButton:hover{background-color:  #A7BEAE;}");
    }
}
void MainWindow::assigningBtnsText(){
    ui->BWBtn->setText("Black and white filter");
    ui->ResizeBtn->setText("Resize");
    ui->FlipBtn->setText("Flip");
    ui->CropBtn->setText("Crop");
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

        ui->BWBtn->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->BWBtn->layout();
        ui->BWBtn->setLayout(layout);
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
    }else if(path.size() != 0){
        loadingFilter();
        secT = QThread::create(flip,ui->radioButton->isChecked(),this,ui->FlipBtn);
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
void cropFilter(int fromX,int fromY,int toX,int toY,MainWindow* mainwindow,QPushButton* btn){
    Image newImage(toX - fromX + 1,toY - fromY + 1);

    int counterX = 0,counterY = 0;

    for(int i = fromX - 1;i < toX;i++){
        for(int j = fromY - 1;j < toY;j++){
            for(int k = 0;k < 3;k++){
                newImage(counterX,counterY,k) = to_image(i,j,k);
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
        ui->resize_width->setVisible(false);
        ui->resize_height->setVisible(false);
        ui->radioButton->setVisible(false);
        ui->radioButton_2->setVisible(false);
        ui->label_2->setVisible(false);
        ui->loadNewImage->setVisible(false);
        ui->label_3->setVisible(false);
        ui->Brightness->setVisible(false);
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
    else if(!(stoi(firstFrom) <= 0 || stoi(firstFrom) > my_image.width - 1) &&
               !(stoi(firstTo) <= 0 || stoi(firstTo) > my_image.width - 1) &&
               !(stoi(secondFrom) <= 0 || stoi(secondFrom) > my_image.height - 1) &&
               !(stoi(secondTo) <= 0 || stoi(secondTo) > my_image.height - 1)){
        if(path.size() != 0){
            loadingFilter();
            secT = QThread::create(cropFilter,stoi(firstFrom),stoi(secondFrom),stoi(firstTo),stoi(secondTo),this,ui->CropBtn);
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
    to_image = my_image;

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

        ui->Infrared->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->Infrared->layout();
        ui->Infrared->setLayout(layout);
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

        ui->OilPaint->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->OilPaint->layout();
        ui->OilPaint->setLayout(layout);
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

        ui->GrayscaleBtn->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->GrayscaleBtn->layout();
        ui->GrayscaleBtn->setLayout(layout);
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
        for(int i = 0; i < my_image.width; i++){
            for(int j = 0; j < my_image.height; j++){
                for(int k = 0; k < 3; k++){
                    // Average RGB values of corresponding pixels
                    MidPoint = (my_image(i,j,k) + my_image2(i,j,k))/2;
                    final_image(i,j,k) = MidPoint;
                }
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

        // Fade-in animation for resize_height
        ui->loadNewImage->setVisible(true);
        setupFadeInAnimation(ui->loadNewImage, 500);
        optionsFor = ui->mergeBtn;
    }else if(path.size() != 0 && path2.size() != 0){
        loadingFilter();
        secT = QThread::create(mergeFilter,ui->mergeBtn,this);
        secT->start();

        ui->mergeBtn->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->mergeBtn->layout();
        ui->mergeBtn->setLayout(layout);
    }
}

void MainWindow::on_Brightness_valueChanged(int value)
{
    double val = value/100.f;
    ui->brightnessBtn->setText("");
    QLabel* spinnerLabel = new QLabel(this);
    spinnerLabel->setStyleSheet("background-color:transparent;");

    QMovie* spinner = new QMovie("spinner.gif");

    spinnerLabel->setMovie(spinner);
    spinner->start();

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
    delete ui->brightnessBtn->layout();
    ui->brightnessBtn->setLayout(layout);
    Image final_image(to_image.width, to_image.height);
    int increase_brightness;
    // Loop through each pixel in the image
    for (int i = 0; i < my_image.width; i++) {
        for (int j = 0; j < my_image.height; j++) {
            for (int k = 0; k < 3; k++) {
                // Get the pixel value at (i, j) for channel k
                int pixel_value = my_image(i, j, k);
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

        ui->EdgeDetection->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->EdgeDetection->layout();
        ui->EdgeDetection->setLayout(layout);
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

        ui->sunLightBtn->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->sunLightBtn->layout();
        ui->sunLightBtn->setLayout(layout);
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

        ui->Purple->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->Purple->layout();
        ui->Purple->setLayout(layout);
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

        ui->Sepia->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->Sepia->layout();
        ui->Sepia->setLayout(layout);
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

        ui->nightMoodBtn->setText("");
        QLabel* spinnerLabel = new QLabel(this);
        spinnerLabel->setStyleSheet("background-color:transparent;");

        QMovie* spinner = new QMovie("spinner.gif");

        spinnerLabel->setMovie(spinner);
        spinner->start();

        QGridLayout* layout = new QGridLayout();
        layout->addWidget(spinnerLabel, 0, 0, Qt::AlignCenter);
        delete ui->nightMoodBtn->layout();
        ui->nightMoodBtn->setLayout(layout);
    }
}

