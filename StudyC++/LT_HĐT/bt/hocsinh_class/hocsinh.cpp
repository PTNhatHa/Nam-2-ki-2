#include "hocsinh.h"
#include<iostream>
using namespace std;

//khoi tao
hocsinh::hocsinh(string hoten, float dvan, float dtoan)
{
    this->ht=hoten;
    this->dv=dvan;
    this->dt=dtoan;
}

//khoi tao
hocsinh::hocsinh(const hocsinh &x)
{
    ht=x.ht;
    dv=x.dv;
    dt=x.dt;
}

//huy bo doi tuong
hocsinh::~hocsinh()
{
    cout <<"Huy bo doi tuong" <<endl;
}

void hocsinh::nhap()
{
    cout <<"Ho ten: ";
    cin >>ht;
    cout <<"Diem van: ";
    cin >>dv;
    cout <<"Diem toan: ";
    cin >>dt;
}

void hocsinh::xuat()
{
    cout <<ht <<endl <<"Diem van: " <<dv <<endl <<"Diem toan: " <<dt <<endl;
}

//lay hoten, dvan, dtoan
void hocsinh::layht()
{
    cout <<"Ho ten la: " <<ht <<endl;
}

void hocsinh::laydv()
{
    cout <<"Diem van la: " <<dv <<endl;
}
void hocsinh::laydt()
{
    cout <<"Diem toan la: " <<dt <<endl;
}

//gan gia tri
void hocsinh::set(string ht1, float dv1, float dt1)
{
    ht=ht1;
    dv=dv1;
    dt=dt1;
}

//diem trung binh
float hocsinh::dtb()
{
    return (dv + dt)/2;
}

//xep loai
void hocsinh::xeploai()
{
    float d=dtb();
    if (d>=8) cout <<"Xep loai gioi"<<endl;
    else if (d>=7) cout <<"Xep loai kha"<<endl;
        else if (d>=5) cout <<"Xep loai trung binh"<<endl;
            else cout <<"Xep loai yeu"<<endl;
}