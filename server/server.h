#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

class server : public QTcpServer
{
    Q_OBJECT
public:
    server();
    ~server();
    QTcpSocket *socket;
    QByteArray Data;

public slots:
    int startServer();
    void incomingConnection(qintptr socketDescriptor);
    void socketReady();
    void socketDisc();

signals:
    void showSignal(QByteArray &bytePicture);
};

#endif // SERVER_H
