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
    QString path;
    QString file_name;
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
     // void imageChanged(const Image& newImage);
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

private:
    QGraphicsDropShadowEffect *Drop_Shadow_Effect;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
