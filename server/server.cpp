#include "server.h"

server::server() {}

server::~server() {}

int server::startServer()
{
    if (this->listen(QHostAddress::LocalHost, 1010))
    {
        qDebug() << "Server is listening";
        return 0;
    }
    else
    {
        qDebug() << "Server isn't listening";
        return -1;
    }
}

void server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()),this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisc()));
    qDebug() << "Client connected";

}

void server::socketReady()
{
    if (socket->bytesAvailable() > 0)
    {
        Data = socket->readAll();
    }
}

void server::socketDisc()
{
    socket->deleteLater();
}
