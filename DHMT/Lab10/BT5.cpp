//#include <GL/glut.h>
//#include <cmath>
//#define WIDTH 800
//#define HEIGHT 800
//int level = 3;
//
//void draw_triangle(float x, float y, float size, float angle) 
//{
//    glBegin(GL_TRIANGLES);
//    glVertex2f(x, y);
//    glVertex2f(x + size * cos(angle), y + size * sin(angle));
//    glVertex2f(x + size * cos(angle + M_PI / 2.0), y + size * sin(angle + M_PI / 2.0));
//    glEnd();
//}
//
//void draw_pythagoras(float x, float y, float size, float angle, int level) 
//{
//    if (level == 0) 
//	{
//        return;
//    }
//    draw_triangle(x, y, size, angle);
//    float x1 = x + size * cos(angle);
//    float y1 = y + size * sin(angle);
//    float x2 = x1 + size * cos(angle - M_PI / 2.0);
//    float y2 = y1 + size * sin(angle - M_PI / 2.0);
//    float x3 = x + size * cos(angle + M_PI / 2.0);
//    float y3 = y + size * sin(angle + M_PI / 2.0);
//    draw_pythagoras(x1, y1, size / sqrt(2.0), angle - M_PI / 4.0, level - 1);
//    draw_pythagoras(x2, y2, size / sqrt(2.0), angle - M_PI / 4.0, level - 1);
//    draw_pythagoras(x3, y3, size / sqrt(2.0), angle + M_PI / 4.0, level - 1);
//}
//
//void display() 
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    glColor3f(0.0, 0.0, 0.0);
//    draw_pythagoras(0, 0, WIDTH, HEIGHT, level);
//
//    glFlush();
//}
//
//void reshape(int w, int h) 
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, w, 0, h);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void keyboard(unsigned char key, int x, int y) 
//{
//    if (key == '+') 
//	{
//        level++;
//        glutPostRedisplay();
//    } 
//	else 
//	if (key == '-') 
//	{
//        level--;
//    	if (level < 0) 
//		{
//        	level = 0;
//    	}
//    	glutPostRedisplay();
//	}
//}
//
//int main(int argc, char** argv) 
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(WIDTH, HEIGHT);
//	glutCreateWindow("Pythagoras Fractal");
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}
