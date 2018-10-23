#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QNetworkReply>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QNetworkAccessManager *networkManager;
    QNetworkRequest networkRequest;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void download_file( QUrl url );

};

#endif // MAINWINDOW_H
