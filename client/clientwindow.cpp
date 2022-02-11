#include "clientwindow.h"
#include "ui_clientwindow.h"

#include <QFile>
#include <QFileDialog>

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
//read a chosen file and send it to the server
void ClientWindow::on_chooseFileButton_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this, "Open a file", "D:/");
    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "File wasn't opened \n";
        return;
    }
    //connect to server
    socket->connectToHost(QHostAddress::LocalHost, 1010);
    Data = file.readAll();
    //send file
    socket->write(Data);
    socket->waitForBytesWritten(300);
}

