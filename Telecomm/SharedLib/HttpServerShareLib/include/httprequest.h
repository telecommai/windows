
#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <QObject>
#include <QHash>
#include <QMetaType>
#include <QUrl>

class QTcpSocket;

class HttpConnection;

typedef QHash<QString, QString> HeaderHash;

class HttpRequest : public QObject
{
    Q_OBJECT

    Q_PROPERTY(HeaderHash headers    READ headers);
    Q_PROPERTY(QString remoteAddress READ remoteAddress);
    Q_PROPERTY(quint16 remotePort    READ remotePort);
    Q_PROPERTY(QString method        READ method);
    Q_PROPERTY(QUrl    url           READ url);
    Q_PROPERTY(QString path          READ path);
    Q_PROPERTY(QString httpVersion   READ httpVersion);

public:
    virtual ~HttpRequest();

    const QString& method() const { return m_method; };

    const QUrl& url() const { return m_url; };

    const QString path() const { return m_url.path(); };

    const QString& httpVersion() const { return m_version; };

    const QString& queryString() const;

    const HeaderHash& headers() const { return m_headers; };

    QString header(const QString &field) { return m_headers[field]; };
	
    const QString& remoteAddress() const { return m_remoteAddress; };

    quint16 remotePort() const { return m_remotePort; };

signals:
 
    void data(const QByteArray &);

    void end();

private:
    HttpRequest(HttpConnection *connection, QObject *parent = 0);

    void setMethod(const QString &method) { m_method = method; }
    void setVersion(const QString &version) { m_version = version; }
    void setUrl(const QUrl &url) { m_url = url; }
    void setHeaders(const HeaderHash headers) { m_headers = headers; }

    HttpConnection *m_connection;
    HeaderHash m_headers;
    QString m_method;
    QUrl m_url;
    QString m_version;
    QString m_remoteAddress;
    quint16 m_remotePort;

    friend class HttpConnection;
};

#endif
