#ifndef QHTTPSERVER_H
#define QHTTPSERVER_H

#include <QObject>

#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>
#include <QFile>
#include <QNetworkProxy>
#include <QHostInfo>

#define HTTPSERVER_VERSION_MAJOR 0
#define HTTPSERVER_VERSION_MINOR 1
#define HTTPSERVER_VERSION_PATCH 0

class QTcpServer;
class HttpRequest;
class HttpResponse;

typedef QHash<QString, QString> HeaderHash;

extern QHash<int, QString> STATUS_CODES;

class QHttpServer : public QObject
{
	Q_OBJECT

public:
	QHttpServer(quint16 port,QObject *parent=0);
	~QHttpServer();

	bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);
	
	bool listen(quint16 port);

public slots:
    void slotThreadListen();

private:
	QString decodeURI(QString str);


signals:
	void sigApplyGroup(QString groupID);

private slots:
	void newConnection();

	void onRequest(HttpRequest*, HttpResponse*);

	
private:
	QTcpServer *m_tcpServer;
	quint16 m_port;

	HttpResponse *m_response;

};

#endif // QHTTPSERVER_H
