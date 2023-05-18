
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidget>
#include <QHBoxLayout>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QListWidgetItem>



MainWindow::MainWindow(TravelAgency travelAgentur, QWidget *parent)
    : QMainWindow(parent),ReiseAgentur(travelAgentur)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::readJsonFile(QString fileName)
{
    std::string text = ReiseAgentur.readFile(fileName);
    QString msgFileText = QString::fromStdString(text);

    return msgFileText;
}

void MainWindow::on_actionEinlesen_2_triggered()
{
    ui->listWidget->clear();
    QString fileName = QFileDialog::getOpenFileName(this,tr("Datei öffnen"), QDir::homePath());

    QString msgFileText = readJsonFile(fileName);
    QString errorFileText;
    QMessageBox msgBox;
    //QHBoxLayout *layout = new QHBoxLayout;

    if(msgFileText.contains("Fehler:"))
    {
        QString errorText = "Wenn Sie die Datei bereits korrigiert haben, wählen Sie Wiederholen. Wählen Sie Verwerfen, um alle Buchungen zu löschen und Abbrechen, um die vorhandenen Buchungen stehenzulassen und diesen Dialog zu verlassen.";
        msgBox.setText(msgFileText);
        msgBox.setDetailedText(errorText);
        errorFileText = msgFileText;

        /*msgBox.addButton("Wiederholen",QMessageBox::ActionRole);
        msgBox.addButton("Verwerfen",QMessageBox::ActionRole);
        msgBox.addButton("Abbrechen",QMessageBox::ActionRole);*/
        msgBox.setStandardButtons(QMessageBox::Retry|QMessageBox::Discard|QMessageBox::Cancel);
        /*QAbstractButton* pButtonRepeat = msgBox.addButton("Wiederholen",QMessageBox::ActionRole);
        QPushButton* pButtonDiscard = msgBox.addButton("Verwerfen",QMessageBox::ActionRole);
        QPushButton* pButtonCancel = msgBox.addButton("Abbrechen",QMessageBox::ActionRole);*/
        int ret = msgBox.exec();
        while (errorFileText.contains("Fehler:"))
        {
            switch (ret)
            {
            case QMessageBox::Retry:
                errorFileText = readJsonFile(fileName);
                msgFileText = errorFileText;
                msgBox.setText(errorFileText);
                msgBox.setDetailedText(errorText);
                if(errorFileText.contains("Fehler:"))
                {
                    msgBox.exec();
                }
                break;
            case QMessageBox::Discard:
                // Don't Save was clicked
                break;
            case QMessageBox::Cancel:
                // Cancel was clicked
                break;
            default:
                // should never be reached
                break;
            }
        }
    }
    else
    {
        msgBox.setText(msgFileText);
        msgBox.exec();
        for(int i=0;i<ReiseAgentur.getBookings().size();i++)
        {
            QString ausgabeText=QString::fromStdString(ReiseAgentur.getBookings()[i]->showDetails());

            ui->listWidget->addItem(ausgabeText);
        }
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    for(int i=0;i<ReiseAgentur.getBookings().size();i++)
    {
        QString ausgabeText=QString::fromStdString(ReiseAgentur.getBookings()[i]->showDetails());
        if(item->text()==ausgabeText)
        {
            QString ID = QString::fromStdString(ReiseAgentur.getBookings()[i]->getId());
            QDate fromDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getBookings()[i]->getFromDate()),"yyyyMMdd");
            QDate toDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getBookings()[i]->getToDate()),"yyyyMMdd");
            double price = ReiseAgentur.getBookings()[i]->getPrice();
            if(ausgabeText.contains("Flugbuchung"))
            {
                ui->tabWidget->setCurrentIndex(0);
                QString airline = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[2]);
                QString fromDest = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[0]);
                QString toDest = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[1]);
                QString bookingClass = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[3]);
                ui->lineEditIdFlug->setText(ID);
                ui->dateEditAbflugFlug->setDate(fromDate);
                ui->dateEditAnkuftFlug->setDate(toDate);
                ui->doubleSpinBoxPreisFlug->setValue(price);
                ui->lineEditFluglinieFlug->setText(airline);
                ui->lineEditVonFlug->setText(fromDest);
                ui->lineEditNachFlug->setText(toDest);
                ui->lineEditKlasseFlug->setText(bookingClass);
            }
            else if(ausgabeText.contains("Hotelreservierung"))
            {
                ui->tabWidget->setCurrentIndex(2);
                QString hotel = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[0]);
                QString town = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[1]);
                QString roomType = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[2]);
                ui->lineEditIdHotel->setText(ID);
                ui->dateAnkunftHotel->setDate(fromDate);
                ui->dateEditAbreiseHotel->setDate(toDate);
                ui->doubleSpinBoxPreisHotel->setValue(price);
                ui->lineEditHotelHotel->setText(hotel);
                ui->lineEditSTadtHotel->setText(town);
                ui->lineEditZimmerHotel->setText(roomType);
            }
            else if(ausgabeText.contains("Mietwagenreservierung"))
            {
                ui->tabWidget->setCurrentIndex(1);
                QString company = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[2]);
                QString pickupLocation = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[0]);
                QString returnLocation = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[1]);
                QString vehicleClass = QString::fromStdString(ReiseAgentur.getBookings()[i]->myType()[3]);
                ui->lineEditIdMietwagen->setText(ID);
                ui->dateEditVonMietwagen->setDate(fromDate);
                ui->dateEditBisMietwagen->setDate(toDate);
                ui->doubleSpinBoxPreisMietwagen->setValue(price);
                ui->lineEditFirmaMietwageb->setText(company);
                ui->lineEditAbholortMietwagen->setText(pickupLocation);
                ui->lineEditAbgabeortMietwagen->setText(returnLocation);
                ui->lineEditKlasseMietwagen->setText(vehicleClass);
            }
        }
    }
}

