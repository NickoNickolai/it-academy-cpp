#include "remoteplayer.h"
#include "netstructs.h"

RemotePlayer::RemotePlayer(std::string name)
    : Player(PlayerType::REMOTE_PLAYER, name)
{}

void RemotePlayer::addCard(Card card)
{
    Player::addCard(card);

    NetworkPacket packet;
    packet.type = PacketType::DECK_CARD;
    packet.card = card;
    emit signalSendNetworkData(toQByteArray(packet));
}

void RemotePlayer::reqCard(PlayerState state)
{
    NetworkPacket packet;
    packet.type = PacketType::REQUEST_CARD;
    packet.exploded = state.exploded;
    emit signalSendNetworkData(toQByteArray(packet));
}

void RemotePlayer::reqNope(PlayerState)
{
    NetworkPacket packet;
    packet.type = PacketType::REQUEST_NOPE;
    emit signalSendNetworkData(toQByteArray(packet));
}

void RemotePlayer::reqFavor()
{
    NetworkPacket packet;
    packet.type = PacketType::REQUEST_FAVOR;
    emit signalSendNetworkData(toQByteArray(packet));
}

void RemotePlayer::addFuture(const Card &card)
{
    Player::addFuture(card);

    NetworkPacket packet;
    packet.type = PacketType::ADD_FUTURE;
    packet.card = card;
    emit signalSendNetworkData(toQByteArray(packet));
}

void RemotePlayer::popFuture()
{
    Player::resetFuture();

    NetworkPacket packet;
    packet.type = PacketType::POP_FUTURE;
    emit signalSendNetworkData(toQByteArray(packet));
}

void RemotePlayer::resetFuture()
{
    Player::resetFuture();

    NetworkPacket packet;
    packet.type = PacketType::RESET_FUTURE;
    emit signalSendNetworkData(toQByteArray(packet));
}
