#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <iostream>
#include <QApplication>

#include <vector>
#include <booking.h>
#include <flightbooking.h>
#include <hotelbooking.h>
#include <rentalcarreservation.h>
#include <travel.h>
#include <customer.h>


class TravelAgency
{
private:
    std::vector<Booking*> bookings;
    std::vector<Travel*> allTravels;
    std::vector<Customer*> allCustomers;
public:
    //TravelAgency();
    ~TravelAgency();
    std::string readFile(QString fileName);
    //void readBinaryFile();
    std::vector<Booking *> getBookings() const;
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
    void clearData();

    std::vector<Travel *> getAllTravels() const;
    std::vector<Customer *> getAllCustomers() const;
    void setBookings(const std::vector<Booking *> &newBookings);
};

#endif // TRAVELAGENCY_H
