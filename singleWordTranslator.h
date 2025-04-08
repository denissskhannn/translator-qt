#ifndef SINGLEWORDTRANSLATOR_H
#define SINGLEWORDTRANSLATOR_H

#include "translator.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class singleWordTranslator : public translator {
public:
    explicit singleWordTranslator(const QString &queryStr);
    virtual ~singleWordTranslator() override {}

    // Implements the translation by executing a prepared SQL query.
    virtual QString translate(const QString &input) override;

private:
    QString m_queryStr;
};

#endif // SINGLEWORDTRANSLATOR_H
