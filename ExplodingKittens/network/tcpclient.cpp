#include "tcpclient.h"
#include "netstructs.h"
#include <QDebug>

TcpClient::TcpClient()
    : TcpClient(QHostAddress::LocalHost, PORT_SRV)
{}

TcpClient::TcpClient(QHostAddress host, quint16 port)
    : _host(host), _port(port)
{
    _cli = new QTcpSocket();
    _cli->connectToHost(_host, _port);

    if(_cli->waitForConnected())
    {
        qDebug() << QString("Connected to %1:%2").arg(_host.toString()).arg(_port);
    }

    connect(_cli, &QTcpSocket::readyRead, this, &TcpClient::slotRecvDataFromServer);
}

TcpClient::~TcpClient()
{
    if(_cli->waitForDisconnected())
    {
        _cli->disconnectFromHost();
        qDebug() << QString("Disconnected from %1:%2").arg(_host.toString()).arg(_port);
        delete _cli;
    }
}

void TcpClient::slotRecvDataFromServer() const
{
    auto data = _cli->readAll();
    while(!data.isEmpty())
    {
        emit signalRecvDataFromServer(data.left(sizeof(NetworkPacket)));
        data = data.mid(sizeof(NetworkPacket));
    }
}

void TcpClient::slotSendDataToServer(QByteArray data) const
{
    _cli->write(data);
    _cli->flush();
}
