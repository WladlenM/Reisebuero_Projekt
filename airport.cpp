
#include "airport.h"


std::string Airport::getName() const
{
    return name;
}

std::string Airport::getIso_country() const
{
    return iso_country;
}

std::string Airport::getMunicipality() const
{
    return municipality;
}

std::string Airport::getIata_code() const
{
    return iata_code;
}

Airport::Airport(std::string nameAirport, std::string iso_land, std::string muni, std::string iata)
{
    name= nameAirport;
    iso_country=iso_land;
    municipality=muni;
    iata_code=iata;
}
