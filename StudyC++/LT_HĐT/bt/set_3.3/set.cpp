#include "set.h"
#include<iostream>
using namespace std;

set::set(int n)
{
    data = new int [n];
}

set::set(int a[], int n)
{
    data = new int [n];
    for (int i=0;i<n;i++)
        this->data[i]=a[i];
}

set::set(const set &x)
{
    data = new int [n];
    for (int i=0;i<n;i++)
        data[i]=x.data[i];
}

set::~set()
{
    delete [] data;
}

void set::xuat()
{
    int i;
    for(i=0;i<n-1;i++)
		    cout << data[i] <<", ";
        cout <<data[i]<<endl;
}

bool ascending(float left, float right)
{
	return left<right;
}

bool descending(float left, float right)
{
	return left>right;
}
 //sx chọn
void selection_sort(int *a, int n, bool CompFunc(float,float)) //con trỏ hàm comfund
{
	int i,j,m;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if (CompFunc(a[j],a[m])) m=j;
		swap(a[i],a[m]);
	}
}

/*
void set::add(int x)
{
    if(n<size && !(this->IsExisted(x)))
    {
        this->data[n] = x;
        n++;
        this->Sort(ascending);
        return;
    }
    else if (n==size) cout<<"\nSet is full.";
    else 
    {
        cout<<"\nPhan tu "<<x<<" bi trung.";
    }
}

void set::deletept(int pt)
{
   if(n==0)
    {
        cout<<"\nSet is null.";
        return;
    }
    // size = 5 | n = 2 | pos = 1
    n--; //n=1
    if(n==0)
    {
        data[0] = NULL;
        return;
    }
    if(pos==n)
    {
        data[pos] = NULL;
        return;
    }
    for(int i = pos; i<n; i++)
    {
        data[i] = data[i+1];
        if(i==n-1) data[n] = NULL;
    }
}

bool set::kt(int pt)
{
    int vt=tim_nhiphan(data,n,pt);
    if (vt==-1) return "khong";
    return "co";
}

void Set::Hop(int a[], int s)
{
    cout<<"\nHop : ";
    for(int i=0; i<n; i++)
    {
        cout<<data[i]<<" | ";
    }
    for(int i=0; i<s; i++)
    {
        if( !(this->IsExisted(a[i])) )
            cout<<a[i]<<" | ";
    }
    cout<<endl;
}

void Set::Giao(int a[], int s)
{
    cout<<"\nGiao : ";
    for(int i=0; i<s; i++)
    {
        if(this->IsExisted(a[i]))
            cout<<a[i]<<" | ";
    }
    cout<<endl;
}
void Set::Hieu(int a[], int s)
{
    cout<<"\nHop : ";
    Set set(a,s,s);
    for(int i=0; i<n; i++)
    {
        if( !(set.IsExisted(data[i])) )
            cout<<data[i]<<" | ";
    }
    cout<<endl;
}
*/