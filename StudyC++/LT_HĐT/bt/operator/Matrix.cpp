#include <iostream>
using namespace std;
class Matrix
{
    private:
        int n;
        int **data;
    public:
        Matrix(int m=3, int a=0);
        Matrix(const Matrix &x);
        ~Matrix();

        Matrix operator + (const Matrix &x);
        Matrix operator - (const Matrix &x);
        Matrix operator * (const Matrix &x);
        int &operator () (int h, int c) const;

        const Matrix &operator = (const Matrix &x);
        friend istream &operator >> (istream &in, Matrix &x);
        friend ostream &operator << (ostream &out, const Matrix &x);


};

Matrix::Matrix(int m, int a)
{
    int i,j;
    n=m;
    data = new int *[n];
    for (i=0;i<n;i++)
        data[i] = new int [n];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            data[i][j]=a;
}

Matrix::Matrix(const Matrix &x)
{
    int i,j,n;
    n=x.n;
    this->n=x.n;
    data = new int *[n];
    for (i=0;i<n;i++)
        data[i] = new int [n];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            data[i][j]=x(i,j);
}

Matrix::~Matrix()
{
    for (int i=0;i<n;i++) delete data[i];
    delete data;
}

int &Matrix::operator () (int h, int c) const
{
    return data[h][c];
}

Matrix Matrix::operator + (const Matrix &x)
{
    Matrix t(this->n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            t(i,j) = (*this)(i,j) + x(i,j);
    return t; 
}

Matrix Matrix::operator - (const Matrix &x)
{
    Matrix t(this->n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            t(i,j) = (*this)(i,j) - x(i,j);
    return t; 
}

Matrix Matrix::operator * (const Matrix &x)
{
    Matrix c(this->n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int t=0;
            for (int k=0; k<n; k++)
                t+=(*this)(i,k)*x(k,j);
            c(i,j)=t;
        }
    return c;
}

const Matrix &Matrix::operator = (const Matrix &x)
{
   if (this!= &x) 
   {
        int i,j;
        delete [] data;
        n = x.n;
        data=new int*[n];
        for(i=0; i<n; i++)
            data[i]=new int [n];
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                data[i][j]=x(i,j);
    }
    return *this;
}

istream &operator >> (istream &in, Matrix &x)
{
    int i,j;
    for (i=0;i<x.n;i++)
        for (j=0;j<x.n;j++)
        {
            cout << "data(" <<i<<","<<j<<")= ";
            cin >> x(i,j);
        }
    return in;
}

ostream &operator << (ostream &out, const Matrix &x)
{
    int i,j;
    for (i=0;i<x.n;i++)
    {
        for (j=0;j<x.n;j++)
            cout << x(i,j) <<"  ";
        cout <<endl;
    }
    return out;
}

int main()
{
    //Hàm dựng mặc định
    Matrix a(3,1);
    cout<<"Ma tran a: "<<endl <<a<<endl;

    //hàm dựng sao chép
    Matrix b(a);
    cout<<"Ma tran b: "<<endl <<b<<endl;

    //operator >> <<
    cout<<"Nhap ma tran vuong b: " <<endl;
    cin>>b;
    cout<<"Ma tran b: "<<endl <<b<<endl;

    //operator + - *
    cout<<"Tong 2 ma tran a + b : "<<endl <<a+b <<endl;
    cout<<"Hieu 2 ma tran a - b : "<<endl <<a-b <<endl;
    cout<<"Tich 2 ma tran a * b : "<<endl <<a*b <<endl;

    //operator =
    Matrix c;
    c=a;
    cout<<"Ma tran c: "<<endl <<c <<endl;

    return 0;
}