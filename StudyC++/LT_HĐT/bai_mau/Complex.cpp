//Khai báo lớp Complex gồm R, I
//Định nghĩa các hàm dựng; toán tử >>, << để nhập, xuất 
//toán tử +, -, * ,/ 2 số phức
#include <iostream>
using namespace std;
class Complex {
    private:
        double R, I;
    public:
        Complex(double r = 0, double i= 0);
        friend ostream &operator <<(ostream &out, const Complex &c);
        friend istream &operator >>(istream &in, Complex &c);
        Complex operator + (const Complex &c);
        friend Complex operator - (const Complex &c1, const Complex &c2);
};
Complex::Complex(double r, double i){
    R = r;
    I = i;
}
ostream &operator <<(ostream &out, const Complex &c){
    out<<"("<<c.R<<","<<c.I<<")"<<endl;
    return out;
}
istream &operator >>(istream &in, Complex &c){
    cout<<"Phần thực: "; in>>c.R;
    cout<<"Phần ảo: "; in>>c.I;
    return in;
}
Complex Complex::operator + (const Complex &c){
    //Complex t(this->R + c.R,this->I + c.I);
    // t.R = this->R + c.R;
    // t.I = this->I + c.I;
    return  Complex(this->R + c.R,this->I + c.I);;
}
Complex operator - (const Complex &c1, const Complex &c2){
    return  Complex(c1.R - c2.R,c1.I - c2.I);
}
int main(){
    Complex c1, c2(3,5), c3(5);
    cout<<"Số phức c1:"; cout <<c1;
    cout<<"Số phức c2:"; cout <<c2;
    cout<<"Số phức c3:"; cout <<c3;
    Complex c4;
    cout<<"Nhập số phức c4:"<<endl; cin>>c4;
    cout<<"Số phức c4:"; cout <<c4;
    cout<<"Số phức c3+c4:"; cout <<c3+c4;
    cout<<"Số phức c2-c4:"; cout <<c2-c4;
}