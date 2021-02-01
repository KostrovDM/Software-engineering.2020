#include "data.h"

Data::Data(QString Name, double Value)
{
    this->Name = Name;
    this->Value = Value;
}

QString Data::getName() const
{
    return Name;
}

double Data::getValue() const
{
    return Value;
}

void Data::setValue(double value)
{
    Value = value;
}
////-----------РЕДАКТОР СТАТЕЙ---------------
//void Data::setName(QString name)
//{
//    Name = name;
//}
////-----------РЕДАКТОР СТАТЕЙ---------------
