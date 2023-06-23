#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include <booking.h>


class RentalCarReservation : public Booking
{
private:
    std::string pickupLocation;
    std::string pickupLatitude;
    std::string pickupLongitude;
    std::string returnLocation;
    std::string returnLatitude;
    std::string returnLongitude;
    std::string company;
    std::string vehicleClass;
public:
    RentalCarReservation(std::string ID,double preis,std::string startDatum,std::string endDatum,std::string Abholstation,std::string Rueckgabestation,std::string Firmenname, std::string autoKlasse, long reiseId, std::string pickupLoc, std::string pickupLongt, std::string returnLoc, std::string returnLongt,std::string predecorId1,std::string predecorId2);
    ~RentalCarReservation();
    std::string showDetails();
    std::vector<std::string> myType();
    void changeType(int index, std::string inhalt);
};

#endif // RENTALCARRESERVATION_H
