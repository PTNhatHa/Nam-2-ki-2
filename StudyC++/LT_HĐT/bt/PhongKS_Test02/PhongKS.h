#ifndef PhongKS_h
#define PhongKS_h
#include <iostream>
#include <string>
#include <iomanip>
#include "Date.cpp"
using namespace std;

class PhongKS
{
    protected:
        string mp; //mã phòng
        string name;
        int sn; //số người tối đa
        bool tt; //tình trạng
        Date nn; //ngày nhận phòng
        Date nt; //ngày trả phòng
        double gia; //giá phòng
    public:
        PhongKS();
        //PhongKS(string mp, int sn, bool tt, Date nn, Date nt, double gia);
        PhongKS(const PhongKS &x);
        
        void setmp(string);
        void setName(string);
        void setsn(int);
        void settt(bool); // true = available
        void setnn(Date);
        void setnt(Date);
        virtual void setgia() =0;
        void setgia(double);
        
        string getmp() const;
        string getName() const;
        int getsn() const;
        bool gettt() const;
        Date getnn() const;
        Date getnt() const;
        double getgia() const;

        const PhongKS& operator = (const PhongKS&);
        // So sanh theo ID phong
        friend bool operator == (const PhongKS&, const PhongKS&);
        friend bool operator < (const PhongKS&, const PhongKS&);
        friend bool operator > (const PhongKS&, const PhongKS&);
        friend istream& operator >> (istream& in, PhongKS&);
        friend ostream& operator << (ostream& out, PhongKS&);
};

//-------------------------------------------------------------------------------------------------------------


class PhongVIP : public PhongKS
{
protected:
    double costPerPerson;
    double surcharge;
public:
    PhongVIP();
    ~PhongVIP();
    PhongVIP(const PhongVIP&);
    void setCostPerPerson();
    double getCostPerPerson() const;
    void setCostPerPerson(double);

    void setSurcharge();
    void setgia();
    const PhongVIP& operator = (const PhongVIP&);

};

//-------------------------------------------------------------------------------------------------------------

class PhongBT : public PhongKS
{
protected:
    double costPerPerson;
public:
    PhongBT();
    ~PhongBT();
    PhongBT(const PhongBT&);
    void setCostPerPerson();
    void setCostPerPerson(double);

    double getCostPerPerson() const;
    void setgia();
    const PhongBT& operator = (const PhongBT&);

};
#endif