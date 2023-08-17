#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "Customer.h"

class Room{
    private:
        std::string checkInDate;
        std::string checkOutDate;
        int numberOfBeds;
        Customer* customer;
        int roomNumber;

    public:
        Room();

        ~Room();

        void setCheckInDate(std::string &checkIn);
        std::string getCheckInDate();

        void setCheckOutDate(std::string &checkOut);
        std::string getCheckOutDate();

        void setNumberOfBeds(int numberOfBeds);
        int getNumberOfBeds();

        void setRoomNumber(int number);
        int getRoomNumber();

        void setCustomer(Customer* customer);
        Customer* getCustomer();


};

#endif