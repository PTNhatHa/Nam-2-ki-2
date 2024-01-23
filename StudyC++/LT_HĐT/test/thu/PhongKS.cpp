#include <iostream>
#include "PhongKS.h"
#include <limits>
#include <iomanip>

using namespace std;

PhongKS::PhongKS()
{

}

PhongKS::~PhongKS()
{

}

PhongKS::PhongKS(const PhongKS& room)
{
    this->idRoom = room.idRoom;
    this->name = room.name;
    this->maxNumOfPeople = room.maxNumOfPeople;
    this->status = room.status;
    this->checkInDate = room.checkInDate;
    this->checkOutDate = room.checkOutDate;
    this->price = room.price;
}

void PhongKS::setIdRoom(string id)
{
    this->idRoom = id;
}

void PhongKS::setName(string s)
{
    this->name = s;
}

void PhongKS::setMaxNumOfPeople(int num)
{
    this->maxNumOfPeople = num;
}

void PhongKS::setStatus(bool status)
{
    this->status = status;
}

void PhongKS::setCheckInDate(Date date)
{
    this->checkInDate = date;
}

void PhongKS::setCheckOutDate(Date date)
{
    this->checkOutDate = date;
}

void PhongKS::setPrice()
{
    
}

void PhongKS::setPrice(double cost)
{
    this->price = cost;
    cout << "Cost = " << cost << endl;
    cout << "PhongKS::setPrice ---" << this->price << endl;

}

string PhongKS::getIdRoom() const 
{
    return this->idRoom;
}

string PhongKS::getName() const
{
    return this->name;
}

int PhongKS::getMaxNumOfPeople() const
{
    return this->maxNumOfPeople;
}

bool PhongKS::getStatus() const
{
    return this->status;
}

Date PhongKS::getCheckInDate() const
{
    return this->checkInDate;
}

Date PhongKS::getCheckOutDate() const
{
    return this->checkOutDate;
}

double PhongKS::getPrice() const
{
    return this->price;
}

const PhongKS& PhongKS::operator = (const PhongKS& room)
{
    if (this != &room)
    {
        this->setIdRoom(room.idRoom);
        this->setMaxNumOfPeople(room.maxNumOfPeople);
        this->setStatus(room.status);
        this->setCheckInDate(room.checkInDate);
        this->setCheckOutDate(room.checkOutDate);
        this->setPrice(room.price);
        this->setName(room.name);
    }
    return *this;
}

bool operator == (const PhongKS& r1, const PhongKS& r2) {
    if (r1.idRoom == r2.idRoom && 
        r1.maxNumOfPeople == r2.maxNumOfPeople && 
        r1.status == r2.status && 
        r1.checkInDate == r2.checkInDate && 
        r1.checkOutDate == r2.checkOutDate && 
        r1.price == r2.price)
        return true;
    else
        return false;
}

bool operator < (const PhongKS& r1, const PhongKS& r2) {
    if (r1.idRoom < r2.idRoom) 
        return true;
    else   
        return false;
}

bool operator > (const PhongKS& r1, const PhongKS& r2) {
    if (r1.idRoom > r2.idRoom) 
        return true;
    else   
        return false;
}

istream& operator >> (istream& in, PhongKS& room)
{
    // Nhap ma phong
    bool isValid = false;
    while (!isValid)
    {
        string id;
        cout << "-- Ma phong: ";
        in >> id;
        if (id.size() == 5 && id[0] >= '1' && id[0] <= '5')
        {
            bool isOk = true;
            for (int i = 1; i < 5; i++)
            {
                if (id[i] < '0' || id[i] > '9')
                    isOk = false;
            }
            isValid = isOk;
        }
        if (isValid)
            room.setIdRoom(id);
        else
            cout << "Ma phong khong hop le. Vui long nhap lai!" << endl;
    }
    // Nhap so nguoi toi da
    isValid = false;
    while (!isValid)
    {
        int num;
        cout << "-- So nguoi toi da: ";
        in >> num;
        if (num >= 1 && num <= 4)
        {
            isValid = true;
            room.setMaxNumOfPeople(num);
        }
        else   
            cout << "So nguoi khong hop le. Vui long nhap lai!" << endl;
    }
    // Nhap trang thai
    isValid = false;
    while (!isValid)
    {
        int status;
        cout << "-- Trang thai (Phong trong = 1, Da co nguoi o = 0): ";
        in >> status;
        if (status == 0 || status == 1)
        {
            isValid = true;
            room.setStatus(status);
            if (status == 0)
            {
                Date checkInDate;
                cout << "-- Ngay nhan phong: ";
                in >> checkInDate;
                room.setCheckInDate(checkInDate);
                bool isOk = false;
                while (!isOk)
                {
                    cout << "-- Ngay tra phong: ";
                    Date checkOutDate;
                    in >> checkOutDate;
                    if (room.checkInDate < checkOutDate || checkOutDate == room.checkInDate)
                    {
                        isOk = true;
                        room.setCheckOutDate(checkOutDate);
                    }    
                    else 
                        cout << "Ngay tra phong khong hop le. Vui long nhap lai!" << endl;
                }
            }
            else
            {
                Date dateNull;
                dateNull.setDate(0, 0, 0);
                room.setCheckInDate(dateNull);
                room.setCheckOutDate(dateNull);
            }
        }
        else   
            cout << "Trang thai khong hop le. Vui long nhap lai!" << endl;
    }
    room.setPrice();
    return in;
}

ostream& operator << (ostream& out, PhongKS& room)
{
    out << "-- " << room.name << endl;
    out << "-- Ma phong: " << room.idRoom << endl;
    out << "-- So nguoi toi da: " << room.maxNumOfPeople << endl;
    out << "-- Trang thai: ";
    if (room.status == true)
        out << "Phong trong" << endl;
    else
    {
        out << "Da co nguoi o" << endl;
        out << "-- Ngay nhan phong: ";
        out << room.checkInDate;
        out << endl;
        out << "-- Ngay tra phong: ";
        out << room.checkOutDate;
        out << endl;
    }
    out << "-- Gia phong: " << setprecision(numeric_limits<double>::digits10) << room.price;
    return out;
}

