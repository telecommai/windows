#include <QtWidgets/QApplication>
#include <qsharedmemory.h>
#include <QTranslator>
#include <tchar.h>
#include <QDebug>
#include "oescreenshot.h"
#ifdef Q_OS_WIN
#include <QLibrary>
#include "ShellScalingApi.h"
#endif
#ifdef _DEBUG
#pragma comment(lib,"ScreenCutShareLibD.lib")
#else
#pragma comment(lib,"ScreenCutShareLib.lib")
#endif

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSharedMemory *p_shareMem = new QSharedMemory("ScreenShotTool");
	int nIndex = 2;
	int nFlag;
	while (nIndex--)
	{
		if (p_shareMem->attach(QSharedMemory::ReadOnly))
		{
			p_shareMem->detach();
		}
	}
	if (p_shareMem->create(1))
	{
		QStringList arguments = QCoreApplication::arguments();
		if (arguments.size() == 3)
		{
			QStringList hwndList = arguments[1].split(",");
			if (hwndList.count() == 2)
			{
				QString language = arguments[2];
				if (language == QString::fromWCharArray(L"简体中文"))
				{
					QTranslator *trans = new QTranslator;
					trans->load(":/Simplified Chinese/Resources/screencutsharelib_zh.qm");
					a.installTranslator(trans);
				}
				if (language == QString::fromWCharArray(L"русский"))
				{
					QTranslator *trans = new QTranslator;
					trans->load(":/Russian/Resources/screencutsharelib_ru.qm");
					a.installTranslator(trans);
				}
				if (language == QString::fromWCharArray(L"Հայերեն"))
				{
					QTranslator *trans = new QTranslator;
					trans->load(":/Hayeren/Resources/screencutsharelib_hy.qm");
					a.installTranslator(trans);
				}
				if (language == QString::fromWCharArray(L"Español"))
				{
					QTranslator *trans = new QTranslator;
					trans->load(":/Spanish/Resources/screencutsharelib_es.qm");
					a.installTranslator(trans);
				}
				if (language == QString::fromWCharArray(L"Português"))
				{
					QTranslator *trans = new QTranslator;
					trans->load(":/Portuguese/Resources/screencutsharelib_pt.qm");
					a.installTranslator(trans);
				}
				if (language == QString::fromWCharArray(L"ไทย"))
				{
					QTranslator *trans = new QTranslator;
					trans->load(":/Thai/Resources/screencutsharelib_th.qm");
					a.installTranslator(trans);
				}
				

				HWND hWnd = (HWND)_tcstoul(hwndList[0].toStdWString().c_str(), NULL, 16);
				QString thisParam = hwndList[1];
				OEScreenshot *screenCut = OEScreenshot::Instance(hWnd, thisParam);
				nFlag = a.exec();
			}
		}
		if (p_shareMem->isAttached())
			p_shareMem->detach();
		delete p_shareMem;
		p_shareMem = NULL;
		return nFlag;
	}
}
