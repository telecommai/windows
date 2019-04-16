#include "screenshottool.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include "oescreenshot.h"

#ifdef _DEBUG
#pragma comment(lib,"ScreenCutShareLibD.lib")
#else
#pragma comment(lib,"ScreenCutShareLib.lib")
#endif
ScreenShotTool::ScreenShotTool(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
}

ScreenShotTool::~ScreenShotTool()
{

}

void ScreenShotTool::SetHwnd(HWND hWnd)
{
	mhWnd = hWnd;
}

void ScreenShotTool::StartScreen()
{
	OEScreenshot *screenCut = OEScreenshot::Instance();
	connect(screenCut, SIGNAL(sigScreenComplete(QString)), this, SLOT(slotSendScreenShotPic(QString)));
	connect(screenCut, SIGNAL(sigScreenCanclePixMap()), this, SLOT(slotScreenCanclePixMap()));
}

void ScreenShotTool::slotSendScreenShotPic(QString strFileName)
{
	QJsonObject json;
	json.insert("CMD", "ScreenShotComplete");
	json.insert("path", strFileName);
	QString strJSON = QString(QJsonDocument(json).toJson());
	qDebug() << strJSON;
	SendCutMessage(strJSON);
}

void ScreenShotTool::SendCutMessage(QString strJson)
{
	QByteArray  ByteArray = strJson.toUtf8();
	const char *strMsg = ByteArray.constData();
	COPYDATASTRUCT copyData = { 0 };
	copyData.dwData = 1;                                                                                                        //标志发送CString类型
	copyData.cbData = strlen(strMsg);
	copyData.lpData = (void*)strMsg;
	HWND hWnd = (HWND)this->winId();
	::SendMessage(mhWnd, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&copyData);
}

void ScreenShotTool::slotScreenCanclePixMap()
{
	QJsonObject json;
	json.insert("CMD", "ScreenCancle");
	json.insert("widgetPtr", m_thisParm);//要传递到的widget指针
	QString strJSON = QString(QJsonDocument(json).toJson());
	SendCutMessage(strJSON);
}
