//#include <iostream>
//#include <stdio.h>
//#include <GL\glut.h>
//#include <cmath>
//
//const float PI = 3.14159265358979323846;
//
///*
//	x = at + x0
//	y = bt + y0
//	z = ct + z0 
//*/
//class Line 
//{
//	public:
//		GLdouble a, b, c;
//		GLdouble x0, y0, z0;
//	
//		Line(GLdouble a, GLdouble b, GLdouble c, GLdouble x0, GLdouble y0, GLdouble z0) {
//			this->a = a;
//			this->b = b; 
//			this->c = c;
//			this->x0 = x0;
//			this->y0 = y0;
//			this->z0 = z0;
//		}
//};
//
//class LineSegment 
//{
//	public:
//		GLdouble x1, y1, z1;
//		GLdouble x2, y2, z2;
//		GLdouble r, g, b;
//	
//		LineSegment(GLdouble x1, GLdouble y1, GLdouble z1, GLdouble x2, GLdouble y2, GLdouble z2, GLdouble r=1.0, GLdouble g=1.0, GLdouble b=1.0) 
//		{
//			this->x1 = x1;
//			this->y1 = y1;
//			this->z1 = z1;
//			this->x2 = x2;
//			this->y2 = y2;
//			this->z2 = z2;
//			this->r = r;
//			this->g = g;
//			this->b = b;
//		}
//		
//		void draw() 
//		{
//			glColor3f(this->r, this->g, this->b);
//			glVertex3f(this->x1, this->y1, this->z1);
//			glVertex3f(this->x2, this->y2, this->z2);	
//		}
//		
//		void translation(GLdouble step_x, GLdouble step_y, GLdouble step_z) 
//		{
//			glTranslatef(step_x, step_y, step_z);
//		}
//		
//		void rotation(GLdouble angle, Line line) 
//		{
//			glTranslatef(line.x0, line.y0, line.z0); 
//			glRotatef(angle, line.a, line.b, line.c);
//			glTranslatef(-line.x0, -line.y0, -line.z0);
//		}
//		
//		void reflection(Line line) 
//		{
//			this->rotation(180, line);
//		}
//};
//
//LineSegment PQ(1.0, 2.0, 0.0, 7.0, 14.0, 0.0, 0.0, 0.8, 0.8);
//Line Ox(1.0, 0.0, 0.0, 1.0, 0.0, 0.0);
//Line Oy(0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
//Line MN(5.0, 40.0, 10.0, 5.0, -40.0, 0.0);
//
//void display() 
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPushMatrix();
//	glBegin(GL_LINES);
//	PQ.draw();
//	glEnd();
//	glPopMatrix();
//	glFlush();
//}
//
//void keyEvents(unsigned char key, int x, int y) {
//	std::cout << "Key: " << key << std::endl;
//	switch (key) {
//		case 116: 	// t
//		case 84: { 	// T
//			PQ.translation(5.0, 0.0, 0.0);
//			glutPostRedisplay();
//			break;
//		}
//		case 114:	// r
//		case 82: {	// R
//			PQ.rotation(30.0, Oy);
//			glutPostRedisplay();
//			break;
//		}
//		case 112:	// p
//		case 80: {	// P
//			PQ.reflection(Ox);
//			glutPostRedisplay();
//			break;
//		}
//		case 102:	// f
//		case 70: {	// F
//			PQ.reflection(MN);
//			glutPostRedisplay();
//			break;
//		}
//		case 104:	// h
//		case 72: {	// H
//			PQ.rotation(30.0, MN);
//			glutPostRedisplay();
//			break;
//		}
//	}
//}
//
//void setupWindow(const char* title, int width, int height, int pos_x, int pos_y) {
//	glutInitWindowSize(width, height);
//	glutInitWindowPosition(pos_x, pos_y);
//	glutCreateWindow(title);
//}
//
//void init() {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-40.0, 40.0, -40.0, 40.0, -40.0, 40.0);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	setupWindow("Lab 02", 640, 480, 100, 100);
//	init();
//	glutDisplayFunc(display);
//	glutKeyboardFunc(keyEvents);
//	glutMainLoop();
//	return 0;
//}
