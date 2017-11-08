#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

static bool createConnection()
{
    //添加数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //数据库连接命名
    db.setDatabaseName("combine.db");
    //打开数据库
    if(!db.open())
    {
        return false;
    }
    QSqlQuery query;
    query.exec("CREATE TABLE Time(h varchar(25) PRIMARY KEY)");
    //query.exec("insert into Time values('2016-01-01 周五')");
    return true;
}

static bool closeConnection()
{
    QSqlDatabase::database().close();
    return 1;
}
#endif // CONNECTION_H
