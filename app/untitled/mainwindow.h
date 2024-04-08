#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void disableObtions();
signals:
     // void imageChanged(const Image& newImage);
private slots:


    void on_BWBtn_clicked();

    void on_ResizeBtn_clicked();

    void on_FlipBtn_clicked();

    void on_CropBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

private:
    QGraphicsDropShadowEffect *Drop_Shadow_Effect;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
