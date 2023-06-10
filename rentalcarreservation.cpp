#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation(std::string ID,double preis,std::string startDatum,std::string endDatum,std::string Abholstation,std::string Rueckgabestation,std::string Firmenname, std::string autoKlasse, long reiseId, std::string pickupLoc, std::string pickupLongt, std::string returnLoc, std::string returnLongt)
{
    id = ID;
    price = preis;
    fromDate = startDatum;
    toDate = endDatum;
    pickupLocation = Abholstation;
    pickupLatitude = pickupLoc;
    pickupLongitude=pickupLongt;
    returnLocation = Rueckgabestation;
    returnLatitude=returnLoc;
    returnLongitude=returnLongt;
    company = Firmenname;
    vehicleClass = autoKlasse;
    travelId = reiseId;
}

RentalCarReservation::~RentalCarReservation()
{

}

std::string RentalCarReservation::showDetails()
{
    std::string PriceToString = std::to_string(price);
    std::string text = "Mietwagenreservierung " + id + " mit " + company + ". Abholung am " + fromDate + " in " + pickupLocation + ". Rueckgabe am " + toDate + " in " + returnLocation + ". Preis: " + PriceToString + "Euro. " + " Autoklasse: " + vehicleClass + "\n";

    return text;
}

std::vector<std::string> RentalCarReservation::myType()
{
    std::vector<std::string> ruckgabe;
    ruckgabe.push_back(pickupLocation);
    ruckgabe.push_back(returnLocation);
    ruckgabe.push_back(company);
    ruckgabe.push_back(vehicleClass);
    ruckgabe.push_back(pickupLatitude);
    ruckgabe.push_back(pickupLongitude);
    ruckgabe.push_back(returnLatitude);
    ruckgabe.push_back(returnLongitude);
    return ruckgabe;
}

void RentalCarReservation::changeType(int index, std::string inhalt)
{
    if(index==0)
    {
        pickupLocation=inhalt;
    }
    else if(index==1)
    {
        returnLocation=inhalt;
    }
    else if(index==2)
    {
        company=inhalt;
    }
    else if(index==3)
    {
        vehicleClass=inhalt;
    }
}
