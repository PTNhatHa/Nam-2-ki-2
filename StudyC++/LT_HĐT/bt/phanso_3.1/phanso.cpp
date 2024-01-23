#include "phanso.h"
#include<iostream>
using namespace std;

phanso::phanso()
{
    tu=0;
    mau=1;
}

phanso::phanso(int t, int m)
{
    tu=t;
    mau=m;
}

phanso::phanso(const int &x)
{
    tu=x;
    mau=1;
}

phanso::phanso(const phanso &x)
{
    this->tu=x.tu;
    this->mau=x.mau;
}

void phanso::nhap()
{
    cout <<"Nhap phan so:"<<endl;
    cout <<"Tu= ";
    cin >>tu;
    do
    {
        cout <<"Mau= ";
        cin >>mau;
    } while (mau==0);
}

void phanso::xuat()
{
    cout <<tu <<"/"<<mau<<endl;
}

int phanso::laytu()
{
    return tu;
}

int phanso::laymau()
{
    return mau;
}

void phanso::gantu(int t)
{
    this->tu=t;
}

void phanso::ganmau(int m)
{
    this->mau=m;
}

void phanso::nghichdao()
{
    if (tu==0) cout <<"Khong the nghich dao"<<endl;
    else swap(tu,mau);
}

void phanso::rutgon()
{
    int a=tu,b=mau;
    //tìm UCLN
    while (a!=b)
    {
        if (a>b) a=a-b;
        else b=b-a;
    }
    tu=tu/a;
    mau=mau/a;
}

phanso operator +(phanso x, phanso y)
{
    phanso ps;
    if (x.laymau()==y.laymau())
    {
        ps.gantu(x.laytu()+y.laytu());
        ps.ganmau(x.laymau());
        return ps;
    }
    ps.gantu(x.laytu()*y.laymau()+y.laytu()*x.laymau());
    ps.ganmau(x.laymau()*y.laymau());
    ps.rutgon();
    return ps;

}

phanso operator -(phanso x, phanso y)
{
    phanso ps;
    if (x.laymau()==y.laymau())
    {
        ps.gantu(x.laytu()-y.laytu());
        ps.ganmau(x.laymau());
        return ps;
    }
    ps.gantu(x.laytu()*y.laymau()-y.laytu()*x.laymau());
    ps.ganmau(x.laymau()*y.laymau());
    ps.rutgon();
    return ps;

}

phanso operator *(phanso x, phanso y)
{
    phanso ps;
    ps.gantu(x.laytu()*y.laytu());
    ps.ganmau(x.laymau()*y.laymau());
    return ps;
}

phanso operator /(phanso x, phanso y)
{
    phanso ps;
    if (x.laytu()==0 || y.laytu()==0) return ps;
    y.nghichdao();
    ps.gantu(x.laytu()*y.laytu());
    ps.ganmau(x.laymau()*y.laymau());
    return ps;
}

void sosanh(const phanso &x)
{

}