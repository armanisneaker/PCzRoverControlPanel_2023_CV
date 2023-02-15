#include "Connection.h"

Connection::Connection(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress(adress),port);
    //podpinamy nasłuchiwanie
    //connect(socket, &QUdpSocket::readyRead, this, &Connection::readDatagram);
}

QByteArray Connection::createFrame(QByteArray frame, QByteArray frameDrive, QByteArray frameArm)
{
    for(int i=0;i<frameDrive.size();i++)
    {
        frame[i+4] = frameDrive[i];
        //qDebug() << frameDrive;
        //qDebug() << frameDrive.size();
    }
    for(int i=0;i<frameArm.size();i++)
    {
        frame[i+67] = frameArm[i];
        //qDebug() << frameDrive;
        //qDebug() << frameDrive.size();
    }

    return frame;
}

bool Connection::sendFrame(QByteArray frame, QString adress, int port)
{
    int bytesSent{0};

    bytesSent = socket->writeDatagram(frame,QHostAddress(adress),port);

    /*qDebug() << "Frame Sent: ";
    for(int i = 0;i<frame.size();i++)
    {
        qDebug() << i << ". " << frame[i];
    }*/
    qDebug() << "Bytes Sent (in this frame): " << bytesSent;
    return bytesSent != -1 ? true : false;
}


bool Connection::readFrame(QByteArray& frame)
{
    frame.resize(socket->pendingDatagramSize());

    bytesReceived = socket->readDatagram(frame.data(),frame.size(),&sender,&senderPort);

    //qDebug()<<bytesReceived;

    return bytesReceived != -1 ? true : false;
}

bool Connection::connectionExecute()
{

    return 0;
}

