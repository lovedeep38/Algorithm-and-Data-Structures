#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer{
    private:
        std::string customerId;
        int numberOfRequestedBeds;

    public:
        Customer();
        ~Customer();
        void setRequestBeds(int &numberOfBeds);
        int getRequestedBeds() const;

        void setCustomerId(std::string &customerId);
        std::string getCustomerId() const;
};

#endif