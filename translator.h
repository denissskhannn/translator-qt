#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QString>

class translator {
public:
    virtual ~translator() {}
    virtual QString translate(const QString &input) = 0;
};

#endif // TRANSLATOR_H
