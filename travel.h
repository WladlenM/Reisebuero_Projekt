
#ifndef TRAVEL_H
#define TRAVEL_H
#include <iostream>
#include <QApplication>

#include <vector>
#include <booking.h>



class Travel
{
private:
    long id;
    long customerId;
    std::vector<Booking*> travelBookings;
public:
    Travel(long id, long customerID1);
    ~Travel();
    void addBooking(Booking* booking);
    long getId() const;
    long getCustomerId() const;
    std::vector<Booking *> getTravelBookings() const;
    void setTravelBookings(const std::vector<Booking *> &newTravelBookings);
};

#endif // TRAVEL_H
