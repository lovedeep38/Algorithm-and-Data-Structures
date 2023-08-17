#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"
#include "Customer.h"

class Node {
    public:
        Customer* customer;
        Node* next;

        Node(Customer* customer) {
            next = nullptr;
        }
};

class Hotel{
    private:
        Node* list;
        Room rooms[180];
        int servedCustomers;
        int refusedCustomers;
        int checkedOutCustomers;
        std::string currentDate;

    public:
        Hotel();
        ~Hotel();

        void gettingInput();
        void addCustomer(Customer* customer);
        void assignCustomer(std::string stayDuration);
        void setRoomsAfterCheckout(Customer* customer, std::string currentDate, std::string stayDuration);
        void gettingDailyInformation(std::string stayDuration);

};

Hotel::Hotel() {
    list == nullptr;
    servedCustomers = 0;
    refusedCustomers = 0;
    checkedOutCustomers = 0;
    currentDate = "";
}

Hotel::~Hotel() {
    servedCustomers = 0;
    refusedCustomers = 0;
    checkedOutCustomers = 0;
    currentDate = "";

    delete[] list;
}

void Hotel::gettingInput() {
    std::ifstream file("Customers.txt");
    std::string checkInDate;
    std::string id;
    int bedsRequested;
    std::string stayDuration;

    int totalCustomers = 0;
    Customer* list = nullptr;

    int count = 1;

    while(file >> checkInDate >> id >> bedsRequested >> stayDuration) {
        Customer* newCustomer = new Customer();
        newCustomer->setCustomerId(id);
        newCustomer->setRequestBeds(bedsRequested);
        
        addCustomer(newCustomer);
        assignCustomer(stayDuration);

        if(count == 1) {
            currentDate = checkInDate;
        }
        count = 2;

        setRoomsAfterCheckout(newCustomer, currentDate, stayDuration);

        if(currentDate != checkInDate) {
            gettingDailyInformation(stayDuration);
        }

        currentDate = checkInDate;
    }

    file.close();
}

void Hotel::addCustomer(Customer* customer) {
    Node* newNode = new Node(customer);
    newNode->next = list;
    list = newNode;

}

void Hotel::assignCustomer(std::string stayDuration) {
    Node* currentCustomer = list;
    while(currentCustomer) {
        Customer* customer = currentCustomer->customer;
        int requestedBeds = customer->getRequestedBeds();

        bool isAssigned = false;

        for(int i = 1; i <= 180; i++) {
            if(requestedBeds == rooms[i].getNumberOfBeds() && rooms[i].getCustomer() == nullptr) {
                rooms[i].setCustomer(customer);
                rooms[i].setCheckOutDate(stayDuration);
                isAssigned = true;
                break;
            }
        }

        if (!isAssigned) {
            int remainingBeds = customer->getRequestedBeds();
            Room* assignedRooms[180];
            int count = 0;

            for(int i = 0; i < 180; ++i) {
                Room& room = rooms[i];

                if(room.getNumberOfBeds() <= remainingBeds && room.getCustomer() == nullptr) {
                    assignedRooms[count++] = &room;
                    remainingBeds -= room.getNumberOfBeds();

                    if(remainingBeds == 0) {
                        break;
                    }
                }
            }

            if(remainingBeds == 0) {
                for(int i = 0; i < count; ++i) {
                    assignedRooms[i]->setCustomer(customer);
                }
                isAssigned = true;
            }
        }

        if(isAssigned == false) {
            std::cout << "Sorry, there is no room available for you" << std::endl;
            refusedCustomers++;
        }
        else{
            servedCustomers++;
        }

        currentCustomer = currentCustomer->next;
    }

}

void Hotel::setRoomsAfterCheckout(Customer* customer, std::string currentDate, std::string stayDuration) {
    for (int i = 1; i < 180; i++) {
        Room& r = rooms[i];

        if (r.getCheckOutDate() == currentDate && r.getCustomer() == customer) {
            r.setCustomer(nullptr);
        }
    }
}

void Hotel::gettingDailyInformation(std::string stayDuration) {
    int checkedOutRooms = 0;

    for (int i = 0; i < 180; ++i) {
        Room& room = rooms[i];

        if (room.getCheckOutDate() == currentDate) {
            checkedOutRooms++;
            setRoomsAfterCheckout(room.getCustomer(), currentDate, stayDuration);
        }
    }
        std::ofstream logFile;
    logFile.open("logFile.txt");
    checkedOutCustomers += checkedOutRooms;

    logFile << "Number of customers served today: " << servedCustomers << std::endl;
    logFile << "Number of customers refused today: " << refusedCustomers << std::endl;
    logFile << "Number of customers checked out today: " << checkedOutRooms << std::endl;
    logFile << "Number of rooms available today: " << (180 - checkedOutRooms) << std::endl;
    logFile.close();

    servedCustomers = 0;
    refusedCustomers = 0;
}

int main() {
    Hotel hotel;

    hotel.gettingInput();

    return 0;
}



