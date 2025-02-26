#ifndef REMOTEGAME_H
#define REMOTEGAME_H

#include <QObject>
#include "human.h"
#include "tcpclient.h"

class RemoteGame : public QObject
{
    Q_OBJECT
public:
    RemoteGame(const std::string &name);
    ~RemoteGame();

    // Инициализация новой игры
    void newGame();

public slots:
    // Слот отправки сетевого сообщения серверу
    void slotSendNetworkData(QByteArray data);

    // Слот получения сетевого сообщения от сервера
    void slotRecvNetworkData(QByteArray data);

signals:

private:
    Player *_player;
    TcpClient *_client;
};

#endif // REMOTEGAME_H
