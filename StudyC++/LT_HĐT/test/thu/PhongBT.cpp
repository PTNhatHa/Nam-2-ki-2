#include <iostream>
#include "PhongKS.h"
#include <iomanip>
#include <limits>
using namespace std;

enum CostOfNormalRoom
{
    floor1 = 500000,
    floor2 = 450000,
    floor3 = 400000,
    floor4 = 350000,
    floor5 = 300000
};

PhongBT::PhongBT()
{

}

PhongBT::~PhongBT()
{

}

PhongBT::PhongBT(const PhongBT& room)
{
    this->idRoom = room.idRoom;
    this->maxNumOfPeople = room.maxNumOfPeople;
    this->status = room.status;
    this->checkInDate = room.checkInDate;
    this->checkOutDate = room.checkOutDate;
    this->costPerPerson = room.costPerPerson;
    this->price = this->maxNumOfPeople * this->costPerPerson;
}

void PhongBT::setCostPerPerson()
{
    switch (this->idRoom[0])
    {   
        case '1': 
            this->costPerPerson = floor1;
            break;
        case '2': 
            this->costPerPerson = floor2;
            break;
        case '3': 
            this->costPerPerson = floor3;
            break;
        case '4': 
            this->costPerPerson = floor4;
            break;
        case '5': 
            this->costPerPerson = floor5;
            break;            
    }
}

void PhongBT::setCostPerPerson(double cost)
{
    this->costPerPerson = cost;
}

double PhongBT::getCostPerPerson() const 
{
    return this->costPerPerson;
}

void PhongBT::setPrice()
{
    this->setCostPerPerson();
    this->price = this->maxNumOfPeople * this->costPerPerson;
    cout << "PhongBT::setPrice ---" << this->price << endl;
}

const PhongBT& PhongBT::operator = (const PhongBT& room)
{
    if (this != &room)
    {
        this->setIdRoom(room.idRoom);
        this->setMaxNumOfPeople(room.maxNumOfPeople);
        this->setStatus(room.status);
        this->setCheckInDate(room.checkInDate);
        this->setCheckOutDate(room.checkOutDate);
        this->setName(room.name);
        this->setPrice();
        this->setCostPerPerson(room.costPerPerson);
    }
    return *this;
}
