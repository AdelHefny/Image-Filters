#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qframe.h"
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
    QString path,path2;
    QString file_name,file_name2;
    QThread *secT;
    QPushButton *optionsFor;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void disableObtions();
    void loadingFilter();
    void assigningBtnsText();
    void clearFilterBtn(QPushButton* btn);
public slots:
    void updateGui();
    void updateToImage(QPushButton* btn);
signals:
    void imageLoaded();
    void filterFinished(QPushButton* btn);
private slots:
    void on_BWBtn_clicked();

    void on_ResizeBtn_clicked();

    void on_FlipBtn_clicked();

    void on_CropBtn_clicked();

    void on_pushButton_clicked();

    void on_saveBtn_clicked();

    void on_clearBtn_clicked();

    void on_applyBtn_toggled(bool checked);

    void on_applyBtn_clicked();

    void on_Infrared_clicked();

    void on_OilPaint_clicked();

    void on_GrayscaleBtn_clicked();

    void on_loadNewImage_clicked();

    void on_mergeBtn_clicked();

    void on_Brightness_valueChanged(int value);

    void on_brightnessBtn_clicked();

    void on_EdgeDetection_clicked();

    void on_sunLightBtn_clicked();

    void on_Purple_clicked();

    void on_Sepia_clicked();

    void on_nightMoodBtn_clicked();

private:
    QGraphicsDropShadowEffect *Drop_Shadow_Effect;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
