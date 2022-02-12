#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QPixmap>

ServerWindow::ServerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerWindow)
{
    ui->setupUi(this);

    myServer.startServer();
    // server sends a signal after receiving a picture, showPicture shows received picture
    connect(&myServer, SIGNAL(showSignal(QByteArray&)), this, SLOT(showPicture(QByteArray&)));
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

//show picture from server
void ServerWindow::showPicture(QByteArray &bytePicture)
{
    QPixmap pic;
    pic.loadFromData(bytePicture, "PNG");
    int w = ui->PictureLabel->width();
    int h = ui->PictureLabel->height();
    ui->PictureLabel->setPixmap(pic.scaled(w,h, Qt::KeepAspectRatio));
}
