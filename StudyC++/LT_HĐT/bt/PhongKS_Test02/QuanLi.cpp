#include <iostream>
#include <string>
#include <stdlib.h>
#include "QuanLi.h"
using namespace std;

template<class T>
QuanLi<T>::QuanLi(int size)
{
    n=0;
    this->size=size;
}

template<class T>
QuanLi<T>::QuanLi(const QuanLi &l)
{
    this->n=l.n;
    this->size=l.size;

}

template<class T>
QuanLi<T>::~QuanLi()
{
}

template<class T>
bool QuanLi<T>::IsEmpty() const
{
    return (n==0);
}

template<class T>
bool QuanLi<T>::IsFull() const
{
    return (n==size);
}

template<typename T>
void QuanLi<T>::push(const T&)
{
    if (this->n < this->size) 
    {
        this->data[this->n] = i;
        this->n++;
    }
    else 
    {
        throw logic_error("Stack is full.");
    }
}

template<typename T>
void QuanLi<T>::pop()
{
    if (this->n > 0)
    {
        this->n--;
    }
    else 
    {
        throw logic_error("Stack is empty.");
    }
}

template<typename T>
T QuanLi<T>::top()
{
    return data[n - 1];
}

template<typename T>
istream &operator >> (istream &in, QuanLi<T> &x)
{

    cout<<"\nSo phong toi da: ";
    cin>>x.size;
    cout<<"\nSo luong phong muon nhap: ";
    cin>>x.n;
    for(int i=0;i<x.n;i++)
    {
        cout<<"\nPhong so "<<i+1<<": \n";
        Node<T> *node;
        cin>>*node;
        x.push(node);
    }
    return in;
}

template<typename T>
ostream &operator << (ostream &out, const QuanLi<T> &x)
{
    if (x.IsEmpty())
    {
        cout<<"\nDanh sach rong!!!\n";
        return out;
    }

    Node<T> *node;
    for(node=x.head; node!=NULL; node=node->get_next())
    {
        cout<<node;
    }
    return out;
}

template<typename T>
const QuanLi<T> &QuanLi<T>::operator = (const QuanLi<T> &x)
{
    if (this!=x)
    {
        this->n=x.n;
        this->size=x.size;
        QuanLi<T> l;
        Node<T> *node;
        for(node=x.head; node!=NULL; node=node->get_next())
        {
            l.push(node);
        }
        for(node=l.head; node!=NULL; node=node->get_next())
        {
            (*this).push(node);
        }
    }
    return *this;
}

template<typename T>
T &QuanLi<T>::operator [] (const int &vt) 
{
    return data[n - index - 1];
}

template<typename T>
void QuanLi<T>::update_sn(string mp)
{
    cout<<"\nCap nhat so nguoi toi da cua phong "<<mp<<endl;
    (this)[mp].edit_sn();
}

template<typename T>
void QuanLi<T>::update_tt(string mp)
{
    cout<<"\nCap nhat tinh trang phong "<<mp<<endl;
    (this)[mp].edit_tt();
}

template<typename T>
int QuanLi<T>::interpolation_search(string id)
{
    int *arr = new int [this->n];
    for (int i = 0; i < this->n; i++)
    {
        arr[i] = stoi(data[i].getIdRoom());
    }
    int idRoom = stoi(id);
    int low = 0, high = this->n - 1;
    while (low <= high && ((idRoom >= arr[low] && idRoom <= arr[high]) || (idRoom <= arr[low] && idRoom >= arr[high])))
    {
        if (low == high)
        {
            if (arr[low] == idRoom) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (idRoom - arr[low]));
        if (arr[pos] == idRoom)
            return pos;
        if ((arr[pos] < idRoom && idRoom <= arr[high]) || (arr[pos] > idRoom && idRoom >= arr[high]))
            low = pos + 1;
        else 
            high = pos - 1;
    }
}
/*
template<typename T>
bool QuanLi<T>::ascending(string bot, string top)
{
    int mpbot=stoi((this)[bot].getmp());
    int mptop=stoi((this)[top].getmp());
    return mpbot>mptop;
}

template<typename T>
bool QuanLi<T>::descending(string bot, string top)
{
    int mpbot=stoi((this)[bot].getmp());
    int mptop=stoi((this)[top].getmp());
    return mpbot<mptop;
}

template<typename T>
void QuanLi<T>::shell_sort(bool comfunc(string, string))
{
    int h,i,j;
    string mp;
    for(h=(n-1)/2;h>0;h/=2)
        for(i=h;i<n;i++)
        {
            mp=(this)[i].getmp();
            for(j=i;j>=h && comfunc((this)[j-h].getmp(),mp);j-=h) 
            {
                T tam=(this)[j];
                (this)[j]=(this)[j-h];
                (this)[j-h]=tam;
            }
        }
}
*/