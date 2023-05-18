#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include <booking.h>


class RentalCarReservation : public Booking
{
private:
    std::string pickupLocation;
    std::string returnLocation;
    std::string company;
    std::string vehicleClass;
public:
    RentalCarReservation(std::string ID,double preis,std::string startDatum,std::string endDatum,std::string Abholstation,std::string Rueckgabestation,std::string Firmenname, std::string autoKlasse, long reiseId);
    ~RentalCarReservation();
    std::string showDetails();
    std::vector<std::string> myType();
};

#endif // RENTALCARRESERVATION_H
