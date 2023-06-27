#include "flightbooking.h"


void FlightBooking::setFromDestination(const std::string &newFromDestination)
{
    fromDestination = newFromDestination;
}

void FlightBooking::setToDestination(const std::string &newToDestination)
{
    toDestination = newToDestination;
}

void FlightBooking::setAirline(const std::string &newAirline)
{
    airline = newAirline;
}

FlightBooking::FlightBooking(std::string ID,double preis,std::string startDatum,std::string flugKrzl1,std::string flugKrzl2,std::string Fluglinie, std::string bookingKlasse,std::string endDate, long reiseId, std::string vonDestLoc, std::string vonDestLongt, std::string zuDestLoc, std::string zuDestLongt,std::string xpredecorID1,std::string xpredecorID2)
{
    id = ID;
    price = preis;
    fromDate = startDatum;
    toDate = endDate;
    predecorId1=xpredecorID1;
    predecorId2=xpredecorID2;
    fromDestination = flugKrzl1;
    fromDestLatitude = vonDestLoc;
    fromDestLongitude = vonDestLongt;
    toDestination = flugKrzl2;
    toDestLatitude = zuDestLoc;
    toDestLongitude = zuDestLongt;
    airline = Fluglinie;
    bookingClass =  bookingKlasse;
    travelId = reiseId;

}

FlightBooking::~FlightBooking()
{

}

std::string FlightBooking::showDetails()
{
    std::string KlasseBooking;
    if(bookingClass=="Y")
    {
        KlasseBooking="Economy class";
    }
    else if(bookingClass=="W")
    {
        KlasseBooking="Premium Economy class";
    }
    else if(bookingClass=="J")
    {
        KlasseBooking="Buseniess class";
    }
    else if(bookingClass=="F")
    {
        KlasseBooking="First class";
    }
    std::string PriceToString = std::to_string(price);
    std::string text = "Flugbuchung " + id + " von " + fromDestination + " mit " + KlasseBooking + " nach " + toDestination + " mit " + airline + " am " + fromDate + ". Preis: " + PriceToString + " Euro\n";

    return text;
}

std::vector<std::string> FlightBooking::myType()
{
    std::string KlasseBooking;
    if(bookingClass=="Y")
    {
        KlasseBooking="Economy class";
    }
    else if(bookingClass=="W")
    {
        KlasseBooking="Premium Economy class";
    }
    else if(bookingClass=="J")
    {
        KlasseBooking="Buseniess class";
    }
    else if(bookingClass=="F")
    {
        KlasseBooking="First class";
    }
    std::vector<std::string> ruckgabe;
    ruckgabe.push_back(fromDestination);
    ruckgabe.push_back(toDestination);
    ruckgabe.push_back(airline);
    ruckgabe.push_back(KlasseBooking);
    ruckgabe.push_back(fromDestLatitude);
    ruckgabe.push_back(fromDestLongitude);
    ruckgabe.push_back(toDestLatitude);
    ruckgabe.push_back(toDestLongitude);
    return ruckgabe;
}

void FlightBooking::changeType(int index, std::string inhalt)
{
    if(index==0)
    {
        fromDestination=inhalt;
    }
    else if(index==1)
    {
        toDestination=inhalt;
    }
    else if(index==2)
    {
        airline=inhalt;
    }
    else if(index==3)
    {
        bookingClass=inhalt;
    }
}

/*void FlightBooking::changeType(std::string newFromDestination, std::string newToDestination, std::string newAirline, std::string newBookingClass)
{
    fromDestination = newFromDestination;
    toDestination = newToDestination;
    airline = newAirline;
    bookingClass = newBookingClass;

}*/
