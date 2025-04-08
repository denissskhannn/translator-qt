#include "singleWordTranslator.h"

singleWordTranslator::singleWordTranslator(const QString &queryStr)
    : m_queryStr(queryStr)
{
}

QString singleWordTranslator::translate(const QString &input) {
    QSqlQuery query;
    query.prepare(m_queryStr);
    query.bindValue(":input", input);

    if (!query.exec()) {
        qDebug() << "Query execution error:" << query.lastError().text();
        return "";
    }
    if (query.next()) {
        return query.value(0).toString();
    }
    return "";
}
