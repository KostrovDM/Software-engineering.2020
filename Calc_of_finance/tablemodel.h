#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "data.h"

class TableModel : public QAbstractTableModel
{

    Q_OBJECT

public:

    explicit TableModel(QObject *parent = nullptr, QString Title = "");

    QJsonObject SaveDataToJson();
    void ReadDataOfJson(QJsonObject jsonObj);

    void setValues(QList<Data> Values);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:

    QString Title;

    QList<Data> Values;

    double CalcSumm() const;

};

#endif // TABLEMODEL_H
