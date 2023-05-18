#include <iostream>
#ifndef ATTRIBUTEBOOKINGS_H
#define ATTRIBUTEBOOKINGS_H




class AttributeBookings
{
public:
    AttributeBookings();
    std::string id;
    double price;
    std::string fromDate;
    std::string toDate;
    std::string fromDestination;
    std::string toDestination;
    std::string airline;
    std::string bookingClass;
    std::string hotel;
    std::string town;
    std::string roomType;
    std::string pickupLocation;
    std::string returnLocation;
    std::string company;
    std::string vehicleClass;
    std::string text;
};

#endif // ATTRIBUTEBOOKINGS_H
