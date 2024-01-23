#include <iostream>
#include <ctime>
#include <string>
#include "PhongKS.h"
using namespace std;

PhongKS::PhongKS()
{
    mp=""; //kí tự đầu là tầng(1-5), 4 kí tự còn lại nhận giá trị 0-9
    sn=0; //số người tối đa có giá trị 1-4
    tt=true; //true-trống, false-đã có người ở
    gia=0;
}      

PhongKS::PhongKS(const PhongKS& room)
{
    this->mp = room.mp;
    this->name = room.name;
    this->sn = room.sn;
    this->tt = room.tt;
    this->nn = room.nn;
    this->nt = room.nt;
    this->gia = room.gia;
}

void PhongKS::setmp(string id)
{
    this->mp = id;
}

void PhongKS::setName(string s)
{
    this->name = s;
}

void PhongKS::setsn(int num)
{
    this->sn = num;
}

void PhongKS::settt(bool tt)
{
    this->tt = tt;
}

void PhongKS::setnn(Date Date)
{
    this->nn = Date;
}

void PhongKS::setnt(Date Date)
{
    this->nt = Date;
}

void PhongKS::setgia(double cost)
{
    this->gia = cost;
    cout << "Cost = " << cost << endl;
    cout << "PhongKS::setgia ---" << this->gia << endl;

}

string PhongKS::getmp() const 
{
    return this->mp;
}

string PhongKS::getName() const
{
    return this->name;
}

int PhongKS::getsn() const
{
    return this->sn;
}

bool PhongKS::gettt() const
{
    return this->tt;
}

Date PhongKS::getnn() const
{
    return this->nn;
}

Date PhongKS::getnt() const
{
    return this->nt;
}

double PhongKS::getgia() const
{
    return this->gia;
}

const PhongKS& PhongKS::operator = (const PhongKS& room)
{
    if (this != &room)
    {
        this->setmp(room.mp);
        this->setsn(room.sn);
        this->settt(room.tt);
        this->setnn(room.nn);
        this->setnt(room.nt);
        this->setgia(room.gia);
        this->setName(room.name);
    }
    return *this;
}

bool operator == (const PhongKS& r1, const PhongKS& r2) {
    if (r1.mp == r2.mp && 
        r1.sn == r2.sn && 
        r1.tt == r2.tt && 
        r1.nn == r2.nn && 
        r1.nt == r2.nt && 
        r1.gia == r2.gia)
        return true;
    else
        return false;
}

bool operator < (const PhongKS& r1, const PhongKS& r2) {
    if (r1.mp < r2.mp) 
        return true;
    else   
        return false;
}

bool operator > (const PhongKS& r1, const PhongKS& r2) {
    if (r1.mp > r2.mp) 
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
            room.setmp(id);
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
            room.setsn(num);
        }
        else   
            cout << "So nguoi khong hop le. Vui long nhap lai!" << endl;
    }
    // Nhap trang thai
    isValid = false;
    while (!isValid)
    {
        int tt;
        cout << "-- Trang thai (Phong trong = 1, Da co nguoi o = 0): ";
        in >> tt;
        if (tt == 0 || tt == 1)
        {
            isValid = true;
            room.settt(tt);
            if (tt == 0)
            {
                Date nn;
                cout << "-- Ngay nhan phong: ";
                in >> nn;
                room.setnn(nn);
                bool isOk = false;
                while (!isOk)
                {
                    cout << "-- Ngay tra phong: ";
                    Date nt;
                    in >> nt;
                    if (room.nn < nt || nt == room.nn)
                    {
                        isOk = true;
                        room.setnt(nt);
                    }    
                    else 
                        cout << "Ngay tra phong khong hop le. Vui long nhap lai!" << endl;
                }
            }
            else
            {
                Date DateNull;
                DateNull.setDate(0, 0, 0);
                room.setnn(DateNull);
                room.setnt(DateNull);
            }
        }
        else   
            cout << "Trang thai khong hop le. Vui long nhap lai!" << endl;
    }
    room.setgia();
    return in;
}

ostream& operator << (ostream& out, PhongKS& room)
{
    out << "-- " << room.name << endl;
    out << "-- Ma phong: " << room.mp << endl;
    out << "-- So nguoi toi da: " << room.sn << endl;
    out << "-- Trang thai: ";
    if (room.tt == true)
        out << "Phong trong" << endl;
    else
    {
        out << "Da co nguoi o" << endl;
        out << "-- Ngay nhan phong: ";
        out << room.nn;
        out << endl;
        out << "-- Ngay tra phong: ";
        out << room.nt;
        out << endl;
    }
    out << "-- Gia phong: "<< room.gia;
    return out;
}



//PhongBT-------------------------------------------------------------------------------------------------------------

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
    this->mp = room.mp;
    this->sn = room.sn;
    this->tt = room.tt;
    this->nn = room.nn;
    this->nt = room.nt;
    this->costPerPerson = room.costPerPerson;
    this->gia = this->sn * this->costPerPerson;
}

void PhongBT::setCostPerPerson()
{
    switch (this->mp[0])
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

void PhongBT::setgia()
{
    this->setCostPerPerson();
    this->gia = this->sn * this->costPerPerson;
    cout << "PhongBT::setgia ---" << this->gia << endl;
}

const PhongBT& PhongBT::operator = (const PhongBT& room)
{
    if (this != &room)
    {
        this->setmp(room.mp);
        this->setsn(room.sn);
        this->settt(room.tt);
        this->setnn(room.nn);
        this->setnt(room.nt);
        this->setName(room.name);
        this->setgia();
        this->setCostPerPerson(room.costPerPerson);
    }
    return *this;
}
//PhongVIP-------------------------------------------------------------------------------------------------------------

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
    this->mp = room.mp;
    this->sn = room.sn;
    this->tt = room.tt;
    this->nn = room.nn;
    this->nt = room.nt;
    this->costPerPerson = room.costPerPerson;
    this->gia = room.surcharge;
    this->surcharge = room.surcharge;
}

void PhongVIP::setCostPerPerson()
{
    switch (this->mp[0])
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
    this->surcharge = this->costPerPerson * this->sn / 10;
}

void PhongVIP::setgia()
{
    this->setCostPerPerson();
    this->setSurcharge();
    this->gia = this->sn * this->costPerPerson + this->surcharge;
    cout << "PhongVIP::setgia ---" << this->gia << endl;

}

const PhongVIP& PhongVIP::operator = (const PhongVIP& room)
{
    if (this != &room)
    {
        this->setmp(room.mp);
        this->setsn(room.sn);
        this->settt(room.tt);
        this->setnn(room.nn);
        this->setnt(room.nt);
        this->setName(room.name);
        this->setgia();
        this->setCostPerPerson(room.costPerPerson);
    }
    return *this;
}