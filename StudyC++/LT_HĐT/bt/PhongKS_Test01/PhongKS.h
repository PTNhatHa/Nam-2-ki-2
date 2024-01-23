#ifndef PhongKS_h
#define PhongKS_h
#include <iostream>
#include <string>
#include "date.cpp"
using namespace std;

class phongks
{
    private:
        string mp; //mã phòng
        int sn; //số người tối đa
        bool tt; //tình trạng
        date nn; //ngày nhận phòng
        date nt; //ngày trả phòng
        double gia; //giá phòng
    public:
        phongks();
        phongks(const phongks &x);
        friend istream &operator >> (istream &in, phongks &x);
        friend ostream &operator << (ostream &out, const phongks &x);
        const phongks &operator = (const phongks &x);
        void edit_sn();
        void edit_tt();
        void edit_gia();
        string getmp();
        double getgia();
};

#endif