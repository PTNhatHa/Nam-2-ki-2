#include <iostream>
#include <string>
#include "List.h"
using namespace std;

list::list(int size)
{
    n=0;
    this->size=size;
    data= new phongks[size];
}

list::list(const list &l)
{
    this->n=l.n;
    this->size=l.size;
    data= new phongks[size];
    for(int i=0;i<n;i++)
        data[i]=l[i];
}

list::~list()
{
    delete [] data;
}

phongks &list::operator [] (int vt) const
{
    return data[vt];
}

istream &operator >> (istream &in, list &x)
{
    cout<<"\nSo phong toi da: ";
    cin>>x.size;
    cout<<"\nSo luong phong muon nhap: ";
    cin>>x.n;
    for(int i=0;i<x.n;i++)
    {
        cout<<"\nPhong so "<<i+1<<": \n";
        cin>>x[i];
    }
    return in;
}

ostream &operator << (ostream &out, const list &x)
{
    for(int i=0;i<x.n;i++)
    {
        cout<<"\n\nPhong so "<<i+1<<": \n";
        cout<<x[i];
    }
    return out;
}

void list::addf(phongks ks)
{
    int i;
    if(n<size) 
    {
        for(i=n;i>0;i--)
            data[i]=data[i-1];
        data[0]=ks;
        n++;
    }
    else cout<<"\nList đa đay\n";
}

void list::addl(phongks ks)
{
    int i;
    if(n<size) 
    {
        data[n]=ks;
        n++;
    }
    else cout<<"\nList đa đay\n";
}
void list::add(int vt, phongks ks)
{
    int i;
    if(n<size) 
    {
        if(vt>0&&vt<n)
        {
            for(i=n;i>vt;i--)
                data[i]=data[i-1];
            data[vt]=ks;
            n++;
        }
        else cout<<vt<<" > size!!!\n";
    }
    else cout<<"\nList đa đay\n";
}

void list::update_sn(int pt)
{
    cout<<"\nCap nhat so nguoi toi da cua phong "<<data[pt].getmp();
    
    data[pt].edit_sn();
}

void list::update_tt(int pt)
{
    cout<<"\nCap nhat tinh trang phong "<<data[pt].getmp();
    data[pt].edit_tt();
}

void list::update_gia(int pt)
{
    cout<<"\nCap nhat gia phong "<<data[pt].getmp();
    data[pt].edit_gia();
}

void list::delf()
{
    int i;
    for(i=0;i<n-1;i++)
        data[i]=data[i+1];
    n--;
}

void list::dell()
{
    n--;
}

void list::del(int vt)
{
    int i;
    for(i=vt;i<n-1;i++)
        data[i]=data[i+1];
    n--;
}

int list::interpolation_search(double x)
{
    int left=0;
    int right=n-1;
    while (left<=right && x>=data[left].getgia() && x<=data[right].getgia())
    {
        double pt1=(double) (x-data[left].getgia()) / (data[right].getgia() - data[left].getgia());
        int pt2=(right-left);
        int pt=left + pt1*pt2;

        if(data[pt].getgia()==x)
            return pt;
        if(data[pt].getgia()<x)
            left=pt+1;
        else
            right=pt-1;
    }
    return -1;
}

bool ascending(double left, double right)
{
    return left>right;
}

bool descending(double left, double right)
{
    return left<right;
}

void list::shell_sort(bool comfunc(double, double))
{
    int h,i,j;
    double t;
    for(h=(n-1)/2;h>0;h/=2)
        for(i=h;i<n;i++)
        {
            t=data[i].getgia();
            for(j=i;j>=h && comfunc(data[j-h].getgia(),t);j-=h) 
            {
                phongks tam=data[j];
                data[j]=data[j-h];
                data[j-h]=tam;
            }
        }
}