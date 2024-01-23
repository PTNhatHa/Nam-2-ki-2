//#include <GL/glut.h>
//#include <cmath>
//#include<stdio.h>
//int n;
//
//void KochCurve(int n, double x1, double y1, double x2, double y2) 
//{
//    if (n == 0) {
//
//        glBegin(GL_LINES);
//        glVertex2d(x1, y1);
//        glVertex2d(x2, y2);
//        glEnd();
//    }
//    else 
//	{
//
//        double x3 = (2*x1 + x2) / 3;
//        double y3 = (2*y1 + y2) / 3;
//        double x4 = (x1 + x2) / 2 + (y1 - y2) / (2*sqrt(3));
//        double y4 = (y1 + y2) / 2 + (x2 - x1) / (2*sqrt(3));
//        double x5 = (x1 + 2*x2) / 3;
//        double y5 = (y1 + 2*y2) / 3;
//        
//        KochCurve(n-1, x1, y1, x3, y3);
//        KochCurve(n-1, x3, y3, x4, y4);
//        KochCurve(n-1, x4, y4, x5, y5);
//        KochCurve(n-1, x5, y5, x2, y2);
//    }
//}
//
//void display() 
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 0.5, 1.0);  
//    glLoadIdentity();
//    KochCurve(n, -0.8, 0.0, 0.8, 0.0);  
//    glFlush();
//}
//
//void reshape(int width, int height) 
//{
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void init() 
//{
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//}
//
//int main(int argc, char** argv) 
//{
//	printf("----------BAI TAP 1----------\n");
//	printf("Nhap bac n : ");
//	scanf("%d",&n); 
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Koch Curve");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}
