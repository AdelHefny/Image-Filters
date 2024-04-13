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
    this->resize(867,600);
    disableObtions();
    ui->pushButton->setCursor(Qt::PointingHandCursor);
    ui->BWBtn->setCursor(Qt::PointingHandCursor);
    ui->ResizeBtn->setCursor(Qt::PointingHandCursor);
    ui->CropBtn->setCursor(Qt::PointingHandCursor);
    ui->FlipBtn->setCursor(Qt::PointingHandCursor);
    ui->clearBtn->setCursor(Qt::PointingHandCursor);
    ui->saveBtn->setCursor(Qt::PointingHandCursor);
    ui->applyBtn->setCursor(Qt::PointingHandCursor);
    ui->Infrared->setCursor(Qt::PointingHandCursor);
    ui->OilPaint->setCursor(Qt::PointingHandCursor);

    Drop_Shadow_Effect = new QGraphicsDropShadowEffect();
    Drop_Shadow_Effect->setBlurRadius(30);
    Drop_Shadow_Effect->setColor(QColor(15,15,15,255));
    Drop_Shadow_Effect->setOffset(0,0);

    QObjectList children = ui->scrollAreaWidgetContents->children();
    for(QObject *child : children) {
        if(QWidget *widget = qobject_cast<QWidget*>(child)) {
            widget->setFocusPolicy(Qt::NoFocus);
        }
    }
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
    QObjectList children = ui->scrollAreaWidgetContents->children();
    for(QObject *child : children) {
        if(QWidget *widget = qobject_cast<QWidget*>(child)) {
            widget->setEnabled(val);
        }
    }
    if(!val){
        for(QObject *child : children) {
            if(QWidget *widget = qobject_cast<QWidget*>(child)) {
                widget->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,200);}");
            }
        }
    }else{
        for(QObject *child : children) {
            if(QWidget *widget = qobject_cast<QWidget*>(child)) {
                widget->setStyleSheet("QPushButton{background-color:  rgba(184, 80, 66,255);}"
                "QPushButton:hover{background-color:  #A7BEAE;}");
            }
        }
    }
}

void MainWindow::assigningBtnsText(){
    ui->BWBtn->setText("Black and white filter");
    ui->ResizeBtn->setText("Resize");
    ui->FlipBtn->setText("Flip");
    ui->CropBtn->setText("Crop");
    ui->OilPaint->setText("Oil Paint");
    ui->Infrared->setText("Infrared");
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

