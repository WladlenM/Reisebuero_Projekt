
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
#include <QInputDialog>



MainWindow::MainWindow(TravelAgency travelAgentur, QWidget *parent)
    : QMainWindow(parent),ReiseAgentur(travelAgentur)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBoxKunde->hide();
    ui->groupBoxReise->hide();
    ui->groupBoxBuchungdetails->hide();

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
    //ui->listWidget->clear();
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
        /*for(int i=0;i<ReiseAgentur.getBookings().size();i++)
        {
            QString ausgabeText=QString::fromStdString(ReiseAgentur.getBookings()[i]->showDetails());

            ui->listWidget->addItem(ausgabeText);
        }*/
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    /*for(int i=0;i<ReiseAgentur.getBookings().size();i++)
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
    }*/
}


void MainWindow::on_actionSuchen_triggered()
{
    int KundenId = QInputDialog::getInt(this,tr("Kund*innensuche"),tr("Gib Id ein: "));
    QMessageBox msgBox;
    if(ReiseAgentur.findCustomer(KundenId)==nullptr)
    {
        QString errorText = "Kunden-Id ist nicht vorhanden!";
        msgBox.setText(errorText);
        msgBox.exec();
    }
    else
    {
        int counter = 0;
        QString CustomerID;
        QString CustomerName;
        ui->tableWidgetReisen->setColumnCount(3);
        QStringList headerLabels;
        headerLabels << "Reise-ID" << "Beginn der Reise" << "Ender der Reise";
        ui->tableWidgetReisen->setHorizontalHeaderLabels(headerLabels);
        for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
        {
            if(ReiseAgentur.getAllTravels()[i]->getCustomerId()==KundenId)
            {
                counter++;
            }
        }
        ui->tableWidgetReisen->setRowCount(counter);
        int row=0;
        for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
        {
            if(ReiseAgentur.getAllTravels()[i]->getCustomerId()==KundenId)
            {
                QString reiseId = QString::number(ReiseAgentur.getAllTravels()[i]->getId());
                QTableWidgetItem* itemReiseId = new QTableWidgetItem(reiseId);
                itemReiseId->setFlags(itemReiseId->flags() & ~Qt::ItemIsEditable);
                ui->tableWidgetReisen->setItem(row,0,itemReiseId);
                row++;
            }
    }

        int rowStartDate=0;
        for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
        {
            if(ReiseAgentur.getAllTravels()[i]->getCustomerId()==KundenId)
            {
                QDate fromDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[0]->getFromDate()),"yyyyMMdd");
                QString startDatum = fromDate.toString();
                QTableWidgetItem* itemStartDatum = new QTableWidgetItem(startDatum);
                itemStartDatum->setFlags(itemStartDatum->flags() & ~Qt::ItemIsEditable);
                ui->tableWidgetReisen->setItem(rowStartDate,1,itemStartDatum);
                rowStartDate++;
            }
        }

        int rowEndDate=0;
        for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
        {
            if(ReiseAgentur.getAllTravels()[i]->getCustomerId()==KundenId)
            {
                QDate toDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-1]->getToDate()),"yyyyMMdd");
                QString endDatum = toDate.toString();
                QTableWidgetItem* itemEndDatum = new QTableWidgetItem(endDatum);
                itemEndDatum->setFlags(itemEndDatum->flags() & ~Qt::ItemIsEditable);
                ui->tableWidgetReisen->setItem(rowEndDate,2,itemEndDatum);
                rowEndDate++;
            }
        }

        for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
        {
            if(ReiseAgentur.getAllTravels()[i]->getCustomerId()==KundenId)
            {
                long tmpKundId = ReiseAgentur.getAllTravels()[i]->getCustomerId();
                CustomerID = QString::number(ReiseAgentur.getAllTravels()[i]->getCustomerId());
                for(int j=0;j<ReiseAgentur.getAllCustomers().size();j++)
                {
                    if(ReiseAgentur.getAllCustomers()[j]->getId()==tmpKundId)
                    {
                        CustomerName = QString::fromStdString(ReiseAgentur.getAllCustomers()[j]->getName());
                    }
                }
            }
        }
        ui->lineEditId->setText(CustomerID);
        ui->lineEditName->setText(CustomerName);

        ui->groupBoxKunde->show();
    }
}


/*void MainWindow::on_tableWidgetReisen_cellDoubleClicked(int row, int column)
{

    int test = ui->tableWidgetReisen->rowCount()-1;
    if(row==row)
    {

    }
}*/


void MainWindow::on_tableWidgetReisen_itemDoubleClicked(QTableWidgetItem *item)
{
    ui->tableWidgetBuchungen->setColumnCount(4);
    QStringList headerLabels;
    headerLabels << "Buchungstyp" << "Start" << "Ende" << "Preis";
    ui->tableWidgetBuchungen->setHorizontalHeaderLabels(headerLabels);
    int size = 0;

    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
    {
        QString reiseId = QString::number(ReiseAgentur.getAllTravels()[i]->getId());
        QDate fromDate =QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[0]->getFromDate()),"yyyyMMdd");
        QString startDatum = fromDate.toString();

        QDate toDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-1]->getToDate()),"yyyyMMdd");
        QString endDatum = toDate.toString();

        if(item->text()==reiseId||startDatum==item->text()||endDatum==item->text())
        {
            size = ReiseAgentur.getAllTravels()[i]->getTravelBookings().size();
        }
    }
    ui->tableWidgetBuchungen->setRowCount(size);

    for(int i=0;ReiseAgentur.getAllTravels().size();i++)
    {
        QString reiseId = QString::number(ReiseAgentur.getAllTravels()[i]->getId());
        QDate fromDate =QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[0]->getFromDate()),"yyyyMMdd");
        QString startDatum = fromDate.toString();

        QDate toDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-1]->getToDate()),"yyyyMMdd");
        QString endDatum = toDate.toString();

        if(reiseId==item->text()||startDatum==item->text()||endDatum==item->text())
        {
            ui->lineEditReiseID->setText(reiseId);
            break;
        }
    }

    int rowBuchungen=0;
    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
    {
        QString reiseId = QString::number(ReiseAgentur.getAllTravels()[i]->getId());
        QDate fromDate =QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[0]->getFromDate()),"yyyyMMdd");
        QString startDatum = fromDate.toString();

        QDate toDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-1]->getToDate()),"yyyyMMdd");
        QString endDatum = toDate.toString();

        if(reiseId==item->text()||startDatum==item->text()||endDatum==item->text())
        {
            int anzBuchungen = ReiseAgentur.getAllTravels()[i]->getTravelBookings().size();
            for(int j=0;j<anzBuchungen;j++)
            {
                QString type = QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->showDetails());
                if(type.contains("Flugbuchung"))
                {
                    QIcon icon(":/new/Icon/airplane-png.png");
                    QTableWidgetItem* itemType = new QTableWidgetItem;
                    itemType->setIcon(icon);
                    itemType->setFlags(itemType->flags() & ~Qt::ItemIsEditable);
                    ui->tableWidgetBuchungen->setItem(rowBuchungen,0,itemType);
                }
                else if(type.contains("Mietwagenreservierung"))
                {
                    QIcon icon(":/new/Icon/car_vehicle_transport_icon_144665.png");
                    QTableWidgetItem* itemType = new QTableWidgetItem;
                    itemType->setIcon(icon);
                    itemType->setFlags(itemType->flags() & ~Qt::ItemIsEditable);
                    ui->tableWidgetBuchungen->setItem(rowBuchungen,0,itemType);
                }
                else if(type.contains("Hotelreservierung"))
                {
                    QIcon icon(":/new/Icon/Hotel-png.png");
                    QTableWidgetItem* itemType = new QTableWidgetItem;
                    itemType->setIcon(icon);
                    itemType->setFlags(itemType->flags() & ~Qt::ItemIsEditable);
                    ui->tableWidgetBuchungen->setItem(rowBuchungen,0,itemType);
                }
                QDate buchungFromDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->getFromDate()),"yyyyMMdd");
                QString buchungStartDatum = buchungFromDate.toString();

                QTableWidgetItem* itemStartDatum = new QTableWidgetItem(buchungStartDatum);
                itemStartDatum->setFlags(itemStartDatum->flags() & ~Qt::ItemIsEditable);
                ui->tableWidgetBuchungen->setItem(rowBuchungen,1,itemStartDatum);

                QDate buchungToDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->getToDate()),"yyyyMMdd");
                QString buchungEndDatum = buchungToDate.toString();

                QTableWidgetItem* itemEndDatum = new QTableWidgetItem(buchungEndDatum);
                itemEndDatum->setFlags(itemEndDatum->flags() & ~Qt::ItemIsEditable);
                ui->tableWidgetBuchungen->setItem(rowBuchungen,2,itemEndDatum);

                QString buchungPreis = QString::number(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->getPrice());

                QTableWidgetItem* itemPreis = new QTableWidgetItem(buchungPreis);
                itemPreis->setFlags(itemPreis->flags() & ~Qt::ItemIsEditable);
                ui->tableWidgetBuchungen->setItem(rowBuchungen,3,itemPreis);
                rowBuchungen++;
            }
        }
    }

    ui->groupBoxReise->show();
}


void MainWindow::on_tableWidgetBuchungen_itemDoubleClicked(QTableWidgetItem *item)
{

    ui->groupBoxBuchungdetails->show();
}

