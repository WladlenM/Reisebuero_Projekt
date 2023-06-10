
#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>



class Airport
{
private:
    std::string name;
    std::string iso_country;
    std::string municipality;
    std::string iata_code;
public:
    Airport(std::string nameAirport, std::string iso_land, std::string muni, std::string iata);
};

#endif // AIRPORT_H
