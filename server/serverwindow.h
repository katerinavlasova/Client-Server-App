#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWindow; }
QT_END_NAMESPACE

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    ServerWindow(QWidget *parent = nullptr);
    ~ServerWindow();

    server myServer;

public slots:
    //show picture that server received
    void showPicture(QByteArray &bytePicture);

private:
    Ui::ServerWindow *ui;

};
#endif // SERVERWINDOW_H
