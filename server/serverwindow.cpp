#include "serverwindow.h"
#include "ui_serverwindow.h"

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


void ServerWindow::showPicture(QByteArray &bytePicture)
{
    qDebug("show picture!! \n");
}
