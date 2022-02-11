#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QPixmap>

ServerWindow::ServerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerWindow)
{
    ui->setupUi(this);

    myServer.startServer();
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
    ui->PictureLabel->setPixmap(pic);
    qDebug("show picture!! \n");
}
