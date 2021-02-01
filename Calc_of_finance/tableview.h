#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QMouseEvent>

class TableView : public QTableView
{

public:

    TableView(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
};

#endif // TABLEVIEW_H
