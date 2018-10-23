#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    networkManager = new QNetworkAccessManager();

    qDebug() << "start";
    download_file(QUrl("http://172.16.2.111/servicebox/servicebox.app.exe"));
    qDebug() << "end";

    QTimer::singleShot(0, this, SLOT(close()));

}

void MainWindow::download_file( QUrl url )
{
    QNetworkReply* reply;
    QEventLoop connection_loop;
    connect(networkManager, SIGNAL( finished( QNetworkReply* ) ), &connection_loop, SLOT( quit() ) );
    networkRequest.setUrl( url );
    qDebug() << "reaching url: " << url;
    reply = networkManager->get( networkRequest );
    connection_loop.exec();
    qDebug() << "get -> " << url << ", done, size: " << reply->bytesAvailable();
    reply->deleteLater();

    QString fileName = QDir::currentPath() +  QDir::separator() + "servicebox.app.exe";
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
            qDebug() << "Could not open %s for writing: %s\n" << qPrintable(file.errorString());
            return;
    }
    qDebug() << fileName;
    file.write(reply->readAll());
    file.close();

    return;
}

MainWindow::~MainWindow()
{

}
