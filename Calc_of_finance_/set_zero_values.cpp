#include "set_zero_values.h"

SetZeroValues::SetZeroValues()
{
    SpendingName = {"Одежда", "Транспорт", "Питание", "Квартира и связь", "Отдых и развлечения",
                       "Лекарства и медицина", "Ипотека, долги, кредиты", "Разное"};

    IncomeName = {"Зарплата", "Зачисления на счет", "Сумма наличными", "Возврат средств"};
}

QList<Data> SetZeroValues::SetupSpendingValues()
{
    QList<Data> result;

    for (qsizetype i = 0; i <  SpendingName.size(); ++i)
    {
            Spending data(SpendingName.at(i), 0);
            result.append(data);
    }

    return result;
}

QList<Data> SetZeroValues::SetupIncomeValues()
{
    QList<Data> result;

    for (qsizetype i = 0; i <  IncomeName.size(); ++i)
    {
            Income data(IncomeName.at(i), 0);
            result.append(data);
    }

    return result;
}
