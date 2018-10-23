#include <QApplication>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QtCore>

#include "runguard.h"

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


    qDebug() << QDir::currentPath();
    return 0;
}
