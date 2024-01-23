//#include <GL/glut.h>
//#include <cmath>
//const int WIDTH = 600; 
//const int HEIGHT = 500; 
//const int MAX_ITER = 1000; 
//
//int is_in_mandelbrot(float real, float imag) 
//{
//    float z_real = 0, z_imag = 0;
//    for (int i = 0; i < MAX_ITER; i++) 
//	{
//        float z_real_new = z_real*z_real - z_imag*z_imag + real;
//        float z_imag_new = 2*z_real*z_imag + imag;
//        z_real = z_real_new;
//        z_imag = z_imag_new;
//        if (z_real*z_real + z_imag*z_imag > 4) 
//		{
//            return i;
//        }
//    }
//    return -1;
//}
//
//void display() 
//{
//    glClear(GL_COLOR_BUFFER_BIT); 
//    glPointSize(1.0);
//    glBegin(GL_POINTS); 
//    for (int i = 0; i < WIDTH; i++) 
//	{
//        for (int j = 0; j < HEIGHT; j++) 
//		{
//            float x = -2.0 + 3.0*i/WIDTH;
//            float y = -1.5 + 3.0*j/HEIGHT;
//            int n = is_in_mandelbrot(x, y); 
//            if (n == -1) 
//			{ 
//                glColor3f(1.0, 1.0, 0.4); 
//                glVertex2f(i, j);
//            } 
//			else 
//			{
//                float c = n - log(log(sqrt(x*x + y*y)))/log(2); 
//                float r = 0.5 + 0.5*cos(c*0.05 + 0.1);
//                float g = 0.5 + 0.5*cos(c*0.1 + 1.2); 
//                float b = 0.5 + 0.5*cos(c*0.15 + 2.3); 
//                glColor3f(r, g, b);
//                glVertex2f(i, j); 
//            }
//        }
//    }
//    glEnd(); 
//    glFlush(); 
//}
//
//void reshape(int w, int h) 
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, w, 0, h);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) 
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(WIDTH, HEIGHT);
//	glutCreateWindow("Mandelbrot Set");
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}
