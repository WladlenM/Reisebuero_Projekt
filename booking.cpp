
#include "booking.h"

std::string Booking::getId() const
{
    return id;
}

double Booking::getPrice() const
{
    return price;
}

std::string Booking::getFromDate() const
{
    return fromDate;
}

std::string Booking::getToDate() const
{
    return toDate;
}

long Booking::getTravelId() const
{
    return travelId;
}

Booking::Booking()
{

}

Booking::~Booking()
{

}

std::string Booking::showDetails(){}

