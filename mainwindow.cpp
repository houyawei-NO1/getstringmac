#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkInterface>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getEthernetMac();
    getWlanMac();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getEthernetMac()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    qDebug()<<"getmac"<<nets;
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
//        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        if(nets[i].type()==QNetworkInterface::Ethernet)
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    qDebug()<<"getEthernetMac"<<strMacAddr;
    return strMacAddr;

}

QString MainWindow::getWlanMac()
{
    QList<QNetworkInterface> nets =             QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    qDebug()<<"getmac"<<nets;
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
//        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        if(nets[i].type()==QNetworkInterface::Wifi)
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
     qDebug()<<"getWlanMac"<<strMacAddr;

    return strMacAddr;

}
