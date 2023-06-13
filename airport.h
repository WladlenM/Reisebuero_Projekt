
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
    std::string getName() const;
    std::string getIso_country() const;
    std::string getMunicipality() const;
    std::string getIata_code() const;
};

#endif // AIRPORT_H
