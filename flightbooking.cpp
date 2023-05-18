#include "flightbooking.h"


FlightBooking::FlightBooking(std::string ID,double preis,std::string startDatum,std::string flugKrzl1,std::string flugKrzl2,std::string Fluglinie, std::string bookingKlasse,std::string endDate, long reiseId)
{
    id = ID;
    price = preis;
    fromDate = startDatum;
    toDate = endDate;
    fromDestination = flugKrzl1;
    toDestination = flugKrzl2;
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
    return ruckgabe;
}
