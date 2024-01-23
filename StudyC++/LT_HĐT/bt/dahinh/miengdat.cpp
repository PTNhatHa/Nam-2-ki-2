#include <iostream>
#include <string>
using namespace std;

class miengdat
{
    protected:
        char maso[5];
        double dongia; //giá 1 m2
    public:
        virtual void nhap();
        virtual void xuat();
        virtual double dientich() = 0;
        virtual double gia() = 0;
};

void miengdat::nhap()
{
    cout<<"\nNhap ma so mieng dat: ";
    cin>>maso;
    cout<<"\nDon gia 1 met vuong: ";
    cin>>dongia;
}

void miengdat::xuat()
{
    cout<<"\nMa so mieng dat: "<<maso;
    cout<<"\nDon gia 1 met vuong: "<<dongia;
    cout<<"\nDien tich mieng dat: "<<(this)->dientich();
    cout<<"\nGia: "<<(this)->gia();
    cout<<endl;
}

class chunhat : public miengdat
{
    private:
        double dai;
        double rong;
    public:
        virtual void nhap();
        virtual double dientich();
        virtual double gia();
};

void chunhat::nhap()
{
    miengdat::nhap();
    cout<<"\nNhap chieu dai: ";
    cin>>dai;
    cout<<"\nNhap chieu rong: ";
    cin>>rong;
}

double chunhat::dientich()
{
    return dai*rong;
}

double chunhat::gia()
{
    return (this)->dientich()*dongia;
}

class thang : public miengdat
{
    private:
        double daylon, daynho;
        double chieucao;
    public:
        virtual void nhap();
        virtual double dientich();
        virtual double gia();
};

void thang::nhap()
{
    miengdat::nhap();
    cout<<"\nNhap day lon: ";
    cin>>daylon;
    cout<<"\nNhap day nho: ";
    cin>>daynho;
    cout<<"\nNhap chieu cao: ";
    cin>>chieucao;
}

double thang::dientich()
{
    return (daylon + daynho) * chieucao / 2;
}

double thang::gia()
{
    return (this)->dientich()*dongia*0.9;
}


class tamgiac : public miengdat
{
    private:
        double day;
        double chieucao;
    public:
        virtual void nhap();
        virtual double dientich();
        virtual double gia();
};

void tamgiac::nhap()
{
    miengdat::nhap();
    cout<<"\nNhap day: ";
    cin>>day;
    cout<<"\nNhap chieu cao: ";
    cin>>chieucao;
}

double tamgiac::dientich()
{
    return day * chieucao / 2;
}

double tamgiac::gia()
{
    return (this)->dientich()*dongia*0.9;
}

int main()
{
    miengdat *ds[50];
    int n=0, hd, i;
    double s=0,g=0;
    cout<<"\nSo luong mieng dat ban muon nhap: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nHinh dang cac mieng dat:\n";
        cout<<"1.Hinh chu nhat\n";
        cout<<"2.Hinh thang\n";
        cout<<"3.Hinh tam giac\n";
        cout<<"Chon thu tu hinh dang mieng dat ban muon nhap (1/2/3):";
        cin>>hd;
        if(hd==1) ds[i] = new chunhat;
        if(hd==2) ds[i] = new thang;
        if(hd==3) ds[i] = new tamgiac;
        ds[i]->nhap();
    }

    cout<<"\nDanh sach nhung mieng dat dang quan ly boi cong ty:\n";
    for (i=0;i<n;i++)
        ds[i]->xuat();
    
    cout<<"\nTong dien tich cac mieng dat: ";
    for(i=0;i<n;i++)
        s+=ds[i]->dientich();
    cout<<s;

    cout<<"\nTong gia tien cac mieng dat: ";
    for(i=0;i<n;i++)
        g+=ds[i]->gia();
    cout<<g;

    return 0;
}