//#include <iostream>
//#include <math.h>
//#include <GL/glut.h>
//#include<stdio.h>
//#define PI 3.14159265358979323846
//int n; 
//
//void drawLine(float x1, float y1, float x2, float y2) 
//{
//    glBegin(GL_LINES);
//    glVertex2f(x1, y1);
//    glVertex2f(x2, y2);
//    glEnd();
//}
//
//void KochCurve(int n, float x1, float y1, float x2, float y2) 
//{
//    if (n == 0) 
//	{ 
//        drawLine(x1, y1, x2, y2); 
//    }
//    else 
//	{
//        float dx = x2 - x1;
//        float dy = y2 - y1;
//        float dist = sqrt(dx*dx + dy*dy); 
//        float angle = atan2(dy, dx); 
//        float segment = dist / 3.0;
//
//        float xA = x1 + cos(angle) * segment;
//        float yA = y1 + sin(angle) * segment;
//
//        float xB = xA + cos(angle - PI / 3.0) * segment;
//        float yB = yA + sin(angle - PI / 3.0) * segment;
//	    float xC = xB + cos(angle + PI / 3.0) * segment;
//	    float yC = yB + sin(angle + PI / 3.0) * segment;
//	
//	    float xD = x1 + 2 * cos(angle) * segment;
//	    float yD = y1 + 2 * sin(angle) * segment;
//	
//	    KochCurve(n - 1, x1, y1, xA, yA);
//	    KochCurve(n - 1, xA, yA, xB, yB);
//	    KochCurve(n - 1, xB, yB, xC, yC);
//	    KochCurve(n - 1, xC, yC, xD, yD);
//	    KochCurve(n - 1, xD, yD, x2, y2);
//	}
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT); 
//	glColor3f(1.0, 0.2, 0.0); 
//	KochCurve(n, -0.8, 0.0, 0.8, 0.0); 
//	glFlush(); 
//}
//
//void init() 
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0); 
//	glMatrixMode(GL_PROJECTION); 
//	glLoadIdentity(); 
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
//}
//
//int main(int argc, char** argv) 
//{
//	printf("----------BAI TAP 2----------\n");
//	printf("Nhap bac n : ");
//	scanf("%d",&n); 
//	glutInit(&argc, argv); 
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100); 
//	glutCreateWindow("Koch Curve - C Curve - Dragon Curve"); 
//	init(); 
//	glutDisplayFunc(display); 
//	glutMainLoop(); 
//	return 0;
//}
