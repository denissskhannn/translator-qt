#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

inline bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("translation_db");
    db.setUserName("postgres");
    db.setPassword("hi");
    if (!db.open()) {
        QMessageBox::warning(0, "Error DB", db.lastError().text());
        return false;
    }
    else
    {
        QMessageBox::information(0, "Nice", "Successful connection to DB!");
        return true;
    }
}

#endif // CONNECTION_H
