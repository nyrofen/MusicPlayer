#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDebug>
#include <QMediaPlaylist>
#include <QListWidgetItem>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sliderProgress_sliderMoved(int position);

    void on_sliderVolume_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_durationChanged(qint64 position);

    void on_positionChanged(qint64 position);

    void on_listWidget_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer * player;
    QMediaPlaylist * playlist;
    QStringList fileNames;
    int total;
};

#endif // MAINWINDOW_H
