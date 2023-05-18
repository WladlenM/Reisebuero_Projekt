#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation(std::string ID,double preis,std::string startDatum,std::string endDatum,std::string Abholstation,std::string Rueckgabestation,std::string Firmenname, std::string autoKlasse, long reiseId)
{
    id = ID;
    price = preis;
    fromDate = startDatum;
    toDate = endDatum;
    pickupLocation = Abholstation;
    returnLocation = Rueckgabestation;
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
    return ruckgabe;
}
