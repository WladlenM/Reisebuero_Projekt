
#include "travel.h"

long Travel::getId() const
{
    return id;
}

long Travel::getCustomerId() const
{
    return customerId;
}

std::vector<std::shared_ptr<Booking>> Travel::getTravelBookings() const
{
    return travelBookings;
}

void Travel::setTravelBookings(const std::vector<std::shared_ptr<Booking>> &newTravelBookings)
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
    /*for(int i = 0;i<(int)travelBookings.size();i++)
    {
        delete travelBookings[i];
    }*/
    travelBookings.clear();
}

void Travel::addBooking(std::shared_ptr<Booking> booking)
{
    for(std::shared_ptr<Booking> existingBooking : travelBookings)
    {
        if(existingBooking->getId()==booking->getId())
        {
            return;
        }
    }
        travelBookings.push_back(booking);
}

