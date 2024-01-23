#include <iostream>
using namespace std;
struct Date {
    int d, m, y;
};
istream &operator >>(istream &in, Date &x);
ostream &operator <<(ostream &out, const Date &x);
Date &operator ++(Date &x); //tien to
Date operator ++(Date &x, int);//hau to
int ncc(int m, int y){
    int sn[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30,31};
    if (y %4==0 && y%100!=0 || y%400 ==0) sn[2] = 29;
    return sn[m];
}
int main(){
    Date today;
    cout<<"Nhap ngay bat ky:"; cin>>today;
    cout<<"Ngay vua nhap:"<<today<<endl;
    cout<<"Ngay hom sau:"<<today++<<endl;  
    cout<<"Ngay hom sau:"<<today<<endl;    
    return 0;
}
istream &operator >>(istream &in, Date &x){
    cout<<"Nhap ngày:"; in>>x.d;
    cout<<"Nhap tháng:"; in>>x.m;
    cout<<"Nhap năm:"; in>>x.y;
    return in;
}
ostream &operator <<(ostream &out, const Date &x){
    out<<x.d<<"/"<<x.m<<"/"<<x.y;
    return out;
}
Date &operator ++(Date &x){
    if(x.d<ncc(x.m,x.y)) x.d+=1;
    else {
        x.d = 1;
        if (x.m<12) x.m += 1;
        else {
            x.m = 1;
            x.y +=1;
        } 
    }
    return x;
}
Date operator ++(Date &x, int){
    Date t = x;
    ++x;
    return t;
}