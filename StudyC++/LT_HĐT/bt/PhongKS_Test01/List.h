#ifndef List_h
#define List_h
#include <iostream>
#include <string>
#include "Phongks.cpp"
using namespace std;

class list
{
    private:
        phongks *data;
        int size, n;
    public:
        list(int size=10);
        list(const list &l);
        ~list();
        phongks &operator [] (int vt) const;
        friend istream &operator >> (istream &in, list &x);
        friend ostream &operator << (ostream &out, const list &x);
       
        void addf(phongks ks); //thêm đối tượng vào vị trí vt
        void addl(phongks ks);
        void add(int vt, phongks ks);

        void update_sn(int pt); //cập nhật thông tin đối tượng
        void update_tt(int pt);
        void update_gia(int pt);

        void delf(); //xóa đối tượng tại vị trí vt
        void dell();
        void del(int vt);

        int interpolation_search(double x); //tìm kiếm theo giá phòng
        void shell_sort(bool comfunc(double, double)); //sắp xếp theo giá phòng

};
#endif