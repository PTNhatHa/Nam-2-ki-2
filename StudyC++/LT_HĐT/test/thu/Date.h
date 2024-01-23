#include <iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    ~Date();
    Date(int, int, int);
    Date(const Date&);
    void setDate(int, int, int);
    void displayDate();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    bool isValidDate();
    friend bool operator == (const Date&, const Date&);
    friend bool operator < (const Date&, const Date&);
    friend istream& operator >> (istream& in, Date&);
    friend ostream& operator << (ostream& out, Date&);
};

#endif