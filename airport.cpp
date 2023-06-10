
#include "airport.h"


Airport::Airport(std::string nameAirport, std::string iso_land, std::string muni, std::string iata)
{
    name= nameAirport;
    iso_country=iso_land;
    municipality=muni;
    iata_code=iata;
}
