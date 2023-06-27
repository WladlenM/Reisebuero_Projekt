#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <iostream>
//#include <QApplication>

#include <vector>
#include <booking.h>
#include <flightbooking.h>
#include <hotelbooking.h>
#include <rentalcarreservation.h>
#include <travel.h>
#include <customer.h>
#include <airport.h>


class TravelAgency
{
private:
    std::vector<std::shared_ptr<Booking>> bookings;
    std::vector<std::shared_ptr<Travel>> allTravels;
    std::vector<std::shared_ptr<Customer>> allCustomers;
    std::vector<std::shared_ptr<Airport>> airpots;
public:
    //TravelAgency();
    ~TravelAgency();
    std::string readFile(QString fileName);
    //void readBinaryFile();
    std::vector<std::shared_ptr<Booking>> getBookings() const;
    std::shared_ptr<Booking> findBooking(long id);
    std::shared_ptr<Travel> findTravel(long id);
    std::shared_ptr<Customer> findCustomer(long id);
    void addAirpots(std::shared_ptr<Airport>);
    void clearData();

    std::vector<std::shared_ptr<Travel>> getAllTravels() const;
    std::vector<std::shared_ptr<Customer>> getAllCustomers() const;
    void setBookings(const std::vector<std::shared_ptr<Booking>> &newBookings);
    void addCustomer(std::shared_ptr<Customer>);
    void addBuchung(std::shared_ptr<Booking>);
    void addTravel(std::shared_ptr<Travel>);
    void saveToJSON(std::string button);
    std::vector<std::shared_ptr<Airport> > getAirpots() const;
    std::vector<std::pair<std::shared_ptr<Booking>,QString>> abcAnalyse(long custId, QString typ);
};

#endif // TRAVELAGENCY_H
