#include "hotelbooking.h"

HotelBooking::HotelBooking(std::string ID,double preis,std::string startDatum,std::string endDatum,std::string hotelname,std::string stadt,std::string raumTyp, long reiseId)
{
    id = ID;
    price = preis;
    fromDate = startDatum;
    toDate = endDatum;
    hotel = hotelname;
    town = stadt;
    roomType = raumTyp;
    travelId = reiseId;

}

HotelBooking::~HotelBooking()
{

}

std::string HotelBooking::showDetails()
{
    std::string RaumTypBedeutung;
    if(roomType=="EZ")
    {
        RaumTypBedeutung="Einzelzimmer";
    }
    else if(roomType=="DZ")
    {
        RaumTypBedeutung="Doppelzimmer";
    }
    else if(roomType=="AP")
    {
        RaumTypBedeutung="Appartment";
    }
    else if(roomType=="SU")
    {
        RaumTypBedeutung="Suite";
    }
    std::string PriceToString = std::to_string(price);
    std::string text = "Hotelreservierung " + id + " im " + hotel +" in " + town + " vom " + fromDate + " bis zum " + toDate + ". Preis: " + PriceToString + "Euro. " + "Raumtyp: " + RaumTypBedeutung + "\n";

    return text;

}

std::vector<std::string> HotelBooking::myType()
{
    std::string RaumTypBedeutung;
    if(roomType=="EZ")
    {
        RaumTypBedeutung="Einzelzimmer";
    }
    else if(roomType=="DZ")
    {
        RaumTypBedeutung="Doppelzimmer";
    }
    else if(roomType=="AP")
    {
        RaumTypBedeutung="Appartment";
    }
    else if(roomType=="SU")
    {
        RaumTypBedeutung="Suite";
    }
    std::vector<std::string> ruckgabe;
    ruckgabe.push_back(hotel);
    ruckgabe.push_back(town);
    ruckgabe.push_back(RaumTypBedeutung);
    return ruckgabe;
}

void HotelBooking::changeType(int index, std::string inhalt)
{
    if(index==0)
    {
        hotel=inhalt;
    }
    else if(index==1)
    {
        town=inhalt;
    }
    else if(index==2)
    {
        roomType=inhalt;
    }
}

