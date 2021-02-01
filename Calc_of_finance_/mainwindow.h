#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QHBoxLayout>
#include "tablemodel.h"

namespace Ui {

class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private slots:

    void on_Save_clicked();
    void on_Load_clicked();
    void on_Exit_clicked();

private:

    Ui::MainWindow *ui;

    TableModel *tableModelSpending;

    TableModel *tableModelIncome;

    QString fileName;

    void SetTable(
        QTableView *tableView,
        TableModel **tableModel,
        QString tableTitle,
        QList<Data> Values
    );

};

#endif // MAINWINDOW_H
