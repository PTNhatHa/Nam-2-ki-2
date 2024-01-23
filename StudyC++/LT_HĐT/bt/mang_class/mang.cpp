#include "mang.h"
#include<iostream>
using namespace std;

mang::mang(int s)
{
    this->size=s;
    a=new int [size];
    for (int i = 0; i < s; i++) 
        a[i]=0;
}

mang::mang(int x[], int s)
{
    this->size=s;
    a=new int [size];
    for (int i = 0; i < size; i++) 
        a[i]=x[i];
}

mang::mang(const mang &x)
{
    this->size=x.size;
    a=new int [size];
    for (int i = 0; i < size; i++) 
        a[i] = x.a[i];
}

mang::~mang()
{
    delete [] a;
    //cout <<"Huy bo doi tuong"<<endl;
}

void mang::nhap()
{
    cout <<"Nhap size: ";
    cin >>size;

    cout <<"Nhap mang: " <<endl;
    for (int i = 0; i < size; i++)
    {
        cout <<"Phan tu thu " <<i <<": ";
        cin >>a[i];
    }
}

void mang::xuat() const
{
    int i;
    //cout <<"Mang da nhap: " <<endl;
    for (i = 0; i < size-1; i++)
        cout <<a[i] <<", ";
    cout <<a[i]<<endl;
}

int mang::kichthuoc() const
{
    return size;
}

int mang::laypt(int vt) const
{
    return (vt>=0 && vt<size) ? a[vt] : 0;
}

void mang::gan(int vt)
{
    if (vt>=0 && vt<size)
    {
        cout <<"Gan gia tri cho pt "<<vt<<": ";
        cin >>a[vt];
    }
    else cout <<"Vt nam ngoai kich thuoc cua mang"<<endl;
}

void mang::tim(int pt) const
{
    int i, kt=0;
    for (i = 0; i < size; i++)
    {
         if (a[i]==pt) 
            if (kt==0)
            {
                kt++;
                cout <<"Phan tu o vi tri: " <<i;
            }
            else cout <<"  " <<i;
    }
    cout <<endl;
    if (kt==0) cout <<"Khong co phan tu can tim" <<endl;
}
 /*
int mang::tim_nhiphan(int x) 
{
	int t,p,g;
	t=0; p=size-1;
	do
	{
		g=(t+p)/2;
		if (x<a[g]) p=g-1;
		else if (x>a[g]) t=g+1;
			else return g;
	}while (t<=p);
	return -1;
}
*/

void mang::sxt()
{
    int i,j;
    for (i = 0; i < size-1; i++)
    {
        int m=i;
        for (j = i; j < size; j++)
            if (a[m]>a[j]) m=j;
        swap(a[i],a[m]);
    }
}

void mang::sxg()
{
     int i,j;
    for (i = 0; i < size-1; i++)
    {
        int m=i;
        for (j = i; j < size; j++)
            if (a[m]<a[j]) m=j;
        swap(a[i],a[m]);
    }
}