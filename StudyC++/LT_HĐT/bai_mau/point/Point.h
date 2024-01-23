#ifndef Point_h
#define Point_h
class  Point {
        int x, y;
    public:
        // Point(); //default constructor
        Point(const Point &p);
        Point(int = 0, int = 0);
        void SetPt(int, int);
        void Display();
        ~Point();
};
#endif
