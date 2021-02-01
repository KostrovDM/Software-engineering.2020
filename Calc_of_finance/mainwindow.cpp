#include <QFileDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "income.h"
#include "spending.h"
#include "set_zero_values.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Image->setPixmap(QPixmap(":/Da.png"));
    setWindowIcon(QIcon(QPixmap(":/Picture.png")));

    SetZeroValues ZeroValues;

    SetTable(ui->tableViewSpending, &tableModelSpending, "Расходы", ZeroValues.SetupSpendingValues());

    SetTable(ui->tableViewIncome, &tableModelIncome, "Доходы", ZeroValues.SetupIncomeValues());
}

void MainWindow::SetTable(
    QTableView *tableView,
    TableModel **tableModel,
    QString tableTitle,
    QList<Data> Values
)
{
    *tableModel = new TableModel(tableView, tableTitle);
    (*tableModel)->setValues(Values);

    tableView->setModel(*tableModel);

    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();    
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tableView->horizontalHeader()->hide();
    tableView->verticalHeader()->hide();
    tableView->setSpan(0, 0, 1, (*tableModel)->columnCount());

    tableView->setStyleSheet("QTableView {gridline-color: red; background-color: white; border: 3px solid red; border-radius: 15px;}" );
    ui->tableViewIncome->setStyleSheet("QTableView {gridline-color: green; background-color: white; border: 3px solid green; border-radius: 15px;}" );
}

MainWindow::~MainWindow()
{
    if (tableModelSpending)
        delete tableModelSpending;

    if (tableModelIncome)
        delete tableModelIncome;

    delete ui;
}

void MainWindow::on_Save_clicked()
{
    if (fileName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName( this, tr("Сохранение данных в файл"), QString(), tr("JSON-файлы (*.json)") );
    }

    if (fileName.isEmpty()) return;

    QJsonObject jsonObjSpending = tableModelSpending->SaveDataToJson();
    QJsonObject jsonObjIncome = tableModelIncome->SaveDataToJson();

    QJsonObject jsonObj;
    jsonObj.insert("расходы", jsonObjSpending);
    jsonObj.insert("доходы", jsonObjIncome);

    QJsonDocument doc(jsonObj);

    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);

    jsonFile.write(doc.toJson(QJsonDocument::Indented));
}

void MainWindow::on_Load_clicked()
{
    fileName = QFileDialog::getOpenFileName( this, tr("Выбор файла сохранения"), QString(), tr("JSON-файлы (*.json)") );

    if (fileName.isEmpty())
        return;

    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);

    QJsonDocument doc = QJsonDocument().fromJson(jsonFile.readAll());

    QJsonObject jsonObj = doc.object();

    QJsonObject jsonObjCosts = jsonObj.value("расходы").toObject();
    tableModelSpending->ReadDataOfJson(jsonObjCosts);

    QJsonObject jsonObjIncome = jsonObj.value("доходы").toObject();
    tableModelIncome->ReadDataOfJson(jsonObjIncome);
}

void MainWindow::on_Exit_clicked()
{
    QMessageBox* SaveAfterExit = new QMessageBox("Подтверждение выхода",
                                    "Сохранить данные перед закрытием?",
                                    QMessageBox::Information,
                                    QMessageBox::Yes,
                                    QMessageBox::No | QMessageBox::Escape,
                                    QMessageBox::Cancel | QMessageBox::Escape,
                                    this);

    SaveAfterExit->setWindowModality(Qt::WindowModal);
    int choise = SaveAfterExit->exec();
    delete SaveAfterExit;

    if(choise == QMessageBox::Yes)
    {
        on_Save_clicked();
        QApplication::quit();
    }
    if(choise == QMessageBox::No)
        QApplication::quit();
}
