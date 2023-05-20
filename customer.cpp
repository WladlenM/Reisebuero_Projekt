
#include "customer.h"

long Customer::getId() const
{
    return id;
}

std::string Customer::getName() const
{
    return name;
}

std::vector<Travel *> Customer::getTravelList() const
{
    return travelList;
}

Customer::Customer(long customerID1,std::string kundenName1)
{
    id = customerID1;
    name = kundenName1;
}

Customer::~Customer()
{
    for(int i = 0;i<(int)travelList.size();i++)
    {
        delete travelList[i];
    }
    travelList.clear();
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

