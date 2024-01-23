//#include <GL/glut.h>
//#include <math.h>
//#include<stdio.h>
//using namespace std;
//int n; 
//const float PI = 3.14159265358979323846;
//
//void DragonCurve(int n, float x1, float y1, float x2, float y2) 
//{
//    if (n == 0) 
//	{
//        glVertex2f(x1, y1);
//        glVertex2f(x2, y2);
//    } else 
//	{
//        float x3 = (x1 + x2 + (y2 - y1)) / 2;
//        float y3 = (y1 + y2 + (x1 - x2)) / 2;
//        DragonCurve(n-1, x1, y1, x3, y3);
//        DragonCurve(n-1, x2, y2, x3, y3);
//    }
//}
//
//void display() 
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.3, 1.0, 1.0); 
//    glBegin(GL_LINES);
//    DragonCurve(n, -0.5, 0, 0.5, 0);
//    glEnd();
//    glFlush(); 
//}
//
//void init() 
//{
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION); 
//    glLoadIdentity(); 
//    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char** argv) 
//{
//	printf("----------BAI TAP 3----------\n");
//	printf("Nhap bac n : ");
//	scanf("%d",&n); 
//    glutInit(&argc, argv); 
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(1000, 500); 
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Dragon Curve"); 
//    init(); 
//    glutDisplayFunc(display); 
//    glutMainLoop(); 
//    return 0;
//}
