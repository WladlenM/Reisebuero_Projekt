
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
