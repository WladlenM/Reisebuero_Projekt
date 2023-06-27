#include <json.hpp>
#include <fstream>
#include <exception>
#include <QApplication>

#include "travelagency.h"

using namespace nlohmann;


std::vector<std::shared_ptr<Booking>> TravelAgency::getBookings() const
{
    return bookings;
}

std::shared_ptr<Booking> TravelAgency::findBooking(long id)
{

}

std::shared_ptr<Travel> TravelAgency::findTravel(long id)
{
    for(std::shared_ptr<Travel> travel : allTravels)
    {
        if(travel->getId()==id)
        {
            return travel;
        }
    }
    return nullptr;
}

std::shared_ptr<Customer>TravelAgency::findCustomer(long id)
{

    for(std::shared_ptr<Customer> customer : allCustomers)
    {
        if(customer->getId()==id)
        {
            return customer;
        }
    }
    return nullptr;
}

void TravelAgency::addAirpots(std::shared_ptr<Airport>air)
{
    airpots.push_back(air);
}

void TravelAgency::addCustomer(std::shared_ptr<Customer> cust)
{
    allCustomers.push_back(cust);
}

void TravelAgency::addBuchung(std::shared_ptr<Booking>book)
{
    bookings.push_back(book);
}

void TravelAgency::addTravel(std::shared_ptr<Travel> travel)
{
    allTravels.push_back(travel);
}

void TravelAgency::saveToJSON(std::string button)
{
    if(button=="preis")
    {
        std::sort(bookings.begin(),bookings.end(),[](std::shared_ptr<Booking>& a, std::shared_ptr<Booking>& b){return a->getPrice()<b->getPrice();});
    }
    else if(button=="fromDate")
    {
        std::sort(bookings.begin(),bookings.end(),[](std::shared_ptr<Booking>& a, std::shared_ptr<Booking>& b){return a->getFromDate()<b->getFromDate();});
    }
    else if(button=="toDate")
    {
        std::sort(bookings.begin(),bookings.end(),[](std::shared_ptr<Booking>& a, std::shared_ptr<Booking>& b){return a->getToDate()<b->getToDate();});
    }
    else if(button=="travelId")
    {
        std::sort(bookings.begin(),bookings.end(),[](std::shared_ptr<Booking>& a, std::shared_ptr<Booking>& b){return a->getTravelId()<b->getTravelId();});
    }
}

void TravelAgency::clearData()
{
    bookings.clear();
    allTravels.clear();
    allCustomers.clear();
}

std::vector<std::shared_ptr<Travel>> TravelAgency::getAllTravels() const
{
    return allTravels;
}

std::vector<std::shared_ptr<Customer>> TravelAgency::getAllCustomers() const
{
    return allCustomers;
}

void TravelAgency::setBookings(const std::vector<std::shared_ptr<Booking>> &newBookings)
{
    bookings = newBookings;
}

std::vector<std::shared_ptr<Airport> > TravelAgency::getAirpots() const
{
    return airpots;
}

std::vector<std::pair<std::shared_ptr<Booking>,QString>> TravelAgency::abcAnalyse(long custId, QString typ)
{
    double total = 0.0;
    std::vector<std::shared_ptr<Booking>> kundBuchung;
    for(auto& trav : allTravels)
    {
        if(trav->getCustomerId()==custId)
        {
            for(auto &buchung : trav->getTravelBookings())
            {
                kundBuchung.push_back(buchung);
                total = total + buchung->getPrice();
            }
        }
    }

    std::sort(kundBuchung.begin(),kundBuchung.end(),[](std::shared_ptr<Booking>& a, std::shared_ptr<Booking>& b){return a->getPrice()>b->getPrice();});

    std::vector<double> prozente;
    for(int i=0;i<kundBuchung.size();i++)
    {
        double proz = (kundBuchung[i]->getPrice()/total)*100;
        prozente.push_back(proz);
    }

    std::vector<std::pair<std::shared_ptr<Booking>,QString>> grenze;
    double tresholdB = total * 0.8;
    double tresholdC = total * 0.9;
    double preis=0.0;
    int i=0;

    for(auto &buchung : kundBuchung)
    {
        preis = preis+buchung->getPrice();
        if(preis>=tresholdC)
        {
            std::cout << "Buchungspreis " << buchung->getPrice() << " gehoert zu Kategorie C" << std::endl;
            std::pair<std::shared_ptr<Booking>,QString> paar = std::make_pair<>(kundBuchung[i],"C");
            grenze.push_back(paar);
        }
        else if((preis>=tresholdB))
        {
            std::cout << "Buchungspreis " << buchung->getPrice() << " gehoert zu Kategorie B" << std::endl;
            std::pair<std::shared_ptr<Booking>,QString> paar = std::make_pair<>(kundBuchung[i],"B");
            grenze.push_back(paar);
        }
        else
        {
            std::cout << "Buchungspreis " << buchung->getPrice() << " gehoert zu Kategorie A" << std::endl;
            std::pair<std::shared_ptr<Booking>,QString> paar = std::make_pair<>(kundBuchung[i],"A");
            grenze.push_back(paar);
        }
        i++;
    }

    /*std::vector<double> prozente;
    for(int i=0;i<kundBuchung.size();i++)
    {
        double proz = (kundBuchung[i]->getPrice()/total)*100;
        prozente.push_back(proz);
    }*/

    //std::vector<std::pair<std::shared_ptr<Booking>,double>> grenze;
    /*for(int i = 0;i<prozente.size();i++)
    {

    }*/


    return grenze;
}

TravelAgency::~TravelAgency()
{
    /*for(int i = 0;i<(int)bookings.size();i++)
    {
        delete bookings[i];
    }*/
    bookings.clear();
    /*for(int i = 0;i<(int)allTravels.size();i++)
    {
        delete allTravels[i];
    }*/
    allTravels.clear();
    /*for(int i = 0;i<(int)allCustomers.size();i++)
    {
        delete allCustomers[i];
    }*/
    allCustomers.clear();
}

std::string TravelAgency::readFile(QString fileName)
{
    clearData();
    std::string dateiName = fileName.toStdString();

    int flugbuchungen1 = 0;
    double flugbuchengenPreis1 = 0.0;
    int Hotelreservierungen1 = 0;
    double HotelreserbierungenPreis1 = 0.0;
    int Autobuchungen1 = 0;
    double AutobuchungenPreis1 = 0.0;
    int zeile=-1;


    std::ifstream einlesen(dateiName);

    json JsonListe;


    if(!einlesen)
    {
        std::cerr<<"Fehler: Datei konnte nicht gelsen werden!";
    }

    einlesen >> JsonListe;
    einlesen.close();


    try {
        for (auto& attribute : JsonListe)
        {
            zeile++;
            std::string Typ1;

            Typ1 = attribute["type"].get<std::string>();
            if(Typ1=="Flight")
            {
                std::string Fluglinie1;
                Fluglinie1 = attribute["airline"].get<std::string>();
                std::string buchungsKlasse;
                buchungsKlasse = attribute["bookingClass"].get<std::string>();
                std::string startDatum1;
                startDatum1 = attribute["fromDate"].get<std::string>();
                std::string flugKrzl1_1;
                flugKrzl1_1 = attribute["fromDest"].get<std::string>();
                std::string fromDestLoc1;
                fromDestLoc1=attribute["fromDestLatitude"].get<std::string>();
                std::string fromDestLongt1;
                fromDestLongt1=attribute["fromDestLongitude"].get<std::string>();
                std::string ID1;
                ID1 = attribute["id"].get<std::string>();
                /*std::vector<std::string> predecessoren;
                std::string predecorID1 = attribute.value("predecessor1","0");
                std::string predecorID2 = attribute.value("predecessor2","0");
                if(predecorID1!="0")
                {
                    predecessoren.push_back(predecorID1);
                }
                if(predecorID2!="0")
                {
                    predecessoren.push_back(predecorID2);
                }*/
                std::string predecorID1;
                if(nullptr==attribute["predecessor1"])
                {
                    predecorID1="0";
                }
                else
                {
                    predecorID1=attribute["predecessor1"];
                }
                std::string predecorID2;
                if(nullptr == attribute["predecessor2"])
                {
                    predecorID2="0";
                }
                else
                {
                    predecorID2 = attribute["predecessor2"];
                }
                long customerID1;
                customerID1 = attribute["customerId"].get<long>();
                std::string kundenName1;
                kundenName1 = attribute["customerName"].get<std::string>();
                long travelId1;
                travelId1 = attribute["travelId"].get<long>();
                double preis1;
                if(attribute["price"].is_number())
                {
                    preis1 = attribute["price"].get<double>();
                }
                else{
                    std::string intZeile = std::to_string(zeile);
                    bookings.clear();
                    throw std::runtime_error("Fehler: Preis ist kein nummerischer Wert in Zeile: " + intZeile);

                }

                std::string endDatum1;
                endDatum1 = attribute["toDate"].get<std::string>();
                std::string flugKrzl2_1;
                flugKrzl2_1 = attribute["toDest"].get<std::string>();
                std::string toDestLoc1;
                toDestLoc1=attribute["toDestLatitude"].get<std::string>();
                std::string toDestLongt1;
                toDestLongt1 = attribute["toDestLongitude"].get<std::string>();
                if(flugKrzl1_1.length()!=3||flugKrzl2_1.length()!=3)
                {
                    std::string intZeile = std::to_string(zeile);
                    throw std::runtime_error("Fehler: Falscher Flughafenkuerzel in Zeile " + intZeile);
                }

                if(Fluglinie1.empty()||startDatum1.empty()||flugKrzl1_1.empty()||ID1.empty()||preis1==0||endDatum1.empty()||flugKrzl2_1.empty())
                {
                    std::string intZeile = std::to_string(zeile);
                    throw std::runtime_error("Fehler: Attribut leer in Zeile " + intZeile);
                }
                std::shared_ptr<FlightBooking> FlugBuchung1 = std::make_shared<FlightBooking>(ID1,preis1,startDatum1,flugKrzl1_1,flugKrzl2_1,Fluglinie1,buchungsKlasse,endDatum1,travelId1, fromDestLoc1, fromDestLongt1, toDestLoc1, toDestLongt1,predecorID1,predecorID2);
                bookings.push_back(FlugBuchung1);

                //travel->addBooking(FlugBuchung1);
                std::shared_ptr<Travel> travel;

                travel = findTravel(travelId1);

                if(travel==nullptr)
                {
                    travel = std::make_shared<Travel>(travelId1, customerID1);
                    allTravels.push_back(travel);

                }
                for(int i=0;i<allTravels.size();i++)
                {
                    if(allTravels[i]->getId()==travelId1)
                    {
                        allTravels.at(i)->addBooking(FlugBuchung1);
                    }
                }
                //allTravels.at(allTravels.size()-1)->addBooking(FlugBuchung1);

                std::shared_ptr<Customer> customer;
                customer = findCustomer(customerID1);

                if(customer==nullptr)
                {
                    customer = std::make_shared<Customer>(customerID1, kundenName1);
                    allCustomers.push_back(customer);
                }

                allCustomers.at(allCustomers.size()-1)->addTravel(travel);

                flugbuchungen1++;
                flugbuchengenPreis1+=preis1;
            }
            else if(Typ1=="RentalCar")
            {
                std::string Firma1;
                Firma1 = attribute["company"].get<std::string>();
                std::string startDatum1;
                startDatum1 = attribute["fromDate"].get<std::string>();
                std::string ID1;
                ID1 = attribute["id"].get<std::string>();
                std::string predecorID1;
                if(nullptr==attribute["predecessor1"])
                {
                    predecorID1="0";
                }
                else
                {
                    predecorID1=attribute["predecessor1"];
                }
                std::string predecorID2;
                if(nullptr == attribute["predecessor2"])
                {
                    predecorID2="0";
                }
                else
                {
                    predecorID2 = attribute["predecessor2"];
                }
                /*if(nullptr==attribute["predecessor1"])
                {
                    predecorID1="0";
                }
                else
                {
                    predecorID1=attribute["predecessor1"];
                }*/

                /*if(nullptr == attribute["predecessor2"])
                {
                    predecorID2="0";
                }
                else
                {
                    predecorID2 = attribute["predecessor2"];
                }*/
                std::string Abholort1;
                Abholort1 = attribute["pickupLocation"].get<std::string>();
                std::string pickupLoc1;
                pickupLoc1=attribute["pickupLatitude"].get<std::string>();
                std::string pickupLongt1;
                pickupLongt1=attribute["pickupLongitude"].get<std::string>();
                double preis1;
                preis1 = attribute["price"].get<double>();
                long customerID1;
                customerID1 = attribute["customerId"].get<long>();
                std::string kundenName1;
                kundenName1 = attribute["customerName"].get<std::string>();
                long travelId1;
                travelId1 = attribute["travelId"].get<long>();
                if(attribute["Price"].is_number())
                {
                    std::string intZeile = std::to_string(zeile);
                    //bookings.clear();
                    throw std::runtime_error("Fehler: Preis ist kein nummerischer Wert in Zeile: " + intZeile);
                }
                std::string Rueckgabeort1;
                Rueckgabeort1 = attribute["returnLocation"].get<std::string>();
                std::string returnLoc1;
                returnLoc1=attribute["returnLatitude"].get<std::string>();
                std::string returnLongt1;
                returnLongt1=attribute["returnLongitude"].get<std::string>();
                std::string endDatum1;
                endDatum1 = attribute["toDate"].get<std::string>();
                std::string vehicleClass;
                vehicleClass = attribute["vehicleClass"].get<std::string>();

                if(Firma1.empty()||startDatum1.empty()||ID1.empty()||Abholort1.empty()||preis1==0||Rueckgabeort1.empty()||endDatum1.empty())
                {
                    std::string intZeile = std::to_string(zeile);
                    //bookings.clear();
                    throw std::runtime_error("Fehler: Attribut leer in Zeile " + intZeile);
                }

                std::shared_ptr<RentalCarReservation> AutoReservierung1 = std::make_shared<RentalCarReservation>(ID1,preis1,startDatum1,endDatum1,Abholort1,Rueckgabeort1,Firma1,vehicleClass,travelId1, pickupLoc1, pickupLongt1, returnLoc1, returnLongt1,predecorID1,predecorID2);
                bookings.push_back(AutoReservierung1);


                std::shared_ptr<Travel> travel = findTravel(travelId1);
                if(travel==nullptr)
                {
                    travel = std::make_shared<Travel>(travelId1, customerID1);
                    allTravels.push_back(travel);
                    //travel->addBooking(AutoReservierung1);
                }

                for(int i=0;i<allTravels.size();i++)
                {
                    if(allTravels[i]->getId()==travelId1)
                    {
                        allTravels.at(i)->addBooking(AutoReservierung1);
                    }
                }
                //allTravels.at(allTravels.size()-1)->addBooking(AutoReservierung1);

                std::shared_ptr<Customer> customer;
                customer = findCustomer(customerID1);

                if(customer==nullptr)
                {
                    customer = std::make_shared<Customer>(customerID1, kundenName1);
                    allCustomers.push_back(customer);
                }

                allCustomers.at(allCustomers.size()-1)->addTravel(travel);

                Autobuchungen1++;
                AutobuchungenPreis1+=preis1;
            }

            else if(Typ1=="Hotel")
            {
                std::string startDatum1;
                startDatum1 = attribute["fromDate"].get<std::string>();
                std::string hotelname1;
                hotelname1 = attribute["hotel"].get<std::string>();
                std::string hotelLoc1;
                hotelLoc1 = attribute["hotelLatitude"].get<std::string>();
                std::string hotelLongt1;
                hotelLongt1 = attribute["hotelLongitude"].get<std::string>();
                std::string ID1;
                ID1 = attribute["id"].get<std::string>();
                //std::vector<std::string> predecessoren;
                std::string predecorID1;
                if(nullptr==attribute["predecessor1"])
                {
                    predecorID1="0";
                }
                else
                {
                    predecorID1=attribute["predecessor1"];
                }
                std::string predecorID2;
                if(nullptr == attribute["predecessor2"])
                {
                    predecorID2="0";
                }
                else
                {
                    predecorID2 = attribute["predecessor2"];
                }
                /*if(nullptr==attribute["predecessor1"])
                {
                    predecorID1="0";
                }
                else
                {
                    predecorID1=attribute["predecessor1"];
                }*/

                /*if(nullptr == attribute["predecessor2"])
                {
                    predecorID2="0";
                }
                else
                {
                    predecorID2 = attribute["predecessor2"];
                }*/
                double preis1;
                preis1 = attribute["price"].get<double>();
                long customerID1;
                customerID1 = attribute["customerId"].get<long>();
                std::string kundenName1;
                kundenName1 = attribute["customerName"].get<std::string>();
                long travelId1;
                travelId1 = attribute["travelId"].get<long>();
                if(attribute["Price"].is_number())
                {
                    std::string intZeile = std::to_string(zeile);
                    //bookings.clear();
                    throw std::runtime_error("Fehler: Preis ist kein nummerischer Wert in Zeile: " + intZeile);
                }
                std::string roomType;
                roomType=attribute["roomType"].get<std::string>();
                std::string endDatum1;
                endDatum1 = attribute["toDate"].get<std::string>();
                std::string stadt1;
                stadt1 = attribute["town"].get<std::string>();

                if(startDatum1.empty()||hotelname1.empty()||ID1.empty()||preis1==0||endDatum1.empty()||endDatum1.empty())
                {
                    std::string intZeile = std::to_string(zeile);
                    //bookings.clear();
                    throw std::runtime_error("Fehler: Attribut leer in Zeile " + intZeile);
                }

                std::shared_ptr<HotelBooking> HotelReservierung1 = std::make_shared<HotelBooking>(ID1,preis1,startDatum1,endDatum1,hotelname1,stadt1,roomType,travelId1, hotelLoc1, hotelLongt1,predecorID1,predecorID2);
                bookings.push_back(HotelReservierung1);


                std::shared_ptr<Travel>travel = findTravel(travelId1);
                if(travel==nullptr)
                {
                    travel = std::make_shared<Travel>(travelId1, customerID1);
                    allTravels.push_back(travel);
                    //travel->addBooking(HotelReservierung1);
                }

                for(int i=0;i<allTravels.size();i++)
                {
                    if(allTravels[i]->getId()==travelId1)
                    {
                        allTravels.at(i)->addBooking(HotelReservierung1);
                    }
                }
                //allTravels.at(allTravels.size()-1)->addBooking(HotelReservierung1);

                std::shared_ptr<Customer> customer;
                customer = findCustomer(customerID1);

                if(customer==nullptr)
                {
                    customer = std::make_shared<Customer>(customerID1, kundenName1);
                    allCustomers.push_back(customer);
                }

                allCustomers.at(allCustomers.size()-1)->addTravel(travel);

                Hotelreservierungen1++;
                HotelreserbierungenPreis1+=preis1;
            }
        }


        std::string intToStringFlugbuchungen = std::to_string(flugbuchungen1);
        std::string intToStringFlugbuchungenPreis = std::to_string(flugbuchengenPreis1);
        std::string intToStringAutobuchungen = std::to_string(Autobuchungen1);
        std::string intToStringAutobuchungenPreis = std::to_string(AutobuchungenPreis1);
        std::string intToStringHotelreservierungen = std::to_string(Hotelreservierungen1);
        std::string intToStringHotelreserbierungenPreis = std::to_string(HotelreserbierungenPreis1);
        std::string intToStringGesamtwert=std::to_string(flugbuchengenPreis1+AutobuchungenPreis1+HotelreserbierungenPreis1);
        int anzahlReisen , kunden;
        std::string intToStringAnzahlReisen = std::to_string(allTravels.size());
        std::string intToStringAnzahlKunden = std::to_string(allCustomers.size());
        int anzahlReisenId1 = 0, anzahlReisenId17 = 0;
        for(int i=0;i<allTravels.size();i++)
        {
            if(allTravels[i]->getCustomerId()==1)
            {
                anzahlReisenId1++;
            }
        }
        for(int i=0;i<bookings.size();i++)
        {
            if(bookings[i]->getTravelId()==17)
            {
                anzahlReisenId17++;
            }
        }        
        std::string intToStringAnzahlReisenId1 = std::to_string(anzahlReisenId1);
        std::string intToStringAnzahlReisenId17 = std::to_string(anzahlReisenId17);
        for(auto &trav : allTravels)
        {
            /*bool roundTrip;
            bool enoughHotels;
            bool noUselessHotels;
            bool noUselessRental;*/
            trav->reihenfolgeBuchung();
            /*roundTrip = trav->checkRoundtrip();
            enoughHotels = trav->checkEnoughHotels();
            noUselessHotels = trav->checkNoUselessHotels();
            noUselessRental = trav->checkNoUselessRentalCars();
            std::cout << trav->getId() << std::endl;
            if(roundTrip==false)
            {
                std::cout<< "Kein RoundTrip" << std::endl;
            }
            else
            {
                std::cout<< "RoundTrip" << std::endl;
            }

            if(enoughHotels==false)
            {
                std::cout<< "Reise nicht lueckenlos" << std::endl;
            }
            else
            {
                std::cout<< "Reise lueckenlos" << std::endl;
            }

            if(noUselessHotels==false)
            {
                std::cout<< "Reise hat ueberfluessige Hotel/Flug" << std::endl;
            }
            else
            {
                std::cout<< "Reise hat keine ueberfluessige Hotel/Flug" << std::endl;
            }

            if(noUselessRental==false)
            {
                std::cout<< "Reise hat ueberfluessige Mietwagenreservierung" << std::endl;
            }
            else
            {
                std::cout<< "Reise hat keine ueberfluessige Mietwagenreservierung" << std::endl;
            }*/
        }

        //std::cout<<"Es wurden " << flugbuchungen1 << " Flugbuchungen im Wert von " << flugbuchengenPreis1 << " Euro, " << Autobuchungen1 << " Mietwagenbuchungen im Wert von " << AutobuchungenPreis1 << " Euro, und " << Hotelreservierungen1 << " Hotelreservierungen im Wert von " << HotelreserbierungenPreis1 << " Euro angelegt.\n"<<std::endl;
        return "Es wurden " + intToStringFlugbuchungen + " Flugreservierungen, " + intToStringHotelreservierungen + " Hotelbuchungen und " + intToStringAutobuchungen + " Mietwagenbuchungen im Gesamtwert von " + intToStringGesamtwert + " Euro eingelesen. " + "Es wurden " + intToStringAnzahlReisen + " Reisen und " + intToStringAnzahlKunden + "Kunden angelegt. Der Kunde mit der ID 1 hat " + intToStringAnzahlReisenId1 + " Reisen gebucht. Zur Reise mit der ID 17 gehoeren " + intToStringAnzahlReisenId17 + " Buchungen.\n";

    }catch (std::exception& e) {
        /*for(auto booking:bookings){
            delete booking;
        }
        for(auto reise:allTravels){
            delete reise;
        }
        for(auto kunde:allCustomers){
            delete kunde;
        }*/
        bookings.clear();
        allTravels.clear();
        allCustomers.clear();
        //std::cout<<e.what()<<std::endl;
        return e.what();
    }

    /*for(int i=0;i<(int)bookings.size();i++)
    {
       std::cout << bookings[i]->showDetails()<<std::endl;
    }*/
}

/*void TravelAgency::readBinaryFile()
{
    char Typ;
    char ID[39];
    double preis;
    char startDatum[9];
    char endDatum[9];
    char flugKrzl1[4];
    char flugKrzl2[4];
    char Fluglinie[16];
    char Abholstation[16];
    char Rueckgabestation[16];
    char Firmenname[16];
    char hotelname[16];
    char stadt[16];

    int flugbuchungen = 0;
    double flugbuchengenPreis = 0.0;
    int Hotelreservierungen = 0;
    double HotelreserbierungenPreis = 0.0;
    int Autobuchungen = 0;
    double AutobuchungenPreis = 0.0;

    std::ifstream datei;
    datei.open("C:\\Users\\wladl\\Documents\\Prog2\\Praktikum\\Praktikum1\\bookingsBinary.bin",std::ios::in|std::ios::binary);
    if(!datei)
    {
        std::cerr<<"Datei kann nicht geoeffnet werden!";
        exit(-1);
    }

    while (datei.read((char*) &Typ,sizeof (Typ))) //  !datei.eof()&&bookings.size()<=86)
    {
        //datei.read((char*) &Typ,1);
        datei.read((char*) ID,38);
        ID[38]='\0';
        datei.read((char*) &preis,sizeof(preis));
        datei.read((char*) startDatum,8);
        startDatum[8]='\0';
        datei.read((char*) endDatum,8);
        endDatum[8]='\0';

        if(Typ=='F')
        {
            datei.read((char*) flugKrzl1,3);
            flugKrzl1[3]='\0';
            datei.read((char*) flugKrzl2,3);
            flugKrzl2[3]='\0';
            datei.read((char*) Fluglinie,15);
            Fluglinie[15]='\0';

            FlightBooking* Flugbuchung = new FlightBooking(ID,preis,startDatum,flugKrzl1,flugKrzl2,Fluglinie);
            bookings.push_back(Flugbuchung);
            flugbuchungen++;
            flugbuchengenPreis=flugbuchengenPreis + preis;
        }
        else if(Typ=='R')
        {
            datei.read((char*) Abholstation,15);
            Abholstation[15]='\0';
            datei.read((char*) Rueckgabestation,15);
            Rueckgabestation[15]='\0';
            datei.read((char*) Firmenname,15);
            Firmenname[15]='\0';
            RentalCarReservation* AutoReservierung = new RentalCarReservation(ID,preis,startDatum,endDatum,Abholstation,Rueckgabestation,Firmenname);
            bookings.push_back(AutoReservierung);
            Autobuchungen++;
            AutobuchungenPreis = AutobuchungenPreis + preis;
        }
        else if(Typ=='H')
        {
            datei.read((char*) hotelname,15);
            hotelname[15]='\0';
            datei.read((char*) stadt,15);
            stadt[15]='\0';
            HotelBooking* HotelBuchung = new HotelBooking(ID,preis,startDatum,endDatum,hotelname,stadt);
            bookings.push_back(HotelBuchung);
            Hotelreservierungen++;
            HotelreserbierungenPreis = HotelreserbierungenPreis + preis;
        }

    }
    datei.close();

    std::cout<<"Es wurden " << flugbuchungen << " Flugbuchungen im Wert von " << flugbuchengenPreis << " Euro, " << Autobuchungen << " Mietwagenbuchungen im Wert von " << AutobuchungenPreis << " Euro, und " << Hotelreservierungen << " Hotelreservierungen im Wert von " << HotelreserbierungenPreis << " Euro angelegt.\n";
    bookings.clear();
}*/

