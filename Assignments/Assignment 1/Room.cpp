#include <string>
#include "Room.h"

Room::Room() {
    roomNumber = 0;
    checkInDate = "";
    checkOutDate = "";
    numberOfBeds = 0;
    customer = nullptr;
}

Room::~Room() {
    roomNumber = 0;
    checkInDate = "";
    checkOutDate = "";
    numberOfBeds = 0;
    customer = nullptr;
}

void Room::setCheckInDate(std::string &checkIn) {
    checkInDate = checkIn;
}

std::string Room::getCheckInDate() {
    return checkInDate;
}

void Room::setCheckOutDate(std::string &checkOut) {
    std::string date = getCheckInDate();
    std::string day;
    if(date[1] == '/'){
        day = date[0];
    }else if(date[2] == '/'){
        day = date[0];
        day += date[1];
    }
    int d = stoi(day);
    int duration = stoi(checkOut);
    d += duration;
    
    std::string result = "";
    result += d;
    if(date[1] == '/'){
        result += date.substr(1);
    }else if(date[2] == '/'){
        result += date.substr(2);
    }

    checkOutDate = result;
}

std::string Room::getCheckOutDate() {
    return checkOutDate;
}

void Room::setNumberOfBeds(int numberOfBeds) {
    this->numberOfBeds = numberOfBeds;
}

int Room::getNumberOfBeds() {
    return numberOfBeds;
}

void Room::setRoomNumber(int number){
    roomNumber = number;
}

int Room::getRoomNumber() {
    return roomNumber;
}

void Room::setCustomer(Customer* customer) {
    this->customer = customer;
}

Customer* Room::getCustomer() {
    return customer;
}