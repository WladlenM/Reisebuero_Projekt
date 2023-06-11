
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include "travelagency.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(TravelAgency travelAgentur, QWidget *parent = nullptr);
    ~MainWindow();
    TravelAgency ReiseAgentur;
    
    QString readJsonFile(QString fileName);
    
private slots:

    void on_actionEinlesen_2_triggered();
    //void handleItemDoubleClicked(QListWidgetItem *item, QListWidget *details,QListWidget *list);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_actionSuchen_triggered();

   // void on_tableWidgetReisen_cellDoubleClicked(int row, int column);

    void on_tableWidgetReisen_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidgetBuchungen_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButtonSave_clicked();

    void enableButtons();

    void on_pushButtonCancel_clicked();

    void on_actionKunde_hinzuf_gen_triggered();

    void on_actionBuchung_hinzuf_gen_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
