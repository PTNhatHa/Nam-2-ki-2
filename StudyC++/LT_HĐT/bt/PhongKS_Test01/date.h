#ifndef date_h
#define date_h

class date
{
    private:
        int d, m, y;
    public:
        date();
        date(const date &x);
        void nhap();
        void xuat() const;
        int getd();
        int getm();
        int gety();

};
#endif