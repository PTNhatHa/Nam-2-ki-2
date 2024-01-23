//Cài đặt 01 lớp Vecto để biểu diễn 01 vecto trong 
//không gian n chiều gồm: n là số chiều của vecto
//và 01 mảng động chứa tọa độ của vecto
//Định nghĩa các hàm dựng, dựng sao chép, hủy
//các toán tử >>, <<
//toán tử +, -, * 02 vecto
// toán tử [], =
#include <iostream>
using namespace std;
class Vecto {
    int n;
    double *data;
    public:
        Vecto(int m = 3);
        Vecto(const Vecto &x);
        ~Vecto();
        
        friend istream &operator >>(istream &in, Vecto &a);
        friend ostream &operator <<(ostream &out, const Vecto &a);
        Vecto operator + (const Vecto &a);
        const Vecto &operator = (const Vecto &a);
        double &operator [] (int i) const;
};
Vecto::Vecto(int m):n(m){
    data = new double [n];
}
Vecto::Vecto(const Vecto &x){
    n = x.n;
    data = new double [n];
    for(int i=0; i<n; i++)
        data[i] = x.data[i];
}
Vecto::~Vecto(){
    delete [] data;
}
istream &operator >>(istream &in, Vecto &a){
    for(int i = 0; i<a.n; i++){
        cout<<"Tọa độ thứ "<<i<<":";
        in>>a.data[i];
    }
    return in;
}
ostream &operator <<(ostream &out, const Vecto &a){
    out<<"(";
    int i =0;
    for(;i<a.n-1;i++) out<<a.data[i]<<",";
    out<<a.data[i]<<")"<<endl;
    return out;
}
Vecto Vecto::operator + (const Vecto &a){
    Vecto t(this->n);
    for(int i=0; i<n; i++)
        t[i] = (*this)[i] + a[i];
    return t; 
}
const Vecto &Vecto::operator = (const Vecto &a){
    if (this!= &a) {
        delete [] data;
        n = a.n;
        data = new double [a.n];
        for(int i=0; i<n;i++) data[i] = a[i];//a.operator [](i)
    }
    return *this;
}
double &Vecto::operator [] (int i) const{
    return data[i];
}
int main(){
    Vecto a,b;
    cout<<"nhập tọa độ của vecto a:"<<endl;
    cin>>a;
    cout<<"nhập tọa độ của vecto b:"<<endl;
    cin>>b;
    cout<<"Vecto a vừa nhập:"<<a;
    cout<<"Vecto b vừa nhập:"<<b;
    cout<<"Vecto tổng a + b:"<<a+b;
    a = b;
    cout<<"nhập tọa độ của vecto a:"<<endl;
    cin>>a;
    cout<<"Vecto a :"<<a;
    cout<<"Vecto b :"<<b;
    return 0;
}