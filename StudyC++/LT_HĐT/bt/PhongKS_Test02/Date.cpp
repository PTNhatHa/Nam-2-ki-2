#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Date::~Date()
{
}


Date::Date(int d, int m, int y)
{
    this->day = d;
    this->month = m;
    this->year = y;
}

Date::Date(const Date& date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

void Date::setDate(int d, int m, int y)
{
    this->day = d;
    this->month = m;
    this->year = y;
}

void Date::displayDate()
{
    cout << this->day << "/" << this->month << "/" << this->year;
}

void Date::setDay(int d)
{
    this->day = d;
}


void Date::setMonth(int m)
{
    this->month = m;
}

void Date::setYear(int y)
{
    this->year = y;
}

int Date::getMonth() const
{
    return this->month;
}

int Date::getDay() const
{
    return this->day;
}

int Date::getYear() const
{
    return this->year;
}

bool Date::isValidDate()
{
    if (this->month < 1 || this->month > 12) return false;
    if (this->month == 2)
    {
        if ((this->year) % 400 == 0 || (this->year % 100 != 0 && this->year % 4 == 0))
        {
            if (this->day < 1 || this->day > 29)
                return false;
        }
        else
        {
            if (this->day < 1 || this->day > 28)
                return false;
        }
    }
    else if (this->month == 1 ||
        this->month == 3 ||
        this->month == 5 ||
        this->month == 7 ||
        this->month == 8 ||
        this->month == 10 ||
        this->month == 12
    )
    {
        if (this->day < 1 || this->day > 31) 
            return false;
    }
    else
    {
        if (this->day < 1 || this->day > 30)
            return false;
    }
    return true;
}

bool operator == (const Date& d1, const Date& d2)
{
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return true;
    else   
        return false;
}

bool operator < (const Date& date1, const Date& date2)
{
    if (date1.year == date2.year)
    {
        if (date1.month == date2.month)
        {
            if (date1.day < date2.day) 
                return true;
        }
        else 
        {
            if (date1.month < date2.month)
            return true;
        }
    }
    else 
    {
        if (date1.year < date2.year)
        return true;
    }
    return false;
}

istream& operator >> (istream& in, Date& date)
{
    bool isOk = false;
    while (!isOk)
    {
        int d, m, y;
        in >> d >> m >> y;
        date.setDate(d, m, y);
        if (date.isValidDate())
            isOk = true;
        else 
            cout << "Ngay khong hop le. Vui long nhap lai!" << endl;
    }   
    return in;
}

ostream& operator << (ostream& out, Date& date)
{
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}

