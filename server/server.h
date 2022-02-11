#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class server : public QTcpServer
{
public:
    server();
    ~server();
    QTcpSocket *socket;
    QByteArray Data;

public slots:
    int startServer();
    void incomingConnection(qintptr socketDescriptor);
    void socketReady();
    void socketDisconnection();
};

#endif // SERVER_H
