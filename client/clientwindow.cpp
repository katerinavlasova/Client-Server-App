#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisc()));
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::socketReady()
{

}

void ClientWindow::socketDisc()
{
    socket->deleteLater();
}
