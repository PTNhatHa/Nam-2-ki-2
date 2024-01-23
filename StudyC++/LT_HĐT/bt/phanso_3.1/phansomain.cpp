#include "phanso.h"
#include "phanso.cpp"
#include<iostream>
using namespace std;

int main()
{
    phanso ps1;
    cout <<"Ps1: ";
    ps1.nhap();
    cout <<"Ps1= ";
    ps1.xuat();
    
    phanso ps2(5,2);
    phanso ps3(6);
    phanso ps4(ps2);
    cout<<"\nTu cua ps2 : " <<ps2.laytu()<<endl;
    cout<<"\nMau cua ps2 : " << ps2.laymau()<<endl;

    cout <<"Gan gia tri 20/5 cho ps 2: "<<endl;
    ps2.gantu(20);
    ps2.ganmau(5);
    cout <<"Ps2= ";
    ps2.xuat();

    cout <<"Nghich dao ps2 :";
    ps2.nghichdao();
    ps2.xuat();

    cout <<"Rut gon cua ps2: ";
    ps2.rutgon();
    ps2.xuat();

    phanso p1(8,6);
    phanso p2(2,3);
    cout <<"\n 8/6 + 2/3 = "; (p1 + p2).xuat();
    cout <<"\n 8/6 - 2/3 = "; (p1 - p2).xuat();
    cout <<"\n 8/6 * 2/3 = "; (p1 * p2).xuat();
    cout <<"\n 8/6 / 2/3 = "; (p1 / p2).xuat();

    return 0;

}