#ifndef CONNECTION_H
#define CONNECTION_H

#pragma once

#include <QUdpSocket>
#include <QDebug>
#include <QTimer>

class Connection : public QObject
{
  Q_OBJECT

  public:
    QString adress = "192.168.0.107";
    int port = 5150;

    QHostAddress sender;
    quint16 senderPort;

    explicit Connection(QObject *parent = 0);

    qint64 bytesReceived{0};
    qint64 bytedSent{0};

  private:
      QUdpSocket *socket;

  signals:

  public slots:
      bool connectionExecute();
      bool sendFrame(QByteArray frame, QString adress, int port);
      bool readFrame(QByteArray &frame);
      QByteArray createFrame(QByteArray frame, QByteArray frameDrive, QByteArray frameArm);

};

#endif // CONNECTION_H
