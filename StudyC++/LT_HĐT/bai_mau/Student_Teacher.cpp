#include <iostream>
#include <iomanip>
using namespace std;
class Nguoi {
    char hoten[50];
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual bool XetPT() = 0; //thuần ảo
};

void Nguoi::Nhap(){
    cout<<"Nhập họ tên:";
    cin>>hoten;
}
void Nguoi::Xuat(){
    cout<<setw(30)<<hoten;
}
class SV : public Nguoi {
    double dtb;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual bool XetPT();
};
void SV::Nhap(){
    Nguoi::Nhap();
    cout<<"Nhập điểm trung bình:"; cin>>dtb;
}
void SV::Xuat(){
    cout<<"Sinh viên:  "; 
    Nguoi::Xuat();
    cout<<setw(10)<<dtb<<endl;
}
bool SV::XetPT(){
    return (dtb>=8.0);
}
class GV: public Nguoi {
        int sbb;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual bool XetPT();
};

void GV::Nhap(){
    Nguoi::Nhap();
    cout<<"Nhập  bài báo:"; cin>>sbb;
}
void GV::Xuat(){
    cout<<"Giảng viên: "; 
    Nguoi::Xuat();
    cout<<setw(10)<<sbb<<endl;
}
bool GV::XetPT(){
    return (sbb>=3);
}
int main(){
    Nguoi *DS[100];
    int n = 0;
    char ch, tl;
    do {  
        cout<<"Bạn muốn nhập Sinh viên hay Giảng viên?(S/G)";
        cin>>tl;
        //tl = toupper(tl);
        if (tl == 'S' || tl =='s')
            DS[n] = new SV;
        else 
            DS[n] = new GV;
        DS[n++]->Nhap();
        cout<<"Bạn có muốn nhập nữa không?(C/K)";
        cin>>ch;
        ch = toupper(ch);
        if (ch == 'K') break;
    } while (1);
    cout<<"Danh sách được khen thưởng:"<<endl;
    for(int i=0; i<n; i++)
        if (DS[i]->XetPT())
            DS[i]->Xuat();
}