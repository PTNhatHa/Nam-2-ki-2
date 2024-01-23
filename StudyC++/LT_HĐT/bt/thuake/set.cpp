#include <iostream>
#include "DSLK.cpp"
using namespace std;

class set : public dslk
{
    private:
        int size; //kích thu?c t?i da
        int n; //kích thu?c th?c t?
    public:
        set(int s=5); //Kh?i t?o kích thu?c c?a t?p h?p
        set(const int a[], int n, int size); //kh?i t?o t?p h?p t? 1 m?ng
        set(const set &a); //kh?i t?o t? 1 t?p h?p khác
        ~set();

        void display();
        void sort(bool compfunc(int,int));

        void operator + (int x); //thêm ph?n t? x vào t?p h?p;
        void operator - (int x); //xóa ph?n t? x kh?i t?p h?p;

        void operator + (const set &a); //h?p
        void operator - (const set &a); //hi?u
        void operator * (const set &a); //giao

        bool operator () (int x) const; //ki?m tra x có thu?c t?p h?p ko
        int operator [] (int x) const; //truy xu?t 1 ph?n t? c?a t?p h?p
        void operator = (const set &a); //gán
        friend ostream &operator << (ostream &out, const set &a);

};

set::set(int s)
{
    size=s;
}

set::set(const int a[], int n, int size)
{
    this->size=size;
    this->n=n;
    for(int i=0;i<n;i++)
        add_last(a[i]);
}

set::set(const set &a)
{
	
    this->size=a.size;
    this->n=a.n;
    for(int i=1;i<=n;i++)
        add_last(a.find_node(i)->get_data());
}

set::~set()
{
    cout<<"\nHuy thanh cong!!!\n";
}

void set::display()
{
    cout<<"\nSo phan tu toi da cua set: "<<this->size;
    cout<<"\nSo phan tu hien co cua set: "<<this->n;
    if(n==0) return;
    dslk::display();
    cout<<endl;
}

bool ascending(int left, int right)
{
    return left<right;
}

void set::sort(bool compfunc(int,int))
{
    int m,t;
    for(int i=1;i<n;i++)
    {
        m=i;
        for(int j=i+1;j<=n;j++)
            if(compfunc(find_node(j)->get_data(),find_node(m)->get_data()))
                m=j;
        t=find_node(m)->get_data();
        find_node(m)->set_data(find_node(i)->get_data());
        find_node(i)->set_data(t);
    }
}

void set::operator + (int x)
{
    if(n<size && (*this)(x)==false)
    {
        add_last(x);
        this->sort(ascending);
        n++;
        return;
    }
    else if (n==size) cout<<"\nTap hop da day!"<<endl;
    else 
        cout<<"\nPhan tu "<<x<<" bi trung."<<endl;
}

void set::operator - (int x)
{
    int k=search(x);
    if(k!=-1)
    {
       node *n=find_node(k);
       (k==0)?delete_first():delete_after(n);
       this->n--;
       return;
    }
    if(n==0)
    {
        cout<<"\nSet rong!!!\n";
        return;
    }
    else cout<<"Pt khong co trong tap hop"<<endl;
}



void set::operator + (const set &a)
{
    int i;
    for(i=0;i<this->n;i++)
        cout<<(*this)[i+1]<<"  ";
    for(i=0;i<a.n;i++)
        if((*this)(a[i+1])==false)
            cout<<a[i+1]<<"  ";
    cout<<endl;
}

void set::operator - (const set &a)
{
    int i;
    for(i=0;i<(*this).n;i++)
        if(a((*this)[i+1])==false)
            cout<<(*this)[i+1]<<"  ";
    cout<<endl;
}

void set::operator * (const set &a)
{
    int i;
    for(i=0;i<a.n;i++)
        if((*this)(a[i+1])==true)
            cout<<a[i+1]<<"  ";
    cout<<endl;
}

bool set::operator () (int x) const
{
    int k=search(x);
    return (k==-1) ? false:true;
}

int set::operator [] (int x) const
{
    return find_node(x)->get_data();
}

void set::operator = (const set &a)
{
    if(this!=&a)
    {
        while ((this)->head !=NULL)
        {
            delete_first();
        }
        this->n = a.n;
        this->size = a.size;
        for(int i=1;i<=n;i++)
            add_last(a[i]);
        return;
    }
    cout<<"\nGan that bai!!!\n";
}

ostream &operator << (ostream &out, const set &a)
{
    int i;
    cout<<"\nSo phan tu toi da cua set: "<<a.size;
    cout<<"\nSo phan tu hien co cua set: "<<a.n<<endl;
    if(a.n==0) return out;
    for(i=0;i<a.n-1;i++)
    	cout<<a[i+1]<<", ";
    cout<<a[i+1]<<endl;
    return out;
}