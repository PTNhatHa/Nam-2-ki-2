#ifndef mang_h
#define mang_h
#include<iostream>
using namespace std;

class mang
{
    private:
        int size;
        int *a; //mảng động nên kb con trỏ
    public:
        mang(int s=5); //giá trị mặc định chỉ đc kb 1 lần trong nguyên mẫu hàm
        mang(int *x, int s);
        mang(const mang &x); //tham chiếu hằng để đảm bảo x ko thay đổi
        ~mang(); //hàm hủy
        void nhap();
        void xuat() const; //ko thay đổi giá trị nên kb hàm hằng
        int kichthuoc() const;
        int laypt(int vt) const;
        void gan(int vt);
        void tim(int pt) const; 
        //int tim_nhiphan(int x);
        void sxt();
        void sxg();
};
#endif