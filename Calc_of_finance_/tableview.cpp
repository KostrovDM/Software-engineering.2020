#include "tableview.h"

TableView::TableView(QWidget *parent):
    QTableView(parent)
{
}

void TableView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

        QModelIndex index = indexAt(event->pos());
        int rowIndex = index.row();
        int colIndex = index.column();

        if (rowIndex > 1 && colIndex == 1
                 && rowIndex < index.model()->rowCount() - 1 && rowIndex != 1 && colIndex != 0)
            edit(index);
    }
    QTableView::mousePressEvent(event);
}
