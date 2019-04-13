#include <QtWidgets/QApplication>
#include <QResource>
#include "opobjectmanager.h"
#include "globalmanager.h"
#ifdef Q_OS_WIN
#include "dependent.h"
#else
#include "inline_mac.h"
#endif

void initEnv()
{
	QString webEngineViewProcessPath = QCoreApplication::applicationDirPath() + "/" + "TelecommHelper.exe";
	qputenv("QTWEBENGINEPROCESS_PATH", webEngineViewProcessPath.toLocal8Bit());
}

int main(int argc, char *argv[])
{
	initMinDump(); 
	
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
	QApplication imchat(argc, argv);
#ifdef Q_OS_WIN
	initEnv();
#endif

	QCoreApplication::setOrganizationName("Telecomm");
	QCoreApplication::setOrganizationDomain("Telecomm");
	QCoreApplication::setApplicationName("Telecomm");

    QDir::setCurrent(QCoreApplication::applicationDirPath());
	imchat.setQuitOnLastWindowClosed(false);

	OPObjectManager objectManager;
	objectManager.InitApp();
	return objectManager.InitMain();
}