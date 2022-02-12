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
private:
    QTcpSocket *socket;
    QByteArray Data;

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();


public slots:
    void socketReady();
    void socketDisc();
private slots:
    //send a chosen file to the server
    void on_chooseFileButton_clicked();

private:
    Ui::ClientWindow *ui;
};
#endif // CLIENTWINDOW_H
