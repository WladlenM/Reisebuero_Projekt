
#include "travel.h"

long Travel::getId() const
{
    return id;
}

long Travel::getCustomerId() const
{
    return customerId;
}

Travel::Travel(long ID, long KundeId)
{
    id = ID;
    customerId = KundeId;
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

