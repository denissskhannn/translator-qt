#include "translator.h"
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>

/*
translate::translate(QWidget *parent)
    : QMainWindow(parent)
{
    if(!setupDatabase()) {
        qDebug() << "Database connection failed!";
    }
}

translate::~translate() {
    if (db.isOpen())
        db.close();
}

bool translate::setupDatabase() {

    db = QSqlDatabase::addDatabase("QPSQL");


    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("translation_db");
    db.setUserName("postgres");
    db.setPassword("hi");


    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database connection established successfully.";
    return true;

}
*/
