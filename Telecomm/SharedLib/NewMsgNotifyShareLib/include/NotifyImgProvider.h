#ifndef NOTIFYIMGPROVIDER_H
#define NOTIFYIMGPROVIDER_H

#include <QQuickImageProvider>

class NotifyImgProvider : public QQuickImageProvider
{
public:
	NotifyImgProvider(ImageType type, Flags flags = 0);
	~NotifyImgProvider();
	QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize);
};

#endif // HEADPROVIDER_H
