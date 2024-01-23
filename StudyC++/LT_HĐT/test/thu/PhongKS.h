#pragma once
#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

#ifndef PHONGKS_H
#define PHONGKS_H

class PhongKS
{
protected:
    string idRoom;
    string name;
    int maxNumOfPeople;
    bool status;
    Date checkInDate;
    Date checkOutDate;
    double price;
public:
    PhongKS();
    PhongKS(const PhongKS&);
    virtual ~PhongKS();

    void setIdRoom(string);
    void setName(string);
    void setMaxNumOfPeople(int);
    void setStatus(bool); // true = available
    void setCheckInDate(Date);
    void setCheckOutDate(Date);
    virtual void setPrice();
    void setPrice(double);
    
    string getIdRoom() const;
    string getName() const;
    int getMaxNumOfPeople() const;
    bool getStatus() const;
    Date getCheckInDate() const;
    Date getCheckOutDate() const;
    double getPrice() const;

    const PhongKS& operator = (const PhongKS&);
    // So sanh theo ID phong
    friend bool operator == (const PhongKS&, const PhongKS&);
    friend bool operator < (const PhongKS&, const PhongKS&);
    friend bool operator > (const PhongKS&, const PhongKS&);
	friend istream& operator >> (istream& in, PhongKS&);
    friend ostream& operator << (ostream& out, PhongKS&);
};

class PhongBT : public PhongKS
{
protected:
    double costPerPerson;
public:
    PhongBT();
    ~PhongBT();
    PhongBT(const PhongBT&);
    void setCostPerPerson();
    void setCostPerPerson(double);

    double getCostPerPerson() const;
    void setPrice();
    const PhongBT& operator = (const PhongBT&);

};

class PhongVIP : public PhongKS
{
protected:
    double costPerPerson;
    double surcharge;
public:
    PhongVIP();
    ~PhongVIP();
    PhongVIP(const PhongVIP&);
    void setCostPerPerson();
    double getCostPerPerson() const;
    void setCostPerPerson(double);

    void setSurcharge();
    void setPrice();
    const PhongVIP& operator = (const PhongVIP&);

};


#endif