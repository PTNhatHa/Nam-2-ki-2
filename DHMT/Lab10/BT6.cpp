//#include <GL/glut.h>
//#include <complex>
//using namespace std;
//#define WIDTH 800
//#define HEIGHT 800
//
//const complex<float> c(-0.8, 0.156);
//
//void color(float r, float g, float b, float radius, int iter) 
//{
//    if (iter == 0) 
//	{
//        glColor3f(0.0, 0.0, 0.0);
//    } 
//	else 
//	{
//        float t = (float) iter / 100.0;
//        glColor3f(r * t, g * t, b * t);
//    }
//}
//
//void draw_julia() 
//{
//    glBegin(GL_POINTS);
//    for (int y = 0; y < HEIGHT; y++) 
//	{
//        for (int x = 0; x < WIDTH; x++) 
//		{
//            complex<float> z((float) x / (float) WIDTH * 4.0 - 2.0, (float) y / (float) HEIGHT * 4.0 - 2.0);
//            int iter = 0;
//            float radius = 0.0;
//            while (iter < 100 && radius < 4.0) 
//			{
//                z = z * z + c;
//                iter++;
//                radius = abs(z);
//            }
//            color(0.5, 0.5, 1.0, radius, iter);
//            glVertex2i(x, y);
//        }
//    }
//    glEnd();
//}
//
//void display() 
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    draw_julia();
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
//int main(int argc, char** argv) 
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(WIDTH, HEIGHT);
//    glutCreateWindow("Julia Set");
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glPointSize(1.0);
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutMainLoop();
//    return 0;
//}

