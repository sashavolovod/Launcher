#include <QApplication>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QtCore>

#include "runguard.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RunGuard guard( "servicebox.app" );
    if(guard.isAnotherRunning())
    {
        QMessageBox::critical(0, QObject::tr("ServiceBox"), QObject::tr("Уже запущена одна копия программы"));
    }
    else
    {
//        QMessageBox::information(0,"servicebox.app", "Можно обовляться");
        MainWindow w;

        QProcess process;
        process.startDetached("servicebox.app.exe");
    }

    return 0;
}
