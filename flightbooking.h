#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <iostream>
#include <booking.h>
#include <attributebookings.h>


class FlightBooking : public Booking
{
private:
    std::string fromDestination;
    std::string toDestination;
    std::string airline;
    std::string bookingClass;
public:
    FlightBooking(std::string ID,double preis,std::string startDatum,std::string flugKrzl1,std::string flugKrzl2,std::string Fluglinie,std::string bookingKlasse,std::string toDate, long reiseId);
    ~FlightBooking();
    std::string showDetails();
    std::vector<std::string> myType();
    void changeType(int index, std::string inhalt);
    //void changeType(std::string newFromDestination, std::string newToDestination, std::string newAirline, std::string newBookingClass);
    void setFromDestination(const std::string &newFromDestination);
    void setToDestination(const std::string &newToDestination);
    void setAirline(const std::string &newAirline);
};

#endif // FLIGHTBOOKING_H
