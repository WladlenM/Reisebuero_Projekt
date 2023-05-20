#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
#include <vector>
#include <attributebookings.h>



class Booking
{
protected:
    std::string id;
    double price;
    std::string fromDate;
    std::string toDate;
    long travelId;

public:
    Booking();
    virtual ~Booking();
    virtual std::string showDetails() = 0;
    std::string getId() const;
    double getPrice() const;
    std::string getFromDate() const;
    std::string getToDate() const;
    virtual std::vector<std::string> myType()=0;
    virtual void changeType(int index, std::string inhalt)=0;
    //virtual void changeType()=0;
    long getTravelId() const;
    void setPrice(double newPrice);
    void setFromDate(const std::string &newFromDate);
    void setToDate(const std::string &newToDate);
};

#endif // BOOKING_H
