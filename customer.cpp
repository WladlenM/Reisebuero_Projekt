
#include "customer.h"

long Customer::getId() const
{
    return id;
}

std::string Customer::getName() const
{
    return name;
}

Customer::Customer(long customerID1,std::string kundenName1)
{
    id = customerID1;
    name = kundenName1;
}

void Customer::addTravel(Travel *travel)
{
    for(Travel* existingTravel : travelList)
    {
        if(existingTravel->getId()==travel->getId())
        {
            return;
        }
    }
    travelList.push_back(travel);
}

