#include <iostream>
using namespace std;
template <typename T>
class Matrix
{
    private:
        int n;
        T **data;
    public:
        Matrix(int m=3, T a=0);
        Matrix(const Matrix &x);
        ~Matrix();

        Matrix operator + (const Matrix &x);
        Matrix operator - (const Matrix &x);
        Matrix operator * (const Matrix &x);
        T &operator () (int h, int c) const;

        const Matrix &operator = (const Matrix &x);
        template <typename U>
        friend istream &operator >> (istream &in, Matrix<U> &x); //chỉ là hàm friend nên ko đc dùng lại T
        template <typename U>
        friend ostream &operator << (ostream &out, const Matrix<U> &x); //chỉ là hàm friend nên ko đc dùng lại T

};

template <typename T>
Matrix<T>::Matrix(int m, T a)
{
    int i,j;
    n=m;
    data = new T *[n];
    for (i=0;i<n;i++)
        data[i] = new T [n];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            data[i][j]=a;
}

template <typename T>
Matrix<T>::Matrix(const Matrix &x)
{
    int i,j,n;
    n=x.n;
    this->n=x.n;
    data = new T *[n];
    for (i=0;i<n;i++)
        data[i] = new T [n];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            data[i][j]=x(i,j);
}

template <typename T>
Matrix<T>::~Matrix()
{
    for (int i=0;i<n;i++) delete data[i];
    delete data;
}

template <typename T>
T &Matrix<T>::operator () (int h, int c) const
{
    return data[h][c];
}

template <typename T>
Matrix<T> Matrix<T>::operator + (const Matrix<T> &x)
{
    Matrix<T> t(this->n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            t(i,j) = (*this)(i,j) + x(i,j);
    return t; 
}

template <typename T>
Matrix<T> Matrix<T>::operator - (const Matrix<T> &x)
{
    Matrix<T> t(this->n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            t(i,j) = (*this)(i,j) - x(i,j);
    return t; 
}

template <typename T>
Matrix<T> Matrix<T>::operator * (const Matrix<T> &x)
{
    Matrix<T> c(this->n);
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

template <typename T>
const Matrix<T> &Matrix<T>::operator = (const Matrix<T> &x)
{
   if (this!= &x) 
   {
        int i,j;
        delete [] data;
        n = x.n;
        data=new T *[n];
        for(i=0; i<n; i++)
            data[i]=new T [n];
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                data[i][j]=x(i,j);
    }
    return *this;
}

template <typename T>
istream &operator >> (istream &in, Matrix<T> &x) //Matrix phụ thuộc vào kiểu T nên phải dùng <T>
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

template <typename T>
ostream &operator << (ostream &out, const Matrix<T> &x) //Matrix phụ thuộc vào kiểu T nên phải dùng <T>
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
    Matrix<float> a(3,1.5);
    cout<<"Ma tran a: "<<endl <<a<<endl;

    //hàm dựng sao chép
    Matrix<float> b(a);
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
    Matrix<float> c;
    c=a;
    cout<<"Ma tran c: "<<endl <<c <<endl;

    return 0;
}