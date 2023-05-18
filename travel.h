
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
    void addBooking(Booking* booking);
    long getId() const;
    long getCustomerId() const;
};

#endif // TRAVEL_H
