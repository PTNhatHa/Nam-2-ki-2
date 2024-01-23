#ifndef Date_h
#define Date_h
#include <iostream>
using namespace std;
class Date
{
    private:
        int d, m, y;
    public:
        Date();
        void setdate(int d, int m, int y);
        friend istream &operator >> (istream &in, Date &x);
        friend ostream &operator << (ostream &out, const Date &x);
        int getd();
        int getm();
        int gety();

};
#endif 