#ifndef SET_ZERO_VALUES_H
#define SET_ZERO_VALUES_H

#include <QObject>
#include <QList>
#include "spending.h"
#include "income.h"

class SetZeroValues
{

public:
    SetZeroValues();

    QList<Data> SetupSpendingValues();
    QList<Data> SetupIncomeValues();

private:
    QList<QString> IncomeName;
    QList<QString> SpendingName;

};

#endif // SET_ZERO_VALUES_H
