#include <iostream>
#include <ctime>
#include <string>
#include "PhongKS.h"
using namespace std;

phongks::phongks()
{
    mp="10001"; //kí tự đầu là tầng(1-5), 4 kí tự còn lại nhận giá trị 0-9
    sn=4; //số người tối đa có giá trị 1-4
    tt=true; //true-trống, false-đã có người ở
    gia=500;
}

phongks::phongks(const phongks &x)
{
    this->mp=x.mp;
    this->sn=x.sn;
    this->tt=x.tt;
    this->nn=x.nn;
    this->nt=x.nt;
    this->gia=x.gia;
    
}

istream &operator >> (istream &in, phongks &x)
{
    int kt;
    do
    {
        cout<<"Nhap ma phong(5 ki tu, ki tu dau tien la so tang 1-4): ";
        cin>>x.mp;
    } while (x.mp.size()!=5);
        
    do
    {
        kt=1;
        cout<<"Nhap so nguoi toi da(1-4): ";
        cin>>x.sn;
        if(x.sn<1||x.sn>4)
        {
             cout<<"\nSo nguoi toi da khong hop le(1-4)"<<endl;
             kt=0;
        }
    } while (kt==0);

    cout<<"Tinh trang phong(trong=1, day=0): ";
    cin>>x.tt;
    if(x.tt==0) 
    {
        cout<<"Ngay nhan phong: \n";
        x.nn.nhap();
        cout<<"Ngay tra phang: \n";
        x.nt.nhap();
    }

    cout<<"Nhap gia phong: ";
    cin>>x.gia;
    return in;
    
}

ostream &operator << (ostream &out, const phongks &x)
{
    cout<<"Ma phong: "<<x.mp<<endl;
    cout<<"So nguoi toi da: "<<x.sn<<endl;
    cout<<"Tinh trang: ";
    if (x.tt==1) cout<<"Phong trong\n";
    else
    {
        cout<<"Phong day\n";
        cout<<"Ngay nhan phong: "; 
        x.nn.xuat(); 
        cout<<"Ngay tra phong: ";
        x.nt.xuat();
    }
    cout<<"Gia phong: "<<x.gia<<endl;
    return out;
}


const phongks &phongks::operator = (const phongks &x)
{
    if(this!=&x)
    {
        int i;
        this->mp=x.mp;
        this->sn=x.sn;
        this->tt=x.tt;
        this->nn=x.nn;
        this->nt=x.nt;
        this->gia=x.gia;
    }
    return *this;
}

void phongks::edit_sn()
{
    cout<<"\nSo nguoi toi da: ";
    cin>>sn;
}

void phongks::edit_tt()
{
    cout<<"\nTinh trang phong(trong=1, het=0): ";
    cin>>tt;
    cout<<"\n Nhap date nhan va tra la 0! \n";
    cout<<"Ngay nhan: \n";
    nn.nhap();
    cout<<"Ngay tra: \n";
    nt.nhap();
}

void phongks::edit_gia()
{
    cout<<"\nGia phong: ";
    cin>>gia;
}

string phongks::getmp()
{
    return mp;
}

double phongks::getgia()
{
    return gia;
}