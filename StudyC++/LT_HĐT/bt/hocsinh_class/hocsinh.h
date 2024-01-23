#ifndef hocsinh_h
#define hocsinh_h
#include<string>
#include<iostream>
using namespace std;

class hocsinh
{
    private:
        string ht;
        float dv;
        float dt;
    public:
        hocsinh(string hoten, float dvan, float dtoan);
        hocsinh(const hocsinh &x);
        ~hocsinh();
        void nhap();
        void xuat();
        void layht();
        void laydv();
        void laydt();
        void set(string, float, float);
        float dtb();
        void xeploai();
};
#endif