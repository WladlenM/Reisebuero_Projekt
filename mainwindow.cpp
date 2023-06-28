
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "airport.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidget>
#include <QHBoxLayout>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QInputDialog>
#include <json.hpp>
#include <fstream>
#include <QDesktopServices>
#include <QInputDialog>
#include <QUuid>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QJsonArray>
#include <QComboBox>
#include <QPalette>
#include <QStandardItem>

//using namespace nlohmann;


MainWindow::MainWindow(TravelAgency travelAgentur, QWidget *parent)
    : QMainWindow(parent),ReiseAgentur(travelAgentur)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBoxKunde->hide();
    ui->groupBoxReise->hide();
    ui->groupBoxBuchungdetails->hide();

    connect(ui->lineEditAbgabeort,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditAbholort,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditbisFlug,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditFahrzeugKlasse,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditFirma,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditFlugsitz,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditFlugzeug,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditHotel,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditStadt,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditvonFlug,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->lineEditZimmertyp,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->dateEditEndDatum,SIGNAL(dateChanged(QDate)),this,SLOT(enableButtons()));
    connect(ui->dateEditStartDatum,SIGNAL(dateChanged(QDate)),this,SLOT(enableButtons()));
    connect(ui->doubleSpinBoxPreis,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->labelKarteUrl,&QLabel::linkActivated,[](const QString &link){QDesktopServices::openUrl(QUrl(link));});

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableButtons()
{
     ui->pushButtonSave->setEnabled(true);
    ui->pushButtonCancel->setEnabled(true);
}

QString MainWindow::readJsonFile(QString fileName)
{   
    std::string text = ReiseAgentur.readFile(fileName);
    QString msgFileText = QString::fromStdString(text);

    std::string dateiName="C:\\Users\\wladl\\Documents\\Prog2\\Praktikum\\Praktikum2\\iatacode.txt";

    std::ifstream einlesen(dateiName);

    nlohmann::json JsonListe;

    if(!einlesen)
    {
        std::cerr<<"Fehler: Datei konnte nicht gelsen werden!";
    }

    einlesen >> JsonListe;
    einlesen.close();

    for (auto& attribute : JsonListe)
    {
        std::string name;
        name = attribute["name"].get<std::string>();
        std::string iso_country;
        iso_country = attribute["iso_country"].get<std::string>();
        std::string municipality;
        municipality = attribute["municipality"].get<std::string>();
        std::string iata_code;
        iata_code= attribute["iata_code"].get<std::string>();

        std::shared_ptr<Airport> airport = std::make_shared<Airport>(name, iso_country, municipality, iata_code);
        ReiseAgentur.addAirpots(airport);
    }

    return msgFileText;
}

void MainWindow::on_actionEinlesen_2_triggered()
{
    ui->groupBoxKunde->hide();
    ui->groupBoxReise->hide();
    ui->groupBoxBuchungdetails->hide();
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
    ui->groupBoxKunde->hide();
    ui->groupBoxReise->hide();
    ui->groupBoxBuchungdetails->hide();
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

        for(int i=0;i<ReiseAgentur.getAllCustomers().size();i++)
        {
            if(ReiseAgentur.getAllCustomers()[i]->getId()==KundenId)
            {
                long tmpKundId = ReiseAgentur.getAllCustomers()[i]->getId();
                CustomerID = QString::number(ReiseAgentur.getAllCustomers()[i]->getId());
                for(int j=0;j<ReiseAgentur.getAllCustomers().size();j++)
                {
                    if(ReiseAgentur.getAllCustomers()[j]->getId()==KundenId)//tmpKundId)
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
    int row = item->row();
    QString reiseIdStr = ui->lineEditReiseID->text();
    long reiseId = reiseIdStr.toLong();
    int getIndex = 0;

    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
    {
        if(ReiseAgentur.getAllTravels()[i]->getId()==reiseId)
        {
            getIndex=i;
        }
    }

    QString bookingId = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->getId());
    ui->lineEditBuchungId->setText(bookingId);

    QDate fromDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->getFromDate()),"yyyyMMdd");
    ui->dateEditStartDatum->setDate(fromDate);

    QDate toDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->getToDate()),"yyyyMMdd");
    ui->dateEditEndDatum->setDate(toDate);

    double price = ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->getPrice();
    ui->doubleSpinBoxPreis->setValue(price);

    QTableWidgetItem* itemIcon = ui->tableWidgetBuchungen->item(row,0);
    QIcon iconCompare = itemIcon->icon();
    QPixmap pixmapCompare = iconCompare.pixmap(QSize(32,32));


    QIcon iconPlane(":/new/Icon/airplane-png.png");
    QPixmap pixmapPlane = iconPlane.pixmap(QSize(32,32));

    QIcon iconHotel(":/new/Icon/Hotel-png.png");
    QPixmap pixmapHotel = iconHotel.pixmap(QSize(32,32));

    QIcon iconAuto(":/new/Icon/car_vehicle_transport_icon_144665.png");
    QPixmap pixmapAuto = iconAuto.pixmap(QSize(32,32));

    if(pixmapCompare.toImage()==pixmapPlane.toImage())
    {
        ui->tabWidgetBuchungTyp->setCurrentIndex(0);
        QString urlMapTmp = "https://jenningsanderson.com/geo/?geojson=";

        QString airplane = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[2]);
        ui->lineEditFlugzeug->setText(airplane);

        QString fromDest = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[0]);
        ui->lineEditvonFlug->setText(fromDest);        

        QString toDest = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[1]);
        ui->lineEditbisFlug->setText(toDest);

        QString toAirport;
        QString fromAirport;
        bool statusStartairport = false;
        bool statusEndairport = false;
        QPalette colourStart = ui->lineEditStartflughafen->palette();
        QPalette colourEnd = ui->lineEditEndflughafen->palette();
        for(int i=0;i<ReiseAgentur.getAirpots().size();i++)
        {
            if(fromDest==QString::fromStdString(ReiseAgentur.getAirpots()[i]->getIata_code()))
            {
                fromAirport=QString::fromStdString(ReiseAgentur.getAirpots()[i]->getName());
                ui->lineEditStartflughafen->setText(fromAirport);
                statusStartairport=true;
                colourStart.setColor(QPalette::Text, Qt::black);
                ui->lineEditStartflughafen->setPalette(colourStart);
            }
            if(toDest==QString::fromStdString(ReiseAgentur.getAirpots()[i]->getIata_code()))
            {
                toAirport=QString::fromStdString(ReiseAgentur.getAirpots()[i]->getName());
                ui->lineEditEndflughafen->setText(toAirport);
                statusEndairport=true;
                colourEnd.setColor(QPalette::Text, Qt::black);
                ui->lineEditEndflughafen->setPalette(colourEnd);
            }
        }
        if(statusStartairport==false)
        {
            ui->lineEditStartflughafen->setText("Ungültiger Iata-Code");
            colourStart.setColor(QPalette::Text, Qt::red);
                ui->lineEditStartflughafen->setPalette(colourStart);
        }
        if(statusEndairport==false)
        {
                ui->lineEditEndflughafen->setText("Ungültiger Iata-Code");
                colourEnd.setColor(QPalette::Text, Qt::red);
                ui->lineEditEndflughafen->setPalette(colourEnd);
        }

        QString flugklasse = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[3]);
        ui->lineEditFlugsitz->setText(flugklasse);

        QString fromDestLoc = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[4]);
        QString fromDestLangt = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[5]);
        QString toDestLoc = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[6]);
        QString toDestLangt = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[7]);

        QString urlMaptmp2 ="{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\", \"coordinates\":[[" +  fromDestLangt + "," + fromDestLoc + "\],\["+toDestLangt + "," +toDestLoc+"\]\]\},\"properties\":{\"Von\":\""+fromDest+"\",\"Bis\":\""+toDest+"\"}}";

        QString urlMap3 = QUrl::toPercentEncoding(urlMaptmp2);

        QString urlMap = urlMapTmp + urlMap3;
        ui->labelKarteUrl->setOpenExternalLinks(true);

        ui->labelKarteUrl->setText(QString("<a href=\""+urlMap+"\">"+urlMap+"</a>"));
    }
    else if(pixmapCompare.toImage()==pixmapHotel.toImage())
    {
        ui->tabWidgetBuchungTyp->setCurrentIndex(1);

        QString urlMapTmp = "https://jenningsanderson.com/geo/?geojson=";

        QString hotel = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[0]);
        ui->lineEditHotel->setText(hotel);

        QString town = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[1]);
        ui->lineEditStadt->setText(town);

        QString roomType = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[2]);
        ui->lineEditZimmertyp->setText(roomType);

        QString hotelDest = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[3]);
        QString hotelLangt = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[4]);

        QString urlMaptmp2 ="{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\", \"coordinates\":[" +  hotelLangt + "," + hotelDest + "\]\},\"properties\":{\"hotel\":\""+hotel+"\"}}";

        QString urlMap3 = QUrl::toPercentEncoding(urlMaptmp2);

        QString urlMap = urlMapTmp + urlMap3;
        ui->labelKarteUrlHotel->setOpenExternalLinks(true);

        ui->labelKarteUrlHotel->setText(QString("<a href=\""+urlMap+"\">"+urlMap+"</a>"));
    }
    else if(pixmapCompare.toImage()==pixmapAuto.toImage())
    {
        ui->tabWidgetBuchungTyp->setCurrentIndex(2);
        QString urlMapTmp = "https://jenningsanderson.com/geo/?geojson=";

        QString company = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[2]);
        ui->lineEditFirma->setText(company);

        QString pickupLoc = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[0]);
        ui->lineEditAbholort->setText(pickupLoc);

        QString returnLoc = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[1]);
        ui->lineEditAbgabeort->setText(returnLoc);

        QString vehicleClass = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[3]);
        ui->lineEditFahrzeugKlasse->setText(vehicleClass);

        QString pickupLat = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[4]);
        QString pickupLongt = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[5]);
        QString returnLat = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[6]);
        QString returnLongt = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[row]->myType()[7]);
        QString urlMaptmp2;

        if(!pickupLoc.compare(returnLoc))
        {
            urlMaptmp2 ="{\"type\":\"Feature\",\"geometry\":{\"type\":\"Point\", \"coordinates\":[" +  pickupLongt + "," + pickupLat + "\]\},\"properties\":{\"Abhol-Rueckgabestation\":\""+pickupLoc+"\",\"Firma\":\""+company+"\"}}";
        }
        else
        {
            urlMaptmp2 = "{\"type\":\"Feature\",\"geometry\":{\"type\":\"LineString\", \"coordinates\":[[" +  pickupLongt + "," + pickupLat + "\],\["+returnLongt + "," +returnLat+"\]\]\},\"properties\":{\"Abholstation\":\""+pickupLoc+"\",\"Rueckgabestation\":\""+returnLoc+"\",\"Firma\":\""+company+"\"}}";

        }
        QString urlMap3 = QUrl::toPercentEncoding(urlMaptmp2);

        QString urlMap = urlMapTmp + urlMap3;
        ui->labelKarteUrlAuto->setOpenExternalLinks(true);

        ui->labelKarteUrlAuto->setText(QString("<a href=\""+urlMap+"\">"+urlMap+"</a>"));
    }

    ui->groupBoxBuchungdetails->show();
    ui->pushButtonSave->setDisabled(true);
    ui->pushButtonCancel->setDisabled(true);
}


void MainWindow::on_pushButtonSave_clicked()
{
    QString QbookingId = ui->lineEditBuchungId->text();
    std::string bookingId = QbookingId.toStdString();

    QDate getFromDate = ui->dateEditStartDatum->date();
    QString stdFromDate =getFromDate.toString("yyyyMMdd");
    std::string fromDate = stdFromDate.toStdString();

    QDate getToDate = ui->dateEditEndDatum->date();
    QString stdToDate =getToDate.toString("yyyyMMdd");
    std::string toDate = stdToDate.toStdString();

    double price = ui->doubleSpinBoxPreis->value();



    for(int i=0;i<ReiseAgentur.getBookings().size();i++)
    {
        if(bookingId==ReiseAgentur.getBookings()[i]->getId())
        {
            ReiseAgentur.getBookings()[i]->setFromDate(fromDate);
            ReiseAgentur.getBookings()[i]->setToDate(toDate);
            ReiseAgentur.getBookings()[i]->setPrice(price);
            QString ausgabeText=QString::fromStdString(ReiseAgentur.getBookings()[i]->showDetails());
            if(ausgabeText.contains("Flugbuchung"))
            {
                QString QfromDest = ui->lineEditvonFlug->text();
                std::string fromDest = QfromDest.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(0,fromDest);

                QString QtoDest = ui->lineEditbisFlug->text();
                std::string toDest = QtoDest.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(1,toDest);

                QString Qairline = ui->lineEditFlugzeug->text();
                std::string airline = Qairline.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(2,airline);

                std::string bookingClass;

                QString QklasseBooking = ui->lineEditFlugsitz->text();
                std::string KlasseBooking = QklasseBooking.toStdString();

                if(KlasseBooking=="Economy class")
                {
                    bookingClass="Y";
                    ReiseAgentur.getBookings()[i]->changeType(3,bookingClass);
                }
                else if(bookingClass=="Premium Economy class")
                {
                    bookingClass="W";
                    ReiseAgentur.getBookings()[i]->changeType(3,bookingClass);
                }
                else if(bookingClass=="Buseniess class")
                {
                    bookingClass="J";
                    ReiseAgentur.getBookings()[i]->changeType(3,bookingClass);
                }
                else if(bookingClass=="First class")
                {
                    bookingClass="F";
                    ReiseAgentur.getBookings()[i]->changeType(3,bookingClass);
                }
                else
                {
                    QMessageBox msgBox;
                    QString errorText = "Ungueltige Eingabe. Bitte wiederhohlen!";
                    msgBox.setText(errorText);
                    msgBox.exec();
                }
            }
            else if(ausgabeText.contains("Hotelreservierung"))
            {
                QString Qhotel = ui->lineEditHotel->text();
                std::string hotel = Qhotel.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(0,hotel);

                QString Qtown = ui->lineEditStadt->text();
                std::string town = Qtown.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(1,town);

                QString Qzimmer = ui->lineEditZimmertyp->text();
                std::string zimmer = Qzimmer.toStdString();

                std::string roomType;
                if(zimmer=="Einzelzimmer")
                {
                    roomType="EZ";
                    ReiseAgentur.getBookings()[i]->changeType(2,roomType);
                }
                else if(zimmer=="Doppelzimmer")
                {
                    roomType="DZ";
                    ReiseAgentur.getBookings()[i]->changeType(2,roomType);
                }
                else if(zimmer=="Appartment")
                {
                    roomType="AP";
                    ReiseAgentur.getBookings()[i]->changeType(2,roomType);
                }
                else if(zimmer=="Suite")
                {
                    roomType="SU";
                    ReiseAgentur.getBookings()[i]->changeType(2,roomType);
                }
                else
                {
                    QMessageBox msgBox;
                    QString errorText = "Ungueltige Eingabe. Bitte wiederhohlen!";
                    msgBox.setText(errorText);
                    msgBox.exec();
                }
            }
            else if(ausgabeText.contains("Mietwagenreservierung"))
            {
                QString QpickupLoc = ui->lineEditAbholort->text();
                std::string pickupLoc = QpickupLoc.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(0,pickupLoc);

                QString QreturnLoc = ui->lineEditAbgabeort->text();
                std::string returnLoc = QreturnLoc.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(1,returnLoc);

                QString Qcompany = ui->lineEditStadt->text();
                std::string company = Qcompany.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(2,company);

                QString QvehicleClass = ui->lineEditFahrzeugKlasse->text();
                std::string vehicleClass = QvehicleClass.toStdString();
                ReiseAgentur.getBookings()[i]->changeType(3,vehicleClass);
            }
        }
    }

    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
    {
        for(int j=0;j<ReiseAgentur.getAllTravels()[i]->getTravelBookings().size();j++)
        {
            if(bookingId==ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->getId())
            {
                ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->setFromDate(fromDate);
                ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->setToDate(toDate);
                ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->setPrice(price);
                QString ausgabeText=QString::fromStdString(ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->showDetails());
                if(ausgabeText.contains("Flugbuchung"))
                {
                    QString QfromDest = ui->lineEditvonFlug->text();
                    std::string fromDest = QfromDest.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(0,fromDest);

                    QString QtoDest = ui->lineEditbisFlug->text();
                    std::string toDest = QtoDest.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(1,toDest);

                    QString Qairline = ui->lineEditFlugzeug->text();
                    std::string airline = Qairline.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(2,airline);

                    std::string bookingClass;

                    QString QklasseBooking = ui->lineEditFlugsitz->text();
                    std::string KlasseBooking = QklasseBooking.toStdString();

                    if(KlasseBooking=="Economy class")
                    {
                        bookingClass="Y";
                        ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(3,bookingClass);
                    }
                    else if(KlasseBooking=="Premium Economy class")
                    {
                        bookingClass="W";
                        ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(3,bookingClass);
                    }
                    else if(KlasseBooking=="Buseniess class")
                    {
                        bookingClass="J";
                        ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(3,bookingClass);
                    }
                    else if(KlasseBooking=="First class")
                    {
                        bookingClass="F";
                        ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(3,bookingClass);
                    }
                }
                else if(ausgabeText.contains("Hotelreservierung"))
                {
                    QString Qhotel = ui->lineEditHotel->text();
                    std::string hotel = Qhotel.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(0,hotel);

                    QString Qtown = ui->lineEditStadt->text();
                    std::string town = Qtown.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(1,town);

                    QString Qzimmer = ui->lineEditZimmertyp->text();
                    std::string zimmer = Qzimmer.toStdString();

                    std::string roomType;
                    if(zimmer=="Einzelzimmer")
                    {
                        roomType="EZ";
                        ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(2,roomType);
                    }
                    else if(zimmer=="Doppelzimmer")
                    {
                        roomType="DZ";
                        ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(2,roomType);
                    }
                    else if(zimmer=="Appartment")
                    {
                        roomType="AP";
                        ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(2,roomType);
                    }
                    else if(zimmer=="Suite")
                    {
                        roomType="SU";
                        ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(2,roomType);
                    }
                }
                else if(ausgabeText.contains("Mietwagenreservierung"))
                {
                    QString QpickupLoc = ui->lineEditAbholort->text();
                    std::string pickupLoc = QpickupLoc.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(0,pickupLoc);

                    QString QreturnLoc = ui->lineEditAbgabeort->text();
                    std::string returnLoc = QreturnLoc.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(1,returnLoc);

                    QString Qcompany = ui->lineEditStadt->text();
                    std::string company = Qcompany.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(2,company);

                    QString QvehicleClass = ui->lineEditFahrzeugKlasse->text();
                    std::string vehicleClass = QvehicleClass.toStdString();
                    ReiseAgentur.getAllTravels()[i]->getTravelBookings()[j]->changeType(3,vehicleClass);
                }
            }
        }
    }
    ui->pushButtonSave->setDisabled(true);
    ui->pushButtonCancel->setDisabled(true);
}


void MainWindow::on_pushButtonCancel_clicked()
{
    QString reiseIdStr = ui->lineEditReiseID->text();
    long reiseId = reiseIdStr.toLong();
    int getIndex = 0;

    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
    {
        if(ReiseAgentur.getAllTravels()[i]->getId()==reiseId)
        {
            getIndex=i;
        }
    }

    for(int j=0;j<ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings().size();j++)
    {
        QString bookingId = ui->lineEditBuchungId->text();
        std::string buchungId = bookingId.toStdString();
        if(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->getId()==buchungId)
        {
        ui->lineEditBuchungId->setText(bookingId);
        QDate fromDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->getFromDate()),"yyyyMMdd");
        ui->dateEditStartDatum->setDate(fromDate);

        QDate toDate = QDate::fromString(QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->getToDate()),"yyyyMMdd");
        ui->dateEditEndDatum->setDate(toDate);

        double price = ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->getPrice();
        ui->doubleSpinBoxPreis->setValue(price);

        QTableWidgetItem* itemIcon = ui->tableWidgetBuchungen->item(j,0);
        QIcon iconCompare = itemIcon->icon();
        QPixmap pixmapCompare = iconCompare.pixmap(QSize(32,32));


        QIcon iconPlane(":/new/Icon/airplane-png.png");
        QPixmap pixmapPlane = iconPlane.pixmap(QSize(32,32));

        QIcon iconHotel(":/new/Icon/Hotel-png.png");
        QPixmap pixmapHotel = iconHotel.pixmap(QSize(32,32));

        QIcon iconAuto(":/new/Icon/car_vehicle_transport_icon_144665.png");
        QPixmap pixmapAuto = iconAuto.pixmap(QSize(32,32));

        if(pixmapCompare.toImage()==pixmapPlane.toImage())
        {
            ui->tabWidgetBuchungTyp->setCurrentIndex(0);

            QString airplane = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[2]);
            ui->lineEditFlugzeug->setText(airplane);

            QString fromDest = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[0]);
            ui->lineEditvonFlug->setText(fromDest);

            QString toDest = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[1]);
            ui->lineEditbisFlug->setText(toDest);

            QString flugklasse = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[3]);
            ui->lineEditFlugsitz->setText(flugklasse);
        }
        else if(pixmapCompare.toImage()==pixmapHotel.toImage())
        {
            ui->tabWidgetBuchungTyp->setCurrentIndex(1);

            QString hotel = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[0]);
            ui->lineEditHotel->setText(hotel);

            QString town = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[1]);
            ui->lineEditStadt->setText(town);

            QString roomType = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[2]);
            ui->lineEditZimmertyp->setText(roomType);
        }
        else if(pixmapCompare.toImage()==pixmapAuto.toImage())
        {
            ui->tabWidgetBuchungTyp->setCurrentIndex(2);

            QString company = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[2]);
            ui->lineEditFirma->setText(company);

            QString pickupLoc = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[0]);
            ui->lineEditAbholort->setText(pickupLoc);

            QString returnLoc = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[1]);
            ui->lineEditAbgabeort->setText(returnLoc);

            QString vehicleClass = QString::fromStdString(ReiseAgentur.getAllTravels()[getIndex]->getTravelBookings()[j]->myType()[3]);
            ui->lineEditFahrzeugKlasse->setText(vehicleClass);
        }
    }
    }
    ui->pushButtonSave->setDisabled(true);
    ui->pushButtonCancel->setDisabled(true);

}


void MainWindow::on_actionKunde_hinzuf_gen_triggered()
{
    QDialog kundePopUp;
    kundePopUp.setWindowTitle("Kunde hinzufügen");
    kundePopUp.setWindowFlag(Qt::Popup);

    QLabel* labelKId = new QLabel("KundenId: ");
    QLabel* labelKName = new QLabel("Kundenname: ");
    QLineEdit* lineEditKId = new QLineEdit(&kundePopUp);
    QLineEdit* lineEditKName = new QLineEdit(&kundePopUp);
    QPushButton* buttonHinzufuegen = new QPushButton("Hinzufügen", &kundePopUp);
    QPushButton* buttonSchliessen = new QPushButton("Schließen", &kundePopUp);

    QFormLayout* layout = new QFormLayout(&kundePopUp);

    int kid=0;

    for(const std::shared_ptr<Customer>& customer : ReiseAgentur.getAllCustomers())
    {
    if(customer->getId()>kid)
        {
        kid = customer->getId();
        }
    }
    kid++;

    QString qstrKid = QString::number(kid);

    lineEditKId->setText(qstrKid);
    lineEditKId->setDisabled(true);
    layout->addRow(labelKId,lineEditKId);
    layout->addRow(labelKName, lineEditKName);
    layout->addWidget(buttonHinzufuegen);
    layout->addWidget(buttonSchliessen);

    QObject::connect(buttonHinzufuegen, &QPushButton::clicked, &kundePopUp, &QDialog::accept);
    QObject::connect(buttonSchliessen, &QPushButton::clicked, &kundePopUp, &QDialog::close);

    std::shared_ptr<Customer> kunde;
    if(kundePopUp.exec()==QDialog::Accepted)
    {
        QString kidtmp = lineEditKId->text();
        long kid = kidtmp.toLong();
        QString knametmp= lineEditKName->text();
        std::string kname = knametmp.toStdString();
        kunde = std::make_shared<Customer>(kid,kname);
        ReiseAgentur.addCustomer(kunde);
    }

}

void MainWindow::on_actionBuchung_hinzuf_gen_triggered()
{
    QDialog buchungPopUpFrage;
    buchungPopUpFrage.setWindowTitle("Buchung hinzufügen");
    buchungPopUpFrage.setWindowFlag(Qt::Popup);

    QLabel* labelFrage = new QLabel("Für bestehende Reise hinzufügen oder neue Reise?");

    QComboBox* comboBoxBuchung = new QComboBox(&buchungPopUpFrage);
    comboBoxBuchung->addItem("Flugbuchung");
    comboBoxBuchung->addItem("Hotelreservierung");
    comboBoxBuchung->addItem("Mietwagenreservierung");

    QPushButton* buttonbestehen = new QPushButton("Bestehende Reise", &buchungPopUpFrage);
    QPushButton* buttonneu = new QPushButton("Neue Reise", &buchungPopUpFrage);

    QFormLayout* layout = new QFormLayout(&buchungPopUpFrage);

    layout->addRow(labelFrage);
    layout->addRow(comboBoxBuchung);
    layout->addWidget(buttonbestehen);
    layout->addWidget(buttonneu);

    QObject::connect(buttonbestehen, &QPushButton::clicked, &buchungPopUpFrage, &QDialog::accept);
    QObject::connect(buttonneu, &QPushButton::clicked, &buchungPopUpFrage, &QDialog::close);

    if(buchungPopUpFrage.exec()==QDialog::Accepted)
    {
        QString selectedBuchung = comboBoxBuchung->currentText();
        buchungPopUpFrage.close();
        QDialog buchungPopUpBest;
        buchungPopUpBest.setWindowTitle("Buchung hinzufügen");
        buchungPopUpBest.setWindowFlag(Qt::Popup);

        QLabel* labelBuchungsId = new QLabel("BuchungsId: ");
        QLineEdit* lineEditBuchungsId = new QLineEdit(&buchungPopUpBest);
        QString bookingId = QUuid::createUuid().toString();

        QLabel* labelReiseId = new QLabel("Für welche Reise(bitte ReiseId eingeben): ");
        QLineEdit* lineEditReiseId = new QLineEdit(&buchungPopUpBest);

        QLabel* labelStartDatum = new QLabel("Von: ");
        QDateEdit* dateEditeStartDatum = new QDateEdit(&buchungPopUpBest);

        QLabel* labelEndDatum = new QLabel("Bis: ");
        QDateEdit* dateEditEndDatum = new QDateEdit(&buchungPopUpBest);

        QLabel* labelPreis = new QLabel("Preis: ");
        QDoubleSpinBox* doubleSpinBoxPreis = new QDoubleSpinBox(&buchungPopUpBest);

        QPushButton* buttonHinzufuegen = new QPushButton("Hinzufügen", &buchungPopUpBest);
        QPushButton* buttonSchliessen = new QPushButton("Schließen", &buchungPopUpBest);

        QObject::connect(buttonHinzufuegen, &QPushButton::clicked, &buchungPopUpBest, &QDialog::accept);
        QObject::connect(buttonSchliessen, &QPushButton::clicked, &buchungPopUpBest, &QDialog::close);
        QFormLayout* layoutbst = new QFormLayout(&buchungPopUpBest);

        lineEditBuchungsId->setText(bookingId);
        lineEditBuchungsId->setDisabled(true);
        layoutbst->addRow(labelBuchungsId, lineEditBuchungsId);
        layoutbst->addRow(labelReiseId, lineEditReiseId);
        layoutbst->addRow(labelStartDatum, dateEditeStartDatum);
        layoutbst->addRow(labelEndDatum, dateEditEndDatum);
        layoutbst->addRow(labelPreis, doubleSpinBoxPreis);
        layoutbst->addWidget(buttonHinzufuegen);
        layoutbst->addWidget(buttonSchliessen);


        if(buchungPopUpBest.exec()==QDialog::Accepted)
        {
            QString bidtmp = lineEditBuchungsId->text();
            std::string bid = bidtmp.toStdString();
            QString ridtmp= lineEditReiseId->text();
            long rid = ridtmp.toLong();

            QDate startDatumtmp = dateEditeStartDatum->date();
            QString qstartDatum =startDatumtmp.toString("yyyyMMdd");
            std::string startDatum = qstartDatum.toStdString();

            QDate endDatumtmp = dateEditEndDatum->date();
            QString qendDatum =endDatumtmp.toString("yyyyMMdd");
            std::string endDatum = qendDatum.toStdString();

            double preis = doubleSpinBoxPreis->value();

            if(selectedBuchung.contains("Flugbuchung"))
            {
                std::shared_ptr<FlightBooking> buchung;
                std::string predecesor1="0";
                std::string predecesor2="0";
                for(int i=0;ReiseAgentur.getAllTravels().size();i++)
                {
                    if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                    {
                        if(ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()>=1)
                        {
                            predecesor1 = ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-1]->getId();
                            if(ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()>=2)
                            {
                                predecesor2 = ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-2]->getId();
                            }
                        }
                        break;
                    }
                }
                buchung = std::make_shared<FlightBooking>(bid,preis,startDatum,"XXX","XXX","airlineTest","W",endDatum,rid,"0.000","0.000","1.000","1.000",predecesor1,predecesor2);
                ReiseAgentur.addBuchung(buchung);

                for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
                {
                    if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                    {
                        ReiseAgentur.getAllTravels()[i]->addBooking(buchung);
                    }
                }
            }
            else if(selectedBuchung.contains("Hotelreservierung"))
            {
                std::shared_ptr<HotelBooking> buchung;
                std::string predecesor1="0";
                std::string predecesor2="0";
                for(int i=0;ReiseAgentur.getAllTravels().size();i++)
                {
                    if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                    {
                        if(ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()>=1)
                        {
                            predecesor1 = ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-1]->getId();
                            if(ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()>=2)
                            {
                                predecesor2 = ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-2]->getId();
                            }
                        }
                        break;
                    }
                }
                buchung = std::make_shared<HotelBooking>(bid, preis, startDatum, endDatum, "hotelTest", "stadtTest", "EZ", rid, "0.000","0.000",predecesor1,predecesor2);
                ReiseAgentur.addBuchung(buchung);

                for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
                {
                    if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                    {
                        ReiseAgentur.getAllTravels()[i]->addBooking(buchung);
                    }
                }
            }
            else if(selectedBuchung.contains("Mietwagenreservierung"))
            {
                std::shared_ptr<RentalCarReservation> buchung;
                std::string predecesor1="0";
                std::string predecesor2="0";
                for(int i=0;ReiseAgentur.getAllTravels().size();i++)
                {
                    if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                    {
                        if(ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()>=1)
                        {
                            predecesor1 = ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-1]->getId();
                            if(ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()>=2)
                            {
                                predecesor2 = ReiseAgentur.getAllTravels()[i]->getTravelBookings()[ReiseAgentur.getAllTravels()[i]->getTravelBookings().size()-2]->getId();
                            }
                        }
                        break;
                    }
                }
                buchung = std::make_shared<RentalCarReservation>(bid, preis, startDatum, endDatum, "pickupTestLoc", "returnTestLoc", "firmaTest", "CCAR", rid, "0.000", "0.000", "0.000","0.0000",predecesor1,predecesor2);
                ReiseAgentur.addBuchung(buchung);

                for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
                {
                    if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                    {
                        ReiseAgentur.getAllTravels()[i]->addBooking(buchung);
                    }
                }
            }

        }
    }
    else
    {
        buchungPopUpFrage.close();
        QString selectedBuchung = comboBoxBuchung->currentText();
        QDialog buchungPopUpNeu;
        buchungPopUpNeu.setWindowTitle("Buchung hinzufügen");
        buchungPopUpNeu.setWindowFlag(Qt::Popup);

        QLabel* labelBuchungsId = new QLabel("BuchungsId: ");
        QLineEdit* lineEditBuchungsId = new QLineEdit(&buchungPopUpNeu);
        QString bookingId = QUuid::createUuid().toString();

        QLabel* labelReiseId = new QLabel("Für welche Reise(bitte ReiseId eingeben): ");
        QLineEdit* lineEditReiseId = new QLineEdit(&buchungPopUpNeu);

        int rid=0;

        for(const std::shared_ptr<Travel>& travel : ReiseAgentur.getAllTravels())
        {
            if(travel->getId()>rid)
            {
                rid = travel->getId();
            }
        }
        rid++;

        QString qrid = QString::number(rid);

        QLabel* labelStartDatum = new QLabel("Von: ");
        QDateEdit* dateEditeStartDatum = new QDateEdit(&buchungPopUpNeu);

        QLabel* labelEndDatum = new QLabel("Bis: ");
        QDateEdit* dateEditEndDatum = new QDateEdit(&buchungPopUpNeu);

        QLabel* labelPreis = new QLabel("Preis: ");
        QDoubleSpinBox* doubleSpinBoxPreis = new QDoubleSpinBox(&buchungPopUpNeu);

        QLabel* labelKunde = new QLabel("KundeId(Wenn keine KundenId vorhanden, bitte eine erstellen): ");
        QLineEdit* lineEditKundeId=new QLineEdit(&buchungPopUpNeu);

        QPushButton* buttonHinzufuegen = new QPushButton("Hinzufügen", &buchungPopUpNeu);
        QPushButton* buttonSchliessen = new QPushButton("Schließen", &buchungPopUpNeu);

        QObject::connect(buttonHinzufuegen, &QPushButton::clicked, &buchungPopUpNeu, &QDialog::accept);
        QObject::connect(buttonSchliessen, &QPushButton::clicked, &buchungPopUpNeu, &QDialog::close);
        QFormLayout* layoutneu = new QFormLayout(&buchungPopUpNeu);

        lineEditBuchungsId->setText(bookingId);
        lineEditBuchungsId->setDisabled(true);
        lineEditReiseId->setText(qrid);
        lineEditReiseId->setDisabled(true);
        layoutneu->addRow(labelBuchungsId, lineEditBuchungsId);
        layoutneu->addRow(labelReiseId, lineEditReiseId);
        layoutneu->addRow(labelKunde, lineEditKundeId);
        layoutneu->addRow(labelStartDatum, dateEditeStartDatum);
        layoutneu->addRow(labelEndDatum, dateEditEndDatum);
        layoutneu->addRow(labelPreis, doubleSpinBoxPreis);
        layoutneu->addWidget(buttonHinzufuegen);
        layoutneu->addWidget(buttonSchliessen);

        std::shared_ptr<FlightBooking> buchung;
        std::shared_ptr<Travel> trav;
        if(buchungPopUpNeu.exec()==QDialog::Accepted)
        {
            QString bidtmp = lineEditBuchungsId->text();
            std::string bid = bidtmp.toStdString();

            QString ridtmp= lineEditReiseId->text();
            long rid = ridtmp.toLong();

            QString kidtmp = lineEditKundeId->text();
            long kid = kidtmp.toLong();

            QDate startDatumtmp = dateEditeStartDatum->date();
            QString qstartDatum =startDatumtmp.toString("yyyyMMdd");
            std::string startDatum = qstartDatum.toStdString();

            QDate endDatumtmp = dateEditEndDatum->date();
            QString qendDatum =endDatumtmp.toString("yyyyMMdd");
            std::string endDatum = qendDatum.toStdString();

            double preis = doubleSpinBoxPreis->value();

            bool idExists = false;
            for(const std::shared_ptr<Customer>& cust : ReiseAgentur.getAllCustomers())
            {
                if(cust->getId()==kid)
                {
                    idExists = true;
                    break;
                }
            }
            if(idExists==true)
            {
                if(selectedBuchung.contains("Flugbuchung"))
                {
                    std::shared_ptr<FlightBooking> buchung;
                    buchung = std::make_shared<FlightBooking>(bid,preis,startDatum,"XXX","XXX","test","W",endDatum,rid,"0.000","0.000","1.000","1.000","0","0");
                    trav = std::make_shared<Travel>(rid,kid);
                    ReiseAgentur.addBuchung(buchung);
                    ReiseAgentur.addTravel(trav);
                    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
                    {
                        if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                        {
                            ReiseAgentur.getAllTravels()[i]->addBooking(buchung);
                        }
                    }
                }
                else if(selectedBuchung.contains("Hotelreservierung"))
                {
                    std::shared_ptr<HotelBooking> buchung;
                    buchung = std::make_shared<HotelBooking>(bid, preis, startDatum, endDatum, "hotelTest", "stadtTest", "EZ", rid, "0.000","0.000","0","0");
                    trav = std::make_shared<Travel>(rid,kid);
                    ReiseAgentur.addBuchung(buchung);
                    ReiseAgentur.addTravel(trav);
                    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
                    {
                        if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                        {
                            ReiseAgentur.getAllTravels()[i]->addBooking(buchung);
                        }
                    }
                }
                else if(selectedBuchung.contains("Mietwagenreservierung"))
                {
                    std::shared_ptr<RentalCarReservation> buchung;
                    buchung = std::make_shared<RentalCarReservation>(bid, preis, startDatum, endDatum, "pickupTestLoc", "returnTestLoc", "firmaTest", "CCAR", rid, "0.000", "0.000", "1.000","1.000","0","0");
                    trav = std::make_shared<Travel>(rid,kid);
                    ReiseAgentur.addBuchung(buchung);
                    ReiseAgentur.addTravel(trav);
                    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
                    {
                        if(ReiseAgentur.getAllTravels()[i]->getId()==rid)
                        {
                            ReiseAgentur.getAllTravels()[i]->addBooking(buchung);
                        }
                    }
                }
            }
            else
            {
                QMessageBox msgBox;
                QString error = "KundenId existiert nicht. Bitte füge zuerst diese KundenId hinzufügen!";
                msgBox.setText(error);
                msgBox.exec();
            }
        }        
    }
}


void MainWindow::on_actionSpeichern_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Sortierauswahl");
    msgBox.setText("Wähle einen Sortierung aus");
    msgBox.addButton("Nach Preis sortiert", QMessageBox::AcceptRole);
    msgBox.addButton("Nach Start Datum sortiert", QMessageBox::AcceptRole);
    msgBox.addButton("Nach End Datum sortiert", QMessageBox::AcceptRole);
    msgBox.addButton("Nach Travel Id sortiert", QMessageBox::AcceptRole);

    int buttonClicked = msgBox.exec();

    std::string button;
    if(buttonClicked==0)
    {
        button="preis";
    }
    else if(buttonClicked==1)
    {
        button="fromDate";
    }
    else if(buttonClicked==2)
    {
        button="toDate";
    }
    else if(buttonClicked==3)
    {
        button="travelId";
    }

    ReiseAgentur.saveToJSON(button);

    QJsonArray jsonArray;
    QJsonObject jsonObject;
    QJsonObject jsonObject2;
    QJsonObject jsonObject3;
    long custId;
    for(int i=0;i<ReiseAgentur.getBookings().size();i++)
    {
        QString type = QString::fromStdString(ReiseAgentur.getBookings()[i]->showDetails());
        if(type.contains("Flugbuchung"))
        {
            std::string airlineStd = ReiseAgentur.getBookings()[i]->myType()[2];
            QString airline = QString::fromStdString(airlineStd);
            jsonObject["airline"] = airline;

            std::string KlasseBooking = ReiseAgentur.getBookings()[i]->myType()[3];
            QString bookingClass;

            if(KlasseBooking=="Economy class")
            {
                bookingClass="Y";
                jsonObject["bookingClass"] = bookingClass;
            }
            else if(KlasseBooking=="Premium Economy class")
            {
                bookingClass="W";
                jsonObject["bookingClass"] = bookingClass;
            }
            else if(KlasseBooking=="Buseniess class")
            {
                bookingClass="J";
                jsonObject["bookingClass"] = bookingClass;
            }
            else if(KlasseBooking=="First class")
            {
                bookingClass="F";
                jsonObject["bookingClass"] = bookingClass;
            }
            for(int j=0;j<ReiseAgentur.getAllTravels().size();j++)
            {
                if(ReiseAgentur.getAllTravels()[j]->getId()==ReiseAgentur.getBookings()[i]->getTravelId())
                {
                    custId = ReiseAgentur.getAllTravels()[j]->getCustomerId();
                    jsonObject["customerId"] = static_cast<qint64>(custId);
                }
            }
            for(int j=0;j<ReiseAgentur.getAllCustomers().size();j++)
            {
                if(ReiseAgentur.getAllCustomers()[j]->getId()==custId)
                {
                    std::string custNameStd = ReiseAgentur.getAllCustomers()[j]->getName();
                    QString custName = QString::fromStdString(custNameStd);
                    jsonObject["customerName"] = custName;
                }
            }
            std::string fromDateStd = ReiseAgentur.getBookings()[i]->getFromDate();
            QString fromDate = QString::fromStdString(fromDateStd);
            jsonObject["fromDate"] = fromDate;
            std::string fromDestStd = ReiseAgentur.getBookings()[i]->myType()[0];
            QString fromDest = QString::fromStdString(fromDestStd);
            jsonObject["fromDest"] = fromDest;
            std::string fromDestLatStd = ReiseAgentur.getBookings()[i]->myType()[4];
            QString fromDestLat = QString::fromStdString(fromDestLatStd);
            jsonObject["fromDestLatitude"] = fromDestLat;
            std::string fromDestLongStd = ReiseAgentur.getBookings()[i]->myType()[5];
            QString fromDestLong = QString::fromStdString(fromDestLongStd);
            jsonObject["fromDestLongitude"] = fromDestLong;
            std::string idStd = ReiseAgentur.getBookings()[i]->getId();
            QString id = QString::fromStdString(idStd);
            jsonObject["id"] = id;
            jsonObject["price"] = ReiseAgentur.getBookings()[i]->getPrice();
            std::string toDateStd = ReiseAgentur.getBookings()[i]->getToDate();
            QString toDate = QString::fromStdString(toDateStd);
            jsonObject["toDate"] = toDate;
            std::string toDestStd = ReiseAgentur.getBookings()[i]->myType()[1];
            QString toDest = QString::fromStdString(toDestStd);
            jsonObject["toDest"] = toDest;
            std::string toDestLatStd = ReiseAgentur.getBookings()[i]->myType()[6];
            QString toDestLat= QString::fromStdString(toDestLatStd);
            jsonObject["toDestLatitude"] = toDestLat;
            std::string toDestLongStd = ReiseAgentur.getBookings()[i]->myType()[7];
            QString toDestLong= QString::fromStdString(toDestLongStd);
            jsonObject["toDestLongitude"] = toDestLong;
            jsonObject["travelId"] = static_cast<qint64>(ReiseAgentur.getBookings()[i]->getTravelId());
            jsonObject["type"] = "Flight";
            jsonArray.append(jsonObject);
        }
        else if(type.contains("Hotelreservierung"))
        {
            for(int j=0;j<ReiseAgentur.getAllTravels().size();j++)
            {
                if(ReiseAgentur.getAllTravels()[j]->getId()==ReiseAgentur.getBookings()[i]->getTravelId())
                {
                    custId = ReiseAgentur.getAllTravels()[j]->getCustomerId();
                    jsonObject2["customerId"] = static_cast<qint64>(custId);
                }
            }

            for(int j=0;j<ReiseAgentur.getAllCustomers().size();j++)
            {
                if(ReiseAgentur.getAllCustomers()[j]->getId()==custId)
                {
                    std::string custNameStd = ReiseAgentur.getAllCustomers()[j]->getName();
                    QString custName = QString::fromStdString(custNameStd);
                    jsonObject2["customerName"] = custName;
                }
            }

            std::string fromDateStd = ReiseAgentur.getBookings()[i]->getFromDate();
            QString fromDate = QString::fromStdString(fromDateStd);
            jsonObject2["fromDate"] = fromDate;

            std::string hotelStd = ReiseAgentur.getBookings()[i]->myType()[0];
            QString hotel = QString::fromStdString(hotelStd);
            jsonObject2["hotel"] = hotel;

            std::string hotelLatStd = ReiseAgentur.getBookings()[i]->myType()[3];
            QString hotelLat = QString::fromStdString(hotelLatStd);
            jsonObject2["hotelLatitude"] = hotelLat;

            std::string hotelLongStd = ReiseAgentur.getBookings()[i]->myType()[4];
            QString hotelLong = QString::fromStdString(hotelLongStd);
            jsonObject2["hotelLongitude"] = hotelLong;

            std::string idStd = ReiseAgentur.getBookings()[i]->getId();
            QString id = QString::fromStdString(idStd);
            jsonObject2["id"] = id;

            jsonObject2["price"] = ReiseAgentur.getBookings()[i]->getPrice();

            std::string zimmer = ReiseAgentur.getBookings()[i]->myType()[2];

            QString roomType;
            if(zimmer=="Einzelzimmer")
            {
                roomType="EZ";
                jsonObject2["roomType"] = roomType;
            }
            else if(zimmer=="Doppelzimmer")
            {
                roomType="DZ";
                jsonObject2["roomType"] = roomType;
            }
            else if(zimmer=="Appartment")
            {
                roomType="AP";
                jsonObject2["roomType"] = roomType;
            }
            else if(zimmer=="Suite")
            {
                roomType="SU";
                jsonObject2["roomType"] = roomType;
            }

            std::string toDateStd = ReiseAgentur.getBookings()[i]->getToDate();
            QString toDate = QString::fromStdString(toDateStd);
            jsonObject2["toDate"] = toDate;

            std::string townStd = ReiseAgentur.getBookings()[i]->myType()[1];
            QString town = QString::fromStdString(townStd);
            jsonObject2["town"] = town;

            jsonObject2["travelId"] = static_cast<qint64>(ReiseAgentur.getBookings()[i]->getTravelId());

            jsonObject2["type"] = "Hotel";
            jsonArray.append(jsonObject2);
        }
        else if(type.contains("Mietwagenreservierung"))
        {
            std::string companyStd = ReiseAgentur.getBookings()[i]->myType()[2];
            QString company = QString::fromStdString(companyStd);
            jsonObject3["company"] = company;

            for(int j=0;j<ReiseAgentur.getAllTravels().size();j++)
            {
                if(ReiseAgentur.getAllTravels()[j]->getId()==ReiseAgentur.getBookings()[i]->getTravelId())
                {
                    custId = ReiseAgentur.getAllTravels()[j]->getCustomerId();
                    jsonObject3["customerId"] = static_cast<qint64>(custId);
                }
            }

            for(int j=0;j<ReiseAgentur.getAllCustomers().size();j++)
            {
                if(ReiseAgentur.getAllCustomers()[j]->getId()==custId)
                {
                    std::string custNameStd = ReiseAgentur.getAllCustomers()[j]->getName();
                    QString custName = QString::fromStdString(custNameStd);
                    jsonObject3["customerName"] = custName;
                }
            }

            std::string fromDateStd = ReiseAgentur.getBookings()[i]->getFromDate();
            QString fromDate = QString::fromStdString(fromDateStd);
            jsonObject3["fromDate"] = fromDate;

            std::string idStd = ReiseAgentur.getBookings()[i]->getId();
            QString id = QString::fromStdString(idStd);
            jsonObject3["id"] = id;

            std::string pickupLatStd = ReiseAgentur.getBookings()[i]->myType()[4];
            QString pickupLat = QString::fromStdString(pickupLatStd);
            jsonObject3["pickupLatitude"] = pickupLat;

            std::string pickupLocStd = ReiseAgentur.getBookings()[i]->myType()[0];
            QString pickupLoc = QString::fromStdString(pickupLocStd);
            jsonObject3["pickupLocation"] = pickupLoc;

            std::string pickupLongStd = ReiseAgentur.getBookings()[i]->myType()[5];
            QString pickupLong = QString::fromStdString(pickupLongStd);
            jsonObject3["pickupLongitude"] = pickupLong;

            jsonObject3["price"] = ReiseAgentur.getBookings()[i]->getPrice();

            std::string returnLatStd = ReiseAgentur.getBookings()[i]->myType()[6];
            QString returnLat = QString::fromStdString(returnLatStd);
            jsonObject3["returnLatitude"] = returnLat;

            std::string returnLocStd = ReiseAgentur.getBookings()[i]->myType()[1];
            QString returnLoc = QString::fromStdString(returnLocStd);
            jsonObject3["returnLocation"] = returnLoc;

            std::string returnLongStd = ReiseAgentur.getBookings()[i]->myType()[7];
            QString returnLong = QString::fromStdString(returnLongStd);
            jsonObject3["returnLongitude"] = returnLong;

            std::string toDateStd = ReiseAgentur.getBookings()[i]->getToDate();
            QString toDate = QString::fromStdString(toDateStd);
            jsonObject3["toDate"] = toDate;

            jsonObject3["travelId"] = static_cast<qint64>(ReiseAgentur.getBookings()[i]->getTravelId());

            jsonObject3["type"] = "RentalCar";

            std::string vehicleClassStd = ReiseAgentur.getBookings()[i]->myType()[3];
            QString vehicleClass = QString::fromStdString(vehicleClassStd);
            jsonObject3["vehicleClass"] = vehicleClass;
            jsonArray.append(jsonObject3);
        }
    }

    QJsonDocument jsonDoc(jsonArray);

    QByteArray jsonData = jsonDoc.toJson();

    QString filePath = QFileDialog::getSaveFileName(this, "JSON-Datei speichern",QDir::homePath(), "JSON-Dateien (*.json;;Alle Dateien(*.*)");

    if(!filePath.isEmpty())
    {

        QFile file(filePath);
        if(file.open(QIODevice::WriteOnly))
        {
            file.write(jsonData);

            file.close();
        }
    }
}


void MainWindow::on_actionPruefergebnisse_triggered()
{
    QDialog pruefergebnisse;
    pruefergebnisse.setWindowTitle("Prüfergebnisse");
        pruefergebnisse.setWindowFlag(Qt::Popup);

    int zeilen = ReiseAgentur.getAllTravels().size();

    QTableWidget* ergebnisseTableWidget = new QTableWidget(zeilen,5,&pruefergebnisse);
    ergebnisseTableWidget->setHorizontalHeaderLabels({"Reise","Fehlendes Hotel","Überflüssiges Hotel","Überflüssiger Mietwagen","Kein Roundtrip"});

    for(int i=0;i<ReiseAgentur.getAllTravels().size();i++)
    {
        ergebnisseTableWidget->setItem(i,0,new QTableWidgetItem(QString::number(ReiseAgentur.getAllTravels()[i]->getId())));
        ergebnisseTableWidget->setItem(i,4,new QTableWidgetItem(QString::number(ReiseAgentur.getAllTravels()[i]->checkRoundtrip())));
        ergebnisseTableWidget->setItem(i,1,new QTableWidgetItem(QString::number(ReiseAgentur.getAllTravels()[i]->checkEnoughHotels())));
        ergebnisseTableWidget->setItem(i,2,new QTableWidgetItem(QString::number(ReiseAgentur.getAllTravels()[i]->checkNoUselessHotels())));
        ergebnisseTableWidget->setItem(i,3,new QTableWidgetItem(QString::number(ReiseAgentur.getAllTravels()[i]->checkNoUselessRentalCars())));
    }

        QVBoxLayout *layout = new QVBoxLayout(&pruefergebnisse);
    layout->addWidget(ergebnisseTableWidget);

        pruefergebnisse.exec();
}


void MainWindow::on_actionABC_Analyse_triggered()
{
        QDialog abcAusgabe;
        abcAusgabe.setWindowTitle("ABC-Analyse");
            abcAusgabe.setWindowFlag(Qt::Popup);

            std::vector<std::pair<std::shared_ptr<Customer>,QString>> abc = ReiseAgentur.abcAnalyse();

            int zeilen = abc.size();

            QTableWidget* ergebnisseTableWidget = new QTableWidget(zeilen,5,&abcAusgabe);
            ergebnisseTableWidget->setHorizontalHeaderLabels({"Kunde","Preis","Prozent","kumuliert","Klasse"});
            int i=0;
            double gesamtTotal=0.0;
            double prozent=0.0;
            std::vector<double> kundTotal;

            for(auto& cust : abc)
            {
                double total = 0.0;
                for(auto& trav : cust.first->getTravelList())
                {
                    for(auto &buchung : trav->getTravelBookings())
                    {
                        total = total + buchung->getPrice();
                    }
                }
                    kundTotal.push_back(total);
            }

            for(auto& gtotal : kundTotal)
            {
                    gesamtTotal = gesamtTotal+gtotal;
            }

            for(auto &item : abc)
            {
            /*std::string typstd = item.first->showDetails();
            QString qtyp = QString::fromStdString(typstd);
                if(qtyp.contains("Flugbuchung"))
                {*/
                    ergebnisseTableWidget->setItem(i,0,new QTableWidgetItem(QString::number(item.first->getId())));
                    ergebnisseTableWidget->setItem(i,1,new QTableWidgetItem(QString::number(kundTotal[i])));
                    ergebnisseTableWidget->setItem(i,2,new QTableWidgetItem(QString::number((kundTotal[i]/gesamtTotal)*100)));
                    prozent = prozent + (kundTotal[i]/gesamtTotal)*100;
                    ergebnisseTableWidget->setItem(i,3,new QTableWidgetItem(QString::number(prozent)));
                    ergebnisseTableWidget->setItem(i,4,new QTableWidgetItem(item.second));

                /*}
                else if(qtyp.contains("Hotelreservierung"))
                {
                    ergebnisseTableWidget->setItem(i,0,new QTableWidgetItem("Hotelreservierung"));
                    ergebnisseTableWidget->setItem(i,1,new QTableWidgetItem(QString::number(item.first->getPrice())));
                    ergebnisseTableWidget->setItem(i,2,new QTableWidgetItem(QString::number((item.first->getPrice()/total)*100)));
                    prozent = prozent + (item.first->getPrice()/total)*100;
                    ergebnisseTableWidget->setItem(i,3,new QTableWidgetItem(QString::number(prozent)));
                    ergebnisseTableWidget->setItem(i,4,new QTableWidgetItem(item.second));

                }
                else if(qtyp.contains("Mietwagenreservierung"))
                {
                    ergebnisseTableWidget->setItem(i,0,new QTableWidgetItem("Mietwagenreservierung"));
                    ergebnisseTableWidget->setItem(i,1,new QTableWidgetItem(QString::number(item.first->getPrice())));
                    ergebnisseTableWidget->setItem(i,2,new QTableWidgetItem(QString::number((item.first->getPrice()/total)*100)));
                    prozent = prozent + (item.first->getPrice()/total)*100;
                    ergebnisseTableWidget->setItem(i,3,new QTableWidgetItem(QString::number(prozent)));
                    ergebnisseTableWidget->setItem(i,4,new QTableWidgetItem(item.second));

                }*/
                i++;
            }

            int rowCount = ergebnisseTableWidget->model()->rowCount();
            int columnCount = ergebnisseTableWidget->model()->columnCount();
            for(int row=0;row<rowCount;++row)
            {
                for(int column=0;column<columnCount;++column)
                {
                    QTableWidgetItem* itemv1 = ergebnisseTableWidget->item(row,4);
                    QTableWidgetItem* itemv2 = ergebnisseTableWidget->item(row,column);
                    if(itemv1->text()=="A")
                    {
                        itemv2->setBackground(Qt::green);
                    }
                    if(itemv1->text()=="B")
                    {
                        itemv2->setBackground(Qt::yellow);
                    }
                    if(itemv1->text()=="C")
                    {
                        itemv2->setBackground(Qt::red);
                    }
                }
            }

            QVBoxLayout *layout = new QVBoxLayout(&abcAusgabe);
            layout->addWidget(ergebnisseTableWidget);

            abcAusgabe.exec();       

}

