#include <iostream>
#include "set.cpp"
using namespace std;

int main()
{
    set a(5);
    cout<<"Tap hop a: "<<a<<endl;

    int x[5]={0,1,2,3,4};
    set b(x,5,10);
    cout<<"Tap hop b: "<<b<<endl;
	
    set c(b);
    cout<<"Tap hop c: "<<c<<endl;

    cout<<"Nhap phan tu muon them vao tap hop c: ";
    int pt;
    cin>>pt;
    c+pt;
    cout<<"Tap hop c sau khi them: "<<c<<endl;

    cout<<"Nhap phan tu muon xoa khoi tap hop c: ";
    int pt1;
    cin>>pt1;
    c-pt1;
    cout<<"Tap hop c sau khi xoa: "<<c<<endl;

    int y[6]={4,5,6,2,7,9};
    set d(y,6,10);
    cout<<"Tap hop d: "<<d<<endl;
    cout<<"Hop c va d: ";
	c+d;
	cout<<endl;
    cout<<"Hieu c va d: ";
	c-d;
	cout<<endl;
    cout<<"Giao c va d: ";
	c*d;
	cout<<endl;

    cout<<"Nhap phan tu muon tim trong tap hop d: ";
    int pt2;
    cin>>pt2;
    cout<<"Kiem tra "<<pt2<<" co thuoc tap hop d khong: ";
    if(d(pt2)==true) cout<<"Co"<<endl;
    else cout<<"Khong"<<endl;

    cout<<"\nTruy xuat den pt thu 2 cua tap hop d "<<d[2]<<endl;

    cout<<"\nGan tap hop d cho tap hop a: "<<endl;
    a=d;
    cout<<"Tap hop a: "<<a<<endl;

    return 0;
}