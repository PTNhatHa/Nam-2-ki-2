#include <iostream>
#include <string>
#include "date.h"
using namespace std;

date::date()
{
    d=NULL;
    m=NULL;
    y=NULL;
}

date::date(const date &x)
{
    this->d=x.d;
    this->m=x.m;
    this->y=x.y;
}

void date::nhap()
{
    cout<<"Nhap ngay: "; cin>>d;
    cout<<"Nhap thang: "; cin>>m;
    cout<<"Nhap nam: "; cin>>y;
}

void date::xuat() const
{
    cout<<d<<"/"<<m<<"/"<<y<<endl;
}

int date::getd()
{
    return d;
}

int date::getm()
{
    return m;
}

int date::gety()
{
    return y;
}