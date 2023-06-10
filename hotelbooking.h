#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <booking.h>
#include <QApplication>


class HotelBooking : public Booking
{
private:
    std::string hotel;
    std::string town;
    std::string roomType;
    std::string hotelLatitude;
    std::string hotelLongitude;
public:
    HotelBooking(std::string ID,double preis,std::string startDatum,std::string endDatum,std::string hotelname,std::string stadt,std::string raumTyp, long reiseId, std::string hotelLat, std::string hotelLongt);
    ~HotelBooking();

    std::string showDetails();
    std::vector<std::string> myType();
    void changeType(int index, std::string inhalt);
};

#endif // HOTELBOOKING_H
