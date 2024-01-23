#include <iostream>
#include "DATE.h"
using namespace std;

bool isLeap(int year)
{
    return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{
    if (y < 1) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;
 
    if (m == 2)
    {
        if (isLeap(y)) return (d <= 29);
        else return (d <= 28);
    }
 
    if (m == 4 || m == 6 || m == 9 || m == 11) return (d <= 30);
    return true;
}

Date::Date()
{
    this->d = NULL;
    this->m = NULL;
    this->y = NULL;
}

void Date::setdate(int d, int m, int y)
{
    if (isValidDate(d,m,y))
    {
        this->d = d;
        this->m = m;
        this->y = y;
        return;
    }
    throw string("\nInvalid Date.\n");
}

istream &operator >> (istream &in, Date &x)
{
    int d, m, y;
    bool success = true;
    do
    {
        cout<<"Nhap ngay: "; cin>>d;
        cout<<"Nhap thang: "; cin>>m;
        cout<<"Nhap nam: "; cin>>y;
        try
        {
            x.setdate(d,m,y);
        }
        catch(string& s)
        {
            cout<<s<<endl;
            success = false;
        }
    } while (!success);

    return in;        
}

ostream &operator << (ostream &out, const Date &x)
{
    out << x.d << "/" << x.m << "/" << x.y;
    return out;
}

int Date::getd() {return d;}

int Date::getm() {return m;}

int Date::gety() {return y;}
