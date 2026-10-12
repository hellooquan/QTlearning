#include "mainwindow.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "ui_mainwindow.h"
/*
    把数据打包成json格式

*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建最外层的对象
    QJsonObject obj;

    //添加键值对：写法1使用[]重载
    obj["商品名字"]="娃哈哈";
    obj["价格"] = 4.5;

    QJsonArray arr;
    arr.append("广东");
    arr.append("福建");

    obj.insert("地区", arr);
    //添加键值对：写法2使用insert方法

    //创建QJsonDocument对象
    QJsonDocument *doc=new QJsonDocument(obj);
    //打包json数据
    //QJsonDocument::Compact枚举值表示打包好json数据在一整行，没有换行，没有缩进
    QByteArray buf=doc->toJson(QJsonDocument::Compact);

    //QJsonDocument::Indented枚举值表示打包好json数据有自动换行，有缩进
    //QByteArray buf=doc->toJson(QJsonDocument::Indented);

    //验证一下: QByteArray字节数组不要直接打印(打印出来是16进制字节)
    //把buf转成QString，方便打印
    QString str(buf);
    qDebug()<<"打包好的json数据是: "<<str;
}

MainWindow::~MainWindow()
{
    delete ui;
}
