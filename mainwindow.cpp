#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QLabel>
#include <QTime>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    duration = 0;
    player->setPlaylist(playlist);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
    time(position/1000);
}

void MainWindow::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_pushButton_clicked()
{
    fileNames = QFileDialog::getOpenFileNames(this, "Open Song");
    foreach (QString argument, fileNames) {
        QUrl url(argument);
        if (url.isValid()) {
        playlist->addMedia(url);
    }
    QFileInfo file(argument);
    ui->listWidget->addItem(file.baseName());
    }
    total = playlist->mediaCount();
}

void MainWindow::on_pushButton_2_clicked()
{
    player->play();
}

void MainWindow::on_pushButton_3_clicked()
{
    player->pause();
}

void MainWindow::on_pushButton_4_clicked()
{
    player->stop();
}

void MainWindow::on_durationChanged(qint64 position)
{
    ui->sliderProgress->setMaximum(position);
}

void MainWindow::on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);
    time(position/1000);
}

void MainWindow::on_listWidget_activated(const QModelIndex &index)
{
    ui->sliderProgress->setRange(0,player->duration()/1000);
    playlist->setCurrentIndex(ui->listWidget->currentRow());
    player->play();
}

void MainWindow::on_pushButton_5_clicked()
{
    playlist->previous();
}

void MainWindow::on_pushButton_6_clicked()
{
    playlist->next();
}

void MainWindow::on_pushButton_7_clicked()
{
    playlist->removeMedia(ui->listWidget->currentRow());
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void MainWindow::on_pushButton_8_clicked()
{
    playlist->clear();
    ui->listWidget->clear();
}

void MainWindow::time(quint64 info)
{
    QString tStr;
    QTime currentTime(0,(info/60)%60, info%60);
    QString format = "mm:ss";
    tStr = currentTime.toString(format);

    ui->label_3->setText(tStr);
}
