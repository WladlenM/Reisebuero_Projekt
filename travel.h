
#ifndef TRAVEL_H
#define TRAVEL_H
#include <iostream>
#include <QApplication>

#include <vector>
#include <booking.h>
//#include <digraph.h>
#include <graph.h>
#include <queue>



class Travel
{
private:
    Graph<std::shared_ptr<Booking>,50> graph;
    long id;
    long customerId;
    std::vector<std::shared_ptr<Booking>> travelBookings;
    std::vector<int> dependencies;
public:
    Travel(long id, long customerID1);
    ~Travel();
    void addBooking(std::shared_ptr<Booking> booking);
    long getId() const;
    long getCustomerId() const;
    std::vector<std::shared_ptr<Booking>> getTravelBookings() const;
    void setTravelBookings(const std::vector<std::shared_ptr<Booking>> &newTravelBookings);
    void reihenfolgeBuchung();
    std::vector<int> sortiere();
    bool checkRoundtrip();
    bool checkEnoughHotels();
    bool checkNoUselessHotels();
    bool checkNoUselessRentalCars();
};

#endif // TRAVEL_H
