#include "set.h"
#include "set.cpp"
#include<iostream>
using namespace std;

int main()
{
    int m[6]={0,1,2,3,4,5};
    set a1(10);
    set a2(m,5);
    set a3(a2);

    int pt;
    cout<<"Mang a2: ";
    a2.xuat();
    cout <<"Nhap gia tri pt muon them vao mang a2: ";
    cin >>pt;
    a2.add(pt);
    a2.xuat();

    //Xóa 01 phần tử khỏi tập hợp
    a3.deletept(2);
    a3.xuat();

    //Kiểm tra 01 phần tử có thuộc tập hợp hay không (có/không)
    cout<<"\n3 co ton tai khong ? " << (a3.kt(3)?"true":"false");
    cout<<"\n4 co ton tai khong ? " << (a3.kt(4)?"true":"false");

    //Tìm hợp của tập hợp với 01 tập hợp khác
    int arr2[4] = {3,4,5,6};
    a3.Hop(arr2,4);
    a3.Giao(arr2,4);
    a3.Hieu(arr2,4);
    return 0;
}