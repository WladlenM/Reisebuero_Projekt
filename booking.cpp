
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

void Booking::setPrice(double newPrice)
{
    price = newPrice;
}

void Booking::setFromDate(const std::string &newFromDate)
{
    fromDate = newFromDate;
}

void Booking::setToDate(const std::string &newToDate)
{
    toDate = newToDate;
}

Booking::Booking()
{

}

Booking::~Booking()
{

}

std::string Booking::showDetails(){}

