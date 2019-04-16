#pragma once

#include <qquickwidget.h>
#include "NewNotifyGui.h"
#include "MessageNotifyModel.h"
#include "NotifyImgProvider.h"
#include "imusermessage.h"
#include "stdafx.h"
#include "imbuddy.h"
#include "imdatabaseoperainfo.h"
#include "imtranstype.h"


class NewMsgNotifyShareLib : public QQuickWidget
{
	Q_OBJECT
private:
	enum enMsgJsonType
	{
		MsgJsonText = 0,
		MsgJsonAt,
	};
	void msgHandleForINTL(MessageInfo *messageInfo);

	void changeStyle(QString styleName);
public:
	NewMsgNotifyShareLib(QWidget *parent = NULL);
	~NewMsgNotifyShareLib();
	MessageNotifyModel *m_msgNotifyModel;
public:
	MessageNotifyModel *getModel();
	void dealMsgFlash(int funcType,  QString imgPath, MessageInfo *messageInfo);
	void OnInsertMessage(
		int msgCount,
		QString strUserID,
		QString strPicPath,
		QString strNickName,
		QString lastMsg,
		int perMsgCount,
		int msgType,
		int funcType
	);

	bool IsValidImage(QString imgPath);

public slots:
	void slotGetIconFlashStatus();
	void slotIgnoreBtnClicked();
	void slotDoClickItem(QString userId);
signals:
	void sigAdjustStyle(MessageNotifyModel *);
	void sigItemOfMsgBoxClicked(QString, int);
	void sigHideWidget();
	void sigDoClickItem(QString userId);
};