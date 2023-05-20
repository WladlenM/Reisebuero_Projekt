
#include "travel.h"

long Travel::getId() const
{
    return id;
}

long Travel::getCustomerId() const
{
    return customerId;
}

std::vector<Booking *> Travel::getTravelBookings() const
{
    return travelBookings;
}

void Travel::setTravelBookings(const std::vector<Booking *> &newTravelBookings)
{
    travelBookings = newTravelBookings;
}

Travel::Travel(long ID, long KundeId)
{
    id = ID;
    customerId = KundeId;
}

Travel::~Travel()
{
    for(int i = 0;i<(int)travelBookings.size();i++)
    {
        delete travelBookings[i];
    }
    travelBookings.clear();
}

void Travel::addBooking(Booking *booking)
{
    for(Booking* existingBooking : travelBookings)
    {
        if(existingBooking->getId()==booking->getId())
        {
            return;
        }
    }
        travelBookings.push_back(booking);
}

