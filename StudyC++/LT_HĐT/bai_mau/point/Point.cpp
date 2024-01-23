#include <iostream>
#include "Point.h"
using namespace std;
// Point::Point(){
//     x = y = 0;
// }
Point::Point(int xx, int yy){
    x = xx; y = yy;
}
Point::Point(const Point &p){
    x = p.x; y = 0;
}
void Point::SetPt(int x, int y){
    this->x = x; this->y = y;
}
 void Point::Display(){
    cout<<"("<<x<<","<<y<<")"<<endl;
 }
 Point::~Point(){
    cout<<"Huy bo doi tuong ("<<x<<","<<y<<")"<<endl;
 }