#include "tcpserver.h"
#include "netstructs.h"
#include <QDebug>

TcpServer::TcpServer()
    : TcpServer(PORT_SRV)
{}

TcpServer::TcpServer(quint16 port)
{
    _srv = new QTcpServer();

    if(!_srv->listen(QHostAddress::AnyIPv4, port))
    {
        qDebug() << "Unable to start TCP server on port" << QString::number(_srv->serverPort());
    }
    else
    {
        qDebug() << "Started TCP server on"
                 << QString("%1:%2").arg(_srv->serverAddress().toString()).arg(_srv->serverPort());
    }

    connect(_srv, &QTcpServer::newConnection, this, &TcpServer::slotNewClientConnected);
}

void TcpServer::slotNewClientConnected()
{
    while(_srv->hasPendingConnections())
    {
        auto cli = _srv->nextPendingConnection();
        _clients.insert(cli);
        qDebug() << "Connected client"
                 << QString("%1:%2").arg(cli->peerAddress().toString()).arg(cli->peerPort());

        connect(cli, &QTcpSocket::readyRead, this, [this, cli]()
        {
            slotRecvDataFromClient(cli);
        });
        connect(cli, &QTcpSocket::disconnected, this, [this, cli]()
        {
            slotClientDisconnected(cli);
        });
    }
}

void TcpServer::slotClientDisconnected(QTcpSocket *cli)
{
    _clients.remove(cli);
    cli->deleteLater();
    qDebug() << "Disconnected client"
             << QString("%1:%2").arg(cli->peerAddress().toString()).arg(cli->peerPort());
}

void TcpServer::slotRecvDataFromClient(QTcpSocket *cli) const
{
    auto data = cli->readAll();
    while(!data.isEmpty())
    {
        emit signalRecvDataFromClient(data.left(sizeof(NetworkPacket)));
        data = data.mid(sizeof(NetworkPacket));
    }
}

void TcpServer::slotSendDataToClient(QByteArray data) const
{
    if(!_clients.isEmpty())
    {
        auto cli = *_clients.begin();
        cli->write(data);
        cli->flush();
    }
}
