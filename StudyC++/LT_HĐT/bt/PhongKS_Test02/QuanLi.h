#ifndef QuanLi_h
#define QuanLi_h
#include <iostream>
#include <string>
#include "Node.cpp"
using namespace std;

template<class T>
class QuanLi //Stack
{
    private:
        T data[size];
        int n; //so phong hien tai
        int size=100; //so phong toi da
    public:
        QuanLi(int size=10);
        QuanLi(const QuanLi &l);
        ~QuanLi();

        bool IsEmpty() const; //kiem tra rong
        bool IsFull() const; //kiem tra day

        void push(const T&); //them pt vao dau ds
        void pop(); //lay pt dau ra khoi ds va xoa
        T top(); //tra ve gia tri tren cung

        template<class U>
        friend istream &operator >> (istream &in, QuanLi<U> &x);
        template<class U>
        friend ostream &operator << (ostream &out, const QuanLi<U> &x);
        const QuanLi<T> &operator = (const QuanLi<T> &x);
        T &operator [] (const int &vt); 

        void update_sn(string mp); //cap nhat thong tin
        void update_tt(string mp);

        bool ascending(string left, string right);
        bool descending(string left, string right);
        int interpolation_search(string mp); //tim kiem
        void shell_sort(bool comfunc(string, string)); //sap xep

};
#endif