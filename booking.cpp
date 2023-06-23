
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

std::string Booking::getPredecorId1() const
{
    return predecorId1;
}

std::string Booking::getPredecorId2() const
{
    return predecorId2;
}

Booking::Booking()
{

}

Booking::~Booking()
{

}

std::string Booking::showDetails(){}

