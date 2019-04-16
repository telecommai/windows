
#ifndef HTTP_CONNECTION_H
#define HTTP_CONNECTION_H

#include <QObject>
#include <QHash>
#include "http_parser.h"

class QTcpSocket;
class HttpRequest;
class HttpResponse;

typedef QHash<QString, QString> HeaderHash;

class HttpConnection : public QObject
{
    Q_OBJECT

public:
    HttpConnection(QTcpSocket *socket, QObject *parent = 0);
    virtual ~HttpConnection();

    void write(const QByteArray &data);
    void flush();

signals:
    void newRequest(HttpRequest*, HttpResponse*);

private slots:
    void parseRequest();
    void responseDone();

private:
    static int MessageBegin(http_parser *parser);
    static int Path(http_parser *parser, const char *at, size_t length);
    static int QueryString(http_parser *parser, const char *at, size_t length);
    static int Url(http_parser *parser, const char *at, size_t length);
    static int Fragment(http_parser *parser, const char *at, size_t length);
    static int HeaderField(http_parser *parser, const char *at, size_t length);
    static int HeaderValue(http_parser *parser, const char *at, size_t length);
    static int HeadersComplete(http_parser *parser);
    static int Body(http_parser *parser, const char *at, size_t length);
    static int MessageComplete(http_parser *parser);

private:
    QTcpSocket *m_socket;
    http_parser_settings m_parserSettings;
    http_parser *m_parser;

    HttpRequest *m_request;

    HeaderHash m_currentHeaders;
    QString m_currentHeaderField;
    QString m_currentHeaderValue;
};

#endif
