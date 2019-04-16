#ifndef VLCWIDGET_H
#define VLCWIDGET_H

#ifdef Q_OS_WIN
#include <Windows.h>
#endif
#include <QWidget>
#include <qtimer.h>
#include <qdesktopwidget.h>
#include <QMouseEvent>
#include <QTime>
#include "QtAV.h"
#include <QLabel>

namespace Ui { class IMVideoPlayer; };

class IMVideoPlayer : public QWidget
{
	Q_OBJECT

public:
	IMVideoPlayer(QWidget *parent = 0);
	~IMVideoPlayer();

	void videoPlay(QString mediaPath);

protected:
	void mousePressEvent(QMouseEvent *event);       
	void mouseReleaseEvent(QMouseEvent *event);     
	void mouseDoubleClickEvent(QMouseEvent *event); 
	void mouseMoveEvent(QMouseEvent *event);        

private:
	Ui::IMVideoPlayer *ui;

	QString address;
	
	bool isPlaying;
	int duration;
	QPoint mouse;

	QPixmap closeImg;
	QPixmap playImg;
	QPixmap pauseImg;

	QtAV::VideoOutput *m_vo;
	QtAV::AVPlayer *m_player;
	int m_unit;

	QLabel *m_firstPicLabel;

signals:
	void sigClose();

public slots:
    void sizeInitSlot();

	void seekBySlider(int value);
	void seekBySlider();
	void playPause();
	void stopPlayer();
private Q_SLOTS:
	void updateSlider(qint64 value);
	void updateSlider();
	void updateSliderUnit();
};

#endif // VLCWIDGET_H
