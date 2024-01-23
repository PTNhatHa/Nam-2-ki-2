#include<iostream>
using namespace std;

/*
class Exam
{
	int prop;
	public:
		Exam(int = 1);
        int operator,(int);
};
Exam::Exam(int prop)
        : prop(prop)
{
}
int Exam::operator,(int prop)
{
    return prop;
}
int main()
{
    Exam obj;
    int var_i = 2;
    cout << obj.operator,(var_i);
    return 0; 
}//2


class Exam
{
    //int prop=10;
    static int count;
    public:
        //int operator ->();
        Exam();
        ~Exam();
        void Func();
        friend ostream& operator << (ostream&, const Exam&);
};
int Exam::operator->()
{
    return prop;
}
int Exam::count = 0;
Exam::Exam()
{
    Exam::count++;
}
Exam::~Exam()
{
    Exam::count--;
}
void Exam::Func()
{
    cout<<Exam::count;
}
ostream& operator<<(ostream& o, const Exam& obj)
{
    o << obj.count;
    return o;
}
int main()
{
    Exam obj_x, obj_y;
    Exam obj_z;
    cout<<obj_x<<obj_y<<obj_z;
    return 0;
}


void Show(int x)
{ 
    cout<<x;
}

void Show(double x)
{
    cout<<x;
}
int main(void)
{
    Show(5);
    Show(500.263);
    system("pause");
    return 0;
}


class Base
{
    int x;
    public:
        Base(int =1);
        friend ostream& operator << (Base&, ostream &);
};
Base::Base(int x) : x(x) {}
ostream& operator << (Base& obj, ostream &o)
{
    o<<obj.x;
    return o;
}
int main()
{
    Base obj1(2), obj2;
    obj1 << (obj2 << cout);
    system("pause");
    return 0;
}

class Base
{
    double R, I;
    public:
        Base ();
        Base operator()(double, double);
        Base operator()(double);
        friend ostream& operator<<(ostream&, const Base&);
};

Base::Base() : R(0), I(0) {}
Base Base::operator()(double R, double I)
{
    this->R+=R;
    this->I+=I;
    return *this;
}
Base Base::operator()(double R)
{
    this->R+=R;
    return *this;
}

ostream& operator << (ostream& o, const Base& obj)
{
    o<<"Base("<<obj.R<<", "<<obj.I<<"). ";
    return o;
}
int main()
{
    Base obj1, obj2;
    obj2 = obj1(3.2, 5.3) ;
    obj1(6.5, 2.7) ;
    obj2(1.9);
    cout << obj1 << obj2;
    system ("pause") ;
    return 0;
}

class Exam
{
	int prop;
	public:
		Exam();
        Exam(double);
        ~Exam();
};
Exam::Exam(){}
Exam::Exam(double prop)
        : prop(prop)
{}
Exam::~Exam(){}
int main()
{
    Exam obj_x(10);
    Exam obj_y = Exam(14);
    (obj_x == obj_y) ? cout<<"Equal" : cout<<"Not Equal";
    return 0; 
}

class Base
{
    int x;
    public:
        Base(int =1);
        friend ostream& operator << (Base&, ostream &);
};
Base::Base(int x) : x(x) {}
ostream& operator << (Base& obj, ostream &o)
{
    o<<obj.x;
    return o;
}
int main()
{
    Base obj1(2);
    obj1 << cout;
    system("pause");
    return 0;
}

class Base
{
    double R, I;
    public:
        Base (double, double);
        Base (double);
        friend Base operator + (Base, Base);
        friend ostream& operator<<(ostream&, const Base&);
};

Base::Base(double R, double I) : R(R), I(I) {}
Base::Base(double R)
{
    this->R=this->I=R;

}
Base operator + (Base obj1, Base obj2)
{
    return Base(obj1.R + obj2.R, obj1.I + obj2.I);
}

ostream& operator << (ostream& o, const Base& obj)
{
    o<<obj.R<<", "<<obj.I;
    return o;
}
int main()
{
    Base obj1(3,4);
    Base obj2 = obj1 + 6;
    cout <<obj2;
    system ("pause") ;
    return 0;
}


class Base
{
    private:
        void* operator new(size_t size) {}
        void* operator new[](size_t size) {}
};
int main()
{
    Base* ptr1; //ko thể truy cập
    Base *ptr2 = new Base[10];
    system("pause");
    return 0;

}

class Base
{
    int x;
    public:
        Base (int=0);
        Base operator + (int);
        friend ostream& operator<<(ostream&, Base);
};
Base::Base(int x):x(x){}
Base Base::operator+(int x)
{
    Base obj;
    obj.x=this->x + x;
    return obj;
}

ostream& operator<<(ostream& o, Base obj)
{
    o << obj.x;
    return o;
}
int main()
{
    Base obj1(1), obj2;
    obj2 = obj1 + 2;
    cout<<obj2;
    system("pause");
    return 0;
}

class Exam
{
    int prop_x, prop_y, prop_z;
    public:
    Exam (int= 0, int = 0, int = 0) ;
    Exam operator () (Exam) ;
    Exam operator () (int, int, int);
    friend ostream& operator<<(ostream&, const Exam&);
};

Exam:: Exam(int prop_x, int prop_y, int prop_z)
: prop_x(prop_x), prop_y (prop_y) , prop_z (prop_z)
{}


Exam Exam::operator () (Exam obj)
{
    return Exam((this->prop_x + obj.prop_x) / 2,(this->prop_y + obj.prop_y) / 2,(this->prop_z + obj.prop_z) / 2);
}

Exam Exam::operator () (int prop_x, int prop_y, int prop_z)
{
    return Exam(this->prop_x + prop_x, this->prop_y + prop_y, this->prop_z + prop_z) ;
}

ostream& operator<<(ostream& o, const Exam& obj)
{
    o << obj.prop_x << obj.prop_y << obj.prop_z;
    return o;
}
int main()
{
    Exam obj_x(1, 2, 3), obj_y(10, 10, 10), obj_z;
    obj_z = obj_x(obj_y(100, 200, 300));
    cout << obj_z;
    return 0;
}

class Exam
{
	int prop;
	public:
		Exam();
        Exam(int);
        Exam(const Exam&);
        friend ostream& operator<<(ostream&, const Exam);
};
Exam::Exam(){}
Exam::Exam(int prop)
        : prop(prop)
{}
Exam::Exam(const Exam& obj)
{
    this->prop = obj.prop;
}
ostream& operator<<(ostream& o, const Exam obj)
{
    o << obj.prop;
    return o;
}

int main()
{
    Exam obj1(1);
    Exam obj2 = obj1;
    cout<<obj2;
    return 0; 
}


int main()
{
    int x=-1;
    char *p;
    p = new char[256];
    try
    {
        // if (p == NULL)
        // {
        //     throw "p is null";
        // }        
        if (x<0)
        {
            throw x;
        }

    }
    catch(...)
    {
        cout << "Exception...: exiting";
    }
    return 0;
    
}


template <class T>
inline T func(T x)
{
    T r=x*x;
    return r;
};
template <>
string func<string>(string s)
{
    return (s+s);
};
int main()
{
    int x=4, y;
    string s("A");
    y=func<int>(x);
    cout<<x<<y;
    cout<<func<string>(s);
    return 0;
}


template<class T>
class exam
{
    T prop;
    public:
        exam();
        ~exam();
        // static int count;
};
// template<class T>
// int exam<T>::count = 0;
template<class T>
exam<T>::exam()
{
    // exam<T>::count++;
}
template<class T>
exam<T>::~exam()
{}
int main()
{
    exam<char> x;
    exam<int> y;
    exam<double> z;
    // cout << exam<int>::count << exam<double>::count;
    cout << sizeof(x) << sizeof(y) << sizeof(z);
    return 0;
}


int main()
{
    try
    {
        try
        {
            throw 20;
        }
        catch(char e)
        {
            cout<<"inner\n";
        }
        
    }
    catch(int e)
    {
        cout<<"outner\n";
    }
    return 0;
}


int main()
{
    char* p;
    try
    {
        p=new char[1024];
        if (p==0)
        {
            throw "error";
        }
        else
            cout << sizeof(p);
        
    }
    catch(char* e)
    {
        cout <<e;
    }
    return 0;
}


struct a
{
    int count;
};
struct b
{
    int* value;
};
struct c : public a, public b
{
};
int main()
{
    c* p = new c;
    p->value=0;
    cout<<"DUT";
    system("pause");
    return 0;
}

using namespace std;
class Base
{
    public:
    virtual void Func();
};
void Base::Func()
{    cout << "B";
}

class Derived : public Base
{
    int prop;
    public:
    void Func();
    Derived();
    int getProp() const;
};
void Derived::Func()
{
    cout << "D":
}
Derived::Derived()
{
    this->prop= 10;
}
int Derived::getProp() const
{return this->prop;}
int main()
{
    Derived obj_d;
    Base* ptr = &obj_d;
    ptr->Func();
    //cout << ptr->getProp():
    return 0;
}

#include<exception>
using namespace std;
void FuncExp()
{
    cout << "Exception:";
    throw;
}
void Func() throw (int, bad_exception)
{
    throw 'x';
}

int main(void)
{
    set_unexpected (FuncExp);
    try
    {
        Func();
    }
    catch (int)
    {
        cout << "int";
    }
    catch (bad_exception be)
    {    
        cout<< "bad exception";
    }
    catch (...)
    {
        cout << "other exception";
    }
    return 0;
}


template<class T>
class Exam
{
    public:
    Exam Func (const T&, const T&);
};
template<class T>
Exam<T> Exam<T>:: Func(const T& x, const T& y)
{
    return var x / var y;
}
int main()
{
    Exam<int> obj;
    cout<<obj;
    cout << obj. Func(3, 2)<< obj. Func (3.0, 2.0) ;
    return 0;
}


template<int n>
struct exam
{
    static const int p = 2 * exam<n-1>::p;
};
template<>
struct exam<0>
{
    static const int p = 1;
};
int main()
{
    cout << exam<10>::p;
    return 0;
}
*/

class B
{
    int p;
    public:
        virtual void func() = 0;
};
class D : public B
{
    public:
        void func();
};
void D::func()
{
    cout<<"ITF";
}
int main()
{
    B obj;
    obj.func();
    return 0;
}