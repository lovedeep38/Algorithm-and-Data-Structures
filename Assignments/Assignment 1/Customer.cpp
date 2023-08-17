#include "Customer.h"

Customer::Customer() {
    customerId = "";
    numberOfRequestedBeds = 0;
}

Customer::~Customer() {
    customerId = "";
    numberOfRequestedBeds = 0;
}

void Customer::setRequestBeds(int &numberOfBeds) {
    numberOfRequestedBeds = numberOfBeds;
}


int Customer::getRequestedBeds() const {
    return numberOfRequestedBeds;
}

void Customer::setCustomerId(std::string &customerId) {
    this->customerId = customerId;
}

std::string Customer::getCustomerId() const {
    return customerId;
}


