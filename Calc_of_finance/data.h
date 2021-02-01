#ifndef DATA_H
#define DATA_H

#include <QString>

class Data
{
public:

    Data(QString Name, double Value);
    QString getName() const;
    double getValue() const;
    void setValue(double value);
//    void setName(QString name);//-----------РЕДАКТОР СТАТЕЙ------------

private:

    QString Name;
    double Value;
};

#endif // DATA_H
