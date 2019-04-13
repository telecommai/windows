#pragma once

#include <QWidget>
#include <qrect.h>
#include "MessageNotifyModel.h"

namespace Ui { class NewNotifyGui; };

class NewNotifyGui : public QWidget
{
	Q_OBJECT
protected:

public:
	NewNotifyGui(QWidget *parent = Q_NULLPTR);
	~NewNotifyGui();
	void addQmlWidget(QWidget *);
private:
	Ui::NewNotifyGui *ui;
	void initStyle();
	MessageNotifyModel *notifyModel = new MessageNotifyModel();
	int msgCounts = 0;
	QPoint sysTrayPos;
	QTimer *timer;
	QPoint handleWinPos(QPoint inPoint);
public slots:
	void slotAdjustStyle(MessageNotifyModel *);
	void slotMouseSuspendIn(QPoint);
	void slotMouseSuspendOut(QPoint, int);
	void slotClickButton();
	void slotHideWindow();
signals:
	void sigSendBoxRect(QRect);
	void sigIgnoreBtnClicked();
	void sigItemClick();
	void sigCancleSuspendedColor();
}
;