#ifndef phanso_h;
#define phanso_h;
#include<iostream>
using namespace std;

class phanso
{
    private:
        int tu;
        int mau;
    public:
        phanso(); //khởi tạo ps mặc đinh
        phanso(int t, int m);//khởi tạo với tử mẫu cho trc
        phanso(const int &x);//khởi tạo từ giá trị nguyên cho trc
        phanso(const phanso &x);//khởi tạo từ 1 phân số khác
        void nhap();
        void xuat();
        int laytu();
        int laymau();
        void gantu(int t);
        void ganmau(int m);
        void nghichdao();
        void rutgon();
        void sosanh(const phanso &x);

};

#endif