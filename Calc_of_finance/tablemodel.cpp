#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include "tablemodel.h"

TableModel::TableModel(QObject *parent, QString Title)
    : QAbstractTableModel(parent)
{
    this->Title = Title;
}

void TableModel::setValues(QList<Data> Values)
{
    this->Values = Values;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return Values.count() + 3;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 2;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int rowIndex = index.row();
    int colIndex = index.column();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (rowIndex) {
        case 0:
            switch (colIndex) {
            case 0: return QVariant(Title);
            }
            break;
        case 1:
            switch (colIndex) {
              case 0: return QVariant("Статья");
            case 1: return QVariant("Сумма");
            }
            break;
        default:
            if (rowIndex == rowCount() - 1)
            {
                switch (colIndex) {
                case 0: return QVariant("Итого:");

                case 1:
                    double Summ = CalcSumm();
                    return QVariant(Summ);

                }
            }
            else if (rowIndex > 1 && rowIndex < rowCount() - 1)
            {
                QList<Data> list = Values;
                Data item = list.at(rowIndex - 2);

                switch (colIndex) {
                case 0: return QVariant(item.getName());
                case 1: return QVariant(item.getValue());
                default:
                    break;
                }
            }
        }
    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);

    int rowIndex = index.row();
    int colIndex = index.column();

        if (rowIndex > 1 && rowIndex < rowCount() - 1 && colIndex == 1)
        {
            QList<Data>& list = Values;

            int i = rowIndex - 2;
            Data newItem = list.at(i);
            newItem.setValue(value.toDouble());
            list.removeAt(i);
            list.insert(i, newItem);
        }
//        //---------------РЕДАКТОР СТАТЕЙ----------------
//        if (rowIndex > 1 && rowIndex < rowCount() - 1 && colIndex == 0)
//        {
//            QList<Data>& list = Values;

//            int i = rowIndex - 2;
//            Data newItem = list.at(i);
//            newItem.setName(value.toString());
//            list.removeAt(i);
//            list.insert(i, newItem);
//        }
//        //---------------РЕДАКТОР СТАТЕЙ----------------

    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    int rowIndex = index.row();
    int colIndex = index.column();

    if (rowIndex > 1 && rowIndex != rowCount() - 1 && colIndex == 1)//----РЕДАКТОР СТАТЕЙ-----
        return Qt::ItemIsEnabled | Qt::ItemIsEditable;

    return QAbstractItemModel::flags(index);
}

double TableModel::CalcSumm() const
{
    double result = 0;
    QList<Data> list = Values;


    for (QList<Data>::iterator it = list.begin(); it != list.end(); ++it)
    {
        result += (*it).getValue();
    }

    return result;
}

QJsonObject TableModel::SaveDataToJson()
{
        QJsonObject Json, JsonDataUnit;
        QJsonArray JsonArr;

        QListIterator<Data> i(Values);
        QListIterator<Data> j(Values);

        while (i.hasNext() && j.hasNext()) {
            int key = 0;

            JsonDataUnit["статья"] = i.next().getName();
            JsonDataUnit["сумма"] = j.next().getValue();

            JsonArr.append(JsonDataUnit);

            Json.insert(QString::number(key), JsonArr);
            key++;
        }
        return Json;
}

void TableModel::ReadDataOfJson(QJsonObject jsonObj)
{
    beginResetModel();

    Values.clear();

    foreach(const QString& key, jsonObj.keys()) {
        QList<Data> list;

        QJsonArray jsonArray = jsonObj.value(key).toArray();

        foreach (const QJsonValue & value, jsonArray) {
            QJsonObject obj = value.toObject();

            Data b(obj["статья"].toString(), obj["сумма"].toDouble());
            list.append(b);
        }

        Values.append(list);
    }

    endResetModel();
}
