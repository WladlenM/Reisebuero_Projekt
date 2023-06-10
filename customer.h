
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include <travel.h>


class Customer
{
private:
    long id;
    std::string name;
    std::vector<std::shared_ptr<Travel>> travelList;
public:
    Customer(long customerID1,std::string kundenName1);
    ~Customer();
    void addTravel(std::shared_ptr<Travel> travel);
    long getId() const;
    std::string getName() const;
    std::vector<std::shared_ptr<Travel>> getTravelList() const;
};

#endif // CUSTOMER_H
