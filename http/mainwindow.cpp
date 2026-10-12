#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
    例子：发送http请求下载网络上的图片
    思路：
          第一步：创建QNetworkRequest类对象--》表示http请求
                 QNetworkRequest(const QUrl &url)
                       参数：url 你要访问的http网址 QUrl(const QString &url)
          第二步：创建QNetworkAccessManager类对象发送http请求
                 发送get请求
                   QNetworkReply *get(const QNetworkRequest &request)
                 发送post请求
                   QNetworkReply *QNetworkAccessManager::post(const QNetworkRequest &request, QIODevice *data)
          第三步：如果请求发送成功，QNetworkAccessManager类对象会自动触发finished(QNetworkReply *reply)信号
                程序员主动关联这个信号，在槽函数中读取应答信息
                     void 槽函数(QNetworkReply *reply)
                     {
                         //读取服务器回复的http应答信息
                         QByteArray msg=reply->readAll();
                     }

*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::geturl);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//下载图片
void MainWindow::on_pushButton_clicked()
{
    //获取单行输入框输入的网址
    QString urlstr=ui->lineEdit->text();
    //创建QUrl对象
    QUrl url(urlstr);
    //
    QNetworkRequest request(url);

    manager->get(request);
}

void MainWindow::geturl(QNetworkReply *reply)
{
    //读取服务器回复的http应答信息
    QByteArray msg = reply->readAll();

    //由于我这个例子下载是网络中图片数据(http请求下载的)
    //因此msg存放的就是图片数据
    //在标签上显示图片
    QPixmap pixmap;
    pixmap.loadFromData(msg);
    ui->label->setPixmap(pixmap);
}
