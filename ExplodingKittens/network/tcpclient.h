#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    TcpClient();
    TcpClient(QHostAddress host, quint16 port);
    ~TcpClient();

signals:
    // Сигнал о получении данных от сервера
    void signalRecvDataFromServer(QByteArray data) const;

public slots:
    // Получение данных от сервера
    void slotRecvDataFromServer() const;

    // Отправка данных на сервер
    void slotSendDataToServer(QByteArray data) const;

private:
    QTcpSocket *_cli;
    QHostAddress _host;
    quint16 _port;
};

#endif // TCPCLIENT_H
