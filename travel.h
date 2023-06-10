
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
    std::vector<std::shared_ptr<Booking>> travelBookings;
public:
    Travel(long id, long customerID1);
    ~Travel();
    void addBooking(std::shared_ptr<Booking> booking);
    long getId() const;
    long getCustomerId() const;
    std::vector<std::shared_ptr<Booking>> getTravelBookings() const;
    void setTravelBookings(const std::vector<std::shared_ptr<Booking>> &newTravelBookings);
};

#endif // TRAVEL_H
