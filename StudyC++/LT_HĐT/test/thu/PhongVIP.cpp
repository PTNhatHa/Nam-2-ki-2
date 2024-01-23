#include <iostream>
#include "PhongKS.h"
#include <iomanip>
#include <limits>
using namespace std;

enum CostOfVIPRoom
{
    floor1 = 700000,
    floor2 = 650000,
    floor3 = 600000,
    floor4 = 550000,
    floor5 = 500000
};

PhongVIP::PhongVIP()
{

}

PhongVIP::~PhongVIP()
{

}

PhongVIP::PhongVIP(const PhongVIP& room)
{
    this->idRoom = room.idRoom;
    this->maxNumOfPeople = room.maxNumOfPeople;
    this->status = room.status;
    this->checkInDate = room.checkInDate;
    this->checkOutDate = room.checkOutDate;
    this->costPerPerson = room.costPerPerson;
    this->price = room.surcharge;
    this->surcharge = room.surcharge;
}

void PhongVIP::setCostPerPerson()
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

void PhongVIP::setCostPerPerson(double cost)
{
    this->costPerPerson = cost;
}

double PhongVIP::getCostPerPerson() const 
{
    return this->costPerPerson;
}

void PhongVIP::setSurcharge()
{
    this->surcharge = this->costPerPerson * this->maxNumOfPeople / 10;
}

void PhongVIP::setPrice()
{
    this->setCostPerPerson();
    this->setSurcharge();
    this->price = this->maxNumOfPeople * this->costPerPerson + this->surcharge;
    cout << "PhongVIP::setPrice ---" << this->price << endl;

}

const PhongVIP& PhongVIP::operator = (const PhongVIP& room)
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