#include <iostream>
#include  "Point.h"
#include  "Point.cpp"

int main(){
    Point p1, p2(10,50), p3(p2);

    //p1.SetPt(10,20);
    p1.Display();

    //p2.SetPt(100,50);
    p2.Display();

    p3.Display();
    return 0;
}