#include "mang.h"
#include "mang.cpp"
#include<iostream>
using namespace std;

int main()
{
    int n, vt,pt;
    int x[10]={0,1,2,3,4,5,6,7,8,9};
    mang a(10);
    mang b(x,5);
    
   
    cout <<"Nhap mang a: "<<endl;
    a.nhap();
    cout <<"Mang a: ";
    a.xuat();

    mang c(a);
    cout <<"Mang b: ";
    b.xuat();
    cout <<"Kich thuoc mang b la: " <<b.kichthuoc()<<endl;

    cout <<"Mang c: ";
    c.xuat();
    cout <<"Nhap vi tri pt muon lay trong mang c: ";
    cin >>vt;
    cout <<"Gia tri pt tai vt " <<vt <<" la: " <<c.laypt(vt) <<endl;;

    cout <<"Nhap vi tri pt muon gan trong mang c: ";
    cin >>vt;
    c.gan(vt);
    cout <<"Mang c sau khi thay doi: ";
    c.xuat();

    cout <<"Nhap gia tri pt muon tim trong mang c: ";
    cin >>pt;
    c.tim(pt);

    cout <<"Mang a: ";
    a.xuat();
    cout <<"Mang a theo thu tu tang: ";
    a.sxt();
    a.xuat();

    cout <<"Mang b: ";
    b.xuat();
    cout <<"Mang b theo thu tu giam: ";
    b.sxg();
    b.xuat();


    return 0;
}