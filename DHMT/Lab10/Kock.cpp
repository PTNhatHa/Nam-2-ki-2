//#include <cmath>
//#include <vector>
//#include <windows.h>
//#include <gl/glut.h>
// 
//using namespace std;
// 
//#define eps 0.00001
//#define WINDOW_WIDTH 500.0
//#define WINDOW_HEIGHT 500.0
//#define pi (2*acos(0.0))
// 
//#define MAX_VAL 9999999
//#define MIN_VAL -9999999
// 
//class Point
//{
//public:
//     double x,y,z;
// 
//     Point(){
//     }
//     Point(double a, double b, double c){
//        x = a;
//        y = b;
//        z = c;
//     }
//     ~Point(){}
//     double dot(Point v){
//        return x*v.x + y*v.y + z*v.z;
//     }
//     Point operator+(Point pt) {
//        return Point(x + pt.x, y + pt.y, z + pt.z);
//    }
//    Point operator-(Point pt) {
//        return Point(x - pt.x, y - pt.y, z - pt.z);
//    }
//    Point operator*(double v) {
//        return Point(x*v, y*v, z*v);
//    }
//    Point operator*(Point v){
//        return Point(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
//    }
//    Point operator/(double pt) {
//        return Point(x/pt, y/pt, z/pt);
//    }
//    Point normalize() {
//        return *this / sqrt(x*x + y*y + z*z);
//    }
// 
//};
// 
//Point pos(0, 0, -150);
//Point u(0,1,0);
//Point r(1, 0, 0);
//Point l(0, 0, 1);
// 
//void drawKoch(double x1, double y1, double x2, double y2, int it){
//    float angle = 60 * (pi/180);
//    double x3 = (2*x1+x2)/3;
//    double y3 = (2*y1+y2)/3;
// 
//    double x4 = (x1+2*x2)/3;
//    double y4 = (y1+2*y2)/3;
// 
//    double x = x3 + (x4 - x3)* cos(angle) + (y4 -y3)* sin(angle);
//    double y = y3 - (x4 - x3)* sin(angle) + (y4 -y3)* cos(angle);
// 
//    if(it>0){
//        drawKoch(x1,y1,x3,y3,it-1);
//        drawKoch(x3,y3,x,y,it-1);
//        drawKoch(x,y,x4,y4,it-1);
//        drawKoch(x4,y4,x2,y2,it-1);
//    }
//    else{
//        glColor3f(0.4, 1.0, 1.3);
//            glBegin(GL_POLYGON);
//			{
//                   glVertex3f( x1,y1,0);
//                   glVertex3f(x3,y3,0);
//                   
//                   glVertex3f(x4,y4,0);
//                   glVertex3f(x2,y2,0);
//
// 			}glEnd();
// 			glBegin(GL_POLYGON);
//			{
//					glVertex3f(x,y,0);
//                   glVertex3f(x4,y4,0);
//
//                   glVertex3f(x3,y3,0);
//                   glVertex3f(x,y,0);
//                   
//
//            }glEnd();
//    }
//}
// 
//void display(){
// 
//     //clear the display
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glClearColor(0,0,0,0);     //color black
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 
//     /********************
//     / set-up camera here
//     ********************/
//     //load the correct matrix -- MODEL-VIEW matrix
//     glMatrixMode(GL_MODELVIEW);
// 
//     //initialize the matrix
//     glLoadIdentity();
// 
//     //now give three info
//     //1. where is the camera (viewer)?
//     //2. where is the camera looking?
//     //3. Which direction is the camera's UP direction?
// 
//     //gluLookAt(100,100,100,   0,0,0, 0,0,1);
//     //gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,             0,0,0, 0,0,1);
//     gluLookAt(pos.x, pos.y, pos.z, pos.x + l.x, pos.y + l.y, pos.z + l.z, u.x, u.y, u.z);
// 
//     //again select MODEL-VIEW
//     glMatrixMode(GL_MODELVIEW);
// 
//    drawKoch(50,0,0,100,2);
//    drawKoch(0,100,-50,0,2);
//    drawKoch(-50,0,50,0,2);
// 
//     //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
//     glutSwapBuffers();
//}
// 
//void init(){
//     //codes for initialization
//     //clear the screen
//     glClearColor(0,0,0,0);
// 
//     /************************
//     / set-up projection here
//     ************************/
//     //load the PROJECTION matrix
//     glMatrixMode(GL_PROJECTION);
// 
//     //initialize the matrix
//     glLoadIdentity();
// 
//     //give PERSPECTIVE parameters
//     //gluPerspective(fovY,     aspect_ratio, Near, Far);
//     gluPerspective(80,   1,     1,     1000.0);
//     //field of view in the Y (vertically)
//     //aspect ratio that determines the field of view in the X direction (horizontally)
//     //near distance
//     //far distance
//}
// 
//int main(int argc, char **argv){
// 
//     glutInit(&argc,argv);
//     glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//     glutInitWindowPosition(0, 0);
//     glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);     //Depth, Double buffer, RGB color
// 
//     glutCreateWindow("My OpenGL Program");
//     init();
// 
//     glEnable(GL_DEPTH_TEST);   //enable Depth Testing
//     glutDisplayFunc(display);  //display callback function
//     glutMainLoop();            //The main loop of OpenGL
// 
//     return 0;
//}

