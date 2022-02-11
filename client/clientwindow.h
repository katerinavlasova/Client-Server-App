#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

    QTcpSocket *socket;
    QByteArray Data;

public slots:
    void socketReady();
    void socketDisc();
private:
    Ui::ClientWindow *ui;
};
#endif // CLIENTWINDOW_H
