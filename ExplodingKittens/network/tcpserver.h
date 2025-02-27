#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSet>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer();
    TcpServer(quint16 port);

signals:
    // Сигнал о получении данных от клиента
    void signalRecvDataFromClient(QByteArray data) const;

public slots:
    // Подключение нового клиента
    void slotNewClientConnected();

    // Подключение нового клиента
    void slotClientDisconnected(QTcpSocket *cli);

    // Получение данных от клиента
    void slotRecvDataFromClient(QTcpSocket *cli) const;

    // Отправка данных клиенту
    void slotSendDataToClient(QByteArray data) const;

private:
    QTcpServer *_srv;
    QSet<QTcpSocket *> _clients;
};

#endif // TCPSERVER_H
