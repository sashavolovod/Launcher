#include <QApplication>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QtCore>

#include "runguard.h"
#include "downloader.h"

#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif

void qSleep(int ms)
{

#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#endif
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    RunGuard guard( "servicebox.app" );
    if(guard.isAnotherRunning())
    {
        QMessageBox::critical(0, QObject::tr("Systray"), QObject::tr("Уже запущена одна копия программы"));
    } else
    {
        QMessageBox::information(0,"servicebox.app", "Можно обовляться");
        QProcess process;
        process.startDetached("./servicebox");
    }
 */

    Downloader *downloader = new Downloader();

    downloader->getData("http://www.mtbank.by/currxml.php");


    qDebug() << "start sleep";
    qSleep(5000);
    qDebug() << QDir::currentPath();
    return 0;
}
