#include "hocsinh.cpp"
#include<iostream>
using namespace std;

int main()
{
    hocsinh hs1("Phan A", 8, 9), hs2(hs1);
    cout <<"Nhap hs1:" <<endl;
    hs1.nhap();
    cout <<"Hs1: " <<endl;
    hs1.xuat();

    cout <<"Lay cua hs2: " <<endl;
    hs2.layht();
    hs2.laydv();
    hs2.laydt();

    hs2.set("Phan B", 7, 6);
    cout <<"Set hs2: " <<endl;
    hs2.xuat();

    cout <<"Diem trung binh cua hs1 la: " <<hs1.dtb() <<endl;
    cout <<"Diem trung binh cua hs2 la: " <<hs2.dtb() <<endl;

    cout <<"Xep loai hs1: ";
    hs1.xeploai();
    cout <<"Xep loai hs2: ";
    hs2.xeploai();

    return 0;
}
