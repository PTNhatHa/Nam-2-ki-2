#include<iostream>
using namespace std;

class set
{
    private:
        int n; //số phần tử của tập hợp
        int *data; //mảng động chứa các phần tử của tập hợp
        int size; //kích thước tối đa của tập hợp
    public:
        set(int s=5); //Khởi tạo kích thước của tập hợp
        set(const int a[], int n, int size); //khởi tạo tập hợp từ 1 mảng
        set(const set &a); //khởi tạo từ 1 tập hợp khác
        ~set();

        int kt(int x) const;
        void operator + (int x); //thêm phần tử x vào tập hợp;
        void operator - (int x); //xóa phần tử x khỏi tập hợp;

        set operator + (const set &a); //hợp
        set operator - (const set &a); //hiệu
        set operator * (const set &a); //giao

        bool operator () (int x) const; //kiểm tra x có thuộc tập hợp ko
        int &operator [] (int x) const; //truy xuất 1 phần tử của tập hợp
        const set &operator = (const set &a); //gán
        friend ostream &operator << (ostream &out, const set &a);
};

set::set(int s)
{
    size=s;
    n=0;
    data = new int [size];
    for(int i=0; i<size; i++) 
        data[i]=0;
}

set::set(const int a[], int n, int size)
{
    this->size=size;
    data = new int [size];
    for(int i=0; i<n; i++) 
        data[i]=a[i];
    this->n=n;
}

set::set(const set &a)
{
    this->size=a.size;
    data = new int [size];
    for(int i=0; i<a.n; i++) 
        data[i]=a[i];
    this->n=a.n;
}

set::~set()
{
    delete [] data;
}

int set::kt(int x) const
{
    int i=0;
    while (i<n)
    {
        if (data[i]==x) return i;
        i++;
    }
    return -1;
}

void set::operator + (int x)
{
    if(n<size && (*this)(x)==false)
    {
        this->data[n] = x;
        n++;
        return;
    }
    else if (n==size) cout<<"\nTap hop da day!"<<endl;
    else 
        cout<<"\nPhan tu "<<x<<" bi trung."<<endl;
}

void set::operator - (int x)
{
    int i=0;
    int k=(*this).kt(x);
    if((*this)(x)==true)
    {
        for(int j=k;j<n;j++)
            data[j]=data[j+1];
        n--;
    }
    else cout<<"Pt khong co trong tap hop"<<endl;
}



set set::operator + (const set &a)
{
    int i,j;
    set t(this->size + a.size);
    for(i=0;i<this->n;i++)
        t[i]=data[i];
    for(j=0;j<a.n;j++)
    {
        if((*this)(a[j])==false)
        {
            t[i]=a[j];
            i++;
        }
    }
    t.n=i;
    return t;
}

set set::operator - (const set &a)
{
    int i,j,k=0;
    set t(this->size + a.size);
    for(i=0;i<(*this).n;i++)
    {

        if(a(data[i])==false)
        {
            t[k]=data[i];
            k++;
        }
    }
    t.n=k;
    return t;
}

set set::operator * (const set &a)
{
    int i,k=0;
    set t(this->size + a.size);
    for(i=0;i<a.n;i++)
    {
        if((*this)(a[i])==true)
        {
            t[k]=a[i];
            k++;
        }
    }
    t.n=k;
    return t;
}

bool set::operator () (int x) const
{
    if( (*this).kt(x)==-1 ) return false;
    else return true;
}

int &set::operator [] (int x) const
{
    return data[x];
}

const set &set::operator = (const set &a)
{
    if(this!=&a)
    {
        delete [] data;
        this->n = a.n;
        this->size = a.size;
        this->data = new int [a.size];
        for(int i=0;i<n;i++)
            data[i]=a[i];
    }
    return *this;
}

ostream &operator << (ostream &out, const set &a)
{
    int i;
    for(i=0;i<a.n-1;i++)
        cout<<a[i]<<", ";
    cout<<a[i]<<endl;
    return out;
}

int main()
{
    set a(5);
    cout<<"Tap hop a: "<<a<<endl;

    int x[5]={0,1,2,3,4};
    set b(x,5,10);
    cout<<"Tap hop b: "<<b<<endl;

    set c(b);
    cout<<"Tap hop c: "<<c<<endl;

    cout<<"Nhap phan tu muon them vao tap hop c: ";
    int pt;
    cin>>pt;
    c+pt;
    cout<<"Tap hop c sau khi them: "<<c<<endl;

    cout<<"Nhap phan tu muon xoa khoi tap hop c: ";
    int pt1;
    cin>>pt1;
    c-pt1;
    cout<<"Tap hop c sau khi xoa: "<<c<<endl;

    int y[6]={4,5,6,2,7,9};
    set d(y,6,10);
    cout<<"Tap hop d: "<<d<<endl;
    cout<<"Hop c va d: "<<c+d<<endl;
    cout<<"Hieu c va d: "<<c-d<<endl;
    cout<<"Giao c va d: "<<c*d<<endl;

    cout<<"Nhap phan tu muon tim trong tap hop d: ";
    int pt2;
    cin>>pt2;
    cout<<"Kiem tra "<<pt2<<" co thuoc tap hop d khong: ";
    if(d(pt2)==true) cout<<"Co"<<endl;
    else cout<<"Khong"<<endl;

    cout<<"Truy xuat den pt thu 2 cua tap hop d "<<d[2]<<endl;

    cout<<"Gan tap hop d cho tap hop a: "<<endl;
    a=d;
    cout<<"Tap hop a: "<<a<<endl;

    return 0;
}