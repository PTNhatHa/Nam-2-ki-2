#ifndef get_h;
#define get_h;
#include<iostream>
using namespace std;

class set
{
    private:
        int *data;
        int size;
        int n;
    public:
        set(int n);
        set(int array[], int n);
        set(const set &x);
        ~set();
        void xuat();
        void add(int pt);
        void deletept(int pt);
        bool kt(int pt);
        void Hop(int a[], int s);
        void Giao(int a[], int s);
        void Hieu(int a[], int s);

};

#endif