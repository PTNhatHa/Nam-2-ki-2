#include <iostream>
using namespace std;

class Point {
    protected:
        int x, y;
    public:
        Point(int a=0, int b= 0):x(a),y(b){}
        friend ostream &operator <<(ostream &out, const Point &p);
};
ostream &operator <<(ostream &out, const Point &p){
    out<<"Point("<<p.x<<","<<p.y<<")"<<endl;
    return out;
}
class Circle: public Point {
    double R;
    public:
        Circle(int = 0, int  = 0, double = 1);
        friend ostream &operator <<(ostream &out, const Circle &c);
        double Area() const { return 3.141592*R*R;}
};
Circle::Circle(int a, int  b, double r):Point(a,b), R(r){
}
ostream &operator <<(ostream &out, const Circle &c){
    out<<"Circle("<<c.x<<","<<c.y<<")R="<<c.R<<endl<<"Area: "<<c.Area()<<endl;
    return out;
}

void Display(Point p){
    cout<<p;
}
int main(){
    Point p(10,20), *pptr;
    Circle c(5,10,2), *cptr;
    cout<<"Point P:"<<p;
    cout<<"Circle C:"<<c;

    pptr = &p;
    cptr = &c;
    cout<<"Point p (via pptr): "<<*pptr;
    cout<<"Circle C (via cptr): "<<*cptr;

    pptr = cptr; //upcast
    cout<<"Circle C (via pptr): "<<*pptr;

    cptr = &c;
    pptr = cptr     ;
    cptr = (Circle*) pptr; //downcast
    cout<<"Point p (via cptr): "<<*cptr;

    return 0;
}